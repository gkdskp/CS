#ifndef _PROCESS
#define _PROCESS

typedef struct 
{
	int p_num;
	int arrival_time;
	int execute_time;
	int priority;

	int turnaround_time;
	int waiting_time;
	int rem_time;
} Process;

typedef Process * Process_ptr;

typedef struct
{
	Process_ptr * processes;
	int length;
} Process_list;

Process_ptr read_process();

Process_list * read_process_list();

void comp_avg_times(Process_list * process_list);

int comp_total_rem_time(Process_list * process_list);

#endif