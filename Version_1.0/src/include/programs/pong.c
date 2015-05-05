static void setup();
static void reset();
static void play();
static void printPbuffer();
static void drawboard(int ploc, int oloc, int x, int y);

//char console_save[VGA_W*VGA_H*2];

void pong(){ 
	int saveoff = typeOffset;
	setup();

	play();
	
	reset();
	typeOffset = saveoff;
}

static void setup(){
	// save console
	int i;
	for(i = 0; i<VGA_W*VGA_H*2; i++){
		console_save[i]=vidptr[i];
	}

	clearScreen();
	int j;
	for(i=0; i<20; i++){
		for(j=0;j<VGA_H;j++){
			putchar(219, j*VGA_W+i);
			putchar(219, j*VGA_W+VGA_W-1-i);
		}
	}
	updateCursor(VGA_W*VGA_H*2);
}

static void reset(){
	// replace console
	int i;
	for(i = 0; i<VGA_W*VGA_H*2; i++){
		vidptr[i]=console_save[i];
	}
}

static void drawboard(int ploc, int oloc, int x, int y){
	int i;
	for(i=20; i<VGA_W-20; i++){
		putchar(' ', i);
		putchar(' ', VGA_W*(VGA_H-1)+i);
	}

	putchar(219, VGA_W*y+x);

	putchar(' ', (y+1)*VGA_W+(x));
	putchar(' ', (y-1)*VGA_W+(x));
	
	if(x>20){
		putchar(' ', (y-1)*VGA_W+(x-1));
		putchar(' ', (y+1)*VGA_W+(x-1));
	}
	if(x<VGA_W-21){
		putchar(' ', (y+1)*VGA_W+(x+1));
		putchar(' ', (y-1)*VGA_W+(x+1));
	}

	putchar(219, (VGA_W*(VGA_H-1)) + ploc);
	putchar(219, (VGA_W*(VGA_H-1)) + ploc+1);
	putchar(219, (VGA_W*(VGA_H-1)) + ploc+2);
	putchar(219, (VGA_W*(VGA_H-1)) + ploc+3);
	putchar(219, (VGA_W*(VGA_H-1)) + ploc+4);
	putchar(219, (VGA_W*(VGA_H-1)) + ploc+5);
	putchar(219, (VGA_W*(VGA_H-1)) + ploc+6);
	putchar(219, (VGA_W*(VGA_H-1)) + ploc+7);

	putchar(219, oloc);
	putchar(219, oloc+1);
	putchar(219, oloc+2);
	putchar(219, oloc+3);
	putchar(219, oloc+4);
	putchar(219, oloc+5);
	putchar(219, oloc+6);
	putchar(219, oloc+7);
}

static void play(){
	key next;
	int ploc = VGA_W/2-4;
	int oloc = VGA_W/2-4;
	int pxloc = VGA_W/2;
	int pyloc = VGA_H/2;
	int dir = 1;
	int i = 0,j = 0;
	drawboard(ploc, oloc, pxloc, pyloc);
	while(1){
		if(!key_queue_is_empty()) {
			next = remove_key();
			if(next.key == 27)					break;
			else if(next.scancode == 75 && ploc%VGA_W>20) 		ploc--;	//left
			else if(next.scancode == 77 && ploc%VGA_W<VGA_W-28)	ploc++;	//right
		}
		i++;
		if(i==1000000){
			i=0;
			if(pxloc == 20) dir+=2;
			if(pxloc == VGA_W-21) dir-=2;
			switch(dir){
				case 0:
					pyloc-=1;
					pxloc-=1;
					break;
				case 1:
					pyloc-=1;
					break;
				case 2:
					pyloc-=1;
					pxloc+=1;
					break;
				case 3:
					pyloc+=1;
					pxloc-=1;
					break;
				case 4:
					pyloc+=1;
					break;
				case 5:
					pyloc+=1;
					pxloc+=1;
					break;
			}
			if(pyloc==VGA_H) {pyloc=VGA_H/2; pxloc=VGA_W/2; dir= 1;}
			else if(pyloc==VGA_H-1){
				if(pxloc>=ploc+3 && pxloc<=ploc+4) dir = (dir+3)%6;
				else if(pxloc>=ploc && pxloc<=ploc+2) dir = (dir+3)%6-1;
				else if(pxloc>=ploc+5 && pxloc<=ploc+7) dir = (dir+3)%6+1;
			}else if(pyloc==0) dir = (dir+3)%6;

			//if((pyloc==VGA_H-1 && (pxloc>=ploc && pxloc<=ploc+7)) || pyloc==0) dir = (dir+3)%6;
			//else if(pyloc==VGA_H) pyloc=VGA_H/2;
			oloc+=(oloc==pxloc-4)?0:(oloc<pxloc-4)?1:-1;
			oloc=(oloc<20)?20:oloc;
			oloc=(oloc>VGA_W-28)?VGA_W-28:oloc;
			drawboard(ploc, oloc, pxloc, pyloc);
		}

	}
}
