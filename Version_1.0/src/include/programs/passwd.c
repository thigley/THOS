int passwd(int argc, char *argv[]){ 
	if(argc>2){ 
		printToConsole("Error: Wrong number of arguments!\n");
		return 1;
	}
	
	int useredit = argc==1?user:getusernum(argv[1]);
	
	char input[32];
	int i;

	if(argc==2){
		printToConsole("Old Password:  \b");
		for(i=0;i<32;i++) input[i]=0;
		i=0;
		while(i<32) {
			if(!key_queue_is_empty()){
				char next = remove_key().key;
				if(next=='\n') break;
				else if(next=='\b'){
					if(i>0) input[--i]=0;
				}
				else if(next==0) continue;
				else input[i++]=next;
			}
		}printCharToConsole('\n');
		if(k_strcmp(input, filesystem.users[useredit].passwd)){
			printToConsole("Incorrect Password!\n");
			return 1;
		}
	}
	printToConsole("New Password:  \b");
	for(i=0;i<32;i++) input[i]=0;
	i=0;
	while(i<32) {
		if(!key_queue_is_empty()){
			char next = remove_key().key;
			if(next=='\n') break;
			else if(next=='\b'){
				if(i>0) input[--i]=0;
			}
			else if(next==0) continue;
			else input[i++]=next;
		}
	}printCharToConsole('\n');

	for(i=0;i<k_strlen(input);i++){
		filesystem.users[useredit].passwd[i]=input[i];
	}
	while(i<32){
		filesystem.users[useredit].passwd[i++]=0;
	}

	 
	return 0;
}
