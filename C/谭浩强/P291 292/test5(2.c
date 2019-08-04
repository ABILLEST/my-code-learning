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
