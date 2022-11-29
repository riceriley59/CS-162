CC=g++ -std=c++11
exe_file=task2

$(exe_file): task2_main.cpp list.o solution2.o memory.o
	$(CC) task2_main.cpp list.o solution2.o memory.o -o $(exe_file) 

list.o: list.cpp list.h
	$(CC) -c list.cpp 

solution2.o: solution2.cpp
	$(CC) -c solution2.cpp 

memory.o: memory.cpp
	$(CC) -c memory.cpp 

clean: 
	rm -f *.o $(exe_file)


.PHONY: clean