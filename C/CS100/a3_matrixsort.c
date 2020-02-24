/*
Write a function for sorting N numbers stored in a one dimensional array of integers in
ascending order. Using this function sort the numbers in each row of a m x n matrix in
ascending order. Write functions for reading and displaying matrix.
*/

#include <stdio.h>

void read_matrix(int [50][50], int, int);
void print_matrix(int [50][50], int, int);
void sort(int [], int);

int main()
{
	int mat[50][50], i, m, n;
	printf("\nEnter order of matrix in mxn format\n");
	scanf("%dx%d", &m, &n);

	read_matrix(mat, m, n);

	printf("\nUnsorted matrix\n");
	print_matrix(mat, m, n);

	//Sorting the rows
	for(i = 0; i < m; i++)
	   sort(mat[i], n);

	printf("\nSorted matrix\n");
	print_matrix(mat, m, n);
}

//Inputting matrix elements
void read_matrix(int matrix[50][50], int m, int n)
{
	int i, j;
	printf("\nEnter the elements of %dx%d matrix\n", m, n);
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}
}

//Printing matrix
void print_matrix(int matrix[50][50], int m, int n)
{
	int i, j;
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}

//Bubble sort
void sort(int ar[], int count)
{
	int i, j, temp;
	for(i = 0; i < count-1; i++)
	{
		for(j = 0; j < count-i-1; j++)
		{
			if(ar[j] > ar[j+1])
			{
				temp = ar[j];
				ar[j] = ar[j+1];
				ar[j+1] = temp;
			}
		}
	}
}

