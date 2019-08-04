#include<stdio.h>
#define DAY 2400
//transTime programme

int main(void){
	int UCT,BJT;
	
	while (UCT != EOF){
		scanf("%d",&UCT);
		if (UCT >= 0&&UCT <= 2359){
			if (UCT <800){
			BJT = (UCT + DAY)-800;
			printf("%d\n",BJT);
			}else{
				BJT = UCT - 800;
				printf("%d\n",BJT);}
		} else{
		printf("Wrong time!\n");
		}
	}
return 0;
}
