/* Write a menu driven program to implement stack operations using linked list
    a) Push b) Pop c) Display */

#include <stdio.h>
#include <stdlib.h>

struct Node
{   int data;
    struct Node *link;
}*header, *newnode, *ptr;

void Push(int item)
{   
    newnode = (struct Node *) malloc(sizeof(struct Node));

    if(header == NULL)
    {   
        header = newnode;
        newnode->data = item;
        newnode->link = NULL;
    }

    else
    {   ptr = header;
        while(ptr->link != NULL)
            ptr = ptr->link;
        ptr->link = newnode;
        newnode->data = item;
        newnode->link = NULL;
    }
}

void Pop()
{       struct Node *ptr1;

        if(header == NULL)
            printf("Stack underflow \n");

        else if(header->link == NULL)
        {   ptr = header;
            printf("%d \n", (ptr->data));
            free(ptr);
            header = NULL;
        }

        else
        {       
            ptr = header;
            while(ptr->link != NULL)
            {   
                ptr1 = ptr;
                ptr = ptr->link;
            }
            ptr1->link = NULL;
            printf("%d \n", (ptr->data));
            free(ptr);
        }
}

void Display()
{   
    if(header == NULL)
    printf("Stack empty\n");
    else
    {   
        ptr = header;
        while(ptr != NULL)
        {   
            printf("%d ", (ptr->data));
            ptr = ptr->link;
        }
	printf("\n");
    }
}

void main()
{   int c, item;
    char choice[2];
    while('1')
    {   
        printf("1.Push \n2.Pop \n3.Display\n");
        scanf("%d", &c);

        if(c == 1)
        {
            scanf("%d", &item);
            Push(item);
        }

        else if(c == 2)
            Pop();
        else if(c == 3)
            Display();
        else
            printf("Invalid Option\n");

        printf("\n");
    }
}

