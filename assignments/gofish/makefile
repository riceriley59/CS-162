CC=g++
EXE_FILE=gofish

all: $(EXE_FILE)

$(EXE_FILE): game.o player.o hand.o deck.o card.o main.cpp
	$(CC) game.o player.o hand.o deck.o card.o main.cpp -o $(EXE_FILE)

game.o: game.h game.cpp
	$(CC) -c game.cpp

player.o: player.h player.cpp
	$(CC) -c player.cpp

hand.o: hand.h hand.cpp
	$(CC) -c hand.cpp

deck.o: deck.h deck.cpp
	$(CC) -c deck.cpp

card.o: card.h card.cpp
	$(CC) -c card.cpp

clean:
	rm -f *.o $(EXE_FILE)