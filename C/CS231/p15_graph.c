/* Write a program to implement BFS and DFS traversal algorithms on a
graph */

#include <stdio.h>
#include <stdlib.h>

int addEdge(int mat[][100], int ai, int bi)
{
    mat[ai][bi] = mat[bi][ai] = 1;
}

int findIndex(int *V, int nv, int v)
{
    int i = 0;
    for(i = 0; i < nv; i++)
        if(V[i] == v)
            return i;
    return -1;
    //quit(0);
}

int depthFirstSearch(int adjMat[][100], int *V, int nv)
{
    int *S = (int *) malloc(100 * sizeof(int));
    int *visited = (int *) malloc(nv * sizeof(int));
    int head = -1, v, i = 0, j = 0;

    S[++head] = V[0];

    while(head != -1)
    {
        v = S[head--];
        if(findIndex(visited, i, v) == -1)
        {
            visited[i++] = v;
            printf("Stack: ");
            for(j = head; j > -1; j--)
                printf("%d ", S[j]);
            printf("\nVisited: ");
            for(j = 0; j < i; j++)
                printf("%d ", visited[j]);

            for(j = 0; j < nv; j++)
            {
                if(adjMat[findIndex(V, nv, v)][j] == 1)
                    S[++head] = V[j];
            }
        }
    }

    printf("\nVisited nodes:\n");
    for(j = 0; j < i; j++)
        printf("%d ", visited[j]);
    printf("\n");
}

int breadthFirstSearch(int adjMat[][100], int *V, int nv)
{
    int *Q = (int *) malloc(100 * sizeof(int));
    int *visited = (int *) malloc(nv * sizeof(int));
    int head = -1, rear = -1, v, i = 0, j = 0;

    visited[0] = V[0];
    Q[++rear] = V[0];
    ++head;

    while(rear != -1)
    {
        v = Q[head++];
        if(head > rear) head = rear = -1;

        for(j = 0; j < nv; j++)
        {
            if(adjMat[findIndex(V, nv, v)][j] == 1)
                if(findIndex(visited, i+1, V[j]) == -1){
                    visited[++i] = V[j];
                    Q[++rear] = V[j];
		    printf("Queue: ");
  	            for(j = head; j < rear+1; j++)
                    printf("%d ", Q[j]);
            	    printf("\nVisited: ");
            	    for(j = 0; j < i; j++)
                    printf("%d ", visited[j]);
		    if(rear == 0) head++;
                }
        }
    }


    printf("\nVisited nodes:\n");
    for(j = 0; j < i+1; j++)
        printf("%d ", visited[j]);
    printf("\n");
}

int main()
{
    int nv, *V, quit = 0, a, b, i, j, ch;
    int adjMat[100][100];

    printf("Enter number of vertices\n");
    scanf("%d", &nv);

    printf("Enter vertices\n");
    V = (int *) malloc(nv * sizeof(int));
    for(i = 0; i < nv; i++)
        scanf("%d", &V[i]);

    while(quit == 0)
    {
        printf("Add edge:\n");
        scanf("%d %d", &a, &b);
        addEdge(adjMat, findIndex(V, nv, a), findIndex(V, nv, b));
        printf("Press 1 to continue:\n");
        scanf("%d", &ch);

        if(ch != 1) quit = 1;
    }

    printf("Adjacency matrix of the graph\n  ");
    
    for(i = 0; i < nv; i++)
        printf("%d ", V[i]);

    printf("\n");
    for(i = 0; i < nv; i++){
        printf("%d ", V[i]);
        for(j = 0; j < nv; j++)
            printf("%d ", adjMat[i][j]);
        printf("\n");
    }

    printf("\nDepth First Search:\n");
    depthFirstSearch(adjMat, V, nv);
    printf("\nBreadth First Search: \n");
    breadthFirstSearch(adjMat, V, nv);
}
