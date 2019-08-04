#include<stdio.h>

int main()
{
	int i,today;
	for(i=1;i<10;i++)
	{
		today = (today+1)*2;
	}
	printf("第一天共摘 %d 个桃子",today);
	return 0;
}
