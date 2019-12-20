/* Write a program to implement hash table using various mapping functions,
 various collision and overflow resolving schemes */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
typedef struct node {
	int number;
	struct node *next;
}Node;

Node * ht[SIZE];

int hashCode(int n) {
	return n % SIZE;
}

void insertHash(int n) {
	Node *newNode;
	int hc;
	hc = hashCode(n);
	newNode = (Node *) malloc(sizeof(Node));
	newNode->number = n;
	if(ht[hc] == NULL) {
		ht[hc] = newNode;
		newNode->next = NULL;
	} else {
		newNode->next = ht[hc];
		ht[hc] = newNode;
	}
}

void printChain(Node *ptr) {
	if(ptr == NULL)
		return ;
	printf("%d ", ptr->number);
	printChain(ptr->next);
}

void displayHash() {
	int i;
	for(i = 0; i < SIZE; i++) {
		printf("Key %d: ", i);
		if(ht[i] == NULL) {
			printf("Empty\n");
			continue;
		}
		printChain(ht[i]);
		printf("\n");
	}
}

void hashFind(int n) {
	int hc, count = 0;
	Node * temp;
	hc = hashCode(n);
	temp = hc[ht];
	while(temp != NULL) {
		if(temp->number == n) {
			break;
		}
		count++;
		temp = temp->next;
	}
	if(temp == NULL) {
		printf("Element not found!\n");
	} else {
		printf("Found at %dth traversal\n", count);
	}

}

void main() {
	int i, n, option;
	for(i = 0; i < SIZE; i++) {
		ht[i] = NULL;
	}
	printf("Hash Table: \n"
	"1. Insert\n"
	"2. Display\n"
	"3. Search\n"
	"Choose an option:\n");
	while(1) {
		scanf("%d", &option);
		switch(option) {
			case 1:
				scanf("%d", &n);
				insertHash(n);
				break;
			case 2:
				displayHash();
				break;
			case 3:
				scanf("%d", &n);
				hashFind(n);
				break;
			default:
				printf("Invalid Option!\n");
		}
		printf("\nChoose an option: ");
	}
}


