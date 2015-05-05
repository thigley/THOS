int echo(int argc, char *argv[]){
	if(argc<2){ 
		printToConsole("Error: Wrong number of arguments!\n");
		return 1;
	}
	int i;
	for(i=1;i<argc;i++){
		printToConsole(argv[i]);
		printCharToConsole(' ');
	}
	printCharToConsole('\n');

	return 0;
}
