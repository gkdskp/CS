#include "process.h"
#ifndef _SCHEDULE
#define _SCHEDULE

int fcfs(Process_list *);
int sjf(Process_list *);
int round_robin(Process_list *, int);
int priority(Process_list *);

#endif