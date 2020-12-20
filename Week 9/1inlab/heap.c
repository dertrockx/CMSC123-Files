#include "heap.h"
#include <stdio.h>
#include <malloc.h>
//include here additional header files

void printHeapHelper(HEAP *H, int index, int tabs)
{
	if (index > H->size)
		return;
	else
	{
		printHeapHelper(H, index * 2 + 1, tabs + 1);
		for (int i = 0; i < tabs; i++)
			printf("\t");
		printf("%d\n", H->heap[index]);
		printHeapHelper(H, index * 2, tabs + 1);
	}
}

void printHeap(HEAP *H)
{
	if (H != NULL && H->size > 0)
	{
		printHeapHelper(H, 1, 0);
	}
	else
	{
		printf("Empty heap!\n");
	}
}

void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

/*IMPLEMENT THE FUNCTIONS HERE*/

HEAP *createHeap(int maxSize, int type)
{
	HEAP *h = (HEAP *)malloc(sizeof(HEAP));

	h->heap = (int *)malloc((maxSize + 1) * sizeof(int));
	h->size = 0;
	h->maxSize = maxSize;
	h->type = type;
}

int isFull(HEAP *H)
{
	if (H != NULL && H->size == H->maxSize)
		return 1;
	else
		return 0;
}

int isEmpty(HEAP *H)
{
	if (H != NULL && H->size == 0)
		return 1;
	else
		return 0;
}

void clear(HEAP *H)
{
	if (H != NULL && !isEmpty(H))
		H->size = 0;
}

// implement insert function

int deleteM(HEAP *H)
{
	if (H != NULL && !isEmpty(H))
	{
		int i = 1, child = i * 2;

		swap(&(H->heap[i]), &(H->heap[H->size])); // swap values of root and last position in the heap
		H->size--;																// decrease size of heap

		// percolate down iterate until the node can be swapped or node becomes a leaf node
		while (child <= H->size)
		{
			if (H->type == 1)
			{ // MAX HEAP
				// check the number of children
				// if there are two children, compare the their values
				if (child != H->size && H->heap[child] < H->heap[child + 1])
				{
					child++;
				}

				// compare the value of the node with its child with the greater value
				if (H->heap[i] < H->heap[child])
				{
					swap(&(H->heap[i]), &(H->heap[child]));
					i = child;
					child = 2 * i;
				}
				else
					break;
			}
			else
			{ // MIN HEAP
				// check the number of children
				// if there are two children, compare the their values
				if (child != H->size && H->heap[child] > H->heap[child + 1])
				{
					child++;
				}

				// compare the value of the node with its child with the greater value
				if (H->heap[i] > H->heap[child])
				{
					swap(&(H->heap[i]), &(H->heap[child]));
					i = child;
					child = 2 * i;
				}
				else
					break;
			}
		}

		return H->heap[H->size + 1]; // return the deleted key
	}
	else
		printf("Heap is empty.\n");

	return -1;
}

// some helper functions
int parent(int i) { return (i) / 2; }

// to get index of left child of node at index i
int left(int i) { return (2 * i); }

// to get index of right child of node at index i
int right(int i) { return (2 * i); }

void insert(HEAP *H, int key)
{

	// checks for overflow
	if (H->size == H->maxSize)
	{
		printf("Error, overflow\n");
		return;
	}

	// first sets the as the last child
	int i = H->size + 1;
	H->heap[i] = key;
	H->size++;

	if (H->type == 0)
	{
		// MINHEAP
		while (i != 1 && H->heap[parent(i)] > H->heap[i])
		{
			swap(&(H->heap[i]), &(H->heap[parent(i)]));
			i = parent(i);
		}
	}
	else
	{
		// MAXHEAP
		while (i != 1 && H->heap[parent(i)] < H->heap[i])
		{
			swap(&(H->heap[i]), &(H->heap[parent(i)]));
			i = parent(i);
		}
	}
}