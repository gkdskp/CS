#include <stdio.h>
#include <stdlib.h>
#include "process.h"

Process_ptr read_process()
{
	Process_ptr process_ptr = malloc(sizeof(Process));
	scanf(
		"%d %d %d %d", 
		&(process_ptr->p_num),
		&(process_ptr->arrival_time),
		&(process_ptr->execute_time),
		&(process_ptr->priority)
	);
	process_ptr->turnaround_time = process_ptr->waiting_time = 0;
	process_ptr->rem_time = process_ptr->execute_time;
	return process_ptr;
}

Process_list * read_process_list()
{
	/* The list must be sorted by arrival time.
	Hence insertion sort is used */
	size_t length, i;
	short int j;
	Process_ptr key, process_itr;
	Process_ptr *processes;
	Process_list *process_list = malloc(sizeof(Process_list));

	printf("Enter number of processes: ");
	scanf("%d", &(process_list->length));

	process_list->processes = malloc(process_list->length * sizeof(Process_ptr *));
	processes = process_list->processes;

	printf("\nEnter process number, arrival time, execution time and priority"
	"\nfor the process. Each value must be seperated by a space\n");
	for(i = 0; i < process_list->length; ++i)
	{
		printf("Process%d: ", i);
		*(processes+i) = read_process();
		key = *(processes+i);
		
		j = i-1;

		while(j >= 0 && processes[j]->arrival_time > key->arrival_time)
		{
			process_itr = *(processes+j);

			*(processes+j+1) = process_itr;
			--j;
		}
		*(processes+j+1) = key;
	}

	return process_list;
}

void comp_avg_times(Process_list * process_list)
{
	float avg_turnaround_time = 0.0;
	float avg_waiting_time = 0.0;

	for(size_t i = 0; i < process_list->length; i++)
	{
		avg_turnaround_time += process_list->processes[i]->turnaround_time;
		avg_waiting_time += process_list->processes[i]->waiting_time;
	}

	avg_turnaround_time /= process_list->length;
	avg_waiting_time /= process_list->length;

	printf(
		"\nAverage waiting time: %.2fu"
		"\nAverage turn-around time: %.2fu\n",
		avg_waiting_time,
		avg_turnaround_time
	);
}

int comp_total_rem_time(Process_list * process_list)
{
	int rem_time = 0;
	for(size_t i = 0; i < process_list->length; i++)
	{
		rem_time += process_list->processes[i]->rem_time;
	}
	return rem_time;
}

void free_mem(Process_list * process_list)
{
	for(size_t i = 0; i < process_list->length; ++i) free(process_list->processes[i]);

	free(process_list->processes);
	free(process_list);
}