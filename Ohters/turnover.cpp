#include<stdio.h>

int main()
{
    int a;
    scanf("%d",&a);
if(a>0)
    printf("%d%d%d",a%10,(a%100)/10,a/100);

return 0;
}
