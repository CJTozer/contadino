# Declaration of variables
CC = g++
CC_FLAGS = -Wall

# Directories
SRC_DIR = src
OBJ_DIR = output
BIN_DIR = output

# File names
EXEC = $(BIN_DIR)/contadino
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%,output/%,$(patsubst %.cpp,%.o,$(SOURCES)))

# Main target
$(EXEC): $(OBJECTS)
	mkdir -p $(BIN_DIR)
	$(CC) $(OBJECTS) -o $(EXEC)

# To obtain object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) -c $(CC_FLAGS) $< -o $@

# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)

test:
	echo $(OBJECTS)
