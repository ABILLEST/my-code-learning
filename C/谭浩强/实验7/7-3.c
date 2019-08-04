#include<stdio.h>

main()
{
	int a[4][4] = {{1,2,3,4},{5,6,7,8},{3,9,10,2},{4,2,9,6}};
	int i, sum = 0;
	
	for(i=0; i<4; i++)
		sum += a[i][i];
	printf("sum = %d\n",sum);
	
	return 0;
}
