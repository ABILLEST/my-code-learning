#include<stdio.h>

//ÆæÅ¼¸öÊı
int main(void){
	int ji = 0;
	int ou = 0;
	long long num[100];
	
	int i = 0;
	while(num[i] != -1){
		scanf("%d ",&num[i]);
		i++;
		}
		if(num[i]%2 == 0){
		ou++;
		num[i++];
		}else if(num[i]%2 != 0)
			ji++;
			num[i++];
	printf("%d ",ji);
		printf("%d\n",ou);

	}
		
	return 0;
} 
