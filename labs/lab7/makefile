CC=g++
CCFLAGS = -std=c++11 -g

EXE_FILE=shape
BIN = bin
SRC = src
INCLUDE = include
OBJ = $(BIN)/obj
OBJS := $(OBJ)/shape.o $(OBJ)/application.o $(OBJ)/rectangle.o $(OBJ)/circle.o $(OBJ)/square.o

all: $(OBJS) $(BIN)/$(EXE_FILE)

valgrind: clean all 
	clear 
	@echo "Checking for Memory Leaks"
	valgrind ./$(BIN)/$(EXE_FILE)

run: 
	./$(BIN)/$(EXE_FILE)

crun: clean all
	clear
	@echo "๐ Executing..."
	./$(BIN)/$(EXE_FILE)

debug: clean all
	clear 
	@echo "Debug Mode..."
	sudo gdb ./$(BIN)/$(EXE_FILE)

clean:
	@echo "๐งน Clearing..."
	rm -rf $(BIN)/*
	mkdir $(OBJ)

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) $(CCFLAGS) -I $(INCLUDE) -c $< -o $@

$(BIN)/$(EXE_FILE): $(OBJS)
	$(CC) $(CCFLAGS) -I $(INCLUDE) $^ -o $@
