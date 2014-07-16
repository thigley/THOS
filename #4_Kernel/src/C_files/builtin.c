void loadHello();
void loadMenu();

void loadHello(){
	OFFSET+=W*2;
        OFFSET+=29*2;
	CURRENTCOLOR = YELLOW;
        println("***********************");
        OFFSET+=29*2;
        println("***                 ***");
        OFFSET+=29*2;
        print("**  ");
        CURRENTCOLOR = BLACK;
        print("Welcome to ");
        CURRENTCOLOR = RED;
        print("THOS");
        CURRENTCOLOR = YELLOW;
        println("  **");
        OFFSET+=29*2;
        print("*     ");
        CURRENTCOLOR = BLACK;
        print("Created by:");
        CURRENTCOLOR = YELLOW;
        println("     *");
        OFFSET+=29*2;
        print("**   ");
        CURRENTCOLOR = RED;
        print("Tyler Higley!");
        CURRENTCOLOR = YELLOW;
        println("   **");
        OFFSET+=29*2;
        println("***                 ***");
        OFFSET+=29*2;
        println("***********************");
        CURRENTCOLOR = BLACK;
}

void loadMenu(){
	OFFSET+=W*2;
	OFFSET+=17*2;
	println("**********************************************");
	OFFSET+=17*2;
	print("* ");
	CURRENTCOLOR = RED;
	print("Applications");
	print("    ");
	print("Files");
	print("    ");
	print("About");
	print("    ");
	print("Other");
	CURRENTCOLOR = BLACK;
	println("    *");
	OFFSET+=17*2;
	println("**********************************************");
	OFFSET+=W*2;
}
