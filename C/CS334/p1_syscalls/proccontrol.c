/* Process Control : fork(), getpid(), exit(), wait() */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	pid_t pid;

	if(fork() == 0) {
		pid = getpid();
		printf("PID of the child process is %d\n", pid);
		exit(EXIT_SUCCESS);
	} 

	pid = getpid();
	printf("PID of the parent process is %d\n", pid);
	printf("Parent going to wait state\n");
	wait(NULL);
	printf("Parent executing after termination of child\n");

	return 0;
}