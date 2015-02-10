unsigned short getlength(char* s){
	unsigned short i = 0;
	while(s[i++]!=0);
	return i-1;
}

int strcmp(char *str1, char *str2){
	while(*str1!='\0'){ // contents of p1 not equal to null:
		if(*str2=='\0') return 1; // contents of p2 equal to null: 
		if(*str2>*str1) return -1; // contents of p2 greater than contents of p1:
		if(*str1>*str2) return 1; // contents of p1 greater than contents of p2:
		str1++;
		str2++;
	}
	if(*str2!='\0') return -1; // contents of p2 not equal to null:
	return 0;
}
