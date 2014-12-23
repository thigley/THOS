// video 
#define W 80
#define H 25
#define VIDEO_ADDRESS 0xb8000

// colors
#define BLACK 0x00
#define BLUE 0x01
#define GREEN 0x02
#define CYAN 0x03
#define RED 0x04
#define MAGENTA 0x05
#define BROWN 0x06
#define LIGHTGRAY 0x07
#define DARKGRAY 0x08
#define LIGHTBLUE 0x09
#define LIGHTGREEN 0x0A
#define LIGHTCYAN 0x0B
#define LIGHTRED 0x0C
#define LIGHTMAGENTA 0x0D
#define YELLOW 0x0E
#define WHITE 0x0F

void screen_setup();
void clear();
void printchar(char);
void print(char*);
void println(char*);
void printint(int);
void newline();
int makecolor();

int CURRENTCOLOR;
int CURRENTBACK;
int OFFSET;
char* vidmem;
