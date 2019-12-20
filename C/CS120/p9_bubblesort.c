/* Sort N numbers in descending order using Bubble sort */

#include <stdio.h>

void main(){
	int N, i, j, temp, ar[50];
	printf("\nEnter number of items: ");
	scanf("%d", &N);

	printf("\nEnter items: ");
	for(i = 0; i < N; i++)
		scanf("%d", &ar[i]);

	for(i = 0; i < N-1; i++)
		for(j = 0; j < N-i-1; j++)
			if(ar[j+1] > ar[j]){
				temp = ar[j+1];
				ar[j+1] = ar[j];
				ar[j] = temp;
			}

	printf("\nSorted list: \n");
	for(i = 0; i < N; i++)
		printf("%d\t", ar[i]);

	printf("\n");
}
