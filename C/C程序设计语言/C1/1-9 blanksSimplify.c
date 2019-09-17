#include<stdio.h>

//print & turn blanks into 1 blank

//My program
/*main()
{
	int c,b,i;
	b = 0;      //number of blanks
	
	while((c = getchar()) != EOF)
	{
		while((c = getchar()) == ' ')
		{
			if((c = getchar()) != ' ')
				break;
			else b++;
		}
		if(b>1)
		{
			for(i=1; i<=b-1; i++)
				printf("\b");
		}
		putchar(c);
	}
		
	return 0;
}*/

//correct answer
#define NONBLANK 'a'
main()
{
	int c,lastc;          //还是用了两个变动标志的方法 
	
	lastc = NONBLANK;
	while((c = getchar()) != EOF)
	{
		if(c != ' ' || lastc != ' ')    //对两个连续字符的循环判断可以判断是否有连续的字符（好方法） 
			putchar(c);
		lastc = c;
	}
}
