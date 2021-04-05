/* Simulate the following non-preemptive CPU Scheduling
Algorithms to find turnaround time and waiting time.
	a) FCFS
	b) SJF
	c) Round Robin (pre-emptive)
	d) Priority */

#include <stdio.h>

#include "process.h"
#include "schedule.h"


int main()
{
	int quantum_time, choice;
	Process_list * process_list = read_process_list();

	printf(
		"Select the scheduling algorithm:"
		"\n\t1) First Come First Serve"
		"\n\t2) Shortest Job First"
		"\n\t3) Round Robin (pre-emptive)"
		"\n\t4) Priority\n"
	);
	scanf("%d", &choice);
	switch (choice)
	{
		case 1:
			fcfs(process_list);
			break;

		case 2:
			sjf(process_list);
			break;
		
		case 3:
			printf("\nEnter quantum time: ");
			scanf("%d", &quantum_time);
			round_robin(process_list, quantum_time);
			break;

		case 4:
			priority(process_list);
			break;

		default:
			break;
	}

	comp_avg_times(process_list);
}
