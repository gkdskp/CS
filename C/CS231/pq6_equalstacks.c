/* PRACTICE QUESTION
You have three stacks of cylinders where each cylinder has the same diameter, 
but they may vary in height. You can change the height of a stack by removing 
and discarding its topmost cylinder any number of times.

Find the maximum possible height of the stacks such that all of the stacks 
are exactly the same height. This means you must remove zero or more cylinders 
from the top of zero or more of the three stacks until they're all the same 
height, then print the height. The removals must be performed in such a 
way as to maximize the height.

Note: An empty stack is still a stack.

Input Format
The first line contains three space-separated integers, n1, n2, and n3, describing the 
respective number of cylinders in stacks 1, 2, and 3. The subsequent lines describe 
the respective heights of each cylinder in a stack from top to bottom:

The second line contains n1 space-separated integers describing the cylinder 
heights in stack 1. The first element is the top of the stack.
The third line contains n2 space-separated integers describing the cylinder heights 
in stack 2. The first element is the top of the stack.
The fourth line contains n3 space-separated integers describing the cylinder heights
 in stack 3. The first element is the top of the stack.

Output Format
Print a single integer denoting the maximum height at which all stacks will be of equal height.

Sample Input
5 3 4
3 2 1 1 1
4 3 2
1 1 4 1

Sample Output
5

OUTPUT in OUTPUT_PATH file defined below
SOURCE: https://www.hackerrank.com/challenges/equal-stacks/problem
*/

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OUTPUT_PATH "out.txt"

char* readline();
char** split_string(char*);



/*
 * Complete the equalStacks function below.
 */
int *equalStacks(int h1_count, int* h1, int h2_count, int* h2, int h3_count, int* h3) {
    /*
     * Write your code here.
     */
    int sumh1[h1_count], sumh2[h2_count], sumh3[h3_count];
    int *small, *slarge, *large, small_size, slarge_size, large_size;
    int j = 0, k = 0;
    sumh1[h1_count-1] = h1[h1_count-1];
    sumh2[h2_count-1] = h2[h2_count-1];
    sumh3[h3_count-1] = h3[h3_count-1];
    for (int i = 1; i < h1_count; i++)
        sumh1[h1_count- 1 - i] = sumh1[h1_count-i] + h1[h1_count - i - 1];
    for (int i = 1; i < h2_count; i++)
        sumh2[h2_count- 1 - i] = sumh2[h2_count-i] + h2[h2_count - i - 1];
    for (int i = 1; i < h3_count; i++)
        sumh3[h3_count- 1 - i] = sumh3[h3_count-i] + h3[h3_count - i - 1];

    if (h1_count < h2_count)
    {
        small = sumh1;
        small_size = h1_count;
        slarge = sumh2;
        slarge_size = h2_count;
    } else {
        small = sumh2;
        small_size = h2_count;
        slarge = sumh1;
        slarge_size = h1_count;
    }
    if (h3_count < small_size)
    {
        large = small;
        large_size = small_size;
        small = sumh3;
        small_size = h3_count;
    } else {
        large = sumh3;
        large_size = h3_count;
    }
    for (int i = 0; i < small_size; i++)
    {
        j = 0;
        while ((slarge[j] != small[i]) && (j < slarge_size))
            j++;
        if (slarge[j] == small[i])
        {        
            k = 0;
            while ((large[k] != small[i]) && (k < large_size))
                k++;
            if (small[i] == large[k])
                return small[i];
        }
    }
    return 0;
}

int main()
{
    FILE* fptr = fopen(OUTPUT_PATH, "w");

    char** n1N2N3 = split_string(readline());

    char* n1_endptr;
    char* n1_str = n1N2N3[0];
    int n1 = strtol(n1_str, &n1_endptr, 10);

    if (n1_endptr == n1_str || *n1_endptr != '\0') { exit(EXIT_FAILURE); }

    char* n2_endptr;
    char* n2_str = n1N2N3[1];
    int n2 = strtol(n2_str, &n2_endptr, 10);

    if (n2_endptr == n2_str || *n2_endptr != '\0') { exit(EXIT_FAILURE); }

    char* n3_endptr;
    char* n3_str = n1N2N3[2];
    int n3 = strtol(n3_str, &n3_endptr, 10);

    if (n3_endptr == n3_str || *n3_endptr != '\0') { exit(EXIT_FAILURE); }

    char** h1_temp = split_string(readline());

    int h1[n1];

    for (int h1_itr = 0; h1_itr < n1; h1_itr++) {
        char* h1_item_endptr;
        char* h1_item_str = h1_temp[h1_itr];
        int h1_item = strtol(h1_item_str, &h1_item_endptr, 10);

        if (h1_item_endptr == h1_item_str || *h1_item_endptr != '\0') { exit(EXIT_FAILURE); }

        h1[h1_itr] = h1_item;
    }

    char** h2_temp = split_string(readline());

    int h2[n2];

    for (int h2_itr = 0; h2_itr < n2; h2_itr++) {
        char* h2_item_endptr;
        char* h2_item_str = h2_temp[h2_itr];
        int h2_item = strtol(h2_item_str, &h2_item_endptr, 10);

      //  if (h2_item_endptr == h2_item_str || *h2_item_endptr != '\0') { exit(EXIT_FAILURE); }

        h2[h2_itr] = h2_item;
    }

    char** h3_temp = split_string(readline());

    int h3[n3];

    for (int h3_itr = 0; h3_itr < n3; h3_itr++) {
        char* h3_item_endptr;
        char* h3_item_str = h3_temp[h3_itr];
        int h3_item = strtol(h3_item_str, &h3_item_endptr, 10);

       // if (h3_item_endptr == h3_item_str || *h3_item_endptr != '\0') { exit(EXIT_FAILURE); }

        h3[h3_itr] = h3_item;
    }

    int result = equalStacks(n1, h1, n2, h2, n3, h3);

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
