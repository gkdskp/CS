/* Program for communication between a child process and its parent process with the
use of Ordinary Pipes */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>

// Child proces to write message
void 
child_process(const int *pipe_fd, const char *message, const int message_length) {
	printf("Child process writing to pipe\n");
	close(pipe_fd[0]);
	write(pipe_fd[1], message, message_length);
	printf("Writing to pipe success\n");

	sleep(1);
	printf("Child process exiting\n");
	exit(EXIT_SUCCESS);
}

// Parent process to read message from child 
void parent_process(const int *pipe_fd, const int message_length) {
	char message[50];

	wait(NULL);

	printf("Parent process reading from pipe\n");
	close(pipe_fd[1]);
	read(pipe_fd[0], message, message_length);
	close(pipe_fd[0]);
	printf("The message read is %s\n", message);

	printf("Parent process exiting\n");
	exit(EXIT_SUCCESS);
}

int main() {
	const char message[] = "Hello world";
	
	// Pipe file descriptors
	// pipe_fd[0] for read
	// pipe_fd[1] for write
	int pipe_fd[2];

	if(pipe(pipe_fd) == -1) {
		printf("Error in creating pipe\n");
		exit(EXIT_FAILURE);
	}

	if(fork()) parent_process(pipe_fd, strlen(message));

	child_process(pipe_fd, message, strlen(message));
	
	return 0;
}