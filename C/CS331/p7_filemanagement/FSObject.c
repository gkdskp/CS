#include "FSObject.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prints the location of present directory
void pwd(Filesystem *fs) {
  printf("/");
  for (int i = 0; i < (fs->pwd_depth) + 1; i++) {
    printf("%s/", fs->wd[i]->name);
  }
}

// Creates a new directory in pwd
void mkdir(Filesystem *fs, char name[255]) {
  FSObject *pwd = fs->wd[fs->pwd_depth];

  if (pwd->no_of_children == MAX_CHILDREN || fs->fs_type == SINGLE ||
      (fs->fs_type == DOUBLE && fs->pwd_depth == 1)) {
    printf("Cannot create a new directory\n");
    return;
  } else {
    FSObject *new_dir = malloc(sizeof(FSObject));
    new_dir->type = DIR;
    strcpy(new_dir->name, name);
    new_dir->no_of_children = 0;

    pwd->children[pwd->no_of_children] = new_dir;
    pwd->no_of_children += 1;
  }
}

// Change directory to a child of pwd
void cd(Filesystem *fs, char name[255]) {
  FSObject *pwd = fs->wd[fs->pwd_depth];

  if (strcmp(name, "..") == 0) {
    fs->pwd_depth -= 1;
  } else if (fs->pwd_depth == PWD_STACK_LENGTH) {
    printf("Cannot cd. Maximum stack length reached\n");
    return;
  } else {
    for (int i = 0; i < pwd->no_of_children; i++) {
      if (strcmp(pwd->children[i]->name, name) == 0 &&
          pwd->children[i]->type == DIR) {
        fs->pwd_depth += 1;
        fs->wd[fs->pwd_depth] = pwd->children[i];
        return;
      }
    }
    printf("No directory named %s in %s\n", name, pwd->name);
  }
}

// Create a new file in pwd
void touch(Filesystem *fs, char name[255]) {
  FSObject *pwd = fs->wd[fs->pwd_depth];

  if (pwd->no_of_children == MAX_CHILDREN) {
    printf("Cannot create file. Max children reached\n");
    return;
  }

  FSObject *new_file = malloc(sizeof(FSObject));
  new_file->type = FIL;
  strcpy(new_file->name, name);

  pwd->children[pwd->no_of_children] = new_file;
  pwd->no_of_children += 1;
}

// List all files and folders in pwd
void ls(Filesystem *fs) {
  FSObject *pwd = fs->wd[fs->pwd_depth];

  for (int i = 0; i < pwd->no_of_children; i++)
    if (pwd->children[i]->type == DIR)
      printf("%s/\t", pwd->children[i]->name);
    else
      printf("%s\t", pwd->children[i]->name);

  printf("\n");
  return;
}