/* Write a C program to perform Binary search */

#include <stdio.h>

int main(){
	int middle, first, last, i, found = 0, search, N, ar[30];
	printf("\nEnter number of elements:\n");
	scanf("%d", &N);
	printf("\nEnter sorted array:\n");
	for(i = 0; i < N; i++)
		scanf("%d", &ar[i]);

	printf("Enter the search term: \n");
	scanf("%d", &search);

	first = 0;
	last = N - 1;
	middle = (first + last) / 2;

	while(first <= last){
		if(ar[middle] == search){
			found = 1;
			printf("Found the term at %dth position\n", middle + 1);
			break;
		}
		else{
			if(ar[middle] > search)
				last =  middle - 1;
			else if(ar[middle] < search)
				first = middle + 1;
		}
		middle = (first + last)/2;
	}

	if(!found)
		printf("The term is not in the array\n");
}
