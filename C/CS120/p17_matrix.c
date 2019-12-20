/* Find the largest number and its position in a m x n matrix */

#include <stdio.h>

void main(){
	int m, n, i, j, lm, ln, largest, ar[50][50];

	printf("\nEnter number of rows and columns in mxn format\n");
	scanf("%dx%d", &m, &n);

	printf("\nEnter matrix elements\n");
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++)
			scanf("%d", &ar[i][j]);
	}

	printf("\nThe matrix is: \n");
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++)
			printf("%d\t", ar[i][j]);
		printf("\n");
	}

	largest = ar[0][0];

	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
			if(ar[i][j] > largest){
				largest = ar[i][j];
				lm = i;
				ln = j;
			}

	printf("\nLargest digit in matrix is: %d in the (%d, %d) position \n", largest, lm+1, ln+1);
}
