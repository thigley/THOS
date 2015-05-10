/* screen.h */

#ifndef SCREEN_H
#define SCREEN_H

void clearScreen();
void updateCursor(int offset);
void printnewline();
void putchar(char x, int loc);
void printchar(char x);
void print(char* str);
void println(char* str);
void printhex(int input);
void printint(int input);

#endif
