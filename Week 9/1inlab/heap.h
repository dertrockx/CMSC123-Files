#ifndef _HEAP_H_
#define _HEAP_H_

typedef struct heap_tag {
  int *heap;
  int size;
  int maxSize;
  int type;
} HEAP;

void printHeap(HEAP *H);


/*
 *  CREATE HEAP
 *  requirements: none
 *  results:
    creates an integr array with size = maxSize+1
      the +1 is needed since this implementation
      will be using index 1 as the root of the heap
    initializes fields of the structure
    returns the created heap
*/
HEAP* createHeap(int maxSize, int type);


/*
 *  IS FULL
 *  requirements: none
 *  results:
      return 1 if the heap is full;
      otherwise return 0
*/
int isFull(HEAP *H);


/*
 *  IS EMPTY
 *  requirements: none
 *  results:
      return 1 if the heap is empty;
      otherwise return 0
*/
int isEmpty(HEAP *H);


/*
 *  CLEAR
 *  requirements:
      a non-null HEAP pointer
      a non-empty *heap
 *  results:
    deletes all the items in the heap
*/
void clear(HEAP *H);


/*
 *  INSERT
 *  requirements:
      a non-null HEAP pointer
      a non-full *heap
 *  results:
      inserts `key` to the `heap`
*/
void insert(HEAP *H, int key);

#endif
