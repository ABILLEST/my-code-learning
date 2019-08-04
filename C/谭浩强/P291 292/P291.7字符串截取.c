#include<stdio.h>
#define MAX 100

int main()
{
	char *cp_m(char *from,int m);
	
	char *p1 = {"This is a test!"},*p2;
	int m;
	printf("从第几个字符开始复制： ");
	scanf("%d",&m);
	p2 = cp_m(p1,m);
	printf("Result: %s\n",*p2);
	return 0;
}

char *cp_m(char *from,int m)
{
	char a[MAX],*p;
	p = a+m-1;
	while((*p++ = *from++) != '\0') ;
	*p = '\0';
	return(a);
}
