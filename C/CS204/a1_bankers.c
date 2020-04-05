/* Write a C program to implement the Banker’s algorithm for checking whether a
given state is safe or not. Assume there are 5 processes at an instant and 3
resource types A,B,C where A is having 10 instances, B is having 5 instances and
C is having 7 instances. Input a snapshot of the current allocation and maximum
requirement. If the system is in safe state give the sequence of processes 
satisfying the safety criteria */

#include <string.h>
#include "common.h"

int is_safe(struct Process **proc_table, int *available, char *seq)
{
	/* Check if the system is safe and to store the sequence of 
	allocation */

	int i = 0, j, repeat = 0, is_finished = 1, finished_count = 0, need;

	for(i = 0; i < PROC_NO; i++)
	{
		if(!proc_table[i]->finished)
		{
			is_finished = 1;
			for(j = 0; j < RES_NO; j++)
			{
				need = proc_table[i]->max_req[j] - proc_table[i]->current_alloc[j];
				is_finished = is_finished && (available[j] >= need);
			}

			if(is_finished)
			{
				repeat = 1;
				for(j = 0; j < RES_NO; j++)
					available[j] += proc_table[i]->current_alloc[j];
				proc_table[i]->finished = 1;
				strcat(seq, proc_table[i]->proc_name);
				finished_count++;
				strcat(seq, (finished_count != PROC_NO) ? " -> " : "");
			}
		}

		if(i == PROC_NO-1 && repeat)
		{
			i = -1;
			repeat = 0;
		}
	}

	return finished_count == PROC_NO;
}


int main()
{
	struct Process** proc_table = get_processes();
	int i = 0, *avialable;

	char *s = malloc(30 * sizeof(char));
	
	avialable = calculate_available(proc_table);

	if(is_safe(proc_table, avialable, s))
		printf("The system is safe\n%s\n", s);
	else
		printf("The system is unsafe\n");

	free(proc_table);
	free(avialable);
	free(s);
}