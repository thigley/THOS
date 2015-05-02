int chown(int argc, char *argv[]){ 
	if(argc!=3){ 
		printToConsole("Error: Wrong number of arguments!\n");
		return 1;
	}
	int nuuse = getusernum(argv[1]);
	int filenum = getfilenum(argv[2]);
	if(filenum<0){
		printToConsole("Error: File not found!\n");
	 	return 1;
	}
	if(user && user!=filesystem.nodes[filesystem.fs[filenum].nodloc].uid){printToConsole("You do not have permission!\n"); return 1;}
	if(nuuse<0){
		printToConsole("Error: User not found!\n");
	 	return 1;
	}

	fs_chown(nuuse, filenum);


	 return 0;
}
