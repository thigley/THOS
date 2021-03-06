/* adduser.c 
adduser, deluser, and listus (list users) */

int addusercurrentnum = 0;
int adduser(int argc, char *argv[]){
	if(argc!=2){ 
		printToConsole("Error: Wrong number of arguments!\n");
		return 1;
	}

	if(addusercurrentnum==NUM_OF_USERS){
		printToConsole("Too many users!\n");
		return 1;
	}
	int j;
	for(j=0;k_strlen(argv[1]);j++){
		if(j==32) break;
		filesystem.users[addusercurrentnum].name[j] = argv[1][j];
	}
	addusercurrentnum++;

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
	
	for(j=uservar+1;j<NUM_OF_USERS;j++){
		for(i=0;i<32;i++){
			filesystem.users[j-1].name[i] = filesystem.users[j].name[i];
		}
	}
	for(j=0;j<32;j++){
		filesystem.users[NUM_OF_USERS-1].name[j] = 0;
	}
	addusercurrentnum--;
}

int listus(){
	int i;
	for(i=0;i<NUM_OF_USERS;i++){
		if(!filesystem.users[i].name[0]) break;
		printToConsole(filesystem.users[i].name);
		printToConsole("\n");
	}
	return 0;
}
