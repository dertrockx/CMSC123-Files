#include "closed_hashtable.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//insert other headers here

//INSTRUCTIONS:
// You are allowed to add functions not declared in the h file
// hash1 and hash2 are already given, and you are not allowed to change them
// Implement all the functions declared in the h file
// The pseudocode for rehashing is already given to help you

void printTable(FILE *fp, HASH_TABLE *H)
{

  printf("print table\n");
  if (isEmpty(H))
  {
    fprintf(fp, "*empty\n");
    return;
  }
  for (int index = 0; index < H->tableSize; index++)
  {
    fprintf(fp, "Cell#%d: ", index);
    if (H->dataPair[index].key != NULL)
    {
      fprintf(fp, "%s", H->dataPair[index].value);
    }
    else
      fprintf(fp, "*empty*");
    fprintf(fp, "\n");
  }
}

HASH_TABLE *createHashTable(int tableSize, float loadFactor)
{
  HASH_TABLE *h;
  int i;

  h = (HASH_TABLE *)malloc(sizeof(HASH_TABLE));
  h->tableSize = tableSize;
  h->size = 0;
  h->loadFactor = loadFactor;
  h->dataPair = (DATA *)malloc(sizeof(DATA) * (tableSize));

  for (i = 0; i < tableSize; i++)
  {
    h->dataPair[i].key = NULL;
    h->dataPair[i].value = NULL;
  }
  //printf("Hash table created\n");
  return h;
}

int isEmpty(HASH_TABLE *h)
{
  if (h->size == 0)
    return 1;
  return 0;
}

int isFull(HASH_TABLE *h)
{
  int capacity = h->tableSize * h->loadFactor;
  capacity = (int)ceil(capacity);
  if (h->size == capacity)
    return 1;
  return 0;
}

int find(HASH_TABLE *H, char *key)
{
  DATA temp;

  for (int i = 0; i < H->tableSize; i++)
  {
    if (H->dataPair[i].value != NULL)
    {
      temp = H->dataPair[i];
      if (strcmp(temp.key, key) == 0)
      { //found the key index
        printf("key found %s\n", key);
        return i;
      }
    }
  }
  printf("key not found\n");
  return -1;
}

void deleteAll(HASH_TABLE *H)
{
  for (int i = 0; i < H->tableSize; i++)
  {
    H->dataPair[i].key = NULL;
    H->dataPair[i].value = NULL;
  }
  H->size = 0;
}

void erase(HASH_TABLE *H)
{
  deleteAll(H);
  free(H->dataPair);
  free(H);
}

int sumOfChar(char *key)
{
  int sum = 0;
  for (int i = 0; i < strlen(key); i++)
  {
    sum += key[i];
  }

  return sum;
}

//mod = hash table size
int hash1(int key, int mod)
{
  return key % mod;
}

int hash2(int key)
{
  return (7 - (key % 7));
}

//insert a given key to the hash table
//idea: check first if the hash table is already full,
//			if it is, perform rehashing first,
//						rehashing means, creating a new table larger than the current,
//														and moving the existing keys to the new hash table
//														by performing hashing to the keys one-at-a-time onto the new hash table
//						after rehashing is done,
//								 insert the given key
//			if no need to rehash, just insert the given key as is
void put(FILE *fp, HASH_TABLE **H, char *key, char *val)
{
  int ikey = sumOfChar(key);
  int array_index = hash1(ikey, (*H)->tableSize), i = 1;

  printf("inserting data %s with key %s %d\n", val, key, ikey);

  // checks if the pair is already on the table
  for (int j = 0; i < (*H)->tableSize; i++)
  {
    if ((*H)->dataPair[j].key != NULL)
    {
      if (strcmp((*H)->dataPair[j].key, key) == 0)
      {
        fprintf(fp, "Insertion Error: {key=%s, data=%s} is already in the table\n", key, val);
        return;
      }
    }
  }

  //performs rehash once size is greater than capacity = ceiling(tableSize*loadFactor)
  if (isFull(*H))
  {
    HASH_TABLE *new = rehash(*H, fp);
    erase(*H);
    *H = new;
    //determine the size of the new hash table
    //new table size = smallest prime number given twice the size of the currentsize
    //ex: currentsize is 7, next table size is 17
    //create a new hash table using the new table size and the same loadFactor
    //rehash all the keys stored in the old hash table to the new hash table
    //assign H to the new hash table and cleanly delete (or destroy) the old hash table
  }

  //insert key to hash table
  printf("inserting\n");
  while ((*H)->dataPair[array_index].key != NULL)
  {
    printf("inserting with probe\n");
    array_index = (hash1(ikey, (*H)->tableSize) + i * hash2(ikey)) % (*H)->tableSize;
    i++;
  }
  printf("inserting na talaga\n");
  DATA temp;
  temp.key = (char *)malloc(sizeof(char) * 20);
  strcpy(temp.key, key);
  temp.value = (char *)malloc(sizeof(char) * 100);
  strcpy(temp.value, val);

  (*H)->dataPair[array_index] = temp;
  (*H)->size++;
  // (*H)->dataPair[array_index].value = val;
  // (*H)->dataPair[array_index].key = key;
}

int nextPrime(int val)
{
  int temp, i = 2;

  for (temp = val; i < temp; i++)
  {
    if (temp % i == 0)
    {
      temp += 1;
      continue;
    }
  }

  return temp;
}

HASH_TABLE *rehash(HASH_TABLE *H, FILE *fp)
{
  int prime = nextPrime(H->tableSize * 2);
  HASH_TABLE *newH = (HASH_TABLE *)malloc(sizeof(HASH_TABLE));
  //printf("%d\n", (*H)->loadFactor);
  newH = createHashTable(prime, (*H).loadFactor);

  //putting already inputted data again

  DATA temp;
  for (int i = 0; i < H->tableSize; i++)
  {
    temp = H->dataPair[i];
    if (temp.key != NULL)
    {
      put(fp, &newH, H->dataPair[i].key, H->dataPair[i].value);
    }
  }

  // for(int i = 0; i<H->tableSize;i++){
  // 	if(H->dataPair[i].key != NULL){
  // 		put(fp, &newH, H->dataPair[i].key, H->dataPair[i].value);
  // 	}
  // }

  return newH;
}