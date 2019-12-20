/* Write a menu driven program to implement stack operations using
array
	a) Push
	b) Pop
	c) Display */

#include <stdio.h>
#define MAX 5

int HEAD = -1;

int push(int stack[])
{
	int val;
	if(HEAD == MAX)
	{
		printf("Stack Overflow\n");
	}
	else
	{
		HEAD++;
		scanf("%d", &val);
		stack[HEAD] = val;
	}
}

int pop(int stack[])
{
	if(HEAD == -1)
	{
		printf("Stack Underflow\n");
	}
	else
	{
		printf("%d\n",stack[HEAD]);
		HEAD--;
	}
}

int display(int stack[])
{
	int i = HEAD;
	while(i > -1)
	{
		printf("%d\t", stack[i]);
		i--;
	}
	printf("\n");
}

int main()
{
	int stack[MAX], ch, quit = 0;

	while(!quit)
	{
		printf(
		"\n\n"
		"------------\n"
		"MENU\n"
		"-------------\n"
		"1. Push\n"
		"2. Pop\n"
		"3. Display\n");

		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				push(stack);
				break;

			case 2:
				pop(stack);
				break;

			case 3:
				display(stack);
				break;

			case 4:
				quit = 1;
				break;
		}
	}
}
