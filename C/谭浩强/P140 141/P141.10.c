#include<stdio.h>
#include<stdlib.h>

int main()
{
	float x1 = 1.0, x2 = 2.0, x3, p, sum=0,i;//ГїТ»По p

	for (i = 1; i <= 20; i++)
	{
		p = x2 / x1;
		x3 = x1 + x2;
		x1 = x2;
		x2 = x3;
		sum += p;
		//printf("p=%f,sum=%f\n", p, sum);
	}
	printf("*sum=%f\n", sum);
	system("pause");
	return 0;
}
