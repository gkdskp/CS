/* PRACTICE QUESTION
You're given the pointer to the head node of a sorted linked list, where the data
 in the nodes is in ascending order. Delete as few nodes as possible so that the 
 list does not contain any value more than once. The given head pointer may be null
indicating that the list is empty.

Input Format

You have to complete the SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) 
method which takes one argument - the head of the sorted linked list. You should NOT 
read any input from stdin/console.

The input is handled by the code in the editor and the format is as follows:
The first line contains an integer , denoting the number of test cases. The format for each test case is as follows:
The first line contains an integer , denoting the number of elements in the linked list.
The next  lines contain an integer each, denoting the elements of the linked list.

Output Format

Delete as few nodes as possible to ensure that no two nodes have the same data. 
Adjust the next pointers to ensure that the remaining nodes form a single sorted 
linked list. Then return the head of the sorted updated linked list. Do NOT print
anything to stdout/console.

The output is handled by the code in the editor and the format is as follows: 
For each test case, print in a new line, the data of the linked list after removing 
the duplicates separated by space. 

OUTPUT in OUTPUT_PATH file defined below
SOURCE: https://www.hackerrank.com/challenges/delete-duplicate-value-nodes-from-a-sorted-linked-list/problem
*/

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OUTPUT_PATH "out.txt"

char* readline();

typedef struct SinglyLinkedListNode SinglyLinkedListNode;
typedef struct SinglyLinkedList SinglyLinkedList;

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

struct SinglyLinkedList {
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;
};

SinglyLinkedListNode* create_singly_linked_list_node(int node_data) {
    SinglyLinkedListNode* node = malloc(sizeof(SinglyLinkedListNode));

    node->data = node_data;
    node->next = NULL;

    return node;
}

void insert_node_into_singly_linked_list(SinglyLinkedList** singly_linked_list, int node_data) {
    SinglyLinkedListNode* node = create_singly_linked_list_node(node_data);

    if (!(*singly_linked_list)->head) {
        (*singly_linked_list)->head = node;
    } else {
        (*singly_linked_list)->tail->next = node;
    }

    (*singly_linked_list)->tail = node;
}

void print_singly_linked_list(SinglyLinkedListNode* node, char* sep, FILE* fptr) {
    while (node) {
        fprintf(fptr, "%d", node->data);

        node = node->next;

        if (node) {
            fprintf(fptr, "%s", sep);
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
    SinglyLinkedListNode *iter = head, *prev = head;
    if(iter == NULL)
        return NULL;
    else
    {
        while(iter != NULL)
        {
            if(prev->data == iter->data && prev != iter)
            {
                prev->next = iter->next;
                iter = iter->next;
            }
            else if(iter->next != NULL && iter->data == iter->next->data)
            {
                prev->next = iter->next;
                iter = iter->next;
            }
            else
            {
                prev = iter;
                iter = iter->next;
            }
        }
        return head;
    }
}

int main()
{
    FILE* fptr = fopen(OUTPUT_PATH, "w");

    char* t_endptr;
    char* t_str = readline();
    int t = strtol(t_str, &t_endptr, 10);

    if (t_endptr == t_str || *t_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int t_itr = 0; t_itr < t; t_itr++) {
        SinglyLinkedList* llist = malloc(sizeof(SinglyLinkedList));
        llist->head = NULL;
        llist->tail = NULL;

        char* llist_count_endptr;
        char* llist_count_str = readline();
        int llist_count = strtol(llist_count_str, &llist_count_endptr, 10);

        if (llist_count_endptr == llist_count_str || *llist_count_endptr != '\0') { exit(EXIT_FAILURE); }

        for (int i = 0; i < llist_count; i++) {
            char* llist_item_endptr;
            char* llist_item_str = readline();
            int llist_item = strtol(llist_item_str, &llist_item_endptr, 10);

            if (llist_item_endptr == llist_item_str || *llist_item_endptr != '\0') { exit(EXIT_FAILURE); }

            insert_node_into_singly_linked_list(&llist, llist_item);
        }

        SinglyLinkedListNode* llist1 = removeDuplicates(llist->head);

        char *sep = " ";

        print_singly_linked_list(llist1, sep, fptr);
        fprintf(fptr, "\n");

        free_singly_linked_list(llist1);
    }

    fclose(fptr);

    printf("Result printed in " 
    OUTPUT_PATH);
    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}
