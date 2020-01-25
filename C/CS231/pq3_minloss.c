/* PRACTICE QUESTION
Given array price[n] where each element gives projected price for
a house for the next n years.
Find the minimum loss someone will incur if he sells the house after few years of buying

Sample Input
3
5 10 3

Sample Output
2

Explanation
X buys the house in year 1 at price[0] = 5 and sells it in year 3 
at price[2] = 3 for a minimal loss of 5-3 = 2. 

OUTPUT in OUTPUT_PATH file defined below
SOURCE: https://www.hackerrank.com/challenges/minimum-loss/problem
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
char** split_string(char*);

long long int min = 10000000000;

struct Node{
    long long int val;
    struct Node *left, *right;
};

struct Node *createNode(long long int val){
    struct Node *new = (struct Node *) malloc(sizeof(struct Node));
    new->val = val;
    new->left = NULL;
    new->right = NULL;
    return new;
}

struct Node *insertNode(struct Node *root, long long int val){
    if(root == NULL){
        return createNode(val);
    }
    if(root->val > val && min > root->val - val)
        min = root->val - val;
    
    if(root->val < val)
        root->right = insertNode(root->right, val);
    else
        root->left = insertNode(root->left, val);
    
    return root;
}

void inOrder(struct Node *root){
    if(root != NULL)
    {
        inOrder(root->left);
        inOrder(root->right);
    }
}

// Complete the minimumLoss function below.
int minimumLoss(int price_count, long* price) {
    long long int n, i, m;
    struct Node *root = NULL;
    
    for(i = 0; i < price_count; i++)
    {
        root = insertNode(root, price[i]);
    }
    return min;
}

int main()
{
    FILE* fptr = fopen(OUTPUT_PATH, "w");

    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char** price_temp = split_string(readline());

    long* price = malloc(n * sizeof(long));

    for (int i = 0; i < n; i++) {
        char* price_item_endptr;
        char* price_item_str = *(price_temp + i);
        long price_item = strtol(price_item_str, &price_item_endptr, 10);

        if (price_item_endptr == price_item_str || *price_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(price + i) = price_item;
    }

    int price_count = n;

    int result = minimumLoss(price_count, price);

    fprintf(fptr, "%d\n", result);

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

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
