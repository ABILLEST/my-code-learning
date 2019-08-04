#include<stdio.h>

#define MAXHIST 15
#define MAXCHAR 'z'

//打印输入中各字符出现频度的直方图 
int main()
{
	int c, i;
	int len;
	int cc[MAXCHAR];
	int maxvalue;
	int ovflow;
	
	ovflow = 0;
	for (i = 0; i <= MAXCHAR; i++)
		cc[i] = 0;
	while((c = getchar()) != EOF){
		if (c <= MAXCHAR)
			++cc[c];
		else
			ovflow++;
	}
	maxvalue = 0;

	for(i = 1; i <= MAXCHAR; ++i)
		if (cc[i] > maxvalue)
			maxvalue = cc[i];
			
	for(i = 1; i <= MAXCHAR; ++i){
		printf("%5d - %5c - %5d : ",i,i,cc[i]);
		if(cc[i] > 0){
			if ((len = cc[i] * MAXHIST / maxvalue) <= 0)
				len = 1;
		}else
			len = 0;
		while(len > 0){
			putchar('@');
			len--;
		}
		printf("\n");
	}
	if (ovflow > 0)
		printf("There are %d char(s) >= %d",ovflow,MAXCHAR);

	return 0;
}
