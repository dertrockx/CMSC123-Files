#ifndef _OPEN_HASHTABLE_H_
#define _OPEN_HASHTABLE_H_
#include <stdio.h>

//Reminder: use this file as is

//NOTE: data = <key, value>
//node structure, doubly linked-list
typedef struct data_tag
{
  struct data_tag *next;
  struct data_tag *prev;
  char *value;
  char *key;
} DATA;

//hash table structure
//separate chaining, list is a vector of pointers to DATA nodes
typedef struct hash_tag
{
  int size;      //total contents of the hash table
  int tableSize; //size of the vector
  DATA **list;
} HASH_TABLE;

//create instance of hashtable given tableSize
HASH_TABLE *createHashTable(int tableSize);
//checks if hash table is empty
//returns 1 if true, 0 if false
int isEmpty(HASH_TABLE *h);
//checks if hash table is full
//returns 1 if true, 0 if false
int isFull(HASH_TABLE *h);
//checks if the data is already in the table
//if not, add node on the linked list corresponding to hashed index
void put(FILE *fp, HASH_TABLE *H, char *key, char *val);
//return index of the hash table where node with key = key is found
int find(HASH_TABLE *H, char *key);
//remove node with key = key from the hash table
void erase(FILE *fp, HASH_TABLE *H, char *key);
//remove all nodes from the hash table
void deleteAll(HASH_TABLE *H);
//print contents of the hash table
//see result.txt for reference
void printTable(FILE *fp, HASH_TABLE *H);

#endif
