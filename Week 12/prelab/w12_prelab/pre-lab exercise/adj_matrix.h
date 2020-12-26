#ifndef _ADJ_MATRIX_H_
#define _ADJ_MATRIX_H_

typedef struct adj_matrix_tag {
  int **matrix; // a 2d array of int called matrix; this is our adjacency matrix
  int num_vertices; // number of vertices in our graph; this is to check for valid operations
} GRAPH;


GRAPH *createGraph(int);
void addEdge(GRAPH*, int, int);
int isAdjacent(GRAPH*, int, int);
void printGraph(GRAPH*);

#endif
