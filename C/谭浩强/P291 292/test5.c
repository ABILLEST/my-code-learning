#include <stdio.h>  
  
int main(void)  
{  
    int N,i;  
    int a[1000];  
    printf("多少只猴子? ");
    scanf("%d", &N);  
    int count = 0, number = N;  
    for (i = 0; i < N; i++)  
        a[i] = i + 1;  
    while (number > 1)  
    {  
        for (i = 0; i < N; i++)  
        {  
            if (a[i] == 0)  
                continue;  
            count++;  
            if (count == 3)  
            {  
                a[i] = 0;  
                count = 0;  
                number--;  
            }  
        }  
    }  
    for (i = 0; i < N; i++)  
        if (a[i] != 0)  
            printf("%d", a[i]);  
  
    return 0;  
} 
