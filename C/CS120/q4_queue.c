/* A queue is a data structure which follows the FIFO principle. The max size
of the queue will be fixed and will be provided at start and let it be N and
if an element is added to an already full queue it results in an overflow and
the element won’t be added. Similarly an element cannot be removed from an
empty queue.
Circular Queue is a linear data structure in which the operations are per-
formed based on FIFO (First In First Out) principle and the last position is
connected back to the first position to make a circle.
Just like any queues you have the following operations :
Enqueue : Insert an element to the end of the queue Dequeue : Remove an
element from the front of the queue Print : Print all elements of the queue
If either enqueue or dequeue fails -1 is output
The program takes in one of 4 possible inputs on a loop :
    1) Enqueue an element
    2) Dequeue an element
    3) Print all elements
    4) Exit the program */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
}*temp=NULL, *last=NULL, *list=NULL, *current;

int main(){
    int n, i = 0, opt, value;
    scanf("%d",&n);
    while(1){
        scanf(" %d",&opt);
        if(opt == 1){
            scanf("%d", &value);
            if(i >= n){
                printf("%d\n", -1);
                continue;
            }
            else{
                i++;
                temp=(struct node *) malloc(sizeof(struct node));
                temp->data = value;
                temp->link = NULL;
                if(list == NULL){
                    list = temp;
                }
                else{
                    last->link = temp;
                }
                last = temp;
                printf("%d\n",0);
            }

        }
        if(opt == 2){
            if(list == NULL || i <= 0){
                printf("%d\n",-1);
            }
            else{
                list = list->link;
                i--;
                printf("%d\n", 0);
            }

        }
        if(opt == 3){
            current = list;
            if(current == NULL){
                printf("-1\n");
            }
            else{
                while(current != NULL){
                    printf("%d ", current->data);
                    current = current->link;
                }
            printf("\n");
            }
        }
        if(opt==4)
            break;
    }
    return 0;
}
