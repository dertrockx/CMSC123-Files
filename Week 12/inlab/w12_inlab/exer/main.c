#include <stdio.h>
#include <stdlib.h>
#include "adj_list.h" // replace with representation of your choice
#include "graph_traversal.h"


int main() {
  int num_vertices, num_edges;
  int u, v;
  int i;

  scanf("%d %d", &num_vertices, &num_edges);
  GRAPH *G = createGraph(num_vertices);

  for (i=0; i<num_edges; i++) {
    scanf("%d %d", &u, &v);
    addEdge(G, u, v);
    addEdge(G, v, u);
  }

  int *visited = malloc(sizeof(int) * num_vertices+1);
  for (i=0; i<num_vertices+1; i++) {
    visited[i] = 0;
  }

  printf("DFS: ");
  DFS(G, 1, visited);
  printf("\n");

  printf("BFS: ");
  BFS(G, 1);
  printf("\n");

  return 0;
}
