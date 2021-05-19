/* Implement Client-Server communication using Socket Programming and TCP as transport
layer protocol - Client */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>

#define MESSAGE_LENGTH 255

// The number of connection requests to be queued, all exceeding
// connections will be rejected
typedef struct sockaddr sockaddr_t;
typedef struct sockaddr_in sockaddr_in_t;

extern int errno;

const int PORT = 8080;

// Create a TCP socket
void create_socket(int *socket_fd) {
  if((*socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("Failed to create socket");
    fprintf(stderr, "Errno: %d\n", errno);
    exit(EXIT_FAILURE);
  }

  printf("Socket created successfully\n");
}

// Connect the socket to server
void connect_server(int *socket_fd) {
  sockaddr_in_t client_addr;

  client_addr.sin_port = htons(PORT);
  client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  client_addr.sin_family = AF_INET;

  if(connect(
    *socket_fd, (sockaddr_t *)&client_addr, sizeof(client_addr)
  ) == -1) {
    perror("Failed to connect to socket");
    fprintf(stderr, "Errno: %d\n", errno);
    exit(EXIT_FAILURE);
  }

  printf("Connected to socket\n");
}

// Read message from server
void read_message(int *socket_fd) {
  char message[MESSAGE_LENGTH];
  ssize_t message_recieved, message_recieved_total = 0;
  
  while(message_recieved && message[message_recieved_total] != '\0') {
    message_recieved = recv(
      *socket_fd, 
      (message+message_recieved_total), 
      MESSAGE_LENGTH, 
      0
    );

    if(message_recieved == -1) {
      perror("Recieving message failed");
      fprintf(stderr, "Errno: %d\n", errno);
      exit(EXIT_FAILURE);
    }

    message_recieved_total += message_recieved;
    printf("%d", message_recieved);
  }
  
  printf(
    "Recieving message success. Recieved %d bytes\n", 
    message_recieved_total
  );
  printf("Recieved message: %s\n", message);
}

int main() {
  int socket_fd;

  create_socket(&socket_fd);
  connect_server(&socket_fd);
  read_message(&socket_fd);

  return 0;
}
