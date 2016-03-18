# Declaration of variables
CC := g++
CC_FLAGS := -Wall -Werror
CLANG := clang
CLANG_FLAGS := --analyze

# Directories
SRC_DIR := src
OBJ_DIR := build
CLANG_DIR := build/clang
BIN_DIR := bin
TEST_DIR := test

# File names
EXEC = $(BIN_DIR)/contadino
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst %,$(OBJ_DIR)/%,$(patsubst %.cpp,%.o,$(SOURCES)))
CLANG_OBJECTS = $(patsubst %,$(CLANG_DIR)/%,$(patsubst %.cpp,%.o,$(SOURCES)))
TEST_EXEC = $(BIN_DIR)/contadino_test
TEST_SOURCES = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJECTS = $(patsubst %,$(OBJ_DIR)/%,$(patsubst %.cpp,%.o,$(TEST_SOURCES)))

# Libraries to link
LIBS =
TEST_LIBS = gtest pthread

# All target
.PHONY: all
all: $(EXEC) $(TEST_EXEC)

# Main target
$(EXEC): $(OBJECTS)
	@$(call print_rule,LINK,$(EXEC))
	@mkdir -p $(BIN_DIR)
	@$(CC) $(OBJECTS) -o $(EXEC) $(addprefix -l,$(TEST_LIBS))

# Test target
$(TEST_EXEC): $(TEST_OBJECTS) $(EXEC)
	@$(call print_rule,LINK,$(TEST_EXEC),$(TEST_EXEC))
	@mkdir -p $(BIN_DIR)
	@$(CC) $(TEST_OBJECTS) -o $(TEST_EXEC) $(addprefix -l,$(TEST_LIBS))

# General compilation rule
$(OBJ_DIR)/%.o: %.cpp
	@$(call print_rule,G++,$<)
	@mkdir -p $(dir $@)
	@$(CC) -c $(CC_FLAGS) $< -o $@

# Clean
.PHONY: clean
clean:
	@$(call print_rule,CLEAN,cleaning...)
	@rm -f $(EXEC) $(TEST_EXEC) $(OBJECTS) $(TEST_OBJECTS) $(CLANG_OBJECTS)

# Run the program
.PHONY: run
run: $(EXEC)
	@$(call print_rule,RUN,$(EXEC))
	@$(EXEC)

# Run tests
.PHONY: test
test: $(TEST_EXEC)
	@$(call print_rule,TEST,$(TEST_EXEC))
	@$(TEST_EXEC) --gtest_color=yes

# Static analysis
.PHONY: clang
clang: $(CLANG_OBJECTS)
$(CLANG_DIR)/%.o: %.cpp
	@$(call print_rule,CLANG,$<)
	@mkdir -p $(dir $@)
	@$(CLANG) -c $(CLANG_FLAGS) $< -o $@

# print_rule: action,target
print_rule = printf "  $(T_BLUE)$(T_BRIGHT)%-6s$(T_RESET) $(T_LIME_YELLOW)%-24s$(T_RESET) %s\n" "$1" "$2"

# print_warning: message
print_warning = ( $(TTY_CLEARLINE) ; printf "  $(T_YELLOW)WARN   $(T_CYAN)%-24s$(T_RESET) %s\n" "$1")

# Colours!
T_BLACK := $(shell tput setaf 0)
T_RED := $(shell tput setaf 1)
T_GREEN := $(shell tput setaf 2)
T_YELLOW := $(shell tput setaf 3)
T_LIME_YELLOW=$(shell tput setaf 190)
T_POWDER_BLUE=$(shell tput setaf 153)
T_BLUE=$(shell tput setaf 4)
T_MAGENTA=$(shell tput setaf 5)
T_CYAN=$(shell tput setaf 6)
T_WHITE=$(shell tput setaf 7)
T_BRIGHT=$(shell tput bold)
T_RESET=$(shell tput sgr0)
T_REVERSE=$(shell tput smso)
T_UNDERLINE=$(shell tput smul)
TTY_CLEARLINE = printf "\r\e[K"
