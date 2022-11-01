CC=g++
CCFLAGS = -std=c++11 -g

EXE_FILE=gofish
BIN = bin
SRC = src
INCLUDE = include
OBJ = $(BIN)/obj
OBJS := $(OBJ)/player.o $(OBJ)/game.o $(OBJ)/deck.o $(OBJ)/hand.o $(OBJ)/card.o $(OBJ)/main.o

all: $(OBJS) $(BIN)/$(EXE_FILE)

valgrind: clean all 
	clear 
	@echo "Checking for Memory Leaks"
	valgrind ./$(BIN)/$(EXE_FILE)

run: 
	./$(BIN)/$(EXE_FILE)

crun: clean all
	clear
	@echo "🚀 Executing..."
	./$(BIN)/$(EXE_FILE)

debug: clean all
	clear 
	@echo "Debug Mode..."
	gdb ./$(BIN)/$(EXE_FILE)

clean:
	@echo "🧹 Clearing..."
	rm -rf $(BIN)/*
	mkdir $(OBJ)

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) $(CCFLAGS) -I $(INCLUDE) -c $< -o $@

$(BIN)/$(EXE_FILE): $(OBJS)
	$(CC) $(CCFLAGS) -I $(INCLUDE) $^ -o $@