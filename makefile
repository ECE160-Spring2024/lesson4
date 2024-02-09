# Definitions for constants
CC=gcc
CFLAGS=-I.

# This will create your final output using .o compiled files
make: main.o board.o
	$(CC) $(CFLAGS) -o main.out main.o board.o

# This will compile atof.c
board.o: board.c board.h globals.h
	$(CC) $(CFLAGS) -c board.c

# This will compile main.c with its dependency
main.o: main.c board.h globals.h
	$(CC) $(CFLAGS) -c main.c

# This will clean or remove compiled files so you can start fresh
clean:
	rm -f *.o *.out
