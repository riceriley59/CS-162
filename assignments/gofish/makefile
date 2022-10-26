CC=g++
CCFLAGS = -g

EXE_FILE=gofish
BIN = bin
SRC = src
INCLUDE = include

all: $(BIN)/$(EXE_FILE)

run: clean all
	clear
	@echo "🚀 Executing..."
	./$(BIN)/$(EXE_FILE)

debug: $(SRC)/*.cpp
	$(CC) $(CCFLAGS) -I $(INCLUDE) $^ -o $(BIN)/$(EXE_FILE)
	gdb ./$(BIN)/$(EXE_FILE)


$(BIN)/$(EXE_FILE): $(SRC)/*.cpp
	$(CC) -I $(INCLUDE) $^ -o $@

clean:
	@echo "🧹 Clearing..."
	-rm $(BIN)/*