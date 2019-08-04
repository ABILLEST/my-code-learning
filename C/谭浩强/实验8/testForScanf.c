#include<stdio.h>

//test for scanf()&gets()
main()
{
	char a[20];
	printf("scanf input:");
	scanf("%s",a);
	printf("%s\n",a);
	printf("gets input:");
	gets(a);
	puts(a);
	
	return 0;
}
