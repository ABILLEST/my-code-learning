#include<stdio.h>

//itob函数：将整数n转换为b进制的数，并保存到字符串s中
void itob(int n, char s[], int b)
{
	static int i = 0;
	int sign;
	if ((sign = n) < 0){		//取绝对值 
		n = -n;
		s[i++] = '-';
	}		
    if (n < b)            //递归结束条件 
    {
        if (n < 10)        //当前数转换成字符放入字符串 
            s[i] = n + '0';
        else
            s[i] = n - 10 + 'A';
        s[i+1] = '\0'; //字符串结束标志 
    }
    else
    {
        itob(n / b,s,b);  	//递归调用 
        i++;                //字符串索引+1 
        n %= b;           //计算当前值
        if (n < 10)        //当前数转换成字符放入字符串 
            s[i] = n + '0';
        else
            s[i] = n - 10 + 'A';
        s[i+1] = '\0'; //字符串结束标志 
    }
} 

int main()
{
	int num,b;
	char s[10];
	
	printf("请输入一个十进制数: ");
	scanf("%d",&num);
	printf("请输入要转换的进制: ");
	scanf("%d",&b);
	itob(num,s,b);
	printf("\n转换结果： ");
	puts(s);
	return 0;
}
