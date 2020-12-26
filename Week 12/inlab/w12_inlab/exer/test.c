#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "graph_traversal.h"
#include "queue.h"
#include "list.h"

void main()
{
  QUEUE *frontier = createQueue();
  NODE *tempNode = (NODE *)malloc(sizeof(NODE));

  tempNode->value = 1;
  tempNode->next = NULL;
  enqueue(frontier, tempNode);
  show(frontier);
}