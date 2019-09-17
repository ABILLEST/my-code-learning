#include<stdio.h>

main()
{
	int b,t,n,c;
	
	b = 0;     //number of blanks
	t = 0;     //number of tabs
	n = 0;     //number of newlines
	while((c = getchar()) != EOF)
	{
		if(c==' ') b++;
		else if(c=='\t') t++;
		else if(c=='\n') n++;
	}
		
	printf("There are %d of blanks, %d of \'\\t\', %d of \'\\n\'",b,t,n);
}
