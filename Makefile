# Declaration of variables
CC := g++
CC_FLAGS := -Wall -Werror

# Directories
SRC_DIR := src
OBJ_DIR := build
BIN_DIR := bin
TEST_DIR := test

# File names
EXEC = $(BIN_DIR)/contadino
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst %,$(OBJ_DIR)/%,$(patsubst %.cpp,%.o,$(SOURCES)))
TEST_EXEC = $(BIN_DIR)/contadino_test
TEST_SOURCES = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJECTS = $(patsubst %,$(OBJ_DIR)/%,$(patsubst %.cpp,%.o,$(TEST_SOURCES)))

# Libraries to link
LIBS =
TEST_LIBS = gtest

# All target
.PHONY: all
all: $(EXEC) $(TEST_EXEC)

# Main target
$(EXEC): $(OBJECTS)
	@$(call print_rule,LINK,$(EXEC),$(EXEC))
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
	@$(call print_rule,CLEAN,removing all output)
	@rm -f $(EXEC) $(OBJECTS) $(TEST_OBJECTS)

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

# print_rule: action,target
print_rule = printf "  $(T_GREEN)%-6s$(T_RESET) $(T_CYAN)%-24s$(T_RESET) %s\n" "$1" "$2"

# print_warning: message
print_warning = ( $(TTY_CLEARLINE) ; printf "  $(T_YELLOW)WARN   $(T_CYAN)%-24s$(T_RESET) %s\n" "$1")

# Colours!
T_RESET := \e[0m
T_BOLD := \e[1m
T_BLACK := \e[30m
T_RED := \e[31m
T_GREEN := \e[32m
T_YELLOW := \e[33m
T_BLUE := \e[34m
T_MAGENTA := \e[35m
T_CYAN := \e[36m
T_WHITE := \e[37m
TTY_CLEARLINE = printf "\r\e[K"
