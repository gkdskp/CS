/* PRACTICE QUESTION
Complete the first pass of insertion sort

Sample Input
5
2 4 6 8 3

Sample Output
2 4 6 8 8 
2 4 6 6 8 
2 4 4 6 8 
2 3 4 6 8

Output in STDOUT
Source: https://www.hackerrank.com/challenges/insertionsort1/problem
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

char* readline();
char** split_string(char*);

// Complete the insertionSort1 function below.
void insertionSort1(int n, int arr_count, int* arr) {
    int i, j, temp = arr[arr_count-1], flag = 1;
    for(i = arr_count-2; i>= 0; i--)
    {
        if(arr[i] > temp)
        {
            arr[i+1] = arr[i];
        }
        else
        {
            //intf("%d \n", i);
            arr[i+1] = temp;
            break;
        }
        for(j = 0; j < arr_count; j++)
            printf("%d ", arr[j]);
        printf("\n");
    }
    if(i == -1)
        arr[i+1] = temp;
    if(flag){
    for(j = 0; j < arr_count; j++)
            printf("%d ", arr[j]);
        printf("\n");
    }

}

int main()
{
    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char** arr_temp = split_string(readline());

    int* arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        char* arr_item_endptr;
        char* arr_item_str = *(arr_temp + i);
        int arr_item = strtol(arr_item_str, &arr_item_endptr, 10);

        if (arr_item_endptr == arr_item_str || *arr_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(arr + i) = arr_item;
    }

    int arr_count = n;

    insertionSort1(n, arr_count, arr);

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
