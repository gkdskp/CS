#include "process.h"
#include <stddef.h>
#include <stdio.h>

void draw_gantt_cell(int p_num, int second, int start_cell, int end_cell) {
  if (start_cell)
    printf("\nGantt Chart (Not-to-scale): ");

  printf("\n----------   t=%du", second);
  printf("\n|P%*d|", 8, p_num);

  if (end_cell)
    printf("\n----------   t=%du\n\n", end_cell);
}

int fcfs(Process_list *process_list) {
  size_t i;
  Process_ptr process_ptr;
  int curr_time = process_list->processes[0]->arrival_time;

  for (i = 0; i < process_list->length; ++i) {
    process_ptr = process_list->processes[i];

    draw_gantt_cell(process_ptr->p_num, curr_time, i == 0,
                    (i == process_list->length - 1)
                        ? curr_time + process_ptr->execute_time
                        : 0);

    process_ptr->waiting_time = curr_time - process_ptr->arrival_time;
    process_ptr->turnaround_time =
        process_ptr->waiting_time + process_ptr->execute_time;
    process_ptr->rem_time = 0;
    curr_time += process_ptr->execute_time;
  }
}

int sjf(Process_list *process_list) {
  size_t i, j;
  Process_ptr process_ptr, process_itr;

  int curr_time = process_list->processes[0]->arrival_time;
  for (i = 0; i < process_list->length; ++i) {
    process_ptr = process_list->processes[i];
    for (j = 0; j < process_list->length; j++) {
      process_itr = process_list->processes[j];
      if (!(process_ptr->rem_time) ||
          process_itr->rem_time && process_itr->arrival_time <= curr_time &&
              process_itr->execute_time < process_ptr->execute_time) {
        process_ptr = process_itr;
      }
    }

    draw_gantt_cell(process_ptr->p_num, curr_time, i == 0,
                    (i == process_list->length - 1)
                        ? curr_time + process_ptr->execute_time
                        : 0);
    process_ptr->waiting_time = curr_time - process_ptr->arrival_time;
    process_ptr->turnaround_time =
        process_ptr->waiting_time + process_ptr->execute_time;
    process_ptr->rem_time = 0;
    curr_time += process_ptr->execute_time;
  }
}

int round_robin(Process_list *process_list, int quantum_time) {
  int total_rem_time = comp_total_rem_time(process_list);
  int instant_work_done, curr_time = 0;

  int last_processed_time[process_list->length];
  Process_ptr process_ptr;
  size_t i;

  // Initialize with all zero
  for (i = 0; i < process_list->length; ++i)
    last_processed_time[i] = 0;

  while (total_rem_time > 0) {
    for (i = 0; i < process_list->length; i++) {
      process_ptr = process_list->processes[i];
      if (!process_ptr->rem_time)
        continue;

      instant_work_done = (process_ptr->rem_time > quantum_time)
                              ? quantum_time
                              : process_ptr->rem_time;
      total_rem_time -= instant_work_done;
      process_ptr->rem_time -= instant_work_done;
      draw_gantt_cell(
          process_ptr->p_num, curr_time, curr_time == 0,
          (total_rem_time == 0 ? curr_time + instant_work_done : 0));
      process_ptr->waiting_time += curr_time - last_processed_time[i];
      process_ptr->turnaround_time +=
          curr_time - last_processed_time[i] + instant_work_done;

      curr_time += instant_work_done;
      last_processed_time[i] = curr_time;
    }
  }
}

int priority(Process_list *process_list) {
  size_t i, j;
  Process_ptr process_ptr, process_itr;

  int curr_time = process_list->processes[0]->arrival_time;
  for (i = 0; i < process_list->length; ++i) {
    process_ptr = process_list->processes[i];  
    for (j = 0; j < process_list->length; j++) {
      process_itr = process_list->processes[j];
      if (!(process_ptr->rem_time) ||
          process_itr->rem_time && process_itr->arrival_time <= curr_time &&
              process_itr->priority < process_ptr->priority) {
        process_ptr = process_itr;
      }
    }

    draw_gantt_cell(process_ptr->p_num, curr_time, i == 0,
                    (i == process_list->length - 1)
                        ? curr_time + process_ptr->execute_time
                        : 0);
    process_ptr->waiting_time = curr_time - process_ptr->arrival_time;
    process_ptr->turnaround_time =
        process_ptr->waiting_time + process_ptr->execute_time;
    process_ptr->rem_time = 0;
    curr_time += process_ptr->execute_time;
  }
}