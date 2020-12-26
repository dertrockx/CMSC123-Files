#include <stdio.h>
#include <stdlib.h>
#include "adj_list.h"

GRAPH *createGraph(int num_vertices)
{
  int i;
  GRAPH *G = (GRAPH *)malloc(sizeof(GRAPH)); // allocate memory for GRAPH G

  G->num_vertices = num_vertices + 1;                          // initialize number of vertices [1]
  G->list = (DATA **)malloc(sizeof(DATA *) * G->num_vertices); // initialize a dynamic 2d array of DATA for G->list

  // initialize each element of G->list to point to NULL
  for (i = 0; i < G->num_vertices; i++)
  {
    G->list[i] = NULL;
  }

  return G;
}

void addEdge(GRAPH *G, int u, int v)
{
  if (u <= G->num_vertices && v <= G->num_vertices)
  {                            //check if u and v are valid vertices based on number of vertices
    DATA **temp = &G->list[u]; // get a reference to the neighbors of u [2]

    DATA *new_data = (DATA *)malloc(sizeof(DATA)); //initialize new DATA
    new_data->v = v;

    while (*temp && new_data->v > (*temp)->v)
    {
      temp = &((*temp)->next); // we are pointing temp to the 'next' pointer
    }

    // insert into the linked list in an ascending order
    // adjust other pointers accordingly
    new_data->next = *temp;
    *temp = new_data;
  }
}

int isAdjacent(GRAPH *G, int u, int v)
{
  if (u <= G->num_vertices && v <= G->num_vertices)
  {                          //check if u and v are valid vertices based on number of vertices
    DATA *temp = G->list[u]; // create a temp that points to the u-th index of the adjacency list;
        // the list at the u-th index are the neighbors of vertex u

    // while u has neighbors
    while (temp)
    {
      if (temp->v == v)
        return 1;        // if neighbor == v, return 1
      temp = temp->next; // else, check other neighbors of u in the list
    }
  }

  return 0; // do not forget to return 0
}

void printGraph(GRAPH *G)
{
  int i;
  DATA *temp;

  for (i = 1; i < G->num_vertices; i++)
  {
    printf("%d -> {", i);
    temp = G->list[i];

    while (temp)
    {
      printf("%d", temp->v);
      temp = temp->next;
      if (temp)
        printf(", ");
      else
        break;
    }
    printf("}\n");
  }
}

/* [1]
  we added a +1 in the num_vertices so that the index zero will be a dummy node or a placeholder node
  this makes our code easier to understand since less calculations will be needed to adjust vertices
    however, this convenience costs our implementation to need more space/storage
    especially in very very large test cases

  try to find an implementation wherein a dummy node is no longer needed
*/

/* [2]
  we are referencing the u-th pointer and
    not simply pointing temp to where the u-th pointer is pointing

  we are doing this:

              [*] --> [ ]--
              [*] --> [ ]--
              [*] --> [ ]--
  temp[*] --> [*] --> [ ]--

  and not this:
              [*] --> [ ]--
              [*] --> [ ]--
              [*] --> [ ]--
              [*] --> [ ]--
                       ^
                       |
                       |
                 temp [*]

  try to draw it in order to visualize it and to understand how it works
*/
