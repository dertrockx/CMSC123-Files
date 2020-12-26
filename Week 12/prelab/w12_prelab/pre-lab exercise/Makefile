CC = gcc
CFLAGS = -0

default: run

run: build
	./run < test2.in
	./run < test1.in
	./run < test3.in
build: compile
	$(CC) -o run main.o adj_list.o
compile: main.c adj_list.h adj_list.c
	$(CC) -c main.c adj_list.c


matrix: build_matrix
	./run_matrix < test1.in
build_matrix: compile_matrix
	$(CC) -o run_matrix main_matrix.o adj_matrix.o
compile_matrix: main_matrix.c adj_matrix.h adj_matrix.c
	$(CC) -c main_matrix.c adj_matrix.c


clean:
	$(RM) *.o *.gch