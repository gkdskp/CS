/* Communication: pipe(), shmget() */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <math.h>
#include <wait.h>

#define MESSAGE_LENGTH 6
#define FTOK_FILE "shmfile"

// Write to pipe
void pipe_write(int *pipe_fd, char *message) {
	printf("Writing to pipe");
	close(pipe_fd[0]); // Closing the read pipe
	write(pipe_fd[1], message, MESSAGE_LENGTH);
	printf(" SUCCESS\n");

	sleep(1);
	exit(EXIT_SUCCESS);
}

// Reads MESSAGE_LENGTH characters from pipe
void pipe_read(int *pipe_fd) {
	char message[10];

	wait(NULL); // Wait for pipe_write process to complete

	printf("Reading from pipe\n");
	close(pipe_fd[1]); // Closing the write pipe
	read(pipe_fd[0], message, MESSAGE_LENGTH);
	close(pipe_fd[0]); // Closing the read pipe

	printf("The message is: %s\n", message);

	exit(EXIT_SUCCESS);
}

// Write to shared memory segment
void shmget_write(char *message) {
	key_t key;
	int shm_id;
	
	key = ftok(FTOK_FILE, 'A'); // Generate a unique token
	shm_id = shmget(key, MESSAGE_LENGTH, 0666 | IPC_CREAT);

	printf("Writing message to shared memory segment");
	char *message_addr = (char *) shmat(shm_id, (void *)0, 0); // Attach to shared memory
	strcpy(message_addr, message);
	shmdt(message_addr); // Detach from shared memory
	printf(" SUCCESS\n");

	sleep(1);
	exit(EXIT_SUCCESS);
}

// Read from shared memory
void shmget_read() {
	key_t key;
	int shm_id;
	char *message_addr;
	
	wait(NULL);

	key = ftok(FTOK_FILE, 'A'); // Generate a unique token
	shm_id = shmget(key, MESSAGE_LENGTH, 0666 | IPC_CREAT);

	printf("Reading message from shared memory segment\n");
	message_addr = (char *) shmat(shm_id, (void *)0, 0);
	printf("Message read is: %s\n", message_addr);
	shmdt(message_addr);

	shmctl(shm_id, IPC_RMID, NULL);
	exit(EXIT_SUCCESS);
}

// Process to facilitate pipe working
void pipe_process(char *message) {
	int pipe_fd[2];

	if(pipe(pipe_fd) == -1) {
		printf("Error in creating pipe\n");
		exit(EXIT_FAILURE);
	}

	if(fork() == 0) pipe_write(pipe_fd, message);

	pipe_read(pipe_fd);
}

// Function to facilitate Shared memory segment
void shmget_process(char *message) {
	wait(NULL); // Wait for pipe_process to stop

	if(fork() == 0) shmget_write(message);

	shmget_read();
}

int main() {
	char *message = "Hello";

	if(fork() == 0) pipe_process(message);

	shmget_process(message);

	return 0;
}