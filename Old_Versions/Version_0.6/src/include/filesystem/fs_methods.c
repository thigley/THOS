void testFiles(){
	createfile("test","this is a test");
	createfilefull("long_test","This test will be considerably longer than the others. The reason for this is to test the filesystems ability to use multiple blocks. In 'test', all of the data fit into a single block so we weren't able to really see if the system was working. In contrast, this file is long enough (more than 512 bytes) that it will need to be stored in multiple blocks. This will not only test it's own ability to store longer files, but also make sure that the next file has no issues caused by side effects of this longer file.",543,1,1);
	createfilefull("final_test","Boo! I'm a ghost!!!! Fear me! Muhahahaha!",777,0,1);
}

void initfs(){
	filesystem.users[0] = "root";
	filesystem.groups[0] = "root";
	filesystem.users[1] = "thigley";
	filesystem.groups[1] = "thigley";
	
	int i;

	for(i=NUM_OF_INODES-1;i>=0;i--){
		push(&filesystem.av_node,i);
		push(&filesystem.av_file,i);
	}
	
	for(i=NUM_OF_BLOCKS-1;i>=0;i--){
		push(&filesystem.av_block,i);
	}
	
	testFiles();
}

int getfilenum(char* name){
	int i;
	for(i=0;i<NUM_OF_INODES;i++){
		if(filesystem.fs[i].used && !k_strcmp(name, filesystem.fs[i].name)){return i;}
	}
	return -1;
}

int createorreplacefile(char* name, char* data){
	int filenum = getfilenum(name);
	if(filenum<0) return createfile(name, data);
	else replacefile(filenum, data);

	return 0;
}

void replacefile(int filenum, char* data){
	unsigned short nodenum = filesystem.fs[filenum].nodloc;
	int prenumblocks = filesystem.nodes[nodenum].size/BLOCKSIZE;
	if(filesystem.nodes[nodenum].size%BLOCKSIZE!=0) prenumblocks++;
	filesystem.nodes[nodenum].size = k_strlen(data);
	replaceblocks(prenumblocks, filesystem.nodes[nodenum].directblocks, data);
}

int fs_chmod(unsigned short numod, int filenum){
	if(filenum<0) return 1;
	filesystem.nodes[filesystem.fs[filenum].nodloc].mode = numod;
	return 0;
}

int rmfile(int filenum){
	//int filenum = getfilenum(name);
	if(filenum<0) return 1;

	filesystem.fs[filenum].used = 0;
	push(&filesystem.av_file,filenum);
	push(&filesystem.av_node, filesystem.fs[filenum].nodloc);

	int prenumblocks = filesystem.nodes[filesystem.fs[filenum].nodloc].size/BLOCKSIZE;
	if(filesystem.nodes[filesystem.fs[filenum].nodloc].size%BLOCKSIZE!=0) prenumblocks++;
	int i;
	for(i=0;i<prenumblocks;i++){
		push(&filesystem.av_block, filesystem.nodes[filesystem.fs[filenum].nodloc].directblocks[i]);
	}

	return 0;
}

int createfile(char* name, char* data){
	return createfilefull(name, data, 777, 0, 0);
}

int sizetoblocks(int size){
	int blocks = size/BLOCKSIZE;
	if(size%BLOCKSIZE!=0) blocks++;
	return blocks;
}

int createfilefull(char* name, char* data, unsigned short mode, unsigned short user, unsigned short group){
	//check errors
	if(isEmpty(&filesystem.av_file)) return 1;
	if(isEmpty(&filesystem.av_node)) return 1;
	if(filesystem.av_block.top<sizetoblocks(k_strlen(data))) return 1;
	

	int filenum = pop(&filesystem.av_file);
	int nodenum = pop(&filesystem.av_node);

	int i = 0;
	while(name[i]!=0){
		filesystem.fs[filenum].name[i]=name[i];
		i++;
	}
	filesystem.fs[filenum].name[i]=0;

	filesystem.fs[filenum].used = 1;
	filesystem.fs[filenum].nodloc = nodenum;

	createinode(nodenum,data, mode, user, group);
	return 0;
}

void createinode(int nodenum, char* data, unsigned short mode, unsigned short user, unsigned short group){
	filesystem.nodes[nodenum].mode = mode;
	filesystem.nodes[nodenum].uid = user;
	filesystem.nodes[nodenum].gid = group;
	filesystem.nodes[nodenum].size = k_strlen(data);
	fillblocks(filesystem.nodes[nodenum].directblocks, data);
}

void fillblocks(unsigned short directblocks[], char* data){
	int offset = 0;
	int dbnum = 0;
	directblocks[dbnum]=pop(&filesystem.av_block);
	while(*data!=0){
		char next = *data;
		filesystem.blocks[directblocks[dbnum]].data[offset] = next;
		data++;
		offset++;
		if(offset==512){
			offset=0;
			directblocks[++dbnum]=pop(&filesystem.av_block);
		}
	}
}

void replaceblocks(int prenumblocks, unsigned short directblocks[], char* data){
	int offset = 0;
	int dbnum = 0;
	while(*data!=0){
		char next = *data;
		filesystem.blocks[directblocks[dbnum]].data[offset] = next;
		data++;
		offset++;
		if(offset==512){
			offset=0;
			if(++dbnum>(prenumblocks-1)) directblocks[dbnum]=pop(&filesystem.av_block);
		}
	}
}
