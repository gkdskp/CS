/* Simulate the following disk scheduling algorithms
	a) FCFS
	b) SCAN 
	c) C-SCAN */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LIM 500

int comp_function(const void * a, const void * b)
{
	return (*(int *)a - *(int *)b);
}

int * read_seek_operations(int n)
{
	int * pos_array = malloc(n * sizeof(int));
	int temp;
	size_t i;

	for(i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		if(temp > LIM)
		{
			printf("Value exceeded limit");
			exit(1);
		}

		pos_array[i] = temp;
	}

	return pos_array;
}

void fcfs(int * pos_arr, int n, int curr_head_pos)
{
	int temp, curr_pos = curr_head_pos, seek_count = 0;
	size_t i;

	printf("%d -> ", curr_head_pos);
	for(i = 0; i < n; i++)
	{
		temp = pos_arr[i];
		printf("%d", temp);
		if(i != n-1) printf(" -> ");

		seek_count += abs(temp - curr_pos);
		curr_pos = temp;
	}

	printf("\nTotal seek count: %d\n", seek_count);
}

void scan(int * pos_arr, int n, int curr_head_pos)
{
	int temp, curr_pos = curr_head_pos, seek_count = 0, direction = 1;
	int i = n-1, j = 0;

	printf("\nSelect initial direction (1 for LTR, -1 for RTL): ");
	scanf("%d", &direction);

	qsort(pos_arr, n, sizeof(int), comp_function);
	
	// Finding the position of head in the sorted array
	while(curr_head_pos > pos_arr[j]) j++;
	temp = (direction == -1) ? j-1: j;

	// Find a better way
	for(i = temp; i >= 0 && i < n; i = i+direction) 
	{
		seek_count += abs(curr_pos - pos_arr[i]);
		curr_pos = pos_arr[i];
		printf("%d -> ", curr_pos);
	}

	seek_count += ((direction == -1)? curr_pos: LIM-curr_pos);
	curr_pos = (direction == -1)? 0: LIM;

	for(i = temp; i >= 0 && i < n; i = i-direction)
	{
		seek_count += abs(curr_pos - pos_arr[i]);
		curr_pos = pos_arr[i];
		printf("%d -> ", curr_pos);
	}

	printf("\nTotal seek count: %d\n", seek_count);
}

int cscan(int * pos_arr, int n, int curr_head_pos)
{
	int temp, curr_pos = curr_head_pos, seek_count = 0, direction = 1;
	int i = n-1, j = 0;

	printf("\nSelect direction (1 for LTR, -1 for RTL): ");
	scanf("%d", &direction);

	qsort(pos_arr, n, sizeof(int), comp_function);
	
	// Finding the position of head in the sorted array
	while(curr_head_pos > pos_arr[j]) j++;
	temp = (direction == -1) ? j-1: j;

	while(i >= 0)
	{
		printf("%d -> ", pos_arr[temp]);
		seek_count += abs(curr_pos - pos_arr[temp]);
		curr_pos = pos_arr[temp];
		temp = temp+direction;

		if((temp == n && direction == 1) && i != 0)
		{
			printf("%d -> ", LIM);
			temp = 0;
			seek_count += LIM-curr_pos;
			curr_pos = 0;
		}
		else if((temp == 0 && direction == -1) && i != 0)
		{
			printf("%d -> ", 0);
			seek_count += curr_pos;
			curr_pos = n-1;
			temp = n-1;
		}

		--i;
	}

	printf("\nTotal seek count: %d\n", seek_count);
}

int main()
{
	int * pos_arr, curr_head_pos, choice;
	size_t n;

	printf("Enter number of seek operations: ");
	scanf("%d", &n);

	printf("\nEnter reuquest sequence: ");
	pos_arr = read_seek_operations(n);

	printf("\nEnter current head position: ");
	scanf("%d", &curr_head_pos);

	printf(
		"\nChoose algorithm:"
		"\n\t1. FCFS"
		"\n\t2. SCAN"
		"\n\t3. C-SCAN\n"
	);
	scanf("%d", &choice);

	switch(choice)
	{
		case 1:
			fcfs(pos_arr, n, curr_head_pos);
			break;

		case 2:
			scan(pos_arr, n, curr_head_pos);
			break;

		case 3:
			cscan(pos_arr, n, curr_head_pos);
			break;
		
		default: 
			printf("\nInvalid Choice");
	}
	printf("\n");

	free(pos_arr);
}