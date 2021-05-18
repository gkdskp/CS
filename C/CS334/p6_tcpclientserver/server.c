/* Implement Client-Server communication using Socket Programming and TCP as transport
layer protocol - Server */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>

// The number of connection requests to be queued, all exceeding
// connections will be rejected
#define QUEUE_LENGTH 5 

// sockaddr acts as a general structure, while sockaddr_in is specific
// for internet sockets
typedef struct sockaddr sockaddr_t; 
typedef struct sockaddr_in sockaddr_in_t;

extern int errno;

const int PORT = 5000;
const char *MESSAGE = "Hello world";

// Create a socket with TCP as protocol
void create_socket(int *socket_fd) {
  if((*socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("Failed to create socket");
    fprintf(stderr, "Errno: %d\n", errno);
    exit(EXIT_FAILURE);
  }

  printf("Socket created with TCP protocol\n");
}

// Configure the socket
void configure_socket(const int *socket_fd) {
  sockaddr_in_t server_addr;

  // For sockaddr_in, sin_family is always AF_INET (for TCP and UDP)
  server_addr.sin_family = AF_INET;
  
  // Accept any incoming message irrespective of IP
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY); 

  // Listen to port specified by PORT
  server_addr.sin_port = htons(PORT);

  if(bind(*socket_fd, (sockaddr_t *)&server_addr, sizeof(server_addr)) == -1) {
    perror("Failed to bind socket configuration");
    fprintf(stderr, "Errno: %d\n", errno);
    exit(EXIT_FAILURE);
  }

  printf("Socket binding successful\n");
}

// Listen and accept connection from clients
void connect_client(const int *socket_fd, int *client_socket_fd) {
  sockaddr_in_t client; // For storing client details

  // Listen for connection from client
  if(listen(*socket_fd, QUEUE_LENGTH) == -1) {
    perror("Listening failed");
    fprintf(stderr, "Errno: %d\n", errno);
    exit(EXIT_FAILURE);
  }

  printf("Server listening\n");
  
  socklen_t len = sizeof(client);
  // Accept connection from client
  if((*client_socket_fd = 
              accept(*socket_fd, (sockaddr_t *)&client, &len)) == -1) {
    perror("Accepting connection failed");
    fprintf(stderr, "Errno: %d\n", errno);
    exit(EXIT_FAILURE);
  }

  printf("Server accepted client\n");
}

// Send the MESSAGE to client
void send_message(const int *client_socket_fd) {
  if(send(*client_socket_fd, (void *)MESSAGE, sizeof(MESSAGE), 0) == -1) {
    perror("Sending message failed");
    fprintf(stderr, "Errno: %d\n", errno);
    exit(EXIT_FAILURE);
  }

  printf("Sending message success\n");
}

// Close the socket
void close_socket(int *socket_fd) {
  close(*socket_fd);
  printf("Socket closed\n");
}

int main() {
  int socket_fd; // The file descriptor for socket
  int client_socket_fd; // The file descriptor for client

  create_socket(&socket_fd);
  configure_socket(&socket_fd);
  connect_client(&socket_fd, &client_socket_fd);
  send_message(&client_socket_fd);
  close_socket(&socket_fd);
  
  return 0;
}