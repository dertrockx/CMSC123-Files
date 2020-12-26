#include <stdio.h>
#include "adj_list.h" // update this to whichever graph representation you want to use

int main()
{
  int num_vertices, num_edges;
  int u, v;
  int i;

  scanf("%d %d", &num_vertices, &num_edges);
  GRAPH *G = createGraph(num_vertices);

  for (i = 0; i < num_edges; i++)
  {
    scanf("%d %d", &u, &v);
    addEdge(G, u, v);
    addEdge(G, v, u);
  }

  printGraph(G);

  // you may add and print isAdjacent here;
  // take note that you still need to interpret the returned values (0 and 1)
  // for the function call to be more meaningful when printing

  return 0;
}
