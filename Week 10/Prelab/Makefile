CC = gcc
CFLAGS = -0

default: run

run: build
	./run < program.cs
build: compile
	$(CC) -o run main.o open_hashtable.o
compile: main.c open_hashtable.h open_hashtable.c
	$(CC) -c main.c open_hashtable.c
clean:
	$(RM) *.o *.gch


