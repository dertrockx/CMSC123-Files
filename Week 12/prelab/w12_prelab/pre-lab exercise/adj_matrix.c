#include <stdlib.h>
#include <stdio.h>
#include "adj_matrix.h"


GRAPH *createGraph(int);
void addEdge(GRAPH*, int, int);
int isAdjacent(GRAPH*, int, int);
void printGraph(GRAPH*);

GRAPH *createGraph(int num_vertices) {
  // instantiate an instance of a GRAPH* and allocate a memory for it

  // initialize its num_vertices; it is up to you if you want to use a dummy row/col

  // initialize its matrix to be a 2d array of size with respect to num_vertices
  // first we initialize the array of int pointers
  // then we initialize each array of int
    // make sure that each element in the matrix is set to 0 first


  // always REMEMBER to RETURN the newly created graph!
}

void addEdge(GRAPH *G, int u, int v) {
  // update the value at cell u-v of the matrix to 1
    // signifying an edge between u and v is present
}

int isAdjacent(GRAPH *G, int u, int v) {
  // simply return the value of cell u-v from the matrix
  // since it already represents if an edge between u and v is present (1) or not (0)
}

void printGraph(GRAPH *G) {
  int i, j;

  for (i=0; i<G->num_vertices; i++) { // prints the column header
    printf("%4d ", i);
  }

  printf("\n");

  for (i=1; i<G->num_vertices; i++) {
    printf("%4d ", i); // prints the row header
    for (j=1 ; j<G->num_vertices; j++) {
      printf("%4d ", G->matrix[i][j]);
    }
    printf("\n");
  }
}
