#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include "message.h"

extern int errno;
const int PORT = 3000;

typedef struct sockaddr sockaddr_t;
typedef struct sockaddr_in sockaddr_in_t;

static char username[USERNAME_LENGTH]; 

void create_socket(int *socket_fd) {
  if((*socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
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

  if(connect(
    *socket_fd, (sockaddr_t *)&client_addr, sizeof(client_addr)
  ) == -1) {
    perror("Failed to connect to socket");
    fprintf(stderr, "Errno: %d\n", errno);
    exit(EXIT_FAILURE);
  }

  printf("Connected to socket\n");
}

void send_message(void *args) {
  int socket_fd = *((int *) args);
  message_t message;
  strcpy(message.username, username);
  char message_text[MESSAGE_LENGTH];
  printf("To send a message type your message and press Enter\n");

  while(1) {
    scanf("%*c%[^\n]", message_text);
    strcpy(message.message, message_text);
    send(socket_fd, (void *)&message, sizeof(message), 0);
  }
}

void recieve_message(void *args) {
  int socket_fd = *((int *) args);
  message_t message;

  while(1) {
    while(recv(socket_fd, (void *)&message, sizeof(message), 0) > 0) {
      if(strcmp(message.username, username)) {
        printf("%s: ", message.username);
      } else {
        printf("You: ");
      }

      printf("%s\n", message.message);
    }
  }
} 

int main() {
  int socket_fd;
  pthread_t read_thread, recieve_thread;

  printf("Choose a username: ");
  scanf("%s", username);

  create_socket(&socket_fd);
  connect_server(&socket_fd);
  
  pthread_create(
    &read_thread,
    NULL,
    (void *) send_message,
    (void *) &socket_fd
  );

  pthread_create(
    &recieve_thread,
    NULL,
    (void *) recieve_message,
    (void *) &socket_fd
  );

  pthread_join(read_thread, NULL);
  pthread_join(recieve_thread, NULL);


  return 0;
}