/* Common header for a1, a2 and a3 */

#include <stdio.h>
#include <stdlib.h>

#define PROC_NO 5
#define RES_NO 3

struct Process
{
	char *proc_name;
	int *current_alloc;
	int *max_req;
	int finished;
};

int tot_res[3] = {10, 5, 7};

struct Process *create_process()
{
	/* Reads process details */

	struct Process *process = malloc(sizeof(struct Process));
	int *current_alloc = malloc(3 * sizeof(int));
	int *max_req = malloc(3 * sizeof(int));
	process->proc_name = malloc(20 * sizeof(char));

	printf("Enter process name: ");
	scanf("%[^\n]%*c", process->proc_name);

	printf("Enter current allocations of A, B and C: ");
	scanf("%d %d %d%*c", current_alloc, (current_alloc + 1), (current_alloc + 2));

	printf("Enter maximum requirements: ");
	scanf("%d %d %d%*c", max_req, max_req + 1, max_req + 2);

	process->current_alloc = current_alloc;
	process->max_req = max_req;
	process->finished = 0;

	return process;
}

struct Process **get_processes()
{
	/* Returns the process table */

	int i;
	struct Process **proc_table = malloc(PROC_NO * sizeof(struct Process));
	for(i = 0; i < PROC_NO; i++)
		proc_table[i] = create_process();
	
	return proc_table;
}

int *get_requests(struct Process **proc_table)
{
	/* Reads resource request from a process */

	int i, j, req;
	int *req_table = malloc(PROC_NO * RES_NO * sizeof(int));

	for(i = 0; i < PROC_NO; i++)
	{
		printf("Request for %s: ", proc_table[i]->proc_name);
		for(j = 0; j < RES_NO; j++)
		{
			scanf("%d", &req);
			*(req_table + i*RES_NO + j) = req;
		}
			
		printf("\n");
	}

	return req_table;
}



int *calculate_available(struct Process **proc_table) 
{
	/* Calculate the remaining resources */

	int *avialable = malloc(3 * sizeof(int)), i, j, sum;

	for(i = 0; i < RES_NO; i++)
	{
		sum = 0;
		for(j = 0; j < PROC_NO; j++)
			sum += proc_table[j]->current_alloc[i];

		avialable[i] = tot_res[i] - sum;
	}

	return avialable;
} 