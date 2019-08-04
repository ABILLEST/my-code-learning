#include<stdio.h>

int main()
{
	int N = 5,*p,m;
	int call_n=0,out_n=0;
	int a[100]={0};
	for (p = a; p <(a+N); p++) printf("%d ",*p);
	printf("\n报多少号的出局？ ");
	scanf("%d",&m);
	
	for (p = a;;){
		if (out_n == N-1) break;
		if (*p == 1){
			p++;
			continue;
		}
		call_n++;
		call_n %= m;
		if (call_n == 0){
			*p = 1;
			out_n++;
		}
		if (p == a+N) p = a;
		else p++; 
	}for (p = a; p <(a+N); p++) printf("%d ",*p);
	for (p = a; p <(a+N); p++)
		if (*p == 0) printf("\n最后的留下的是 %d 号\n",p-a+1);
	return 0;
}

/*
//简洁算法
#include <stdio.h> 

 int M; 

int main() 
{ 
    int n, s = 0,i;
    printf("多少个人？ ");
	scanf("%d", &n);
	printf("报数多少的出局？ ");
    scanf("%d", &M); 
    
    for (i = 2; i <= n; ++i) 
        s = (s+M)%i; 
    printf("%d\n", s+1); 
    return 0; 
}
*/ 
