#define OS "THOS"
#define op1 "applications"
#define op2 "files"
#define op3 "about"
#define op4 "other"

int selectedop;

void loadHello();
void loadMenu();
void runinput();
int lineEq(char*);

void runinput(){
	int length = OFFSET%(W*2);
	OFFSET -= length;
	int i;
	selectedop = 0;
	if(lineEq(op1)){selectedop = 1;}
        else if(lineEq(op2)){selectedop = 2;}
        else if(lineEq(op3)){selectedop = 3;}
        else if(lineEq(op4)){selectedop = 4;}
	for(i = 0; i<length/2; i++){
		vidmem[OFFSET++]=' ';
		OFFSET++;
	}
	OFFSET-=length;
	 outportb(0x60, 250);
}
int lineEq(char* op){
	int change = 0;
	while(op[change]!='\0'){
		if(op[change]!=vidmem[OFFSET+(change*2)]){
			return 0;
		}
		change++;
	}
	return 1;
}

void loadHello(){
	selectedop = 0;

	println("");
        OFFSET+=29*2;
	CURRENTCOLOR = WHITE;
        println("***********************");
        OFFSET+=29*2;
        println("***                 ***");
        OFFSET+=29*2;
        print("**  ");
        CURRENTCOLOR = BLACK;
        print("Welcome to ");
        CURRENTCOLOR = YELLOW;
        print(OS);
        CURRENTCOLOR = WHITE;
        println("  **");
        OFFSET+=29*2;
        print("*     ");
        CURRENTCOLOR = BLACK;
        print("Created by:");
        CURRENTCOLOR = WHITE;
        println("     *");
        OFFSET+=29*2;
        print("**   ");
        CURRENTCOLOR = RED;
        print("Tyler Higley!");
        CURRENTCOLOR = WHITE;
        println("   **");
        OFFSET+=29*2;
        println("***                 ***");
        OFFSET+=29*2;
        println("***********************");
        CURRENTCOLOR = BLACK;
}

void loadMenu(){
	OFFSET=9*W*2;
	OFFSET+=17*2;
	println("**********************************************");
	OFFSET+=17*2;
	print("* ");
	CURRENTCOLOR = selectedop==1?WHITE:RED;
	print(op1);
	print("    ");
	CURRENTCOLOR = selectedop==2?WHITE:RED;
	print(op2);
	print("    ");
	CURRENTCOLOR = selectedop==3?WHITE:RED;
	print(op3);
	print("    ");
	CURRENTCOLOR = selectedop==4?WHITE:RED;
	print(op4);
	CURRENTCOLOR = BLACK;
	println("    *");
	OFFSET+=17*2;
	println("**********************************************");
	println("");
}
