int mkdir(int argc, char *argv[]){ 
	if(argc!=2){ 
		printToConsole("Error: Wrong number of arguments!\n");
		return 1;
	}
	int filenum = getfilenum(argv[1]);
	if(filenum>=0){
		printToConsole("Error: There is already a file called ");
		printToConsole(argv[1]);
		printCharToConsole('\n');
		return 1;
	}
	createdir(argv[1]);

	return 0;
}

int rmdir(int argc, char *argv[]){ 

	return 0;
}

int cd(int argc, char *argv[]){ 
	if(argc!=2){ 
		printToConsole("Error: Wrong number of arguments!\n");
		return 1;
	}
	int filenum = getfilenum(argv[1]);
	if(filenum<0 || filesystem.nodes[filesystem.fs[filenum].nodloc].mode<1000){ 
		printToConsole("Error: No such folder!\n");
		return 1;
	}
	dir = filenum;
	
	return 0;
}
void printAllDir(int thecd);
int pwd(int argc, char *argv[]){ 
	int thecd = dir;
	printAllDir(thecd);
	printCharToConsole('\n');
	return 0;
}

void printAllDir(int thecd){
	if(thecd == 0) printCharToConsole('/');
	else {
		printAllDir(filesystem.nodes[filesystem.fs[thecd].nodloc].directblocks[1]); 
		printToConsole(filesystem.fs[thecd].name); 
	}
}
