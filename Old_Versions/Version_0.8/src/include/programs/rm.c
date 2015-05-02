int rm(int argc, char *argv[]){
	if(argc!=2){ 
		printToConsole("Error: Wrong number of arguments!\n");
		return 1;
	}
 	
	//get file num
	char *name = argv[1];
	int i;
	int filenum = getfilenum(name);
	if(filenum<0){printToConsole("Error: No such file!\n"); return 1;}
	if(user && !(checkperm(filenum)&2)){printToConsole("You do not have permission!\n"); return 1;}
	rmfile(filenum);

	return 0;
}

