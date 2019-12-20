/* Write a C program to perform Sequential search */

#include <stdio.h>

void main(){
	int N, i, query, found = 0, ar[50];

	printf("\nEnter number of elements: ");
	scanf("%d", &N);

	printf("\nEnter items: \n");
	for(i = 0; i < N; i++)
		scanf("%d", &ar[i]);

	printf("\nEnter the term to be searched: \n");
	scanf("%d", &query);

	for(i = 0; i < N; i++)
		if(ar[i] == query){
			printf("\nThe item is in the %d position of array", i+1);
			found++;
		}

	if(found)
		printf("\nThe item is occuring %d times\n", found);
	else
		printf("\nThe item is not in the array\n");
}
