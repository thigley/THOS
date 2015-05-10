/* ls.c */

static void lsfile(int filenum, int l, int numin);
int ls(int argc, char *argv[]){ 
	int l = 0;
	if(argc>1 &&(k_strcmp(argv[1], "-l")==0)) l = 1;

	int i;
	for(i = 0; i < filesystem.nodes[filesystem.fs[dir].nodloc].size; i++){
		lsfile(filesystem.nodes[filesystem.fs[dir].nodloc].directblocks[i], l, i);
	} 

	if(!l) printCharToConsole('\n');

	return 0;
}

static void lsfile(int i, int l, int numin){
	if(l){
		unsigned int copy = filesystem.nodes[filesystem.fs[i].nodloc].mode;
		//dir?
		printCharToConsole(copy>777?'d':'-');
		//perm
		copy= copy%1000;

		int j;
		for(j = 0; j<3; j++){
			switch(copy/100){
				case 0:
					printToConsole("---");
					break;
				case 1:
					printToConsole("--x");
					break;
				case 2:
					printToConsole("-w-");
					break;
				case 3:
					printToConsole("-wx");
					break;
				case 4:
					printToConsole("r--");
					break;
				case 5:
					printToConsole("r-x");
					break;
				case 6:
					printToConsole("rw-");
					break;
				case 7:
					printToConsole("rwx");
					break;
			}
			copy = (copy%100)*10;
		}

		printCharToConsole('\t');
		//user
		printToConsole(filesystem.users[filesystem.nodes[filesystem.fs[i].nodloc].uid].name);
		printCharToConsole('\t');
		//group
		printToConsole(filesystem.groups[filesystem.nodes[filesystem.fs[i].nodloc].gid]);
		printCharToConsole('\t');
		//size
		printIntToConsole(filesystem.nodes[filesystem.fs[i].nodloc].size);
		printCharToConsole('\t');
	}
	//name
	if(!l && filesystem.nodes[filesystem.fs[i].nodloc].mode>1000) textColor = WHITE;
	if(numin==0) printCharToConsole('.');
	else if(numin==1) printToConsole("..");
	else printToConsole(filesystem.fs[i].name);
	textColor = LIGHTGRAY;
	printCharToConsole(l?'\n':' ');
}
