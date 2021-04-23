/* Program to show IPC with the help of message queue. Here there are two processes- writer
and reader.
Reference: https://users.cs.cf.ac.uk/Dave.Marshall/C/node25.html */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define BUFFER_SIZE 100
#define FTOK_FILE "msgqfile"

const char *messages = "Hello world";

typedef struct message {
	long type;
	char body[BUFFER_SIZE];
} message_t;

int main() {
	int message_id;
	key_t key;
	message_t message;
	int buffer_size;

	key = ftok(FTOK_FILE, 'A');

	if((message_id = msgget(key, IPC_CREAT | 0666)) < 0) {
		perror("Error getting message_id");
		exit(EXIT_FAILURE);
	}

	message.type = 1;
	strcpy(message.body, messages);
	buffer_size = strlen(message.body) + 1;

	if(msgsnd(message_id, &message, buffer_size, IPC_NOWAIT) < 0) {
		perror("Error sending message");
		exit(EXIT_FAILURE);
	}

	printf("Message sent successfully\n");
	return 0;
}