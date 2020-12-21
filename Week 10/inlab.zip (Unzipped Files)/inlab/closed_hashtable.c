#include "closed_hashtable.h"
//insert other headers here
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//INSTRUCTIONS:
// You are allowed to add functions not declared in the h file
// hash1 and hash2 are already given, and you are not allowed to change them
// Implement all the functions declared in the h file
// The pseudocode for rehashing is already given to help you

//mod = hash table size
int hash1(int key, int mod)
{
	return key % mod;
}

int hash2(int key)
{
	return (7 - (key % 7));
}

int getMaxCapacity(HASH_TABLE *h)
{
	int maxCapacity = (int)ceil(h->tableSize * h->loadFactor);
	return maxCapacity;
}

int isFull(HASH_TABLE *h)
{
	if (h->size >= getMaxCapacity(h))
		return 1;
	else
		return 0;
}

// used for hashing
int sumOfChars(char *key)
{
	int i = 0, sum = 0;
	for (i; i < strlen(key); i++)
	{
		sum += key[i];
	}
	return sum;
}

void printTable(FILE *fp, HASH_TABLE *H)
{
	printf("Hash Table: \n");
	if (H->size == 0)
	{
		fprintf(fp, "*empty");
		return;
	}
	for (int i = 0; i < H->tableSize; i++)
	{
		char *tempVal = (char *)malloc(sizeof(char) * 200);
		if (H->dataPair[i].key == NULL)
			strcpy(tempVal, "*empty*");
		else
			strcpy(tempVal, H->dataPair[i].value);
		fprintf(fp, "Cell#%d: %s\n", i, tempVal);
	}
}

//create hashTable given tableSize and loadFactor
HASH_TABLE *createHashTable(int tableSize, float loadFactor)
{
	HASH_TABLE *h = (HASH_TABLE *)malloc(sizeof(HASH_TABLE));
	h->size = 0;
	h->tableSize = tableSize;
	h->loadFactor = loadFactor;
	h->dataPair = (DATA *)malloc(sizeof(DATA) * tableSize);
	for (int i = 0; i < tableSize; i++)
	{
		h->dataPair[i].key = NULL;
		h->dataPair[i].value = NULL;
	}
	printf("Successfully created hash table!\n");
	return h;
}

// a utility function that you may use when rehashing
int nextPrime(int val)
{
	int temp, i = 2;
	for (temp = val; i < temp; i++)
	{
		if (temp % i == 0)
		{
			temp += 1;
		}
	}
	return temp;
}

//return 1 for empty, 0 for not
int isEmpty(HASH_TABLE *h)
{
	// first implementation, not recommened since this yields to O(n)
	// for (int i = 0; i < h->tableSize; i++)
	// {
	// 	if (h->dataPair[i].key != NULL)
	// 		return 0;
	// }
	// return 1;

	// this however yields to O(1)
	if (h->size == 0)
		return 1;
	return 0;
}

//given data, insert data on hash table
//perform closed hashing, using double hashing as collision resolution strategy

//find key return index
int find(HASH_TABLE *H, char *key)
{
	DATA temp;
	for (int i = 0; i < H->tableSize; i++)
	{
		if (H->dataPair[i].key != NULL)
		{
			temp = H->dataPair[i];
			if (strcmp(temp.key, key) == 0)
			{
				printf("Key %s found!\n", key);
				return i;
			}
		}
	}
	printf("key not found :(\n");
	return -1;
}

//delete all contents of the hash table
//note: this doesn't destroy the hash table
void deleteAll(HASH_TABLE *H)
{
	printf("Deleting all pairs\n");
	DATA temp;
	temp.key = NULL;
	temp.value = NULL;
	for (int i = 0; i < H->tableSize; i++)
	{
		H->dataPair[i] = temp;
	}
	H->size = 0;
}

//destroy the hash table
void erase(HASH_TABLE *H)
{
	printf("Destorying the entire hash table!!!\n");
	deleteAll(H);
	free(H->dataPair);
	free(H);
}

HASH_TABLE *rehash(HASH_TABLE *H, FILE *fp)
{

	// creates a new hash table
	int newSize = nextPrime(H->tableSize * 2);

	fprintf(fp, "New hash tableSize: %d. Printing Table before Rehashing...\n", newSize);
	printTable(fp, H);
	HASH_TABLE *new_table = (HASH_TABLE *)malloc(sizeof(HASH_TABLE));
	new_table = createHashTable(newSize, H->loadFactor);

	// inserting previous data
	DATA temp;
	for (int i = 0; i < H->tableSize; i++)
	{
		temp = H->dataPair[i];
		if (temp.key != NULL)
		{
			put(fp, &new_table, temp.key, temp.value);
		}
	}
	return new_table;
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
	// first let's check if the entry already exists in the table
	int index_key = sumOfChars(key);
	int index = hash1(index_key, (*H)->tableSize);
	int i = 1;
	printf("Checking first if data pair %s-%s already exist\n", key, val);
	for (int j = 0; j < (*H)->tableSize; j++)
	{
		// checks if the cell is not empty
		if ((*H)->dataPair[j].key != NULL)
		{
			// compares the values if the keys are equal
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
		fprintf(fp, "**Alert! Table capacity is reached. Performing rehashing...\n\n");
		HASH_TABLE *new = rehash(*H, fp);
		erase(*H);
		*H = new;
		fprintf(fp, "Rehashing complete\n\n");
		//determine the size of the new hash table
		//new table size = smallest prime number given twice the size of the currentsize
		//ex: currentsize is 7, next table size is 17
		//create a new hash table using the new table size and the same loadFactor
		//rehash all the keys stored in the old hash table to the new hash table
		//assign H to the new hash table and cleanly delete (or destroy) the old hash table
	}

	//insert key to hash table
	// introduce double hashing

	while ((*H)->dataPair[index].key != NULL)
	{
		index = (hash1(index_key, (*H)->tableSize) + i * hash2(index_key)) % (*H)->tableSize;
		i++;
	}
	// printf("Inserting at index %d\n", index);
	DATA temp;
	// max size of key and value
	temp.key = (char *)malloc(sizeof(char) * 20);
	temp.value = (char *)malloc(sizeof(char) * 200);

	// copy all data to temp variable
	strcpy(temp.key, key);
	strcpy(temp.value, val);

	(*H)->dataPair[index] = temp;
	(*H)->size++;

	printf("Successfully inserted %s-%s!\n", key, val);
}