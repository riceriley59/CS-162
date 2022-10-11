CC=g++
EXE_FILE=pokedex

all: $(EXE_FILE)

$(EXE_FILE): pokemon.o pokemon.h run_pokemon.cpp
	$(CC) pokemon.o run_pokemon.cpp -o $(EXE_FILE)

pokemon.o: pokemon.cpp pokemon.h
	$(CC) -c pokemon.cpp

clean:
	rm -f *.o $(EXE_FILE)
