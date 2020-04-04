/* Assuming the situation in question a1, write a C program for implementing the 
resouce request algorithm for a given process Pi. */

#include "common.h"

int main()
{
	struct Process **proc_table = get_processes();
	int *available, can_allocate = 1, need, i, j;
	int *req = malloc(RES_NO * sizeof(int));

	available = calculate_available(proc_table);
	printf("Enter the process number to run resource request algorithm: ");
	scanf("%d", &i);

	printf("Enter the units of resources to request");
	for(j = 0; j < RES_NO; j++)
	{
		printf("\nResource%d: ", j);
		scanf("%d", req+j);
	}

	for(j = 0; j < RES_NO; j++)
	{
		need = proc_table[i]->max_req[j] - proc_table[i]->current_alloc[j];

		if(req[j] > need)
		{
			printf("Error: request exceeded maximum\n");
			return 1;
		}

		if(available[j] < need)
		{
			printf("The process must wait since resources not available\n");
			return 1;
		}

		available[j] -= req[j];
		proc_table[i]->current_alloc[j] += req[j];
	}

	printf("\n\nRequest granted\n"
	"RES_NO\tmax\tpre\treq\tcur\n");
	for(j = 0; j < RES_NO; j++)
	{
		printf("%d\t%d\t%d\t%d\t%d\n",
			j,
			proc_table[i]->max_req[j],
			proc_table[i]->current_alloc[j] - req[j],
			req[j],
			proc_table[i]->current_alloc[j]
		);
	}

	free(proc_table);
	free(available);
}
