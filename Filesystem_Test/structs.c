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
	Inode nodes[10];
	Datablock blocks[60];
	File fs[10];
	int openfile;
	int openblock;
	char* users[4];
	char* groups[4];
} FileSystem;
