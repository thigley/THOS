#define OS "THOS"
#define op1 "Applications"
#define op2 "Files"
#define op3 "About"
#define op4 "Other"

int selectedop;

void loadHello();
void loadMenu();

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
