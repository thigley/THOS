// video 
#define W 80
#define H 25
#define VIDEO_ADDRESS 0xb8000

// colors
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15

void setup();
void clear();
void printchar(char);
void print(char*);
void println(char*);
void printint(int);

int CURRENTCOLOR;
int OFFSET;
char* vidmem;
