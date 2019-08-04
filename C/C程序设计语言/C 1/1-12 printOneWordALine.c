#include<stdio.h>
#define IN 1    //在单词内 
#define OUT 0   //在单词外 

//以每行一个单词的形式打印其输入 
/*main() 
{
	int c,state;
	state = OUT;
		
	while((c = getchar()) != EOF)
	{	
		if(c == ' ' || c == '\n' || c == '\t')
		{
			state = OUT;
			printf("\n");
		}
			
		else if(state == OUT)
				state = IN;
		putchar(c);
	}
	return 0;
}*/

//Answer
main() 
{
	int c, state;
	
	state = OUT;
	while((c = getchar()) != EOF)
	{	
		if(c == ' ' || c == '\n' || c == '\t'){	
			if(state == IN){
				printf("\n");
				state = OUT;
			}
		}else if(state == OUT){
				state = IN;
				putchar(c);
		}else putchar(c);
	}
	return 0;
}
