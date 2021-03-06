#define BLOCKSIZE 512
#define NUM_OF_INODES 10
#define NUM_OF_BLOCKS 60
#include <stdio.h>
#include "string.c"
#include "stack.c"
#include "filesystem.c"
#include "display.c"

int main()
{
	
	initfs();
	
	createfile("test","this is a test");
	createfilefull("long_test","This test will be considerably longer than the others. The reason for this is to test the filesystems ability to use multiple blocks. In 'test', all of the data fit into a single block so we weren't able to really see if the system was working. In contrast, this file is long enough (more than 512 bytes) that it will need to be stored in multiple blocks. This will not only test it's own ability to store longer files, but also make sure that the next file has no issues caused by side effects of this longer file.",543,1,1);
	createfilefull("final_test","Boo! I'm a ghost!!!! Fear me! Muhahahaha!",777,0,1);


	char input[32];
	
	while(1){
		int i;
		printf("$ ");
		for(i=0;i<32;i++){input[i]='\0';}
		scanf("%s", input);

		if(!strcmp(input, "exit")){return;}
		else if(!strcmp(input, "cat")){
			scanf("%s", input);
			viewfile(input);
			printf("\n");
		}
		else if(!strcmp(input, "chmod")){
			//printf("which file: ");
			unsigned short numod;
			scanf("%hu", &numod);
			scanf("%s", input);
			int error = chmod(numod,input);
			if(error){printf("There was an error!\n");}
		}
		else if(!strcmp(input, "vi")){
			scanf("%s", input);
			fflush(stdin);
			char content[2048];
			printf("->");
			char trash;
			scanf("%c",&trash);
			scanf("%[^\n]s", content);

			if(createorreplacefile(input, content)) printf("error\n");
		}
		else if(!strcmp(input, "rm")){
			scanf("%s", input);
			rmfile(input);
		}
		else if(!strcmp(input, "ls")){
			printfiles();
		}
		else if(!strcmp(input, "dump")){
			dump();
		}
		else if(!strcmp(input, "help")){
			printf("\tls \t\t\t\t- list all files\n");
			printf("\tchmod [new mode] [file name] \t- change file permissions\n");
			printf("\tcat [file name] \t\t- view contents of that file\n");
			printf("\tvi [file name] \t\t\t- create or edit file with name\n");
			printf("\trm [file name] \t\t\t- remove file with name\n");
			printf("\tdump \t\t\t\t- view all inodes and contents of blocks\n");
		}
		else printf("Command not recognized\n");
	}
}

