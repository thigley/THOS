/* chmod.c */

int chmod(int argc, char *argv[]){
	if(argc!=3){ 
		printToConsole("Error: Wrong number of arguments!\n");
		return 1;
	}

	unsigned short numod = 0;
	int i;
	for(i=k_strlen(argv[1])-3;i<k_strlen(argv[1]);i++){
		numod*=10;
		if(argv[1][i]=='7') numod+=7;
		if(argv[1][i]=='6') numod+=6;
		if(argv[1][i]=='5') numod+=5;
		if(argv[1][i]=='4') numod+=4;
		if(argv[1][i]=='3') numod+=3;
		if(argv[1][i]=='2') numod+=2;
		if(argv[1][i]=='1') numod+=1;
	}
	if(numod==0){
		printToConsole("Error: New mode is unuseable!\n");
	 	return 1;
	}

	int filenum = getfilenum(argv[2], dir);
	if(filenum<0){
		printToConsole("Error: File not found!\n");
	 	return 1;
	}
	if(user && user!=filesystem.nodes[filesystem.fs[filenum].nodloc].uid){printToConsole("You do not have permission!\n"); return 1;}

	fs_chmod(numod, filenum);
	return 0;
}
