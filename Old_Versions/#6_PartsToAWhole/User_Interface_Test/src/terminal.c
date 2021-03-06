#define W 80
#define H 25
#define BUFFERSIZE W*4

char *vidptr = (char*) 0xb8000; //location of video memory
int typeOffset = 0;
int background = BLACK;
int textColor = WHITE;
char textBuffer[BUFFERSIZE];
char command[10];

int colors(){
	return (background<<4)+textColor;
}

void clearBuffer(){
	int i;
	for(i=0; i<BUFFERSIZE; i++){
		textBuffer[i] = 0;
	}
}

int bufferLength(){
	int ret = 0;
	while(textBuffer[ret++]!=0);
	return ret;
}

void scroll(){
	int i,j;
	for(i=0; i<(H-1); i++){
		for(j=0; j<W*2; j++){
			vidptr[(i*W*2+j)] = vidptr[W*2+(i*W*2+j)];
		}
	}
	for(i =0; i<W; i++){
		vidptr[2*W*(H-1)+i*2] = ' ';
	}
}

void setBackground(int back){
	background = back;
}

void setTextColor(int col){
	textColor = col;
}

void updateCursor(int row, int col){
	unsigned short position = row*80+col;
	outportb(0x3d4, 0x0f);
	outportb(0x3d5, position&0xff);
	outportb(0x3d4, 0x0e);
	outportb(0x3d5, (position>>8)&0xff);
}

void clearScreen(){
	unsigned int j = 0;
	while(j<W*H*2){
		vidptr[j++]= ' ';
		vidptr[j++]=colors();
	}
	typeOffset = 0;
}

void printnewline(){
	do {
		vidptr[typeOffset++]= ' ';
		vidptr[typeOffset++]=colors();
	} while(typeOffset%(W*2)!=0);
}

void printchar(char x){
	if(x==0){ return;
	}else if(x=='\b'){
		typeOffset-=2;
		vidptr[typeOffset] = ' ';
		return;
	}else if(x=='\n'){
		printnewline();
		return;
	}else if(x=='\t'){
		typeOffset+=8;
		return;
	}

	vidptr[typeOffset++] = x;
	vidptr[typeOffset++] = colors();
	updateCursor(((typeOffset/2)/W)%H,(typeOffset/2)%W);
}
void print(char* str){
	while(*str!='\0'){
		printchar(*str);
		*str++;
	}

}
void println(char* str){
	print(str);
	printnewline();
}

void printhex(int input){
	char* output = "0x0000";
	output+=5;
	int i;
        for(i = 1; i < 4; i++){
                *output = '0'+ input%16;
		if(*output>'9'){
			*output-='0';
			*output%=10;
			*output+='A';
		}
                input/=16;
                output--;
        }
        output-=2;
        print(output);
}

void printint(int input){
	int neg = input<0?1:0;
	input = input<0?-input:input;

	
	char* output = "000000000";
	output+=8;
	int i;
	for(i = 0; i < 8; i++){
		*output = '0'+ input%10;
		input/=10;
		output--;
	}
	while(*output=='0'&&--i>=0){
		output++;
	}
	if(neg){
		--output;
		*output = '-';
	}
	print(output);
}

void charToBuffer(char c, int pos){
	char next = c, after = textBuffer[pos];

	while(next!=0){
		textBuffer[pos++] = next;
		next = after;
		after = textBuffer[pos];
	}
}
void charFromBuffer(int pos){
	char next = textBuffer[pos];

	while(next!=0){
		textBuffer[pos-1] = next;
		next = textBuffer[pos++];
	}
	textBuffer[pos-1] = next;
}

void typePrompt(){
	print("$ ");
}

void readCommand(){
	clearBuffer();
	int pos = 0, line=((typeOffset/2)/W)%H;
	while(1){
		if(!newInput()) continue;
		char next = getchar();
		if(next=='\n') {
			if(typeOffset>(H-1)*W*2) {scroll();typeOffset-=2*W;}
			typeOffset=(typeOffset+W*2)-(typeOffset/2)%W*2;
			return;
		}else if(next=='\b') {if(pos==0) continue; else charFromBuffer(pos--);}
		else if(next!=0) {if(pos>(BUFFERSIZE)/2-4) continue; else charToBuffer(next, pos++);}

		if(line==H-1 && bufferLength()>=W){scroll();line--;}
		typeOffset = line*W*2;
		typePrompt();
		print(textBuffer);
		int oldpos = typeOffset;
		do{
			printchar(' ');
		}while(typeOffset/2%W!=0);
		typeOffset = oldpos;
		updateCursor(((typeOffset/2)/W)%H,(typeOffset/2)%W);
	}
}

void welcome(){
	setTextColor(WHITE);
	println("Welcome to THOS! (THOS Has Occasional Success)");
	print("An Operating System by Tyler Higley ");
	setTextColor(RED);
	println("(Features coming soon)");
	setTextColor(LIGHTGRAY);
	updateCursor(((typeOffset/2)/W)%H,(typeOffset/2)%W);
}

int checkBuiltin(){
	copystrto(textBuffer, command);
	replacefirst(command,' ',0);
	if(strcmp(command, "clear")==0){
		clearScreen();
		return 1;
	}else if(strcmp(command, "welcome")==0){
		welcome();
		return 1;
	}

	return 0;
}

void shell(){
	clearScreen();
	welcome();
	while(1){
		typePrompt();
		readCommand();
		//addToHistory(line);
		checkBuiltin();
		// do stuff
	}
}

