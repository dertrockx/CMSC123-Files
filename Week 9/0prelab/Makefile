CC = gcc
CFLAGS = -0

default: run

run: build
	./run < program.cs
build: compile
	$(CC) -o run main.o heap.o
compile: main.c heap.h heap.c
	$(CC) -c main.c heap.c
clean:
	$(RM) *.o *.gch


run2: build2
	./run2 < program2.cs
build2: compile
	$(CC) -o run2 main.o heap.o
compile2: main.c heap.h heap.c
	$(CC) -c main.c heap.c