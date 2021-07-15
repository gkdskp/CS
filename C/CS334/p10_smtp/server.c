/* Implement Client-Server communication using Socket Programming and TCP as transport
layer protocol - Server */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

#define QUEUE_LENGTH 5 

typedef struct sockaddr sockaddr_t; 
typedef struct sockaddr_in sockaddr_in_t;

const char *message_220 = "220 smtp.domain.com ESMTP Postfix";
const char *message_250 = "250 OK";
const char *message_503 = "503 Bad sequence of commands";
const char *message_501 = "501 Syntax error in parameters";
const char *message_354 = "354 End data with <CR><LF>.<CR><LF>";
const char *message_221 = "221 Bye";

const char *domain = "domain.com";

extern int errno;

const int PORT = 3009;
const char *MESSAGE = "Hello world";

char users[][250] = {
  "user1@domain.com",
  "user2@domain.com",
  "user3@domain.com"
};

int no_of_users = sizeof(users)/(250*sizeof(char));

void create_socket(int *socket_fd) {
  if((*socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("Failed to create socket");
    fprintf(stderr, "Errno: %d\n", errno);
    exit(EXIT_FAILURE);
  }

  printf("Socket created with TCP protocol\n");
}

void configure_socket(const int *socket_fd) {
  sockaddr_in_t server_addr;

  server_addr.sin_family = AF_INET;  
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY); 
  server_addr.sin_port = htons(PORT);

  if(bind(*socket_fd, (sockaddr_t *)&server_addr, sizeof(server_addr)) == -1) {
    perror("Failed to bind socket configuration");
    fprintf(stderr, "Errno: %d\n", errno);
    exit(EXIT_FAILURE);
  }

  printf("Socket binding successful\n");
}


void connect_client(const int *socket_fd, int *client_socket_fd) {
  sockaddr_in_t client; 
  
  if(listen(*socket_fd, QUEUE_LENGTH) == -1) {
    perror("Listening failed");
    fprintf(stderr, "Errno: %d\n", errno);
    exit(EXIT_FAILURE);
  }

  printf("Server listening\n");
  
  socklen_t len = sizeof(client);
  
  if((*client_socket_fd = 
              accept(*socket_fd, (sockaddr_t *)&client, &len)) == -1) {
    perror("Accepting connection failed");
    fprintf(stderr, "Errno: %d\n", errno);
    exit(EXIT_FAILURE);
  }

  printf("Server accepted client\n");
}

