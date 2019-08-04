#include<stdio.h>

//printEOF
int main()
{
	char c;
	
	while(c = getchar()!=EOF)
		printf("%d\n",c);
	printf("%d - at EOF\n",c);
	
	return 0;
}
