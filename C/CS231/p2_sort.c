/* Write a menu driven program to implement
	a) Selection Sort
	b) Bubble Sort */

#include <stdio.h>
#include <stdlib.h>

void print_array(int *, int);
int bubble_sort(int *, int);
int select_sort(int *, int);
int merge_sort(int *, int, int);
int merge(int *, int, int, int);
int quick_sort(int *, int, int);
int partition(int *, int, int);
int insertion_sort(int *, int);

int main(){
	int n, i, ch, ar[100], copy[100], quit = 0;

	printf("\nEnter no. of elements\n");
	scanf("%d", &n);


	printf("Enter the elements of the array\n");
	for(i = 0; i < n; i++)
		scanf("%d", ar+i);

	printf("Unsorted array\n");
	print_array(ar, n);

	while(!quit){

		printf("Menu\n"
		"1. Selection sort\n"
		"2. Bubble sort\n"
		"3. Insertion sort\n"
		"4. Merge Sort\n"
		"5. Quick Sort\n"
		"6. Quit\n"
		);
		scanf("%d", &ch);

		for(i = 0; i < n; i++)
			copy[i] = ar[i];

		switch(ch){
			case 1:
				select_sort(copy, n);
				break;
			case 2:
                                bubble_sort(copy, n);
				break;
			case 3:
				insertion_sort(copy, n);
				break;
			case 4:
				merge_sort(copy, 0, n-1);
				break;
			case 5:
				quick_sort(copy, 0, n-1);
				break;
			case 6:
				quit = 1;
				break;
			default:
				printf("Invalid option\n");
		}

		printf("Sorted array\n");
		print_array(copy, n);

		//free(ar);
	}
}

int bubble_sort(int *ar, int n){
	int i, j, k, temp;
	printf("Steps\n");
	for(i = 0; i < n-1; i++){
		for(j = 0; j < n-i-1; j++){
			if(ar[j] > ar[j+1]){
				temp = ar[j];
				ar[j] = ar[j+1];
				ar[j+1] = temp;
			}
		}
		print_array(ar, n);
	}
}

int select_sort(int *ar, int n){
	int i, j, temp;
	printf("Steps\n");
	for(i = 0; i < n; i++){
		for(j = i+1; j < n; j++){
			if(ar[i] > ar[j]){
				temp = ar[i];
				ar[i] = ar[j];
				ar[j] = temp;
			}
		}
		print_array(ar, n);
	}
}

int merge_sort(int *ar, int l, int r)
{
	int m;
	if(l < r)
	{
		m = (l + r) / 2;
		merge_sort(ar, l, m);
		merge_sort(ar, m+1, r);
		merge(ar, l, m, r);
	}
}

int merge(int *ar, int l, int m, int r)
{
	int n1 = m-l+1, n2 = r-m;
	int L[n1], R[n2], i, j, k;
	for (i = 0; i < n1; i++)
        	L[i] = ar[l + i];
    	for (j = 0; j < n2; j++)
        	R[j] = ar[m + 1+ j];

	i = j = 0;
    	k = l;


	while(i < n1 && j < n2)
	{
		if(L[i] < R[j]){
			ar[k] = L[i];
			k++;
			i++;
		}
		else{
			ar[k] = R[j];
			k++;
			j++;
		}
	}
	while(i < n1){
		ar[k] = L[i];
		k++;
		i++;
	}
	while(j < n2)
	{
		ar[k] = R[j];
		k++;
		j++;
	}

}

int partition(int *ar, int l, int h)
{
        int pivot = ar[h], i = l -1, j, temp;
        for(j = l; j <= h-1; j++)
        {
                if(ar[j] < pivot)
                {
                        i++;
                        temp = ar[i];
                        ar[i] = ar[j];
                        ar[j] = temp;
                }

        }
        temp = ar[i+1];
        ar[i+1] = ar[h];
        ar[h] = temp;

        return i+1;
}

int quick_sort(int *ar, int l, int h)
{
        int i;
        if(l < h)
        {
                i = partition(ar, l, h);
                quick_sort(ar, l, i-1);
                quick_sort(ar, i+1, h);
	}
}

int insertion_sort(int *ar, int n)
{
	int temp, i, j;
        for(i = 1; i < n; i++)
        {
                j = i-1;
                temp = ar[i];
                while(j >= 0 && ar[j] > temp)
                {
                        ar[j+1] = ar[j];
                        j = j-1;
                }
                ar[j+1] = temp;
        }
}



void print_array(int *ar, int n){
	int i;
	printf("{");
	for(i = 0; i < n; i++)
		printf("%d, ", *(ar+i));
	printf("}\n");
}