void process_mail(const int *client_socket_fd) {
  char from[250];
  char to[250];
  char message[500];
  char buffer[100];
  int n, i;

  send(*client_socket_fd, message_220, strlen(message_220), 0);

  n = recv(*client_socket_fd, buffer, sizeof(buffer), 0);
  buffer[n] = '\0';
  printf("Client: %s\n", buffer);

  char *command = strtok(buffer, " ");

  if(strcmp(command, "HELO") != 0) {
    fprintf(stderr, "Didn't recieve HELO from client. Sending 503\n");
    send(*client_socket_fd, message_503, strlen(message_503), 0);
    close(*client_socket_fd);
    fprintf(stderr, "Closed connection to client\n");
    exit(EXIT_FAILURE);
  }

  command = strtok(NULL, " ");
  if(strcmp(command, domain) != 0) {
    fprintf(stderr, "Cannot serve domain %s. Sending 501 and closing\n", command);
    send(*client_socket_fd, message_501, strlen(message_501), 0);
    close(*client_socket_fd);
    exit(EXIT_FAILURE);
  }

  printf("Recieving HELO success. Sending 250\n");
  send(*client_socket_fd, message_250, strlen(message_250), 0);

  n = recv(*client_socket_fd, buffer, sizeof(buffer), 0);
  buffer[n] = '\0';
  printf("Client: %s\n", buffer);

  command = strtok(buffer, ":");
  if(strcmp(command, "MAIL FROM") != 0) {
    fprintf(stderr, "Didn't recieve MAIL FROM from client. Sending 503\n");
    send(*client_socket_fd, message_503, strlen(message_503), 0);
    close(*client_socket_fd);
    fprintf(stderr, "Closed connection to client\n");
    exit(EXIT_FAILURE);
  }

  printf("Recieving MAIL FROM successful\n");
  command = strtok(NULL, ":");
  sscanf(command, "<%s", from);
  strtok(from, ">");
  printf("Got from: %s. Searching for a user\n", from);

  for(i = 0; i < no_of_users; i++) {
    if(strcmp(from, users[i]) == 0) break;
  }

  if(i == no_of_users) {
    fprintf(stderr, "User %s not found. Sending 501\n", from);
    send(*client_socket_fd, message_501, strlen(message_501), 0);
    close(*client_socket_fd);
    fprintf(stderr, "Closed connection to client\n");
    exit(EXIT_FAILURE);
  }

  printf("User %s found. Sending 250\n", from);
  send(*client_socket_fd, message_250, strlen(message_250), 0);

  n = recv(*client_socket_fd, buffer, sizeof(buffer), 0);
  buffer[n] = '\0';
  printf("Client: %s\n", buffer);

  command = strtok(buffer, ":");
  if(strcmp(command, "RCPT TO") != 0) {
    fprintf(stderr, "Didn't recieve RCPT TO from client. Sending 503\n");
    send(*client_socket_fd, message_503, strlen(message_503), 0);
    close(*client_socket_fd);
    fprintf(stderr, "Closed connection to client\n");
    exit(EXIT_FAILURE);
  }

  printf("Recieving RCPT TO successful\n");
  command = strtok(NULL, ":");
  sscanf(command, "<%s", to);
  strtok(to, ">");
  printf("Got from: %s. Searching for a user\n", to);

  for(i = 0; i < no_of_users; i++) {
    if(strcmp(to, users[i]) == 0) break;
  }

  if(i == no_of_users) {
    fprintf(stderr, "User %s not found. Sending 501\n", to);
    send(*client_socket_fd, message_501, strlen(message_501), 0);
    close(*client_socket_fd);
    fprintf(stderr, "Closed connection to client\n");
    exit(EXIT_FAILURE);
  }

  printf("User %s found. Sending 250\n", to);
  send(*client_socket_fd, message_250, strlen(message_250), 0);  

  n = recv(*client_socket_fd, buffer, sizeof(buffer), 0);
  buffer[n] = '\0';

  if(strcmp(buffer, "DATA") != 0) {
    fprintf(stderr, "Didn't recieve DATA from client. Sending 503\n");
    send(*client_socket_fd, message_503, strlen(message_503), 0);
    close(*client_socket_fd);
    fprintf(stderr, "Closed connection to client\n");
    exit(EXIT_FAILURE);
  }

  printf("Recieving DATA successful. Sending 354\n");
  send(*client_socket_fd, message_354, strlen(message_354), 0);

  n = recv(*client_socket_fd, message, sizeof(message), 0);
  message[n] = '\0';
  printf("Recieved message: %s\nSending 250\n", message);
  send(*client_socket_fd, message_250, strlen(message_250), 0);  

  n = recv(*client_socket_fd, buffer, sizeof(buffer), 0);
  buffer[n] = '\0';

  if(strcmp(buffer, "QUIT") != 0) {
    fprintf(stderr, "Didn't recieve QUIT from client. Sending 503\n");
    send(*client_socket_fd, message_503, strlen(message_503), 0);
    close(*client_socket_fd);
    fprintf(stderr, "Closed connection to client\n");
    exit(EXIT_FAILURE);
  }

  printf("Recieved QUIT from client. Sending 221\n");
  send(*client_socket_fd, message_221, strlen(message_221), 0);  

}

void close_socket(int *socket_fd) {
  close(*socket_fd);
  printf("Socket closed\n");
}

int main() {
  int socket_fd; 
  int client_socket_fd; 

  create_socket(&socket_fd);
  configure_socket(&socket_fd);
  connect_client(&socket_fd, &client_socket_fd);
  process_mail(&client_socket_fd);
  close_socket(&socket_fd);
  
  return 0;
}