/* Write a menu driven program to implement input restricted deque and output restricted
deque using array */

#include <stdio.h>
#include <stdlib.h>

int head = -1, rear = -1;
#define n 5

void push(int deque[])
{
	int val;
	scanf("%d", &val);

	if(head == 0)
	{
		printf("Element cannot be inserted\n");
		return;
	}
	else if(head == -1)
	{
                head = head+1;
		if(rear == -1) rear = 0; 
                deque[head] = val;
        }
		else
		{
		head = head-1;
		deque[head] = val;
	}
}

void inject(int deque[])
{
	int val;
	scanf("%d", &val);
	if(rear == n)
		printf("Deque is full\n");
	else
	{
		rear++;
		deque[rear] = val;
		if(head == -1)
			head = 0;
	}
}

void eject(int deque[])
{
	int temp;
	if(head > rear || head == -1)
		printf("Deque is empty\n");
	else
	{
		temp = deque[rear];
		rear--;
		if(rear < head)
			rear = head = -1;
		printf("%d", temp);
	}
}

void pop(int deque[])
{
	int temp;
	if(head > rear || head == -1)
		printf("Deque is empty\n");
	else
	{
		temp = deque[head];
		head++;
		if(head > rear)
			head = rear = -1;
		printf("%d", temp);
	}
}

void display(int deque[])
{
	int i;
	for(i = head; i <= rear; i++)
		printf("%d\t", deque[i]);
	printf("\n");
}

void main()
{
	int ch1, ch2, quit = 0, deque[8];
	printf("Enter MAX\n");
	//scanf("%d", &n);
	//deque = (int *)malloc(n * sizeof(int));
	printf("1. Input restricted DEQUE\n"
	"2. Output restricted DEQUE\n");
	scanf("%d", &ch1);

	if(ch1 == 1)
	{
		while(!quit)
		{
			printf("\n\nMenu\n"
			"1. Insert\n"
			"2. Delete from front\n"
			"3. Delete from rear\n"
			"4. Display\n");
			scanf("%d", &ch2);
			switch(ch2)
			{
				case 1:
					inject(deque);
					break;

				case 2:
					pop(deque);
					break;

				case 3:
					eject(deque);
					break;

				case 4:
					display(deque);
					break;
				default:
					quit = 1;
			}
		}
	}else
	{
		 while(!quit)
		 {
                        printf("\n\nMenu\n"
                        "1. Insert from front\n"
                        "2. Insert from rear\n"
                        "3. Delete\n"
			"4. Display\n");
                        scanf("%d", &ch2);
                        switch(ch2)
						{
                                case 1:
                                        push(deque);
                                        break;

                                case 2:
                                        inject(deque);
                                        break;

                                case 3:
                                        pop(deque);
                                        break;

				case 4:
					display(deque);
					break;

                                default:
                                        quit = 1;
                        }
                }


	}
}
