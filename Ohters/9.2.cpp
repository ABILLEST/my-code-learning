#include <stdio.h>
#include <string.h>

int main(){
	char s[] = "Hello";
	char *p = strchr(s,'l');
	p = strchr(p+1,'l');
	printf("%s",p);
	
	return 0;
}
