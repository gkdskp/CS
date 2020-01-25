/* Write a menu-driven program to implement the following singly linked list operations
    a) Insertion at head
    b) Deletion at head
    c) Insertion at tail
    d) Deletion at tail
    e) Insertion at a position
    f) Deletion at a position
    g) Insertion before a data
    h) Deletion before a data */

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *link;
} *head = NULL;

struct Node *newNode()
{
    int data;
    struct Node *new = (struct Node *) malloc(sizeof(struct Node));
    scanf("%d", &data);
    new->data = data;
    new->link = NULL;
    return new;
}

int insertAt(int pos)
{
    struct Node *temp = head, *prev = NULL, *new = newNode();
    int i = 0;

    if(pos == 0)
    {
        new->link = head;
        head = new;
        return 0;
    }

    else if(pos == -1)
    {
        if(!head){
            head = new;
            return 0;
        }

        while(temp->link)
            temp = temp->link;
        
        temp->link = new;
        return 0;
    }

    else{
        while(temp && i != pos){
            prev = temp;
            temp = temp->link;
            ++i;
        }

        if(i == pos){
            prev->link = new;
            new->link = temp;
            return 0;
        }
        else
        {
            printf("Invalid position\n");
            return 1;
        }
        
    }
}

int insertBefore(int data)
{
    struct Node *temp = head, *prev = NULL, *new;
    if(!temp){
        return 1;
    }
    while(temp){
        if(temp->data == data)
        {
            new = newNode();
            if(prev) prev->link = new;
            else head = new;
            new->link = temp;
        }
        prev = temp;
        temp = temp->link;
    }
}

int deleteAt(int pos)
{
    int i = 0;
    struct Node *temp = head, *prev = NULL, *delnode;
    if(pos == 0 && head)
    {
        delnode = head;
        head = head->link;
        free(delnode);
        return 0;
    }
    else if(pos == -1)
    {
        while(temp->link){
            prev = temp;
            temp = temp->link;
        }

        if(prev) prev->link = NULL;
        free(temp);
        return 0;
    }

    else{
        while(temp && i != pos){
            prev = temp;
            temp = temp->link;
            ++i;
        }

        if(i == pos){
            delnode = temp;
            prev->link = temp->link;
            free(temp);
            return 0;
        }
        else
        {
            printf("Invalid position\n");
            return 1;
        } 
    }
}

int deleteBefore(int data)
{
    struct Node *temp = head, *prev = NULL, *next = head->link, *delnode;
    if(!temp){
        return 1;
    }
    while(next){
        if(next->data == data)
        {
            if(prev) prev->link = next;
            else head = next;
            delnode = temp;
        }
        prev = (delnode == temp) ? prev: temp;
        if(delnode == temp) free(delnode);
        temp = next;
        next = next->link;
    }
}

int displayNodes()
{
    struct Node *temp = head;
    printf("List: ");
    while(temp){
        printf("%d ", temp->data);
        temp = temp->link;
    }

    printf("\n");
}

int main()
{
    int quit = 0, option, choice = 1;
    while(!quit)
    {
        printf("Menu\n"
        "Insertion\n"
        "  1. Insert at HEAD\n"
        "  2. Insert at TAIL\n"
        "  3. Insert at position\n"
        "  4. Insert before data\n"
        "Deletion\n"
        "  5. Delete HEAD\n"
        "  6. Delete TAIL\n"
        "  7. Delete at position\n"
        "  8. Delete before data\n");
        choice = 1;
        scanf("%d", &option);

        switch(option){
            case 1:
                insertAt(0);
                break;

            case 2:
                insertAt(-1);
                break;

            case 3:
                scanf("%d", &choice);
                insertAt(choice);
                break;

            case 4:
                scanf("%d", &choice);
                insertBefore(choice);
                break;
            
            case 5:
                deleteAt(0);
                break;
            
            case 6:
                deleteAt(-1);
                break;
            
            case 7:
                scanf("%d", &choice);
                deleteAt(choice);
                break;
            
            case 8:
                scanf("%d", &choice);
                deleteBefore(choice);
                break;
        }

        displayNodes();
    }
}