void printfiles();
void printfile(int i);
void dump();

void dump(){
	printf("BEGIN DUMP:\n");
	printf("Inodes:\n");
	int i;
	for(i=0;i<10;i++){
		printf("*****\n");
		printf("\t");
		printf("%i",filesystem.nodes[i].mode);
		printf("->");
		printf("%i",filesystem.nodes[i].uid);
		printf("->");
		printf("%i",filesystem.nodes[i].gid);
		printf("->");
		printf("%i",filesystem.nodes[i].size);
		printf("\n\t");
		int j;
		for(j=0;j<4;j++){
			printf("->");
			printf("%i",filesystem.nodes[i].directblocks[j]);
		}
		printf("\n");
	}
			
	printf("Blocks:\n");
	for(i=0;i<NUM_OF_BLOCKS;i++){
		int j; 
		for(j=0;j<512;j++) printf("%c",filesystem.blocks[i].data[j]);
		printf("/");
	}
	printf("\nEND DUMP:\n");
}

void viewfile(char* name){
	//get file num
	int i;
	int filenum = getfilenum(name);
	if(filenum<0){printf("no such file\n"); return;}

	int length = filesystem.nodes[filesystem.fs[filenum].nodloc].size;
	int db = 0;
	int pos = 0;
	
	for(i=0; i<length; i++){
		int nodenum = filesystem.fs[filenum].nodloc;
		int blocknum = filesystem.nodes[nodenum].directblocks[db];
		printf("%c", filesystem.blocks[blocknum].data[pos++]);
		if(pos==512) {pos=0;db++;}
	}

}

void printfiles(){
	int i;
	for(i = 0; i < NUM_OF_INODES; i++){
		if(filesystem.fs[i].used==0) continue;
		printfile(i);
		printf("\n");
	}
}

void printfile(int i){
	unsigned int copy = filesystem.nodes[filesystem.fs[i].nodloc].mode;
	//dir?
	printf("%c", copy>777?'d':'-');
	//perm
	copy= copy%1000;

	int j;
	for(j = 0; j<3; j++){
		switch(copy/100){
			case 0:
				printf("---");
				break;
			case 1:
				printf("--x");
				break;
			case 2:
				printf("-w-");
				break;
			case 3:
				printf("-wx");
				break;
			case 4:
				printf("r--");
				break;
			case 5:
				printf("r-x");
				break;
			case 6:
				printf("rw-");
				break;
			case 7:
				printf("rwx");
				break;
		}
		copy = (copy%100)*10;
	}

	
	printf(" ");
	//user
	printf("%s ", filesystem.users[filesystem.nodes[filesystem.fs[i].nodloc].uid]);
	//group
	printf("%s ", filesystem.groups[filesystem.nodes[filesystem.fs[i].nodloc].gid]);
	//size
	printf("%i ", filesystem.nodes[filesystem.fs[i].nodloc].size);
	//name
	printf("%s", filesystem.fs[i].name);
}
