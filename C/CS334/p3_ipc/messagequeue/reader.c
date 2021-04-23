/* Program to show IPC with the help of message queue. Here there are two processes- writer
and reader.
Reference: https://users.cs.cf.ac.uk/Dave.Marshall/C/node25.html */

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define BUFFER_SIZE 100
#define FTOK_FILE "msgqfile"

typedef struct message {
	long type;
	char body[BUFFER_SIZE];
} message_t;

int main() {
	key_t key;
	int message_id;
	message_t message;

	key = ftok(FTOK_FILE, 'A');

	if((message_id = msgget(key, 0666 | IPC_CREAT)) < 0) {
		perror("Error getting message_id");
		exit(EXIT_FAILURE);
	}

	printf("Reading data from message queue\n");
	if(msgrcv(message_id, &message, BUFFER_SIZE, 1, 0) < 0) {
		perror("Error recieving message");
		exit(EXIT_FAILURE);
	}
	printf("Message received: %s\n", message.body);

	msgctl(message_id, IPC_RMID, NULL);

	return 0;
}