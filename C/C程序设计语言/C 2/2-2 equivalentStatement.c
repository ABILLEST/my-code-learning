#include<stdio.h>

int main()
{
	int i;
	for (i = 0; ; ++i){
		if (i < lim-1)
			if((c=getchar())!=EOF)
				if (c != '\n')
					s[i] = c;
				else break;
	}
	return 0;
}
