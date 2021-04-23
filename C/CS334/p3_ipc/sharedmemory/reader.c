/* Program to show IPC with the help of shared memory. Here there are two processes
writer and reader. */

#include <stdio.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/ipc.h>

#define MESSAGE_LENGTH 6
#define FTOK_FILE "shmfile"

int main() {
	key_t key;
	int shm_id;
	char *message_addr;

	key = ftok(FTOK_FILE, 'A');
	shm_id = shmget(key, MESSAGE_LENGTH, 0666 | IPC_CREAT);

	printf("Reading message from shared memory segment\n");
	message_addr = (char *) shmat(shm_id, (void *)0, 0);
	printf("Message read is: %s\n", message_addr);
	shmdt(message_addr);

	shmctl(shm_id, IPC_RMID, NULL);
	return 0;
}