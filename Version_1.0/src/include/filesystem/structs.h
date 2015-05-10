/* structs.h */

#include "stack.h"
#define BLOCKSIZE 512
#define NUM_OF_INODES 10
#define NUM_OF_BLOCKS 60
int createfile(char* name, char* data);
int createfilefull(char* name, char* data, unsigned short mode, unsigned short user, unsigned short group);
void createinode(int nodenum, char* data, unsigned short mode, unsigned short user, unsigned short group);
void fillblocks(unsigned short directblocks[], char* data);
void replaceblocks(int prenumblocks, unsigned short directblocks[], char* data);
int createorreplacefile(char* name, char* data);
void replacefile(int filenum, char* data);
int getfilenum(char* name, int folder);

typedef struct Inodes {
	unsigned short mode;
	unsigned short uid;
	unsigned short gid;
	unsigned short size;		
	unsigned short directblocks[8];
} Inode;

typedef struct Datablocks {
	char data[BLOCKSIZE];
} Datablock;

typedef struct Files {
	int used;
	char name[32];
	unsigned short nodloc;
} File;

#define NUM_OF_USERS 16
typedef struct Users {
	char name[32];
	char passwd[32];
} User;

typedef struct FileSystems {
	Inode nodes[NUM_OF_INODES];
	StackI av_node;

	Datablock blocks[60];
	StackI av_block;

	File fs[NUM_OF_INODES];
	StackI av_file;

	int openfile;
	int openblock;
	
	User users[NUM_OF_USERS];
	char *groups[5];
} FileSystem;
