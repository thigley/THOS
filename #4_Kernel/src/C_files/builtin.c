void loadHello();
void loadMenu();

void loadHello(){
        char* indent = "                             ";
        CURRENTCOLOR = GREEN;
        print(indent);
        println("***********************");
        print(indent);
        println("***                 ***");
        print(indent);
        print("**  ");
        CURRENTCOLOR = WHITE;
        print("Welcome to ");
        CURRENTCOLOR = YELLOW;
        print("THOS");
        CURRENTCOLOR = GREEN;
        println("  **");
        print(indent);
        print("*     ");
        CURRENTCOLOR = WHITE;
        print("Created by:");
        CURRENTCOLOR = GREEN;
        println("     *");
        print(indent);
        print("**   ");
        CURRENTCOLOR = LIGHTMAGENTA;
        print("Tyler Higley!");
        CURRENTCOLOR = GREEN;
        println("   **");
        print(indent);
        println("***                 ***");
        print(indent);
        println("***********************");
        CURRENTCOLOR = WHITE;
}

void loadMenu(){
	println("");
	print("                 ");
	println("**********************************************");
	print("                 * ");
	print("Applications");
	print("    ");
	print("Files");
	print("    ");
	print("About");
	print("    ");
	print("Other");
	println("    *");
	print("                 ");
	println("**********************************************");
	println("");
}
