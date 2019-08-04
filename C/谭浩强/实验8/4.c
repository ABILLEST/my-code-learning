#include<stdio.h>
#include<string.h>
#include<stdlib.h>

main()
{
	char str1[80]="This Is a ",str2[80]="c Program";
    printf("String1 is: %s\n",str1);
    printf("String2 is: %s\n",str2);
    strcat(str1,str2);          /*使用strcat函数实现，注意其格式*/
    printf("Result is: %s\n",str1);

	system("pause");
	return 0;
}
