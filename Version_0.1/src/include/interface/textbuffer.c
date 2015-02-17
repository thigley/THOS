/* textbuffer.c */

#define BUFFERSIZE VGA_W*4
char textBuffer[BUFFERSIZE];

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
