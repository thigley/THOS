int addusercurrentnum = 0;
int adduser(int argc, char *argv[]){
	if(argc!=2){ 
		printToConsole("Error: Wrong number of arguments!\n");
		return 1;
	}

	if(addusercurrentnum==5){
		printToConsole("Too many users!\n");
		return 1;
	}
	int j;
	for(j=0;k_strlen(argv[1]);j++){
		if(j==16) break;
		filesystem.users[addusercurrentnum][j] = argv[1][j];
	}
	addusercurrentnum++;
	printToConsole(filesystem.users[0]);
	printToConsole("\n");
	printToConsole(filesystem.users[1]);
	printToConsole("\n");
	printToConsole(filesystem.users[2]);
	printToConsole("\n");
	printToConsole(filesystem.users[3]);
	printToConsole("\n");
	printToConsole(filesystem.users[4]);
	printToConsole("\n");
	return 0;
}

int deluser(int argc, char *argv[]){
	if(argc!=2){ 
		printToConsole("Error: Wrong number of arguments!\n");
		return 1;
	}

	int uservar = getusernum(argv[1]);
	
	if(uservar==-1){
		printToConsole("Error: No such user!\n");
		return 1;
	}
	if(uservar==0){
		printToConsole("Error: Can't remove root!\n");
		return 1;
	}
	int j,i;
	
	for(j=uservar+1;j<5;j++){
		for(i=0;i<16;i++){
			filesystem.users[j-1][i] = filesystem.users[j][i];
		}
	}
	for(j=0;j<16;j++){
		filesystem.users[4][j] = 0;
	}
	addusercurrentnum--;
	printToConsole(filesystem.users[0]);
	printToConsole("\n");
	printToConsole(filesystem.users[1]);
	printToConsole("\n");
	printToConsole(filesystem.users[2]);
	printToConsole("\n");
	printToConsole(filesystem.users[3]);
	printToConsole("\n");
	printToConsole(filesystem.users[4]);
	printToConsole("\n");
}
