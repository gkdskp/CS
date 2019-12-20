/* You are given 2 arrays A and B of sizes m and n respectively with elements sorted
in both. The problem requires you to merge these 2 arrays whilst maintaining
the sorting and output the merged array */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int m, n, A[1000000], B[1000000], C[200000], i = 0, j = 0, c, d, k;
    char *s, *ch;


    scanf("%d%d", &m, &n);
    for(i = 0; i < m; i++)
        scanf("%d ", &(A[i]));
    for(j = 0; j < n; j++)
        scanf("%d", &(B[j]));

    c = 0;
    d = 0;
    k = 0;
    while((c < m ) && (d < n)){
        if(A[c] < B[d]){
            C[k] = A[c];
            k++;
            c++;
        }
        else{
            C[k] = B[d];
            k++;
            d++;
        }
    }
    while(c < m){
        C[k++] = A[c++];
    }
    while(d < n){
        C[k++] = B[d++];
    }

    for(i = 0; i < k; i++)
        printf("%d ", C[i]);

    return 0;
}
