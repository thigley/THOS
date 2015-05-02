int su(int argc, char *argv[]){ 
	if(argc!=2){ 
		printToConsole("Error: Wrong number of arguments!\n");
		return 1;
	}

	int uservar = -1;
	int i,j;
	for(i=0; i<4;i++){ 
		j=0;
		while(filesystem.users[i][j]!=0){
			if(filesystem.users[i][j]!=argv[1][j]) goto next;
			j++;
		}
		uservar = i;
		break;
		next:;
	}
	
	if(uservar==-1){
		printToConsole("Error: No such user!\n");
		return 1;
	}

	user = uservar;
	

	return 0;
}
