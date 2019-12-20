/* 
You are given a tree (a simple connected graph with no cycles).

Find the maximum number of edges you can remove from the tree
 to get a forest such that each connected component of the forest
contains an even number of nodes.


Function Description
Complete the evenForest function in the editor below. It should return an integer as described.

evenForest has the following parameter(s):
t_nodes: the number of nodes in the tree
t_edges: the number of undirected edges in the tree
t_from: start nodes for each edge
t_to: end nodes for each edge, (Match by index to t_from.)
Input Format

The first line of input contains two integers  and , the number of nodes and edges.
The next  lines contain two integers  and  which specify nodes connected by an edge
of the tree. The root of the tree is node .

Note: The tree in the input will be such that it can always be decomposed
into components containing an even number of nodes

Output Format
Print the number of removed edges.

OUTPUT in OUTPUT_PATH file defined below
SOURCE: https://www.hackerrank.com/challenges/even-tree/problem

SOLUTION LOGIC: Starting from each leaf, go upwards counting the number of nodes connected
to a node including itself. Eg: for a leaf, no. of connected nodes = 1, For a node connected
to two leaves, no. of connected nodes = 3, For a node connected to this node, n = 4.
If the number of connected nodes is even, this group can be cut off from the main tree.

Hence total number of trees = total number of nodes with even no. of connected nodes
total number of cuts made = total number of trees - 1.
*/

#include <assert.h>
#include <ctype.h>
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
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int adjMat[100][100];

int noOfConnected(int t_nodes, int node){
    int i = 0, n = 1, j = 0, flag;
    
    for(i = 0; i < t_nodes; i++)
    {
        if(adjMat[node][i] == 1)
        {
            n = n + noOfConnected(t_nodes, i);
        }
        
    }
    
    return n;
}


// Complete the evenForest function below.
int evenForest(int t_nodes, int t_edges, int* t_from, int* t_to) {
    int noOfconnected[t_nodes], i, j;
    int count = -1;
    
    for(i = 0; i < t_nodes; i++)
        for(j = 0; j < t_nodes; j++)
            adjMat[i][j] = 0;
    
    for(i = 0; i < t_nodes; i++)
        noOfconnected[i] = 0;
    
    for(int i = 0; i < t_edges; i++)
    {
        adjMat[t_to[i]-1][t_from[i]-1] = 1;
    
    }
    
    
    for(i = 0; i < t_edges; i++){
        noOfconnected[i] = noOfConnected(t_nodes, i);
        if(noOfconnected[i] % 2 == 0)
            count++;
    }
    
    
    return count;
}


int main()
{
    FILE* fptr = fopen(OUTPUT_PATH, "w");

    char** t_nodes_edges = split_string(rtrim(readline()));

    char* t_nodes_endptr;
    char* t_nodes_str = t_nodes_edges[0];
    int t_nodes = strtol(t_nodes_str, &t_nodes_endptr, 10);

    if (t_nodes_endptr == t_nodes_str || *t_nodes_endptr != '\0') { exit(EXIT_FAILURE); }

    char* t_edges_endptr;
    char* t_edges_str = t_nodes_edges[1];
    int t_edges = strtol(t_edges_str, &t_edges_endptr, 10);

    if (t_edges_endptr == t_edges_str || *t_edges_endptr != '\0') { exit(EXIT_FAILURE); }

    int t_from[t_edges];
    int t_to[t_edges];

    for (int t_i = 0; t_i < t_edges; t_i++) {
        char** t_from_to = split_string(rtrim(readline()));

        char* t_from_temp_endptr;
        char* t_from_temp_str = t_from_to[0];
        int t_from_temp = strtol(t_from_temp_str, &t_from_temp_endptr, 10);

        if (t_from_temp_endptr == t_from_temp_str || *t_from_temp_endptr != '\0') { exit(EXIT_FAILURE); }

        char* t_to_temp_endptr;
        char* t_to_temp_str = t_from_to[1];
        int t_to_temp = strtol(t_to_temp_str, &t_to_temp_endptr, 10);

        if (t_to_temp_endptr == t_to_temp_str || *t_to_temp_endptr != '\0') { exit(EXIT_FAILURE); }

        t_from[t_i] = t_from_temp;
        t_to[t_i] = t_to_temp;
    }

    int res = evenForest(t_nodes, t_edges, t_from, t_to);

    fprintf(fptr, "%d\n", res);

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

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
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
