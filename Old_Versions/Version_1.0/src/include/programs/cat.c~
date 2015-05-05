int cat(int argc, char *argv[]){
	if(argc!=2){ 
		printToConsole("Error: Wrong number of arguments!\n");
		return 1;
	}
 	
	//get file num
	char *name = argv[1];
	int i;
	int filenum = getfilenum(name);
	if(filenum<0){printToConsole("Error: No such file!\n"); return 1;}
	if(user && !(checkperm(filenum)&4)){printToConsole("You do not have permission!\n"); return 1;}

	int length = filesystem.nodes[filesystem.fs[filenum].nodloc].size;
	int db = 0;
	int pos = 0;
	
	for(i=0; i<length; i++){
		int nodenum = filesystem.fs[filenum].nodloc;
		int blocknum = filesystem.nodes[nodenum].directblocks[db];
		printCharToConsole(filesystem.blocks[blocknum].data[pos++]);
		if(pos==512) {pos=0;db++;}
	}
 	printToConsole("\n");
	return 0;
}
