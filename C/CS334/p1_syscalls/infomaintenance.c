/* Information Maintenance: alarm(), sleep(), getpid() */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void signal_handler() {
	printf("Timed out!\n");
}

int main() {
	unsigned int timeout, elapsed = 0;
	pid_t pid;

	pid = getpid();
	printf("The PID of the process is: %d\n", pid);

	printf("Set timeout after: ");
	scanf("%d", &timeout);

	signal(SIGALRM, signal_handler);
	alarm(timeout);

	while(elapsed++ < timeout) {
		printf("Sleeping for 1 second...\n");
		sleep(1);
	}

	return 0;
}
