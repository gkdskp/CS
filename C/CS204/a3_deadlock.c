/* Write a C program to implement the deadlock detection algorithm in the case
of several instances of a resource type. Assume the situation of problem 1 and
display the processes which are in deadlock state, if deadlock exists. */

#include "common.h"

int main() {
	struct Process **proc_table = get_processes();
  	int *work, i, j, is_finished, repeat = 0, is_deadlock = 0;
  	int *req_table;

	work = calculate_available(proc_table);
	req_table = get_requests(proc_table);

	for (i = 0; i < PROC_NO; i++) {
    	if (!proc_table[i]->finished) 
		{
      		is_finished = 1;
      		for (j = 0; j < RES_NO; j++)
        		if (work[j] < *(req_table + i * RES_NO + j))
          			is_finished = 0;

      		if (is_finished) 
			{
        		for (j = 0; j < RES_NO; j++)
          			work[j] += proc_table[i]->current_alloc[j];
				proc_table[i]->finished = 1;
        		repeat = 1;
      		}
    	}

    	if (i == PROC_NO - 1 && repeat)
		{
      		i = -1;
      		repeat = 0;
    	}
  	}

	for (i = 0; i < PROC_NO; i++)
	{
    	if (!proc_table[i]->finished) 
		{
      		printf("%s is in deadlock state\n", proc_table[i]->proc_name);
      		is_deadlock = 1;
    	}
  	}

  	if (!is_deadlock)
    	printf("System is not in a deadlock state\n");
}