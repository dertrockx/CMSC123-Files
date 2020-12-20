#include "heap.h"
#include <stdio.h>
#include <malloc.h>
//include here additional header files

void printHeapHelper(HEAP *H, int index, int tabs){
	if(index > H->size) return;
	else{
		printHeapHelper(H, index*2+1, tabs + 1);
		for(int i=0; i<tabs; i++) printf("\t");
		printf("%d\n", H->heap[index]);
		printHeapHelper(H, index*2, tabs + 1);
	}
}

void printHeap(HEAP *H){
	if(H!=NULL && H->size>0){
		printHeapHelper(H, 1, 0);
	}else{
		printf("Empty heap!\n");
	}
}

/*IMPLEMENT THE FUNCTIONS HERE*/

void swap(int *x, int *y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

HEAP* createHeap(int maxSize, int type){
	HEAP *h = (HEAP *) malloc(sizeof(HEAP));

	h->heap = (int *) malloc((maxSize+1) * sizeof(int));
	h->size = 0;
	h->maxSize = maxSize;
	h->type = type;
}

int isFull(HEAP *H){
	if(H!=NULL && H->size == H->maxSize) return 1;
	else return 0;
}

int isEmpty(HEAP *H){
	if(H!=NULL && H->size == 0) return 1;
	else return 0;
}

void clear(HEAP *H){
	if(H!=NULL && !isEmpty(H)) H->size = 0;
}