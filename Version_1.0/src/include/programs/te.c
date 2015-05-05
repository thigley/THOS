//it should be noted that files are restricted to the size of the screen.

static void setupte(int filenum);
static void load(int filenum);
static void editfile(char *filename, int canEdit);
static void printbuffer();
static void typeTeBottom();
static int fileBufferLength();
static void addToFileBuff(char c, int pos);
static void removeFromFileBuff(int pos);
static int getScreenPos(int loc);

char console_save[VGA_W*VGA_H*2];
char file_buffer[VGA_W*VGA_H];
char *te_bottom= 0;
char *te_bottom_write="q - quit    w - write    e - edit                                               ";
char *te_bottom_read="q - quit    w - write    e - edit    (READ ONLY)                                ";

int te(int argc, char *argv[]){ 
	if(argc!=2){ 
		printToConsole("Error: Wrong number of arguments!\n");
		return 1;
	}
	int saveoff = typeOffset;
	
	// find file
	int filenum = getfilenum(argv[1], dir);
	if(user && !(checkperm(filenum)&4)){printToConsole("You do not have permission!\n"); return 1;}
	int canEdit = (filenum<0 || (checkperm(filenum)&2))?1:0;
	te_bottom= canEdit?te_bottom_write:te_bottom_read;
	// save console
	int i;
	for(i = 0; i<VGA_W*VGA_H*2; i++){
		console_save[i]=vidptr[i];
	}

	// allow for editing
	setupte(filenum);
	editfile(argv[1], canEdit);

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

static void editfile(char *filename, int canEdit){
	int mode = 0; //1 edit mode
	printbuffer();
	int location = k_strlen(file_buffer);
	typeOffset =(location+1)*2;
	updateCursor(typeOffset/2);
	typeTeBottom();
	key next;
	while(1){
		if(key_queue_is_empty()) continue;
		next = remove_key();
		if(mode){
			if(next.scancode==75 && location>0){
				location--;
				typeOffset =2*getScreenPos(location);
				updateCursor(typeOffset/2);}//left arrow
			if(next.scancode==77 && location<fileBufferLength()-1){
				location++;
				typeOffset =2*getScreenPos(location);
				updateCursor(typeOffset/2);}//right arrow
			if(next.scancode==72 && getScreenPos(location)>VGA_W){
				int desired = getScreenPos(location)-VGA_W;
				while(getScreenPos(location)>desired) location--;
				typeOffset =2*getScreenPos(location);
				updateCursor(typeOffset/2);}//up arrow
			if(next.scancode==80 && 
			getScreenPos(location)/VGA_W<getScreenPos(fileBufferLength())/VGA_W){
				int desired = getScreenPos(location)+VGA_W;
				while(getScreenPos(location)<desired &&
					location<fileBufferLength()-1) location++;
				if(getScreenPos(location)>desired) location--;
				typeOffset =2*getScreenPos(location);
				updateCursor(typeOffset/2);}//down arrow
			if(next.key==27) { mode =0;
				typeTeBottom();
				continue;
			}
			if(next.key==0) continue;
			if(next.key!='\b') addToFileBuff(next.key, location++);//file_buffer[location++]=next.key;
			else removeFromFileBuff(location--);//file_buffer[--location]=0;
			clearScreen();
			printbuffer();
			typeOffset = 2*getScreenPos(location);
			updateCursor(typeOffset/2);
		} else{
			if(next.key=='q') break;
			else if(next.key=='w') { if(canEdit) createorreplacefile(filename, file_buffer);}
			else if(next.key=='e') { mode = 1; clearScreen(); printbuffer();}
		}
	}
}

static int fileBufferLength(){
	int ret = 0;
	while(file_buffer[ret++]!=0);
	return ret;
}

static int getScreenPos(int loc){
	int single = 0;
	int ret = 0;
	while(single<loc){
		if(file_buffer[single]=='\t'){
			ret+=4-(ret%4);
		}else if(file_buffer[single]=='\n'){
			ret+=VGA_W-(ret%VGA_W);
		}else ret++;
		single++;
	}
	return ret;
}

static void addToFileBuff(char c, int pos){
	char next = c, after = file_buffer[pos];

	while(next!=0){
		file_buffer[pos++] = next;
		next = after;
		after = file_buffer[pos];
	}
}

static void removeFromFileBuff(int pos){
	char next = file_buffer[pos];

	while(next!=0){
		file_buffer[pos-1] = next;
		next = file_buffer[++pos];
	}
	file_buffer[pos-1] = next;
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

