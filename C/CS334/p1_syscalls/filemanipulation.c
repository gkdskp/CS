/* File Manipulation: open(), close(), read(), write() */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

extern int errno;

int main() {
	int fd = open("file.txt", O_WRONLY | O_CREAT);
	char text_to_write[] = "Hello world";
	char *text_read = malloc(512 * sizeof(char));
	
	if(fd == -1) {
		printf("File open failed with error code %d\n", errno);
		exit(1);
	}

	printf("File descriptor for write #%d\n", fd);

	printf("Writing to file");
	write(fd, text_to_write, strlen(text_to_write));
	printf(" SUCCESS\n");

	close(fd);
	printf("Closed file\n");

	fd = open("file.txt", O_RDONLY);

	if(fd == -1) {
		printf("File open failed with error code %d\n", errno);
		exit(1);
	}

	printf("File descriptor for read #%d\n", fd);

	printf("Reading from file\n");
	read(fd, text_read, sizeof(text_to_write));
	printf("%s", text_read);

	close(fd);
	printf("\n");

	return 0;
}