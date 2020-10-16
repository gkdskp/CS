#ifndef _FSOBJECT
#define _FSOBJECT

#define MAX_CHILDREN 25
#define PWD_STACK_LENGTH 100

typedef enum { DIR, FIL } FSObjectType;

typedef enum { SINGLE, DOUBLE, HIERARCHIAL } FilesystemType;

struct FileSystemObject {
  char name[255];
  FSObjectType type;
  struct FileSystemObject *children[MAX_CHILDREN];
  int no_of_children;
};

typedef struct FileSystemObject FSObject;

typedef struct {
  FSObject *root;
  FSObject *wd[PWD_STACK_LENGTH];
  int pwd_depth;
  FilesystemType fs_type;
} Filesystem;

void pwd(Filesystem *);
void mkdir(Filesystem *, char[255]);
void cd(Filesystem *, char[255]);
void touch(Filesystem *, char[255]);
void ls(Filesystem *);

#endif