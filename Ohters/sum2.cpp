#include<stdio.h>

//Sum
int main(void){
	int a = 100,sum = 0,counter2;
	int counter1 = 1;
	counter2 = counter1;
		
	while(counter1 <= a){
		sum += counter1;
		counter1++;
	}
	printf("%d\n\n",counter2);
	printf("%d\n",sum);
	
	return 0;
} 
