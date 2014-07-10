#include "video.h"

void setup(){
	video_memory = (char*) 0xb8000;

}
void clear(){
	int i;
	for(i = 0; i<W*H*2; i++){
		*video_memory++ = ' ';
		*video_memory++ = BLACK;
	}
}
void print(char* str){
}
void println(char* sr){
}

