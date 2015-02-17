/* terminal.c */

#include "textbuffer.c"


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
	print("$ ");
}

void printToConsole(char *s){
	print(s);
	if(((typeOffset/2)/VGA_W)==VGA_H){ scroll();
	typeOffset = typeOffset-VGA_W*2;}
}

void readCommand(){
	clearBuffer();
	int pos = 0, line=((typeOffset/2)/VGA_W);//%VGA_H;
	while(1){
		if(!newInput()) continue;
		char next = getchar();
		if(next=='\n') {
			if(typeOffset>(VGA_H-1)*VGA_W*2) {scroll();typeOffset-=2*VGA_W;}
			typeOffset=(typeOffset+VGA_W*2)-(typeOffset/2)%VGA_W*2;
			return;
		}else if(next=='\b') {if(pos==0) continue; else charFromBuffer(pos--);}
		else if(next!=0) {if(pos>(BUFFERSIZE)/2-4) continue; else charToBuffer(next, pos++);}

		if(line==VGA_H-1 && bufferLength()>=VGA_W){scroll();line--;}
		typeOffset = line*VGA_W*2;
		typePrompt();
		print(textBuffer);
		int oldpos = typeOffset;
		do{
			printchar(' ');
		}while(typeOffset/2%VGA_W!=0);
		typeOffset = oldpos;
		updateCursor(typeOffset/2);
	}
}

void welcome(){
	textColor = WHITE;
	println("Welcome to THOS! (THOS Has Occasional Success)");
	print("An Operating System by Tyler Higley ");
	textColor = RED;
	println("(Features coming soon)");
	textColor = LIGHTGRAY;
	updateCursor(typeOffset/2);
}
char command[10];
int argc; char *argv[0];
int runCommand(){
	int i = 0;
	while(textBuffer[i]!=' ') { command[i]=textBuffer[i]; i++; }
	
	if(k_strcmp(command, "clear")==0){
		clearScreen();
		typeOffset = 0;
		return 1;
	}else if(k_strcmp(command, "ls")==0){ ls(argc, argv); }
	else if(k_strcmp(command, "cat")==0){ cat(argc, argv); }
	else if(k_strcmp(command, "rm")==0){ rm(argc, argv); }
	else if(k_strcmp(command, "chmod")==0){ chmod(argc, argv); }
	else if(k_strcmp(command, "te")==0){ te(argc, argv); }
	else if(k_strcmp(command, "cp")==0){ cp(argc, argv); }
	else if(k_strcmp(command, "diff")==0){ diff(argc, argv); }
	else if(k_strcmp(command, "wc")==0){ wc(argc, argv); }
	// else check file
	else {
		printToConsole("Unknown command '");
		printToConsole(command);
		printToConsole("'\n");
	}

	return 0;
}

void shell(){
	clearScreen();
	print(spashscreen);
	welcome();
	while(1){
		typePrompt();
		readCommand();
		//addToHistory(line);
		runCommand();
	}
}

