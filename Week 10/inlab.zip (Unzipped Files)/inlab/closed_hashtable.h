#ifndef _CLOSED_HASHTABLE_H_
#define _CLOSED_HASHTABLE_H_
#include <stdio.h>

//REMINDER: you are NOT allowed to change this file
//NOTE: data = <key,value>
typedef struct data_tag
{
  char *key;
  char *value;
} DATA;

typedef struct hash_tag
{
  int size;
  int tableSize;
  float loadFactor;
  DATA *dataPair;
} HASH_TABLE;

//insert your solutions here
//print contents of hash table
//refer to sample output for formatting
void printTable(FILE *fp, HASH_TABLE *H);

//create hashTable given tableSize and loadFactor
HASH_TABLE *createHashTable(int tableSize, float loadFactor);

//return 1 for empty, 0 for not
int isEmpty(HASH_TABLE *h);

//full means table size has reached the capacity
//note: capacity = ceiling(tableSize*loadFactor)
int isFull(HASH_TABLE *h);

//given data, insert data on hash table
//perform closed hashing, using double hashing as collision resolution strategy
void put(FILE *fp, HASH_TABLE **H, char *key, char *val);

//find key return index
int find(HASH_TABLE *H, char *key);

//delete all contents of the hash table
//note: this doesn't destroy the hash table
void deleteAll(HASH_TABLE *H);

//destroy the hash table
void erase(HASH_TABLE *H);

#endif
