CC=g++
EXE_FILE=pokedex

all: $(EXE_FILE)

$(EXE_FILE): pokemon.o pokemon.h run_pokemon.cpp
        $(CC) multdiv.o prog.cpp -o $(EXE_FILE)

multdiv.o: pokemon.h pokemon.cpp
        $(CC) -c multdiv.cpp

clean:
        rm -f *.o $(EXE_FILE)
