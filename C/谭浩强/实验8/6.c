#include<stdio.h>
#include<stdlib.h>

int main()
{
	char a[50];	//定义a存放字符串
	int b[50];	//存放指定字符位置
	int flag=0, i, j=0,k, ch;		//定义标志变量、循环变量

	printf("\n输入文本：");
	gets(a);
	printf("输入要查找的字符： ");
	ch = getchar();
	//puts(a);				//调试用 
	
	for(i = 0; a[i] != '\0'; i++){
		if (a[i] == ch){			//找到指定字符
			b[j] = i;				//将下标存放在指定数组 
			flag = 1;				//标志变量置1表示找到指定字符 
			j++;
		}
	}
	
	k = j;							//保存b的有效位 
	if (flag == 0)	printf("没有找到该字符\n");
	else{
		printf("指定字符%2c出现了%3d次\n位置是： ",ch,j);
		for(j = 0; j < k; j++)
				printf("%d\t",b[j]+1);
	}
	system("pause");
	return 0;
}
