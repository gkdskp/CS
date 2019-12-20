/* Write a C program to perform  Matrix Multiplication and addition. Write separate 
functions for Reading, operation and Display */

#include <stdio.h>
#define MAX 10

int matrix_input(int [][MAX], int);
int matrix_addn(int [][MAX], int [][MAX], int [][MAX], int);
int matrix_display(int [][MAX], int);
int matrix_multi(int [][MAX], int [][MAX], int [][MAX], int);

void main(){
	int n, ar1[MAX][MAX], ar2[MAX][MAX], sum[MAX][MAX], mult[MAX][MAX];

	printf("\nEnter order of matrix\n");
	scanf("%d", &n);

	printf("\nEnter elements of first matrix\n");
	matrix_input(ar1, n);

	printf("\nEnter elements of second array\n");
	matrix_input(ar2, n);

	printf("\na1 = \n");
	matrix_display(ar1, n);

	printf("\na2 = \n");
	matrix_display(ar2, n);

	matrix_addn(ar1, ar2, sum, n);
	printf("\nSum = \n");
	matrix_display(sum, n);

	matrix_multi(ar1, ar2, mult, n);
	printf("\nProduct = \n");
	matrix_display(mult, n); 

}

int matrix_input(int mat[][MAX], int n){
	int i, j;
	for(i = 0; i < n; i++)
	        for(j = 0; j < n; j++)
	                scanf("%d", &mat[i][j]);
}

int matrix_display(int mat[][MAX], int n){
	int i, j;
	for(i = 0; i < n; i++){
                for(j = 0; j < n; j++)
                        printf("%d\t", mat[i][j]);
                printf("\n");
	}
}

int matrix_addn(int mat1[][MAX], int mat2[][MAX], int result[][MAX], int n){
	int i, j;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			result[i][j] = mat1[i][j] + mat2[i][j];

}

int matrix_multi(int mat1[][MAX], int mat2[][MAX], int result[][MAX], int n){
	int i, j, k;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			result[i][j] = 0;
			for(k = 0; k < n; k++)
				result[i][j] += (mat1[i][k] * mat2[k][j]);
		}

	}

}
