#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]){
	char s1[32];
	char s2[32];
	printf("please enter two strings\n");
	scanf("%s",&s1);
	scanf("%s",&s2);
	
	if(strcmp(s1,s2) == 0)
		printf("Equal\n");
		else if (strcmp(s1,s2) == 1)
			printf("s1 is bigger\n");
		else if (strcmp(s1,s2) == -1)
			printf("s2 is bigger\n");
	return 0;
}
