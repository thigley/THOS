#include "structs.c"

FileSystem filesystem;


void createfile(char* name, char* data);
void createfilefull(char* name, char* data, unsigned short mode, unsigned short user, unsigned short group);
void createinode(unsigned short nodenum, char* data, unsigned short mode, unsigned short user, unsigned short group);
void fillblocks(unsigned short directblocks[], char* data);

void initfs(){
	filesystem.users[0] = "root";
	filesystem.groups[0] = "root";
	filesystem.users[1] = "thigley";
	filesystem.groups[1] = "thigley";
}

void createfile(char* name, char* data){
	createfilefull(name, data, 777, 0, 0);
}
void createfilefull(char* name, char* data, unsigned short mode, unsigned short user, unsigned short group){
	int filenum = filesystem.openfile++;
	int nodenum = filenum;
	int i = 0;
	while(name[i]!=0){
		filesystem.fs[filenum].name[i]=name[i];
		i++;
	}
	filesystem.fs[filenum].used = 1;
	filesystem.fs[filenum].nodloc = nodenum;
	createinode(nodenum,data, mode, user, group);
}

void createinode(unsigned short nodenum, char* data, unsigned short mode, unsigned short user, unsigned short group){
	filesystem.nodes[nodenum].mode = mode;
	filesystem.nodes[nodenum].uid = user;
	filesystem.nodes[nodenum].gid = group;
	filesystem.nodes[nodenum].size = getlength(data);
	fillblocks(filesystem.nodes[nodenum].directblocks, data);
}

void fillblocks(unsigned short directblocks[], char* data){
	int offset = 0;
	int dbnum = 0;
	directblocks[dbnum]=filesystem.openblock++;
	while(*data!=0){
		char next = *data;
		filesystem.blocks[directblocks[dbnum]].data[offset] = next;
		data++;
		offset++;
		if(offset==512){
			offset=0;
			directblocks[++dbnum]=filesystem.openblock++;
		}
	}
}
