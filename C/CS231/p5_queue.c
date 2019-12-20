/* Write a menu driven program to implement queue operations using
array
	a) Insert
	b) Delete
	c) Display */

#include <stdio.h>
#define MAX 5

int HEAD = -1, REAR = -1;

int insert(int queue[])
{
	int val;
	if(REAR == MAX)
		printf("Queue Full\n");
	else
	{
		scanf("%d", &val);
		if(HEAD == -1 && REAR == -1)
                        HEAD = REAR = 0;
                else
                        REAR++;

		queue[REAR] = val;
	}
}

int delete(int queue[])
{
	if(HEAD == REAR)
		printf("Queue Empty\n");
	else
	{
		printf("%d\n", queue[HEAD]);
		HEAD++;
	}
}

int display(int queue[])
{
	for(int i = HEAD; i <= REAR; i++)
		printf("%d\t", queue[i]);
	printf("\n");
}

int main()
{
	int quit = 0, ch, queue[MAX];
	while(!quit)
	{
		printf("\n-----------------\n"
		"1. Insert\n"
		"2. Delete\n"
		"3. Display\n"
		"4. Quit\n"
		);
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				insert(queue);
				break;
			case 2:
				delete(queue);
				break;
			case 3:
				display(queue);
				break;

			case 4:
				quit = 1;
		}
	}
}
