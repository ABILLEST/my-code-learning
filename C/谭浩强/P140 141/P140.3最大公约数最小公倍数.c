#include<stdio.h>

int main()
{
	int x,y,m,i,a=1;
	printf("请输入两个数：");
	scanf("%d %d",&x,&y);
	
	if(x<=0||y<=0) printf("输入不能为非正数！\n"); 
	else
	{	m = x;
		if(x<y)
		{
			x = y;
			y = m;
		}
		
		for(i=2;i<=y;i++)
		{
			if(x%i==0&&y%i==0) 
			a = i;
		 } 
		 
		m = (x*y)/a;
		printf("最大公约数是 %d ,最小公倍数是 %d",a,m);
	}
	return 0;
}
//增强功能
//#include <stdio.h>

/*int fun(int a,int b)	// 2个数的公约数 
{
	int t;

	while(b)
	{
		t = a%b;
		a = b;
		b = t;         //变量交换 
	}

	return a;
}

int main()
{
	int a[100];
	int n;
	int i;
	int res;

	scanf("%d",&n);	        	// 先输入数的总数n 
	if(n < 2)
	{
		printf("n不能小于2\n");
		return 0;
	}
	for(i=0;i<n;i++)       	// 输入n个数  
		scanf("%d",&a[i]);
	res = fun(a[0],a[1]);  
	for(i=2;i<n;i++)
		res = fun(res,a[i]);       //递归 
	printf("%d\n",res);

	return 0;
}  */ 
