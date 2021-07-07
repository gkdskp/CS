#include "message.h"
#include <errno.h>
#include <netinet/in.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define QUEUE_LENGTH 5

extern int errno;
const int PORT = 3000;

typedef struct sockaddr sockaddr_t;
typedef struct sockaddr_in sockaddr_in_t;

typedef struct
{
  int *client_fds; // Array of client fds
  int i; // Index of current client
  int *n; // Total number of clients
} thread_args_t;


void create_socket(int *socket_fd) {
  if ((*socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("Failed to create socket");
    fprintf(stderr, "Errno: %d\n", errno);
    exit(EXIT_FAILURE);
  }

  printf("Socket created successfully\n");
}

void configure_socket(const int *socket_fd) {
  sockaddr_in_t server_addr;

  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port = htons(PORT);

  if (bind(*socket_fd, (sockaddr_t *)&server_addr, sizeof(server_addr)) == -1) {
    perror("Failed to bind socket configuration");
    fprintf(stderr, "Errno: %d\n", errno);
    exit(EXIT_FAILURE);
  }

  printf("Socket binding successful\n");
}

void listen_for_client(const int *socket_fd) {
  if (listen(*socket_fd, QUEUE_LENGTH) == -1) {
    perror("Listening failed");
    fprintf(stderr, "Errno: %d\n", errno);
    exit(EXIT_FAILURE);
  }

  printf("Server listening\n");
}

void* recieve_message_from_client(void *args) {
  thread_args_t thread_args = *((thread_args_t *)args);
  message_t message;

  while(recv(
    thread_args.client_fds[thread_args.i], 
    (void *)&message, 
    sizeof(message), 0) > 0) {
    for(int i = 0; i < *(thread_args.n); i++) {
      send(
        thread_args.client_fds[i],
        (void *) &message,
        sizeof(message),
        0
      );
    }
  }
}

void accept_client(const int *socket_fd, int *client_fds, int *n, pthread_t *client_threads) {
  int client_socket_fd;
  sockaddr_in_t client;
  socklen_t len = sizeof(client);
  thread_args_t thread_args;

  if ((client_socket_fd = accept(*socket_fd, (sockaddr_t *)&client, &len)) ==
      -1) {
    perror("Accepting connection failed");
    fprintf(stderr, "Errno: %d\n", errno);
    exit(EXIT_FAILURE);
  }

  printf("Server accepted client %d\n", *n);

  thread_args.client_fds = client_fds;
  thread_args.n = n;
  thread_args.i = *n;

  client_fds[*n] = client_socket_fd;
  pthread_create(
    &client_threads[*n], 
    NULL, 
    (void *)recieve_message_from_client,
    (void *) &thread_args
  );
}



void main() {
  int socket_fd;
  int client_fds[MAX_CLIENTS];
  int n = 0;
  pthread_t client_threads[MAX_CLIENTS];

  create_socket(&socket_fd);
  configure_socket(&socket_fd);
  listen_for_client(&socket_fd);
  while(1) {
    accept_client(&socket_fd, client_fds, &n, client_threads);
    n++;
  }
  
}