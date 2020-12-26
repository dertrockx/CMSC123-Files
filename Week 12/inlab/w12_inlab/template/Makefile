CC = gcc
CFLAGS = -0

default: run

run: build
	./run 
run1: build
	./run < test1.in
run2: build
	./run < test2.in
run3: build
	./run < test3.in
run4: build
	./run < test4.in
run5: build
	./run < test5.in

build: compile
	$(CC) -o run main.o graph_traversal.o adj_list.o list.o queue.o
compile: main.c adj_list.c graph_traversal.c list.c queue.c adj_list.h graph_traversal.h list.h queue.h
	$(CC) -c main.c adj_list.c graph_traversal.c list.c queue.c
clean:
	$(RM) *.o *.gch


test: build_test
	./run_test
build_test: compile_test
	$(CC) -o run_test test.o graph_traversal.o adj_list.o list.o queue.o
compile_test: test.c adj_list.c graph_traversal.c list.c queue.c adj_list.h graph_traversal.h list.h queue.h
	$(CC) -c test.c adj_list.c graph_traversal.c list.c queue.c
