#include <stdio.h>
#include <stdlib.h>
#include "adj_list.h" // replace with representation of your choice
#include "graph_traversal.h"
#include "list.h"
#include "queue.h"

void DFS(GRAPH *G, int source, int *visited)
{ // [1]
  int i;

  visited[source] = 1;   // set source as visisted
  printf("%d ", source); // print source vertex

  for (i = 1; i < G->num_vertices; i++)
  {
    if (isAdjacent(G, source, i) && !visited[i])
    {                     // for each adjacent vertex that is not visited
      DFS(G, i, visited); //perform DFS; recursive call on same graph, adjacent vertex, and same visited array
    }
  }
}

void BFS(GRAPH *G, int source)
{
  //  initialize frontier [2] and visited variables
  QUEUE *frontier = createQueue();
  int numVertices = G->num_vertices;
  int *visited = malloc(sizeof(int) * numVertices + 1);
  // instantiate the frontier queue
  for (int j = 0; j < numVertices + 1; j++)
  {
    visited[j] = 0;
  }
  // QUEUE: NODE; GRAPH: DATA;

  // visited[source] = TRUE
  // frontier.enqueue(source)
  visited[source] = 1;

  enqueue(frontier, createNode(source));

  while (!isEmpty(frontier))
  {
    int u = dequeue(frontier);
    printf("%d ", u);
    for (int i = 1; i < numVertices; i++)
    {
      if (!visited[i] && isAdjacent(G, u, i))
      {
        visited[i] = 1;

        enqueue(frontier, createNode(i));
      }
    }
  }
}

/* [1]
  take note of the parameters for DFS

  why do we need to add int *invested as params?
    this is to properly keep track the visited vertices during recursive calls

  if we instantiate a new visited array every time a recursive call happens
    we lose all the information we had before

  you may also think of the visited array as an accumulator
*/

/* [2]
  for the frontier, it is best to implement a queue

  it is up to you if you use your previous queue ADT
    or you want to create a more simpler one
*/
