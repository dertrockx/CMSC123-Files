#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

	char command;
	int key, result, type;
    int* sorted;

	scanf("%d ", &type);
	//type is zero (0) if MINHEAP, one (1) if MAXHEAP
	HEAP *H = createHeap(30, type);

	while(1){
		scanf("%c ", &command);

		switch(command){
			case '+':
				scanf(" %d\n", &key);
				printf("Inserting key: %d...\n", key);
				insert(H, key);
				break;
			case 'p':
				printf("Printing the heap (rotated +90 degrees)...\n");
				printHeap(H);
				printf("\n");
				break;
			case 'E':
				printf("Heap %s empty.\n", isEmpty(H)?"is":"is not");
				break;
			case 'F':
				printf("Heap %s full.\n", isFull(H)?"is":"is not");
				break;
			case 'C':
				printf("Removing all contents...\n");
				clear(H);
				break;
			case 'Q':
				return 0;
			default:
				printf("Unknown command: %c\n", command);
		}
	}

	return 0;
}
