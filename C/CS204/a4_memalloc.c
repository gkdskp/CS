/* Simulate the following memory allocation methods for fixed partition
(a) First Fit (b) Best Fit (c) Worst Fit
{Example case : Total free memory available in terms of fixed partitions are
200K,400K,600K, 500K, 300K, 250K.
Four processes P1,P2,P3 and P4 each of sizes 350K, 230K, 470K, 490.
Show the resultant allocation for each cases. ie. Which process is allocated to
which partition. Show the internal partition in each case.
( eg. P1(350K) -> 400 - IntFrag(50K) .... Total internal fragmentation)
If some processes can not be allocated, diplay comments. Find the total external
fragmentation} */

#include <stdio.h>
#include <stdlib.h>

int no_of_partitions;
int no_of_processes;

int *get_partitions()
{
	int i;
	int *partitions;

	printf("Enter number of partitions\n");
	scanf("%d", &no_of_partitions);

	partitions = malloc(no_of_partitions * sizeof(int));

	printf("Enter partition size\n");
	for(i = 0; i < no_of_partitions; i++)
		scanf("%d", &partitions[i]);

	return partitions;
}

int *get_processes()
{
	int i;
	int *processes;

	printf("Enter number of processes\n");
	scanf("%d", &no_of_processes);

	processes = malloc(no_of_processes * sizeof(int));

	printf("Enter process size\n");
	for(i = 0; i < no_of_processes; i++)
		scanf("%d", &processes[i]);	

	return processes;
}

int compar(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int first_fit(int *partitions, int *processes)
{
	int i, j, total_int_fragmentation = 0, total_ext_fragmentation = 0, allocated = 0;
	int *partitions_copy = malloc(no_of_partitions * sizeof(int));

	for(i = 0; i < no_of_partitions; i++)
		partitions_copy[i] = partitions[i];

	for(i = 0; i < no_of_processes; i++)
	{
		allocated = 0;

		for(j = 0; j < no_of_partitions; j++)
		{
			if(processes[i] <= partitions_copy[j]
				&& partitions_copy[j] == partitions[j])
			{
				printf("P%d(%dK) -> %d - IntFrag(%dK)\n", i+1, processes[i],
				partitions[j], partitions_copy[j] - processes[i]);
				allocated = 1;
				partitions_copy[j] -= processes[i];
				total_int_fragmentation += partitions_copy[j];
				break;
			}
		}

		if(!allocated)
		{
			printf("P%d not allocated\n", i+1);
		}
	}

	for(i = 0; i < no_of_partitions; i++)
		if(partitions[i] == partitions_copy[i])
			total_ext_fragmentation += partitions[i];

	printf("Total Internal Fragmentation: %d\n"
		"Total External Fragmentation: %d\n", 
		total_int_fragmentation, total_ext_fragmentation);
}

int best_fit(int *partitions, int *processes)
{
	int i, j, total_int_fragmentation = 0, total_ext_fragmentation = 0, allocated = 0;
	int *partitions_copy = malloc(no_of_partitions * sizeof(int));

	for(i = 0; i < no_of_partitions; i++)
		partitions_copy[i] = partitions[i];

	for(i = 0; i < no_of_processes; i++)
	{
		allocated = 0;

		for(j = 0; j < no_of_partitions; j++)
		{
			if(processes[i] <= partitions_copy[j] 
				&& partitions_copy[j] == partitions[j])
			{
				printf("P%d(%dK) -> %d - IntFrag(%dK)\n", i+1, processes[i],
				partitions[j], partitions_copy[j] - processes[i]);
				allocated = 1;
				partitions_copy[j] -= processes[i];
				total_int_fragmentation += partitions_copy[j];
				break;
			}
		}

		if(! allocated)
		{
			printf("P%d not allocated\n", i+1);
		}
	}

	for(i = 0; i < no_of_partitions; i++)
		if(partitions[i] == partitions_copy[i])
			total_ext_fragmentation += partitions[i];

	printf("Total Internal Fragmentation: %d\n"
		"Total External Fragmentation: %d\n", 
		total_int_fragmentation, total_ext_fragmentation);
}

int worst_fit(int *partitions, int *processes)
{
	int i, j, total_int_fragmentation = 0, total_ext_fragmentation = 0, allocated = 0;
	int *partitions_copy = malloc(no_of_partitions * sizeof(int));

	for(i = 0; i < no_of_partitions; i++)
		partitions_copy[i] = partitions[i];

	for(i = 0; i < no_of_processes; i++)
	{
		allocated = 0;

		for(j = no_of_partitions-1; j >= 0; j--){
			if(processes[i] <= partitions_copy[j] 
				&& partitions_copy[j] == partitions[j])
			{
				printf("P%d(%dK) -> %d - IntFrag(%dK)\n", i+1, processes[i],
				partitions[j], partitions_copy[j] - processes[i]);
				allocated = 1;
				partitions_copy[j] -= processes[i];
				total_int_fragmentation += partitions_copy[j];
				break;
			}
		}

		if(! allocated)
		{
			printf("P%d not allocated\n", i+1);
		}
	}

	for(i = 0; i < no_of_partitions; i++)
		if(partitions[i] == partitions_copy[i])
			total_ext_fragmentation += partitions[i];

	printf("Total Internal Fragmentation: %d\n"
		"Total External Fragmentation: %d\n", 
		total_int_fragmentation, total_ext_fragmentation);
}

int main()
{
	int *partitions = get_partitions();
	int *processes = get_processes();

	printf("\nFirst Fit----------\n");
	first_fit(partitions, processes);

	qsort(partitions, no_of_partitions, sizeof(int), compar);

	printf("\nWorst Fit----------\n");
	worst_fit(partitions, processes);

	printf("\nBest Fit----------\n");
	best_fit(partitions, processes);
}