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
int getfilenum(char* name);

typedef struct Inodes {
	unsigned short mode;
	unsigned short uid;
	unsigned short gid;
	unsigned short size;		
	unsigned short directblocks[4];
} Inode;

typedef struct Datablocks {
	char data[BLOCKSIZE];
} Datablock;

typedef struct Files {
	int used;
	char name[32];
	unsigned short nodloc;
} File;

typedef struct FileSystems {
	Inode nodes[NUM_OF_INODES];
	StackI av_node;

	Datablock blocks[60];
	StackI av_block;

	File fs[NUM_OF_INODES];
	StackI av_file;

	int openfile;
	int openblock;
	
	char users[5][16];
	char *groups[5];
} FileSystem;
