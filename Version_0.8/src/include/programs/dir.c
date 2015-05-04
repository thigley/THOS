int mkdir(int argc, char *argv[]){ 
	if(argc!=2){ 
		printToConsole("Error: Wrong number of arguments!\n");
		return 1;
	}
	int filenum = getfilenum(argv[1], dir);
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
	if(argc!=2){ 
		printToConsole("Error: Wrong number of arguments!\n");
		return 1;
	}
	int filenum = getfilenum(argv[1],dir);
	if(filenum<0 || filesystem.nodes[filesystem.fs[filenum].nodloc].mode<1000){ 
		printToConsole("Error: No such folder!\n");
		return 1;
	}

	if(filesystem.nodes[filesystem.fs[filenum].nodloc].size>2){ 
		printToConsole("Error: Folder has contents!\n");
		return 1;
	}
	rmfile(filenum);
	return 0;
}

int cd(int argc, char *argv[]){ 
	if(argc!=2){ 
		printToConsole("Error: Wrong number of arguments!\n");
		return 1;
	}
	int filenum = getfilenum(argv[1],dir);
	if(k_strcmp(argv[1], "..")==0) filenum = filesystem.nodes[filesystem.fs[dir].nodloc].directblocks[1];
	else if(k_strcmp(argv[1], ".")==0) filenum = filesystem.nodes[filesystem.fs[dir].nodloc].directblocks[0];
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
	if(dir==0) printCharToConsole('/');
	printToConsole("\n");
	return 0;
}

void printAllDir(int thecd){
	if(thecd != 0) {
		printAllDir(filesystem.nodes[filesystem.fs[thecd].nodloc].directblocks[1]);
		printCharToConsole('/');
		printToConsole(filesystem.fs[thecd].name); 
	}
}

int mv(int argc, char *argv[]){
	if(argc!=3){ 
		printToConsole("Error: Wrong number of arguments!\n");
		return 1;
	}
	int filenum = getfilenum(argv[1],dir);
	int dirnum = getfilenum(argv[2],dir);
	if(k_strcmp(argv[2], "..")==0) dirnum = filesystem.nodes[filesystem.fs[dir].nodloc].directblocks[1];
	else if(k_strcmp(argv[2], ".")==0) dirnum = filesystem.nodes[filesystem.fs[dir].nodloc].directblocks[0];
	if(dirnum<0 || filesystem.nodes[filesystem.fs[dirnum].nodloc].mode<1000){ 
		printToConsole("Error: No such folder!\n");
		return 1;
	}
	if(filenum<0){ 
		printToConsole("Error: No such file!\n");
		return 1;
	}
	removefromfolder(filenum);
	addFileToDir(filenum, dirnum);
	return 0;
}
