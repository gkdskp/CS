/* Implement Client-Server communication using Socket Programming and TCP as
transport layer protocol - Client */

#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>

#define MESSAGE_LENGTH 255

typedef struct sockaddr sockaddr_t;
typedef struct sockaddr_in sockaddr_in_t;

extern int errno;

const int PORT = 3009;

void create_socket(int *socket_fd) {
  if ((*socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("Failed to create socket");
    fprintf(stderr, "Errno: %d\n", errno);
    exit(EXIT_FAILURE);
  }

  printf("Socket created successfully\n");
}

void connect_server(int *socket_fd) {
  sockaddr_in_t client_addr;

  client_addr.sin_port = htons(PORT);
  client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  client_addr.sin_family = AF_INET;

  if (connect(*socket_fd, (sockaddr_t *)&client_addr, sizeof(client_addr)) ==
      -1) {
    perror("Failed to connect to socket");
    fprintf(stderr, "Errno: %d\n", errno);
    exit(EXIT_FAILURE);
  }

  printf("Connected to socket\n");
}

void send_message(int *socket_fd, char *mail_from_in, char *mail_to_in) {
  const char *message = "HELO domain.com";
  char buffer[250];
  char *temp;
  int n;

  char mail_from[250], mail_to[250];

  sprintf(mail_from, "MAIL FROM:<%s>", mail_from_in);
  sprintf(mail_to, "RCPT TO:<%s>", mail_to_in);

  n = recv(*socket_fd, buffer, sizeof(buffer), 0);
  buffer[n] = '\0';
  printf("Server: %s\n", buffer);

  temp = strtok(buffer, " ");

  if(strcmp(temp, "220") != 0) {
    fprintf(stderr, "Didn't recieve 220 from server. Exiting\n");
    exit(EXIT_FAILURE);
  }

  printf("Recieved 220 from server\n");

  n = send(*socket_fd, message, strlen(message), 0);
  if(n > 0) {
    printf("Send HELO success. Total %d bytes\n", n);
  }

  n = recv(*socket_fd, buffer, sizeof(buffer), 0);
  buffer[n] = '\0';
  printf("Server: %s\n", buffer);

  temp = strtok(buffer, " ");
  if(strcmp(temp, "250") != 0) {
    fprintf(stderr, "Didn't recieve 250 from server. Closing\n");
    exit(EXIT_FAILURE);
  }
  printf("Recieved 250 from server\n");

  n = send(*socket_fd, mail_from, strlen(mail_from), 0);
  if(n > 0) {
    printf("Send MAIL FROM success. Total %d bytes\n", n);
  }

  n = recv(*socket_fd, buffer, sizeof(buffer), 0);
  buffer[n] = '\0';
  printf("Server: %s\n", buffer);

  temp = strtok(buffer, " ");
  if(strcmp(temp, "250") != 0) {
    fprintf(stderr, "Didn't recieve 250 from server. Closing\n");
    exit(EXIT_FAILURE);
  }

  printf("Recieved 250 from server\n");

  n = send(*socket_fd, mail_to, strlen(mail_to), 0);
  if(n > 0) {
    printf("Send RCPT TO success. Total %d bytes\n", n);
  }

  n = recv(*socket_fd, buffer, sizeof(buffer), 0);
  buffer[n] = '\0';
  printf("Server: %s\n", buffer);

  temp = strtok(buffer, " ");
  if(strcmp(temp, "250") != 0) {
    fprintf(stderr, "Didn't recieve 250 from server. Closing\n");
    exit(EXIT_FAILURE);
  }

  printf("Recieved 250 from server\n");

  n = send(*socket_fd, "DATA", 4, 0);
  if(n > 0) {
    printf("Send DATA success. Total %d bytes\n", n);
  }

  n = recv(*socket_fd, buffer, sizeof(buffer), 0);
  buffer[n] = '\0';
  printf("Server: %s\n", buffer);

  temp = strtok(buffer, " ");
  if(strcmp(temp, "354") != 0) {
    fprintf(stderr, "Didn't recieve 354 from server. Closing\n");
    exit(EXIT_FAILURE);
  }

  printf("Recieved 354 from server\n");
  printf("Enter your message: ");
  scanf("%*c%[^\n\r]%*c", buffer);

  n = send(*socket_fd, buffer, strlen(buffer), 0);
  if(n > 0) {
    printf("Send message success. Total %d bytes\n", n);
  }

  n = recv(*socket_fd, buffer, sizeof(buffer), 0);
  buffer[n] = '\0';
  printf("Server: %s\n", buffer);

  temp = strtok(buffer, " ");
  if(strcmp(temp, "250") != 0) {
    fprintf(stderr, "Didn't recieve 250 from server. Closing\n");
    exit(EXIT_FAILURE);
  }

  printf("Recieved 250 from server\n");

  n = send(*socket_fd, "QUIT", 4, 0);
  if(n > 0) {
    printf("Send QUIT success. Total %d bytes\n", n);
  }

  n = recv(*socket_fd, buffer, sizeof(buffer), 0);
  buffer[n] = '\0';
  printf("Server: %s\n", buffer);

  temp = strtok(buffer, " ");
  if(strcmp(temp, "221") != 0) {
    fprintf(stderr, "Didn't recieve 221 from server. Closing\n");
    exit(EXIT_FAILURE);
  }

  printf("Recieved 221 from server\n");
  printf("Quitting succesfully\n");
}

int main() {
  int socket_fd;
  char mail_from[250], mail_to[250];

  printf("From: ");
  scanf("%s", mail_from);

  printf("To: ");
  scanf("%s", mail_to);

  create_socket(&socket_fd);
  connect_server(&socket_fd);
  send_message(&socket_fd, mail_from, mail_to);

  return 0;
}
