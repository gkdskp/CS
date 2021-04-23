/* Program to show IPC using Named pipes
Reference: https://www.geeksforgeeks.org/named-pipe-fifo-example-c-program */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 140

int main() {
	int fd;
	const char *path = "/tmp/chat";
	char message[BUFFER_SIZE];

	mkfifo(path, 0666);

	while(1) {
		printf("Waiting for User1 to message\n");
		fd = open(path, O_RDONLY);
		read(fd, message, BUFFER_SIZE);
		close(fd);
		
		printf("User1: %s", message);

		printf(">> ");
		fgets(message, BUFFER_SIZE, stdin);

		fd = open(path, O_WRONLY);
		write(fd, message, BUFFER_SIZE);
		close(fd);
	}

	return 0;
}