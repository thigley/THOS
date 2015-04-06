//it should be noted that files are restricted to the size of the screen.

static void setupte(int filenum);
static void load(int filenum);
static void editfile(char *filename);
static void printbuffer();
static void typeTeBottom();

char console_save[VGA_W*VGA_H*2];
char file_buffer[VGA_W*VGA_H];
char *te_bottom="q - quit    w - write    e - edit                                               ";

int te(int argc, char *argv[]){ 
	if(argc!=2){ 
		printToConsole("Error: Wrong number of arguments!\n");
		return 1;
	}
	int saveoff = typeOffset;

	// save console
	int i;
	for(i = 0; i<VGA_W*VGA_H*2; i++){
		console_save[i]=vidptr[i];
	}
	
	// find file
	int filenum = getfilenum(argv[1]);

	// allow for editing
	setupte(filenum);
	editfile(argv[1]);

	// replace console
	for(i = 0; i<VGA_W*VGA_H*2; i++){
		vidptr[i]=console_save[i];
	}
	typeOffset = saveoff;
	return 0;
}

static void setupte(int filenum){
	int newfile = filenum<0?1:0;
	int i;
	for(i=0;i<VGA_W*VGA_H;i++) file_buffer[i]= 0;

	clearScreen();
	if(filenum>=0){load(filenum);}
	typeOffset=0;
	updateCursor(typeOffset);
	

}

static void load(int filenum){
	int i;
	int db = 0;
	int pos = 0;
	for(i=0; i<VGA_W*VGA_H; i++){
		int nodenum = filesystem.fs[filenum].nodloc;
		int blocknum = filesystem.nodes[nodenum].directblocks[db];
		file_buffer[i]= filesystem.blocks[blocknum].data[pos++];
		if(pos==512) {pos=0;db++;}
	}
}

static void editfile(char *filename){
	int mode = 0; //1 edit mode
	printbuffer();
	int location = k_strlen(file_buffer);
	typeTeBottom();
	while(1){
		if(mode){
			if(!newInput()) continue;
			char next = getchar();
			if(next==27) { mode =0;
				typeTeBottom();
				continue;
			}
			if(next==0) continue;
			if(next!='\b') file_buffer[location++]=next;
			else file_buffer[--location]=0;
			clearScreen();
			printbuffer();
		} else{
			if(!newInput()) continue;
			char next = getchar();
			if(next=='q') break;
			else if(next=='w') createorreplacefile(filename, file_buffer);
			else if(next=='e') { mode = 1; clearScreen(); printbuffer();}
		}
	}
}

static void printbuffer(){
	int i;
	typeOffset = 0;
	for(i=0; i<VGA_W*VGA_H; i++){
		if(file_buffer[i]==0) break;
		printchar(file_buffer[i]);
	}
}

static void typeTeBottom(){
	int stype = typeOffset;
	typeOffset = 2*VGA_W*(VGA_H-1);
	background = WHITE;
	textColor = BLACK;
	print(te_bottom);
	textColor = LIGHTGRAY;
	background = BLACK;
	typeOffset = stype;
}

