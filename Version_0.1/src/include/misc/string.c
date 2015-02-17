/* string.c */

/* To Add
void itoa(char *buf, unsigned long int n, int base);
void *memcpy(char *dst, char *src, int n);
void *memset(char *dst,char src, int n);
*/
int k_strlen(char *str);
int k_strcmp(char *s, char *t);
void k_strcpy(char *s, char *t);
void k_touppercase(char *str);
void k_tolowercase(char *str);

int k_strlen(char *str){
	int len = -1;
	while(str[1+len++]!=0);
	return len;
}

int k_strcmp(char *s, char *t)
{
	while(*s==*t) {
		if(*s=='\0') return 0;
		s++; t++;
	}
	return *s-*t;
}

void k_strcpy(char *s, char *t)
{
	while(*s++=*t++);
}

void k_touppercase(char *str){
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

void k_tolowercase(char *str){
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