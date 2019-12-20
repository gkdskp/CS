/* Give two sorted list of numbers. Merge these two lists to form a new list such that 
the resultant list is also in sorted order. (without sorting) */

#include <stdio.h>

void main(){
	int ar1[50], ar2[50], ar[50], n1, n2, n3, i, c = 0, d = 0;

	printf("\nEnter number of elements in first and second array\n");
	scanf("%d%d", &n1, &n2);

	printf("\nEnter elements of first sorted array: ");
	for(i = 0; i < n1; i++)
		scanf("%d", &ar1[i]);

	printf("\nEnter elements of second sorted array: ");
	for(i = 0; i < n2; i++){
		scanf("%d", &ar2[i]);
	}

	//Merging the arrays
	i = 0;
	while(c < n1 && d < n2){
		if(ar1[c] < ar2[d]){
			ar[i] = ar1[c];
			i++;
			c++;
		}
		else if(ar1[c] > ar2[d]){
			ar[i] = ar2[d];
			i++;
			d++;
		}
		else{
			ar[i++] = ar1[c];
			ar[i++] = ar2[d];
			c++;
			d++;
		}
	}
	while(c < n1){
		ar[i] = ar1[c];
		i++;
		c++;
	}
	while(d < n2){
		ar[i] = ar2[d];
		i++;
		d++;
	}


	n3 = i; //Number of elements in merged array

	//Outputting the merged array
	printf("\nMerged Array:\n");
	for(i = 0; i < n3; i++)
		printf("%d\t", ar[i]);
	printf("\n");
}
