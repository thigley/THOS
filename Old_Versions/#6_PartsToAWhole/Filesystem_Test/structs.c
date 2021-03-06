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
	
	char* users[4];
	char* groups[4];
} FileSystem;
