#include <stdio.h>
#define HEXLEN 40
 
char saveH [HEXLEN]; //用于存放转换好的十六进制字符串，可根据需要定义长度
 
//10进制转16进制函数 
char * ItoH(int aa)
{
    static int i = 0;
    if (aa < 16)            //递归结束条件 
    {
        if (aa < 10)        //当前数转换成字符放入字符串 
            saveH[i] = aa + '0';
        else
            saveH[i] = aa - 10 + 'A';
        saveH[i+1] = '\0'; //字符串结束标志 
    }
    else
    {
        ItoH(aa / 16);  	//递归调用 
        i++;                //字符串索引+1 
        aa %= 16;           //计算当前值
        if (aa < 10)        //当前数转换成字符放入字符串 
            saveH[i] = aa + '0';
        else
            saveH[i] = aa - 10 + 'A';
        saveH[i+1] = '\0'; //字符串结束标志 
    }
    return (saveH);
}
 
int main ()
{
  int num;
  char * hex_str;			//定义指针 
  printf ("Enter a number: ");
  scanf ("%d",&num);
  hex_str = ItoH(num);		
  printf ("Hexadecimal number: %sH\n", hex_str);	//用指针输出字符串 
  return 0;
}

/*
//标准输入输出法
int main()
{
	int num;
	scanf("%d",&num);
	printf("%x",num);
	return 0;
} 
