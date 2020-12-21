#include "open_hashtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//print contents of the hash table
void printTable(FILE *fp, HASH_TABLE *H)
{
	DATA *temp;
	int index;

	if (isEmpty(H))
	{
		fprintf(fp, "*empty\n");
		return;
	}

	for (index = 0; index < H->tableSize; index++)
	{
		temp = H->list[index];

		fprintf(fp, "Cell#%d: ", index);
		if (temp)
		{
			do
			{
				fprintf(fp, "%s -> ", temp->value);
				temp = temp->next;
			} while (temp);
			fprintf(fp, "NULL");
		}
		else
			fprintf(fp, "*empty*");
		fprintf(fp, "\n");
	}
}

//return instance of a hash table given table size
HASH_TABLE *createHashTable(int tableSize)
{
	HASH_TABLE *h;
	int i;

	h = (HASH_TABLE *)malloc(sizeof(HASH_TABLE));
	h->tableSize = tableSize;
	h->size = 0;
	h->list = (DATA **)malloc(sizeof(DATA *) * tableSize);

	for (i = 0; i < tableSize; i++)
	{
		// since a pointer is just an array
		// we access each succeeding pointer using an array index
		h->list[i] = NULL;
	}

	return h;
}

//return 1 for empty, 0 for not
int isEmpty(HASH_TABLE *h)
{
	if (h->size == 0)
		return 1;
	return 0;
}
//return 1 for full, 0 for not
int isFull(HASH_TABLE *h)
{
	if (h->size == h->tableSize)
		return 1;
	return 0;
}

//given character key, return hashed index
int hash(char *key, int mod)
{
	int i = 0;
	int sum = 0;

	for (i = 0; i < strlen(key); i++)
	{
		sum += key[i];
	}

	return sum % mod;
}

//check if the given key is already found in the hashed index
// @returns DATA node
DATA *checkIndex(HASH_TABLE *H, char *key, int array_index)
{
	int i;
	DATA *temp = NULL;

	if (H->list[array_index] != NULL)
	{
		//separate chaining here!
		temp = H->list[array_index];
		while (temp != NULL)
		{
			if (strcmp(temp->key, key) == 0)
			{ //key found
				break;
			}
			temp = temp->next;
		}
	}
	return temp;
}

//hash the index corresponding given key
//check if node is found in the hashed index
//if not, insert node on the linked list attached to the hashed index
//if found, print error
void put(FILE *fp, HASH_TABLE *H, char *key, char *val)
{
	int array_index = hash(key, H->tableSize);
	DATA *temp;

	if (!checkIndex(H, key, array_index))
	{
		temp = (DATA *)malloc(sizeof(DATA));
		temp->next = temp->prev = NULL;
		temp->key = (char *)malloc(sizeof(char) * 20);
		strcpy(temp->key, key);
		temp->value = (char *)malloc(sizeof(char) * 100);
		strcpy(temp->value, val);

		//insertion at head;
		if (H->list[array_index] != NULL)
			H->list[array_index]->prev = temp;
		temp->next = H->list[array_index];
		H->list[array_index] = temp;
		H->size++;
	}
	else
		fprintf(fp, "Insertion Error: {key=%s, data=%s} is already in the table\n", key, val);
}

//find key return index
int find(HASH_TABLE *H, char *key)
{
	int array_index = hash(key, H->tableSize);
	if (checkIndex(H, key, array_index))
		return array_index;
	return -1;
}

//hash key
//given hashed index, remove node corresponding to key from the linked list attached to hashed index
void erase(FILE *fp, HASH_TABLE *H, char *key)
{
	int array_index = find(H, key);
	DATA *dataNode = checkIndex(H, key, array_index);
	if (dataNode)
	{
		if (dataNode == H->list[array_index])
		{
			if (dataNode->next)
				dataNode->next->prev = H->list[array_index];
			H->list[array_index] = dataNode->next;
		}
		else
		{
			if (dataNode->next)
				dataNode->next->prev = dataNode->prev;
			dataNode->prev->next = dataNode->next;
		}
		fprintf(fp, "Key:%s succesfully 'removed' from the table.\n", key);
		H->size--;
	}
	else
	{
		fprintf(fp, "Key:%s is not found in the table. \n", key);
	}
}

//remove all nodes from the hash table
void deleteAll(HASH_TABLE *H)
{
	int index;
	DATA *temp;

	for (index = 0; index < H->tableSize; index++)
	{
		while (H->list[index])
		{
			temp = H->list[index];
			H->list[index] = H->list[index]->next;
			free(temp);
		}
	}
	H->size = 0;
}
