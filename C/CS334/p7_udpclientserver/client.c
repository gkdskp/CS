#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <string.h>

#define MESSAGE_SIZE 200

typedef struct sockaddr sockaddr_t;
typedef struct sockaddr_in sockaddr_in_t;

extern int errno;

const int PORT = 3000;

void create_socket(int *socket_fd) {
  if((*socket_fd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
    perror("Failed to create socket");
    fprintf(stderr, "Errno: %d\n", errno);
    exit(EXIT_FAILURE);
  }

  fprintf(stdout, "Socket created with UDP protocol\n");
}

void configure_server_info(
  sockaddr_in_t *server_addr, unsigned int server_addr_size
) {
  server_addr->sin_family = AF_INET;
  server_addr->sin_port = PORT;
  server_addr->sin_addr.s_addr = htonl(INADDR_ANY);

  fprintf(stdout, "Configuring server info successful\n");
}

void send_message(
  int *socket_fd, sockaddr_in_t *server_addr, unsigned int server_addr_size
) {
  const char *message = "Hello world";
  size_t message_size = strlen(message);

  sendto(
    *socket_fd,
    message,
    message_size,
    MSG_WAITALL,
    (sockaddr_t *) server_addr,
    server_addr_size
  );

  fprintf(stdout, "Message sent to server\n");
}

void recieve_acknowledgement(
  int *socket_fd, sockaddr_in_t *server_addr, unsigned int server_addr_size
) {
  int message_length = 0;
  char message[MESSAGE_SIZE];

  fprintf(stdout, "Waiting for acknowledgement from server\n");

  message_length = recvfrom(
    *socket_fd,
    (char *) message,
    MESSAGE_SIZE,
    MSG_CONFIRM,
    (sockaddr_t *) server_addr,
    &server_addr_size
  );

  message[message_length] = '\0';
  printf("Message recieved from server: %s\n", message);
}


int main() {
  int socket_fd;
  sockaddr_in_t socket_addr;
  unsigned int socket_addr_size = sizeof(socket_addr);

  create_socket(&socket_fd);
  configure_server_info(&socket_addr, socket_addr_size);
  send_message(&socket_fd, &socket_addr, socket_addr_size);
  recieve_acknowledgement(&socket_fd, &socket_addr, socket_addr_size);
}