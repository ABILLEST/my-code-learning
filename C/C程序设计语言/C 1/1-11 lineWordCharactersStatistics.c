#include<stdio.h>

#define IN 1    //在单词内 
#define OUT 0   //在单词外 

//统计输入的行数、单词数与字符数 
main()
{
	int c,nl,nw,nc,state;
	
	state = OUT;
	nl = nw = nc = 0;
	while((c = getchar()) != EOF)
	{
		++nc;
		if(c == '\n')
			++nl;
		if(c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if(state == OUT)
			{
				state = IN;
				++nw;
			}
	}
	printf("%d %d %d\n",nl,nw,nc);
	return 0;
}
//错误:用除了' ','\n','\t'分开的两个单词计算成了一个 
//例如：hello,world

//答案：测试单词计数程序的边界条件：没有输入、没有单词、每个单词各占一行、单词出现于文本行行首、单词出现于一串空格后 等情况 
