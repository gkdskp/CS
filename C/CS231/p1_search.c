/* Write a menu driven program to implement
	a) Linear Search
	b) Binary Search (iterative & recursive) */

#include <stdio.h>
#define MAX 100

int linear_search(int ar[], int n, int q)
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(ar[i] == q)
		{
			return i;
		}
	}
	return -1;
}

int bin_search_iter(int ar[], int n, int q)
{
	int first = 0, last = n, middle, i;
	do
	{
		middle = (first + last) / 2;
		if(ar[middle] == q)
			return middle;
		else if(ar[middle] > q)
			last = middle - 1;
		else
			first = middle + 1;
	}while(first <= last);
	return -1;
}

int bin_search_recursive(int ar[], int first, int last, int q)
{
	int middle;
	if(first <= last)
	{
		middle = (first + last) / 2;
		if(ar[middle] == q)
			return middle;
		else if(ar[middle] > q)
			bin_search_recursive(ar, first, middle-1, q);
		else
			bin_search_recursive(ar, middle+1, last, q);
	}else
		return -1;
}

void bubble_sort(int ar[], int n)
{
	int i, j, temp;
	for(i = 0; i < n-1; i++)
	{
		for(j = 0; j < n-i-1; j++)
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

int main()
{
	int i, n, ar[MAX], q, choice, pos = -1, start_again = 1;

	printf("Enter number of elements\n");
	scanf("%d", &n);

	printf("Enter array elements\n");
	for(i = 0; i < n; i++)
		scanf("%d", &ar[i]);

	printf("Enter search term\n");
	scanf("%d", &q);

	while(start_again)
	{
		 printf("\nMenu\n"
       		 "1.Linear Search\n"
       		 "2.Binary Search using iteration\n"
        	"3.Binary Search using recursion\n"
        	"4. Quit\n");
        	scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				pos = linear_search(ar, n, q);
				break;
			case 2:
				bubble_sort(ar, n);
				pos = bin_search_iter(ar, n, q);
				break;
			case 3:
				bubble_sort(ar, n);
				pos = bin_search_recursive(ar, 0, n, q);
				break;
			case 4:
				start_again = 0;
				break;
			default:
				printf("Invalid option\n");

		}
		(pos != -1)? printf("Found in %d position in the array\n", pos+1)
                : printf("Not found\n");

	}
}

