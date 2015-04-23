/* terminal.c */
#include "textbuffer.c"
int user = 0;

void scroll(){
	int i,j;
	for(i=0; i<(VGA_H-1); i++){
		for(j=0; j<VGA_W*2; j++){
			vidptr[(i*VGA_W*2+j)] = vidptr[VGA_W*2+(i*VGA_W*2+j)];
		}
	}
	for(i =0; i<VGA_W; i++){
		vidptr[2*VGA_W*(VGA_H-1)+i*2] = ' ';
	}
}

void typePrompt(){
	textColor = WHITE;
	print(filesystem.users[user]);
	textColor = LIGHTRED;
	print("@THOS:");
	textColor = WHITE;
	print("/$ ");
	textColor = LIGHTGRAY;
}

void printCharToConsole(char c){
	printchar(c);
	if(((typeOffset/2)/VGA_W)==VGA_H){ 
		scroll();
		typeOffset = typeOffset-VGA_W*2;
	}
	updateCursor(typeOffset/2);
}

void printIntToConsole(int i){
	printint(i);
	if(((typeOffset/2)/VGA_W)==VGA_H){ 
		scroll();
		typeOffset = typeOffset-VGA_W*2;
	}
	updateCursor(typeOffset/2);
}

void printToConsole(char *s){
	while(*s!=0) {
		printCharToConsole(*s);
	s++;}
}
void clearLine(){
	int oldpos = typeOffset;
	do{
		printchar(' ');
	}while(typeOffset/2%VGA_W!=0);
	typeOffset = oldpos;
}

void readCommand(){
	clearBuffer();
	int pos = 0, line=((typeOffset/2)/VGA_W); //%VGA_H;
	clearLine();
	updateCursor(typeOffset/2);
	key next;
	while(1){
		if(key_queue_is_empty()) continue;
		next = remove_key();
		/*printint(next.scancode);
		print(" ");
		continue;*/
		if(next.scancode==75 && pos>0){pos--;}			//left arrow
		if(next.scancode==77 && pos<bufferLength()-1){pos++;}	//right arrow
		if(next.scancode==72) {
			lookupHistory();
			pos=k_strlen(textBuffer);
		}//up arrow
		if(next.scancode==80) {
			lookdownHistory();
			pos=k_strlen(textBuffer);
		}//down arrow
		if(next.key=='\n') {
			if(typeOffset>(VGA_H-1)*VGA_W*2) {scroll();typeOffset-=2*VGA_W;}
			typeOffset=(typeOffset+VGA_W*2)-(typeOffset/2)%VGA_W*2;
			return;
		}else if(next.key=='\b') {if(pos==0) continue; else charFromBuffer(pos--);}
		else if(next.key!=0) {if(pos>(BUFFERSIZE)/2-4) continue; else charToBuffer(next.key, pos++);}

		if(line==VGA_H-1 && bufferLength()>=VGA_W){scroll();line--;}
		typeOffset = line*VGA_W*2;
		typePrompt();
		int save = typeOffset;
		print(textBuffer);
		clearLine();
		typeOffset = save+pos*2;
		updateCursor(typeOffset/2);
	}
}

void splash(){
	textColor = LIGHTRED;
	printToConsole(spashscreen);
	textColor = LIGHTGRAY;
}

void welcome(){
	textColor = WHITE;
	printToConsole("Welcome to ");
	textColor = LIGHTRED;
	printToConsole("THOS");
	textColor = WHITE;
	printToConsole("! (THOS Has Occasional Success)\nTyler Higley's Operating System ");
	textColor = LIGHTRED;
	printToConsole("(Version 0.4)");
	textColor = LIGHTGRAY;
	printToConsole("\n");
}

void listCommands(){
	textColor = LIGHTGRAY;
	printToConsole("\tls \t\t\t\t\t\t- list all files\n");
	printToConsole("\tcat [file] \t\t\t\t- view contents of that file\n");
	printToConsole("\trm [file] \t\t\t\t- remove file with name\n");
	printToConsole("\tchmod [mode] [file] \t- change file permissions\n");
	printToConsole("\tte [file] \t\t\t\t- create or edit file with name\n");
	printToConsole("\twc [file] \t\t\t\t- reports lines, words, and characters of a file\n");
	printToConsole("\thistory \t\t\t\t- display previous 15 commands\n");
	printToConsole("\tsu [user] \t\t\t\t- switch current user\n");
	printToConsole("\tchown [user] [file]\t\t- change owner of a file\n");
	printToConsole("\tadduser [user]\t\t\t- add new user\n");
	printToConsole("\tdeluser [user]\t\t\t- remove user\n");
	printToConsole("\techo [word]...\t\t\t- print text to screen\n");
	/*
	printToConsole("\tcp [file] [new file]\t- make a copy of a file\n");
	printToConsole("\tdiff [file 1] [file 2]\t- compare two files\n");
	printToConsole("\tpasswd\t\t\t\t\t- change password for current user\n");
	*/

}

char *argv[10];
int runCommand(){
	int i = 0;
	int argc = splitString(textBuffer, ' ');
	for(i =0;i<argc;i++){argv[i]=stringArray[i];}
	
	if(k_strcmp(argv[0], "")==0){}
	else if(k_strcmp(argv[0], "clear")==0){ clearScreen(); typeOffset = 0;}
	else if(k_strcmp(argv[0], "history")==0){ printHistory();}
	else if(k_strcmp(argv[0], "pong")==0){ pong();}
	else if(k_strcmp(argv[0], "help")==0){ listCommands();}
	else if(k_strcmp(argv[0], "welcome")==0){ welcome();}
	else if(k_strcmp(argv[0], "splash")==0){ splash();}
	else if(k_strcmp(argv[0], "ls")==0){ ls(argc, argv); }
	else if(k_strcmp(argv[0], "cat")==0){ cat(argc, argv); }
	else if(k_strcmp(argv[0], "rm")==0){ rm(argc, argv); }
	else if(k_strcmp(argv[0], "chmod")==0){ chmod(argc, argv); }
	else if(k_strcmp(argv[0], "te")==0){ te(argc, argv); }
	else if(k_strcmp(argv[0], "cp")==0){ cp(argc, argv); }
	else if(k_strcmp(argv[0], "diff")==0){ diff(argc, argv); }
	else if(k_strcmp(argv[0], "wc")==0){ wc(argc, argv); }
	else if(k_strcmp(argv[0], "su")==0){ su(argc, argv); }
	else if(k_strcmp(argv[0], "chown")==0){ chown(argc, argv); }
	else if(k_strcmp(argv[0], "echo")==0){ echo(argc, argv); }
	else if(k_strcmp(argv[0], "adduser")==0){ adduser(argc, argv); }
	else if(k_strcmp(argv[0], "deluser")==0){ deluser(argc, argv); }
	else if(k_strcmp(argv[0], "passwd")==0){ passwd(argc, argv); }
	// else check files
	else {
		printToConsole("Error: Unknown command '");
		printToConsole(argv[0]);
		printToConsole("'\n");
	}

	return 0;
}

void shell(){
	clearScreen();
	splash();
	welcome();
	while(1){
		typePrompt();
		readCommand();
		addToHistory(textBuffer);
		runCommand();
	}
}

