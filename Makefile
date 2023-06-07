CXX = g++
LDFLAGS = -lboost_iostreams -lboost_system -lboost_filesystem
BUILD_DIR=build
SRC = $(wildcard *.cpp)
# OBJ = $(SRC:.cpp=.o)
OBJ := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(notdir $(SRC)))
TEST := $(BUILD_DIR)/test_program

$(TEST): $(OBJ)
	$(CXX) -std=c++17 $(OBJ) $(LDFLAGS) -o $@

$(BUILD_DIR)/%.o: %.cpp
	$(CXX) -std=c++17 -o $@ -c $<

clean:
	rm -f $(BUILD_DIR)/*

.PHONY: clean rebuild

rebuild: clean $(TEST)