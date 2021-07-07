#ifndef message_h_
#define message_h_

#define USERNAME_LENGTH 20
#define MESSAGE_LENGTH 500

typedef struct message {
  char username[USERNAME_LENGTH];
  char message[MESSAGE_LENGTH];
} message_t;

#endif