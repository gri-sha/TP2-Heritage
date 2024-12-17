CXX = g++
CXXFLAGS = -c -Wall -std=c++11 -DMAP

SRC_FILES = main.cpp trajet.cpp trajetSimple.cpp trajetCompose.cpp catalogue.cpp
BIN_DIR = bin
EXECUTABLE = ./trajets

# Generation of object file names
OBJ_FILES = $(SRC_FILES:%.cpp=$(BIN_DIR)/%.o)

all: $(EXECUTABLE)

# Link object files into the executable
$(EXECUTABLE): $(OBJ_FILES)
	$(CXX) $^ -o $@

# Compile source files into object files
# Ensuing that the bin directory exists
$(BIN_DIR)/%.o: %.cpp
	@mkdir -p $(BIN_DIR) 
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -rf $(BIN_DIR)

.PHONY: all clean
