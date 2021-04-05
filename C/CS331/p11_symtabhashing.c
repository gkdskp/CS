/* Implement the symbol table with suitable hashing */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20

struct SymTabItem
{
	char label[10];
	char datatype[10];
	int address;

	struct SymTabItem * next;
};

struct SymTabItem * hash_map[SIZE];

struct SymTabItem * create_item(char label[], char datatype[], int address)
{
	struct SymTabItem * item;
	item = malloc(sizeof(struct SymTabItem));
	item->address = address;
	strcpy(item->datatype, datatype);
	strcpy(item->label, label);
	item->next = NULL;

	return item;
}

// Hash function presented in K&R version 2
unsigned calculate_hash(char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;

    return hashval % SIZE;
}

void insert(char label[], char datatype[], int address)
{
	unsigned hash = calculate_hash(label);
	struct SymTabItem * curr_item;
	struct SymTabItem * iter = hash_map[hash];

	if(iter == NULL)
	{
		hash_map[hash] = create_item(label, datatype, address);
		printf("Insertion successful\n");
		return;
	}

	while(iter->next != NULL)
	{
		if(strcmp(iter->label, label) == 0)
		{
			printf("Duplicate symbol\n");
			return;
		}

		iter = iter->next;
	}

	iter->next = create_item(label, datatype, address);
}

void delete(char label[])
{
	unsigned hash = calculate_hash(label);
	struct SymTabItem * prev, * iter;
	prev = iter = hash_map[hash];

	while(iter != NULL)
	{
		if(strcmp(iter->label, label) == 0)
		{
			// If the first element is the label
			if(prev == iter) hash_map[hash] = NULL;
			else prev->next = iter->next;

			printf("Deleted succesfully\n");
			free(iter);
			return;	
		}

		prev = iter;
		iter = iter->next;
	}

	printf("No such label present\n");
	return;
}

void display()
{
	struct SymTabItem * iter;

	for(int i = 0; i < SIZE; i++)
	{
		iter = hash_map[i];
		printf("%d: ", i);
		while(iter != NULL)
		{
			printf(
				"[%s %s %d]",
				iter->label,
				iter->datatype,
				iter->address
			);

			iter = iter->next;
		}
		printf("\n");
	}
}

void search(char label[])
{
	unsigned hash = calculate_hash(label);
	struct SymTabItem * iter = hash_map[hash];

	while(iter != NULL)
	{
		if(strcmp(iter->label, label) == 0)
		{
			printf(
				"Item found\n[%s %s %d]\n",
				iter->label,
				iter->datatype,
				iter->address
			);
			return;
		}

		iter = iter->next;
	}

	printf("Item not found in symtab\n");
}

void modify(char label[], int address)
{
	unsigned hash = calculate_hash(label);
	struct SymTabItem * iter = hash_map[hash];

	while(iter != NULL)
	{
		if(strcmp(iter->label, label) == 0)
		{
			iter->address = address;
			printf("Address modified successfully\n");
			return;
		}

		iter = iter->next;
	}

	printf("Item not found in symtab\n");
}

int main()
{
	int choice = 0, address;
	char label[20], datatype[20];

	for(int i = 0; i < SIZE; i++) hash_map[i] = NULL;

	printf(
		"Enter choice: \n"
		"1. Insertion\n\tformat: 1 label dtype addr\n"
		"2. Deletion\n\tformat: 2 label\n"
		"3. Display\n\tformat: 3\n"
		"4. Search\n\tformat: 4 label\n"
		"5.Modify\n\tformat: 5 label newaddr"
		"6. Quit\n"
	);
	
	do 
	{
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			scanf(" %s %s %d", label, datatype, &address);
			insert(label, datatype, address);
			break;
		
		case 2:
			scanf(" %s", label);
			delete(label);
			break;

		case 3:
			display();
			break;

		case 4:
			scanf(" %s", label);
			search(label);
			break;
		
		case 5:
			scanf(" %s %d", label, &address);
			modify(label, address);
			break;
		
		case 6:
			break;

		default:
			printf("Unknown choice\n");
		}
	} while(choice != 6);
}
