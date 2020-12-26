CC = gcc
CFLAGS = -0

default: run

run: build
	./run 
build: compile
	$(CC) -o run main.o adj_list.o
compile: main.c adj_list.h adj_list.c
	$(CC) -c main.c adj_list.c


run_matrix: build_matrix
	./run_matrix
build_matrix: compile_matrix
	$(CC) -o run_matrix main_matrix.o adj_matrix.o
compile_matrix: main_matrix.c adj_matrix.h adj_matrix.c
	$(CC) -c main_matrix.c adj_matrix.c


clean:
	$(RM) *.o *.gch