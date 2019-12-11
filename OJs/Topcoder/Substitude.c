#include<iostream>
#include<string>
//Substitude

int getValue(const char* KEY, const char* CODE)
{
	int i,j;
	char key[10],code[100];
	strcpy(key,KEY);
	strcpy(code,CODE);
	for (i = 0; code[i] != '\0'; i++){
		for (j = 0; j < 10; j++)
			if (code[i] == key[j])
				if (j+1 == 10)	printf("0");
				else			printf("%d",j+1);
	}
}

int main()
{
	getValue("CRYSTALBUM","MMA");
	return 0;
}
