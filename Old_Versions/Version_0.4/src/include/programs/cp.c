int cp(int argc, char *argv[]){
	if(argc!=3){ 
		printToConsole("Error: Wrong number of arguments!\n");
		return 1;
	}

	int filenum = getfilenum(argv[1]);
	if(filenum<0){printToConsole("Error: No such file!\n"); return 1;}

	
	return 0;
}
