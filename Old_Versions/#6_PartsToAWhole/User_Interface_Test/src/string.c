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

int strlen(char *str){
	int len = 0;
	while(str[len++]!=0);
	return len;
}

void copystrto(char *old, char *new){
	int i= 0;
	while(old[i]!=0){
		new[i]=old[i];
		i++;
	}
	new[i]=0;
}

void replacefirst(char *c,char r,char w){
	int i = 0;
	while(c[i]!=r&&c[i]!=0) i++;
	c[i]=w;
}

void touppercase(char *str){
	int i = 0;
	int diff = 'a'-'A';
	while(str[i]!=0){
		char cur = str[i];
		if(cur>='a'&&cur<='z'){
			cur-=diff;
			str[i]=cur;
		}
		i++;
	}
}

void tolowercase(char *str){
	int i = 0;
	int diff = 'A'-'a';
	while(str[i]!=0){
		char cur = str[i];
		if(cur>='A'&&cur<='Z'){
			cur-=diff;
			str[i]=cur;
		}
		i++;
	}
}
