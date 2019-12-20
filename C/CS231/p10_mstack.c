/* Write a program to implement multiple stacks using array */

#include <stdio.h>

#define MAX 5
int Stack[MAX], head1 = -1, head2 = -1;

int push(int n)
{
	if(n == 1)
	{
		if(head1 == head2-1)
		{
			printf("Stack full\n");
		}
		else
		{
			head1++;
			scanf("%d", &Stack[head1]);
		}
	}
	else
	{
		if(head2 - 1 == head1)
			printf("Stack full\n");
		else
			head2 = (head2 == -1)? MAX-1: head2 - 1;
			scanf("%d",  &Stack[head2]);
	}
}

int pop(int n)
{
	if(n == 1)
	{
		if(head1 == -1)
			printf("Stack empty\n");
		else
		{
			printf("%d\n", Stack[head1]);
			head1--;
		}
	}
	else
	{
		if(head2 == -1)
			printf("Stack empty\n");
		else
		{
			printf("%d\n", Stack[head2]);
			head2 = (head2 == MAX-1)? -1: head2 + 1;
		}
	}
}

int display(){
	int i = 0;
	if(head1 == -1) printf("Stack1 is empty\n");
	else
	{
		printf("Stack1:\t");
		for(i = head1; i >= 0; i--)
			printf("%d\t", Stack[i]);
		printf("\n");
	}
	if(head2 == -1) printf("Stack2 is empty\n");
	else
	{	printf("Stack2:\t");
		for(i = head2; i <= MAX-1; i++)
			printf("%d\t", Stack[i]);
		printf("\n");
	}
}

int main()
{
	int ch, n, quit = 0;
	while(!quit)
	{
		printf("\n\n1. Push\n2.Pop\n3.Display\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				//printf("Enter Stackno:\n");
				scanf("%d", &n);
				push(n);
				break;
			case 2:
                //printf("Enter Stackno:\n");
                scanf("%d", &n);
                pop(n);
                break;
			case 3:
				display();
				break;
			default:
				quit = 1;

		}
	}
}
