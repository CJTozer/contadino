# Declaration of variables
CC = g++
CC_FLAGS = -Wall -Werror

# Directories
SRC_DIR = src
OBJ_DIR = output/objects
BIN_DIR = output

# File names
EXEC = $(BIN_DIR)/contadino
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(patsubst %.cpp,%.o,$(SOURCES)))

# Main target
$(EXEC): $(OBJECTS)
	@$(call print_rule,LINK,$(EXEC),$(EXEC))
	@mkdir -p $(BIN_DIR)
	@$(CC) $(OBJECTS) -o $(EXEC)

# To obtain object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(call print_rule,G++,$<)
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c $(CC_FLAGS) $< -o $@

# To remove generated files
clean:
	@$(call print_rule,CLEAN,$(EXEC) $(OBJECTS))
	@rm -f $(EXEC) $(OBJECTS)

# Run the program
run: $(EXEC)
	@$(call print_rule,RUN,$(EXEC))
	@$(EXEC)

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
