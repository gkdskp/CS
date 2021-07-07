#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <string.h>
#include <time.h>

#define MESSAGE_SIZE 200

typedef struct sockaddr sockaddr_t;
typedef struct sockaddr_in sockaddr_in_t;

extern int errno;

const int PORT = 3000;
const char *TIME_COMMAND = "TIME";
const char *ACK_COMMAND = "ACK";

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
  int request_length = 0;
  char request[MESSAGE_SIZE];

  fprintf(stdout, "Waiting for request from client\n");

  request_length = recvfrom(
    *socket_fd,
    (char *) request,
    MESSAGE_SIZE,
    MSG_WAITALL,
    (sockaddr_t *) client_addr,
    client_addr_size
  );

  request[request_length] = '\0';
  fprintf(stdout, "Request recieved from client: %s\n", request);

  if(strcmp(request, TIME_COMMAND) == 0) return;
  
  else if(strcmp(request, ACK_COMMAND) == 0) { 
    fprintf(stdout, "Recieved acknowledgment from client\n");
  }

  else {
    fprintf(stderr, "Wrong command recieved from client: %s\n", request);
  }
  
  recieve_message(socket_fd, client_addr, client_addr_size);
}

void send_time(
  int *socket_fd, sockaddr_in_t *client_addr, unsigned int client_addr_size
) {
  time_t curr_time = time(0);
  char *curr_time_s = ctime(&curr_time);
  size_t curr_time_length = strlen(curr_time_s);

  int n = sendto(
    *socket_fd,
    curr_time_s,
    curr_time_length,
    MSG_CONFIRM,
    (sockaddr_t *) client_addr,
    client_addr_size
  );

  perror("Hi");
  fprintf(stdout, "Sending time to client succesfull. Send %d bytes\n", n);
}

int main() {
  int socket_fd;
  sockaddr_in_t client_addr; // Used to store client address
  unsigned int client_addr_size = sizeof(client_addr);

  create_socket(&socket_fd);
  configure_socket(&socket_fd);

  while(1) {
    recieve_message(&socket_fd, &client_addr, &client_addr_size);
    send_time(&socket_fd, &client_addr, client_addr_size);
  }
}