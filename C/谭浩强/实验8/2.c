#include<stdio.h>

int main()
{
	char a[20];
	int uplt, lwlt, num, blk, other,i;
	uplt = lwlt = num = blk = other = 0;
	gets(a);
	//printf("*%s\n",a);                    //µ÷ÊÔÓÃ
	
	for(i = 0; a[i]!='\0'; i++){
		if (a[i] > 'A' && a[i] < 'Z')	uplt++;
		else if (a[i] > 'a' && a[i] < 'z')	lwlt++;
		else if (a[i] > '0' && a[i] < '9')	num++;
		else if (a[i] == ' ')	blk++;
		else other++;
	}
	
	printf("There are %d upletter(s), %d lowletter(s), %d number(s), %d blank(s), %d others.\n",uplt, lwlt, num, blk, other);
	
	return 0;
}
