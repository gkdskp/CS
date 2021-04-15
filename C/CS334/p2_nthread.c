/* Program to create N threads */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

void *thread_function(void *n) {
	printf("Thread %d executing\n", (* (int *)n));
}

void create_n_threads(const int N) {
	int i;
	pthread_t tid;

	for(i = 0; i < N; i++) {
		pthread_create(&tid, NULL, thread_function, (void *)&i);
		pthread_join(tid, NULL);
	}
}

int main() {
	int N;

	printf("Enter N: ");
	scanf("%d", &N);

	if(fork() == 0) {
		printf("From child process\n");
		create_n_threads(N);
		exit(EXIT_SUCCESS);
	}

	wait(NULL);
	printf("From parent process\n");
	create_n_threads(N);

	return 0;
}