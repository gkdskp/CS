#include "FSObject.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FSObject *init_root_dir(char name[255]) {
  FSObject *root_folder = malloc(sizeof(FSObject));
  strcpy(root_folder->name, name);
  root_folder->type = DIR;
  root_folder->no_of_children = 0;

  return root_folder;
}

Filesystem *init_fs(FilesystemType fs_type, FSObject *root_folder) {
  Filesystem *filesystem = malloc(sizeof(filesystem));
  filesystem->root = root_folder;
  filesystem->fs_type = fs_type;
  filesystem->wd[0] = root_folder;
  filesystem->pwd_depth = 0;

  return filesystem;
}

int main() {
  int choice;
  char command[5], operand[255];
  Filesystem *filesystem;
  FSObject *root_dir;
  FilesystemType fs_type;

  printf("Enter type of filesystem\n1. Single\t 2. Double\t 3. Hierarchial\n");
  scanf("%d", &choice);

  switch (choice) {
  case 1:
    fs_type = SINGLE;
    break;

  case 2:
    fs_type = DOUBLE;
    break;

  case 3:
    fs_type = HIERARCHIAL;
    break;

  default:
    printf("Unknown type\n");
    exit(0);
  }

  printf("Enter root directory name: ");
  scanf("%s", operand);

  root_dir = init_root_dir(operand);
  filesystem = init_fs(fs_type, root_dir);

  printf("\n\nList of available commands:\n"
         "pwd\tls\tmkdir\ttouch\tcd\texit\n");

  while (strcmp(command, "exit") != 0) {

    pwd(filesystem);
    printf(">> ");
    scanf("%s", command);

    if (strcmp(command, "pwd") == 0) {
      pwd(filesystem);
      printf("\n");
    } else if (strcmp(command, "ls") == 0)
      ls(filesystem);
    else if (strcmp(command, "touch") == 0) {
      scanf("%s", operand);
      touch(filesystem, operand);
    } else if (strcmp(command, "mkdir") == 0) {
      scanf("%s", operand);
      mkdir(filesystem, operand);
    } else if (strcmp(command, "cd") == 0) {
      scanf("%s", operand);
      cd(filesystem, operand);
    }  else if (strcmp(command, "exit") == 0) {
		continue;
    } else {
      printf("Unknown command %s\n", command);
    }
  	printf("\n");
  }

  return 0;
}