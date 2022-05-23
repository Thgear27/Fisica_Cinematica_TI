CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -g

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lopengl32
EXECUTABLE	:= main


all: $(BIN)/$(EXECUTABLE)

run: clean
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -I./src -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
