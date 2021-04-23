/* Program to show IPC with the help of shared memory. Here there are two processes
writer and reader. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/ipc.h>

#define MESSAGE_LENGTH 6
#define FTOK_FILE "shmfile"

int main() {
	key_t key;
	int shm_id;
	const char *message = "Hello";
	
	key = ftok(FTOK_FILE, 'A'); // Generate a unique token
	shm_id = shmget(key, MESSAGE_LENGTH, 0666 | IPC_CREAT);

	printf("Writing message to shared memory segment");
	char *message_addr = (char *) shmat(shm_id, (void *)0, 0); // Attach to shared memory
	strcpy(message_addr, message);
	shmdt(message_addr); // Detach from shared memory
	printf(" SUCCESS\n");

	return 0;
}