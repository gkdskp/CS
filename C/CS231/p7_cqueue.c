/* Write a menu driven program to implement circular queue using array */

#include <stdio.h>
#include <stdlib.h>

#define MAX 6
int cqueue[MAX], head = -1, rear = -1;

int insert()
{
    if((rear + 1)% MAX == head)
    {
        printf("Queue full\n");
        scanf("%*d");
        return -1;
    }
    else
    {
        rear = (rear + 1)% MAX;
        if(head == -1) head = 0;
        scanf("%d", &cqueue[rear]);
    }
}

int delete()
{
    int temp;
    if(head == -1)
    {
        printf("Queue empty\n");
    }
    else
    {
        temp = cqueue[head];
        head = (head != rear)? (head + 1)% MAX: -1;
        if(head == -1) rear = -1;
        printf("%d\n", temp);
        return temp;
    }
}

int display()
{
    int i;
    for(i = head; i != rear; i = (i + 1)% MAX)
    {
        printf("%d\t", cqueue[i]);
    }
    printf("%d\n", cqueue[i]);
}

int main()
{
    int ch, quit = 0;
    while(!quit)
    {
        printf("1. Insert\n"
        "2. Delete\n"
        "3. Display\n"
        "4. Quit\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
            default:
                quit = 1;
        }
    }
}