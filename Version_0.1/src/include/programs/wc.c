int wc(int argc, char *argv[]){
	if(argc!=2){ 
		printToConsole("Error: Wrong number of arguments!\n");
		return 1;
	}
 	
	//get file num
	char *name = argv[1];
	int i;
	int filenum = getfilenum(name);
	if(filenum<0){printToConsole("Error: No such file!\n"); return 1;}

	int length = filesystem.nodes[filesystem.fs[filenum].nodloc].size;
	int db = 0;
	int pos = 0;
	
	int lines =1;
	int words = 0;
	int bytes =length;
	int inword =0;
	for(i=0; i<length; i++){
		int nodenum = filesystem.fs[filenum].nodloc;
		int blocknum = filesystem.nodes[nodenum].directblocks[db];
		char next = filesystem.blocks[blocknum].data[pos++];
		if(next=='\n') lines++;
		else if(next==' ') inword=0;
		else if(!inword) {inword=1; words++;}
		if(pos==512) {pos=0;db++;}
	}
	printIntToConsole(lines);
	printCharToConsole('\t');
	printIntToConsole(words);
	printCharToConsole('\t');
	printIntToConsole(bytes);
	printCharToConsole('\n');

	return 0;
}
