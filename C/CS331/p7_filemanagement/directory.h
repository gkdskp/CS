#ifndef _DIRECTORY
#define _DIRECTORY

typedef struct 
{
	char *dirname;
	char **filename;
	int filecount;
} Directory;

#endif