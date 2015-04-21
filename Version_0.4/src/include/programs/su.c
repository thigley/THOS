int su(int argc, char *argv[]){ 
	if(argc!=2){ 
		printToConsole("Error: Wrong number of arguments!\n");
		return 1;
	}

	int uservar = getusernum(argv[1]);
	
	if(uservar==-1){
		printToConsole("Error: No such user!\n");
		return 1;
	}

	user = uservar;
	

	return 0;
}
