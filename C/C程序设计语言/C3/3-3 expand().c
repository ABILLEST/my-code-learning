#include<stdio.h>

//My answer
void expand(char s1[], char s2[])
{
	int i, j;
	
	i = j = 0;
	while (s1[i] != '-')
		i++;
	s2[j++] = s1[i-1];
	do {
		s2[j] = s2[j-1] + 1;
		}while (s2[j++] <= s1[i+1]);
	s2[--j] = '\0';
}

int main()
{
	char s1[20],s2[100];
	printf("Please enter S1: ");
	gets(s1);
	expand(s1,s2);
	printf("\nSpreaded: %s",s2);
	return 0;
}
