/* Write a menu driven program to create a linked list in
	1. LIFO order
	2. FIFO order */

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int value;
	struct node *next;
} node;

typedef struct{
	node *top;
	int n;
} stack;

typedef struct{
	node *head, *tail;
	int n;
} queue;

void stack_fun(){
	stack s;
	int ch;
	node *n;
	s.top = NULL;
	s.n = 0;
	puts("Stack");
        puts("1\t Push");
        puts("2\t Pop");
       	puts("3\t Top");

	do {
		printf("Enter your choice: ");
		scanf(" %d", &ch);

		switch (ch){
		case 1:
			n = malloc(sizeof(node));
			printf("Enter value: ");
			scanf(" %d", &n->value);
			n->next = s.top;
			s.top = n;
			++s.n;
			break;

		case 2:
			if (s.n == 0) {
				printf("Stack Empty!\n");
			} else {
				printf("Popped %d\n", s.top->value);
				n = s.top->next;
				free(s.top);
				s.top = n;
				--s.n;
			}
			break;

		case 3:
			if (s.n != 0)
				printf("Top: %d\n", s.top->value);
			else
				printf("Stack Empty!\n");
			break;

		default:
			printf("EXIT\n");
			while (s.top != NULL){
				n = s.top->next;
				free(s.top);
				s.top = n;
			}
			return;
		}
	} while (1);
}

void queue_fun()
{
	queue q;
	int ch;
	node *n;
	q.head = q.tail = NULL;
	q.n = 0;
	puts("Queue");
        puts("1.\tInsert");
        puts("2.\tRemove");
       	puts("3.\tHead");

	do {
		printf("Enter your choice: ");
		scanf(" %d", &ch);

		switch (ch){
		case 1:
			n = malloc(sizeof(node));
			printf("Enter value: ");
			scanf(" %d", &n->value);
			n->next = NULL;
			if (q.n == 0) {
				q.head = q.tail = n;
			}else{
				q.tail->next = n;
				q.tail = n;
			}
			++q.n;
			break;

		case 2:
			if (q.n == 0){
				printf("Queue Empty!\n");
			}else{
				printf("Remove %d\n", q.head->value);
				n = q.head->next;
				free(q.head);
				q.head = n;
				--q.n;
				if (q.n == 0)
					q.head = q.tail = NULL;
			}
			break;

		case 3:
			if (q.n != 0)
				printf("Head: %d\n", q.head->value);
			else
				printf("Queue Empty!\n");
			break;
		default:
			printf("EXIT\n");
			while (q.head != NULL) {
				n = q.head->next;
				free(q.head);
				q.head = n;
			}
			return;
		}
	} while (1);
}


int main() {
	int ch;

	puts("Menu ");
	puts("1. \t LIFO order (Stack)");
	puts("2. \t FIFO order (Queue)");


	printf("Enter your choice: ");
	scanf(" %d", &ch);

	switch (ch) {
	case 1:
		stack_fun();
		break;

	case 2:
		queue_fun();
		break;

	default:
		puts("Exit");
		return 0;
	}
}


