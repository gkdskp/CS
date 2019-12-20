/* Given two sets of numbers (A,B). Write a menu driven program for performing the followingset operations 
using functions
	1. Union
	2. Intersection
	3. Set Difference 
*/

#include <stdio.h>

void sort(int [], int);
int seqsearch(int[], int, int);

void main(){
	int set1[50], set2[50], union_set[50], intrsctn[50], difference[50], i, j = 0, m, n;

	printf("\nEnter number of elements in set1 and set2\n");
	scanf("%d%d", &m, &n);

	printf("\nEnter elements of first set:\n");
	for(i = 0; i < m; i++)
		scanf("%d", &set1[i]);

	printf("\nEnter elements of second array\n");
	for(i = 0; i < n; i++)
		scanf("%d", &set2[i]);

	i = 0;
	while(i < m){
		if(!seqsearch(union_set, j, set1[i]))
			union_set[j++] = set1[i];
		++i;
	}

	i = 0;
	while(i < n){
                if(!seqsearch(union_set, j, set2[i]))
                        union_set[j++] = set2[i];
                ++i;
        }

	sort(union_set, j);
	printf("\nUnion set: \n");
	for(i = 0; i < j; i++)
		printf("%d\n", union_set[i]);

	j = 0;
	for(i = 0; i < m; i++){
		if(seqsearch(set2, n, set1[i])){
			intrsctn[j++] = set1[i];
		}
	}

	for(i = 0; i < m; i++){
		if(seqsearch(set1, m, set2[i])){
			if(!seqsearch(intrsctn, j, set2[i])){
				intrsctn[j++] = set2[i];
			}
		}
	}
	sort(intrsctn, j);

	printf("\nIntersection set: \n");
        for(i = 0; i < j; i++)
                printf("%d\n", intrsctn[i]);

	j = 0;
	for(i = 0; i < n; i++)
		if(!seqsearch(set1, m, set2[i]))
			difference[j++] = set2[i];

	sort(difference, j);

        printf("\nDifference set (B - A): \n");
        for(i = 0; i < j; i++)
                printf("%d\n", difference[i]);

	 j = 0;
        for(i = 0; i < m; i++)
                if(!seqsearch(set2, n, set1[i]))
                        difference[j++] = set1[i];

        sort(difference, j);

        printf("\nDifference set (A - B): \n");
        for(i = 0; i < j; i++)
                printf("%d\n", difference[i]);


}

int seqsearch(int ar[], int max, int query){
	int i;
	for(i = 0; i < max; i++)
		if(ar[i] == query)
			return 1;

	return 0;
}

void sort(int ar[], int n){
	int i, j, temp;
	for(i = 0; i <= n-1; i++)
		for(j = 0; j < n-i-1; j++)
			if(ar[j+1] < ar[j]){
				temp = ar[j+1];
				ar[j+1] = ar[j];
				ar[j] = ar[j+1];
			}
}
