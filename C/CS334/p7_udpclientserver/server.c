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

void configure_socket(int *socket_fd) {
  sockaddr_in_t server_addr;

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = PORT;
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  if(bind(*socket_fd, (sockaddr_t *)&server_addr, sizeof(server_addr)) == -1) {
    perror("Failed to bind socket configuration");
    fprintf(stderr, "Errno: %d\n", errno);
    exit(EXIT_FAILURE);
  }

  fprintf(stdout, "Socket binding successful\n");
}

void recieve_message(
  int *socket_fd, sockaddr_in_t *client_addr, unsigned int *client_addr_size
) {
  int message_length = 0;
  char message[MESSAGE_SIZE];

  fprintf(stdout, "Waiting for message from client\n");

  message_length = recvfrom(
    *socket_fd,
    (char *) message,
    MESSAGE_SIZE,
    MSG_WAITALL,
    (sockaddr_t *) client_addr,
    client_addr_size
  );

  message[message_length] = '\0';
  fprintf(stdout, "Message recieved from client: %s\n", message);
}

void send_acknowledgement(
  int *socket_fd, sockaddr_in_t *client_addr, unsigned int client_addr_size
) {
  const char *ack = "Message recieved successfully";
  size_t ack_size = strlen(ack);

  sendto(
    *socket_fd,
    ack,
    ack_size,
    MSG_CONFIRM,
    (sockaddr_t *) client_addr,
    client_addr_size
  );
}

int main() {
  int socket_fd;
  sockaddr_in_t client_addr; // Used to store client address
  unsigned int client_addr_size = sizeof(client_addr);

  create_socket(&socket_fd);
  configure_socket(&socket_fd);
  recieve_message(&socket_fd, &client_addr, &client_addr_size);
  send_acknowledgement(&socket_fd, &client_addr, client_addr_size);
}