#include "open_hashtable.h"
#include <stdlib.h>
#include <stdio.h>

//Note: use this file as is
int main()
{

	char command;
	char *key;
	char *data;
	int result;
	int i;

	int tsize;
	HASH_TABLE *H;

	FILE *fp = fopen("result.txt", "w");

	// get table size then maxsize
	scanf("%d\n", &tsize);
	H = createHashTable(tsize);
	//assume max key size is 20
	key = (char *)malloc(sizeof(char) * 20); //first hash function
	key[0] = '\0';
	// assume max data size is 100
	data = (char *)malloc(sizeof(char) * 100);
	data[0] = '\0';

	while (1)
	{
		scanf("%c ", &command);
		switch (command)
		{
		case '+':
			scanf(" k:%s d:%s\n", key, data);
			fprintf(fp, "Inserting data %s with key %s\n", data, key);
			put(fp, H, key, data);
			break;
		case '-':
			scanf(" k:%s\n", key);
			fprintf(fp, "Deleting data with key %s ... ", key);
			erase(fp, H, key);
			break;
		case '?':
			scanf(" k:%s\n", key);
			fprintf(fp, "Searching data with key: %s ... ", key);
			result = find(H, key);
			if (result == -1)
			{
				fprintf(fp, "Key: %s not found!\n", key);
			}
			else
			{
				fprintf(fp, "Key: %s found in index: %d\n", key, result);
			}
			break;
		case 'p':
			fprintf(fp, "\nHash Table: \n");
			printTable(fp, H);
			fprintf(fp, "\n");
			break;
		case 'E':
			fprintf(fp, "Hash table %s empty.\n", isEmpty(H) ? "is" : "is not");
			break;
		case 'F':
			fprintf(fp, "Hash table %s full.\n", isFull(H) ? "is" : "is not");
			break;
		case 'C':
			fprintf(fp, "Deleting all contents.\n");
			deleteAll(H);
			break;
		case 'Q':
			free(key);
			free(data);
			deleteAll(H);
			free(H->list);
			free(H);
			return 0;
		default:
			fprintf(fp, "Unknown command: %c\n", command);
			break;
		}
	}

	return 0;
}
