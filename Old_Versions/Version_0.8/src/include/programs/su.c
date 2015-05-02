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

	printToConsole("Password:  \b");
	char input[32];
	int i;
	for(i=0;i<32;i++) input[i]=0;
	i=0;
	while(i<32) {
		if(!key_queue_is_empty()){
			char next = remove_key().key;
			if(next=='\n') break;
			else if(next=='\b'){
				input[--i]=0;
			}
			else if(next==0) continue;
			else input[i++]=next;
		}
	}
	printCharToConsole('\n');
	if(!k_strcmp(input,filesystem.users[uservar].passwd)) user = uservar;
	else {printToConsole("Incorrect Password!\n");}

	return 0;
}
