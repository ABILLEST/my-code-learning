#include "stdio.h"
#include<stdlib.h>

int main( )
{ 
	char str[80]="This Is a c Program";
    int i;
    printf("String is: %s\n", str);
    for (i = 0; str[i]!='\0'; i++)
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] -= 32;				/*将小写字母转换成大写字母*/
    printf("Result is: %s\n",str);

	system("pause");
	return 0;
}
