CC = gcc
CFLAGS = -O

default: run

run: build
	run < program.cs
build: compile
	$(CC) -o run main.o closed_hashtable.o -lm
compile: main.c closed_hashtable.c closed_hashtable.h
	$(CC) -c main.c closed_hashtable.c 
clean:
	$(RM) *.o *.gch

test: build_test
	./run_test
build_test: compile_test
	$(CC) -o run_test test.o closed_hashtable.o -lm
compile_test: main.c closed_hashtable.c closed_hashtable.h
	$(CC) -c test.c closed_hashtable.c 
