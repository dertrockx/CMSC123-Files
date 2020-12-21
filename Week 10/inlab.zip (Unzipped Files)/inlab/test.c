#include "closed_hashtable.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void main()
{
  float loadFactor = 0.70;
  int tableSize = 5;
  int maxCapacity = (int)ceil(tableSize * loadFactor);
  printf("Max capacity of tableSize %d: %d\n", tableSize, maxCapacity);
  HASH_TABLE *h = createHashTable(tableSize, loadFactor);

  char *key = "username";
  char *data = "password";

  FILE *fp = fopen("test_results.txt", "w");
  printf("Inserting data %s with key %s\n", data, key);
  put(fp, &h, key, data);
  printTable(fp, h);

  key = "jukesonme";
  data = "paycar";
  printf("Inserting data %s with key %s\n", data, key);
  put(fp, &h, key, data);
  printTable(fp, h);

  deleteAll(h);
  printTable(fp, h);
}