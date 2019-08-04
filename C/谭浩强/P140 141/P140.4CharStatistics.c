#include<stdio.h>

int main()
{
	printf("ÊäÈëÒ»´®×Ö·û\n");
	char c;
	int letter=0,num=0,space=0,otherSymbols=0;
	while((c=getchar())!='\n')
	{
		if(c>='a'&&c<='z') letter++;
		else if(c>='A'&&c<='Z') letter++;
		else if(c==' ') space++;
		else if(c>='0'&&c<='9') num++ ;
		else otherSymbols++;
	}
	printf("letter=%d,space=%d,number=%d,other symbols=%d\n",letter,space,num,otherSymbols);
}
