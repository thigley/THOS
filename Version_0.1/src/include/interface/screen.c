/* screen.c */

char *vidptr = (char*) 0xb8000; //location of video memory
int typeOffset = 0;

void clearScreen(){
	unsigned int j = 0;
	while(j<VGA_W*VGA_H*2){
		vidptr[j++]= ' ';
		vidptr[j++]=colors();
	}
}

void updateCursor(int offset){
	unsigned short position = offset;
	outportb(0x3d4, 0x0f);
	outportb(0x3d5, position&0xff);
	outportb(0x3d4, 0x0e);
	outportb(0x3d5, (position>>8)&0xff);
}

void printnewline(){
	do {
		vidptr[typeOffset++]= ' ';
		vidptr[typeOffset++]=colors();
	} while(typeOffset%(VGA_W*2)!=0);
}

void printchar(char x){
	if(x==0){ return;
	}else if(x=='\b'){
		typeOffset-=2;
		vidptr[typeOffset] = ' ';
		updateCursor(typeOffset/2);
		return;
	}else if(x=='\n'){
		printnewline();
		updateCursor(typeOffset/2);
		return;
	}else if(x=='\t'){
		while(++typeOffset%8);
		updateCursor(typeOffset/2);
		return;
	}

	vidptr[typeOffset++] = x;
	vidptr[typeOffset++] = colors();
	updateCursor(typeOffset/2);
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

