CC=g++
EXE_FILE=student

all: $(EXE_FILE)

$(EXE_FILE): student.o student.h prog.cpp
	$(CC) student.o prog.cpp -o $(EXE_FILE)

student.o: student.h student.cpp
	$(CC) -c student.cpp

clean:
	rm -f *.o $(EXE_FILE)
