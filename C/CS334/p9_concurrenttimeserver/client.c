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

void request_time(
  int *socket_fd, sockaddr_in_t *server_addr, unsigned int server_addr_size
) {
  const char *request = "TIME";
  size_t request_size = strlen(request);

  sendto(
    *socket_fd,
    request,
    request_size,
    MSG_WAITALL,
    (sockaddr_t *) server_addr,
    server_addr_size
  );

  fprintf(stdout, "Message sent to server\n");
}

void recieve_time(
  int *socket_fd, sockaddr_in_t *server_addr, unsigned int server_addr_size
) {
  int message_length = 0;
  char message[MESSAGE_SIZE];

  fprintf(stdout, "Waiting for time from server\n");

  message_length = recvfrom(
    *socket_fd,
    (char *) message,
    MESSAGE_SIZE,
    MSG_CONFIRM,
    (sockaddr_t *) server_addr,
    &server_addr_size
  );

  message[message_length] = '\0';
  fprintf(stdout, "Time recieved from server: %s\n", message);
}

void send_acknowledgement(
  int *socket_fd, sockaddr_in_t *server_addr, unsigned int server_addr_size
) {
  const char *request = "ACK";
  size_t request_size = strlen(request);

  sendto(
    *socket_fd,
    request,
    request_size,
    MSG_WAITALL,
    (sockaddr_t *) server_addr,
    server_addr_size
  );

  fprintf(stdout, "Acknowledgement sent to server\n");
}

int main() {
  int socket_fd;
  sockaddr_in_t socket_addr; // Used to store server address
  unsigned int socket_addr_size = sizeof(socket_addr);

  create_socket(&socket_fd);
  configure_server_info(&socket_addr, socket_addr_size);
  request_time(&socket_fd, &socket_addr, socket_addr_size);
  recieve_time(&socket_fd, &socket_addr, socket_addr_size);
  send_acknowledgement(&socket_fd, &socket_addr, socket_addr_size);
}