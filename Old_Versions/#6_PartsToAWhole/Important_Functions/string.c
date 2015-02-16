/*void itoa(char *buf, unsigned long int n, int base);

void *memcpy(char *dst, char *src, int n);
void *memset(char *dst,char src, int n);

int strlen(char *s);*/
void t_strcpy(char *s, char *t);
int t_strcmp(char *s, char *t);


void t_strcpy(char *s, char *t)
{
	while(*s++=*t++);
}

int t_strcmp(char *s, char *t)
{
	while(*s==*t) {
		if(*s=='\0') return 0;
		s++; t++;
	}
	return *s-*t;
}
