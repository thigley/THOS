/* history.c */

static char histBuffer[BUFFERSIZE][15];
static int histpeak = 15;

void addToHistory(char* next){
	topHistory();
	if(k_strlen(next)==0) return;
	int i, j;
	j=0;
	while(j<BUFFERSIZE){
		if(histBuffer[j][14]!=next[j]) break;
		if(next[j]== 0 || j==BUFFERSIZE-1) return;
		j++;
	}

	for(i=0; i<14; i++){
		for(j=0; j<BUFFERSIZE;j++){
			histBuffer[j][i]=histBuffer[j][i+1];
		}
	}
	i=0;
	while(i<BUFFERSIZE) {histBuffer[i][14]=0; i++;}
	i=0;
	while(next[i]!=0) {histBuffer[i][14]=next[i]; i++;}

}

void printHistory(){
	int i,j;
	i=0;
	while(histBuffer[0][i]==0) i++;
	for(i;i<15;i++) {
		for(j=0;j<BUFFERSIZE;j++) {
			printCharToConsole(histBuffer[j][i]);
		}
		printCharToConsole('\n');
	}
}

void lookupHistory(){
	if(histpeak>0) histpeak--;
	if(histBuffer[0][histpeak]==0){histpeak++;return;}
	int i;
	for(i=0;i<BUFFERSIZE;i++){
		textBuffer[i]=histBuffer[i][histpeak];
	}
}

void lookdownHistory(){
	if(histpeak<15) histpeak++;
	if(histpeak==15) {memset(textBuffer, 0, BUFFERSIZE);return;}
	int i;
	for(i=0;i<BUFFERSIZE;i++){
		textBuffer[i]=histBuffer[i][histpeak];
	}
}

void topHistory(){
	histpeak = 15;
}
