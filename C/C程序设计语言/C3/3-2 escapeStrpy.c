#include<stdio.h>
//escape : expand newline and tab into visible sequences
//			while copying the string t to s
void escape(char *s, char* t)
{
	int i,j;
	
	for (i = j = 0; t[i] != '\0'; i++)
		switch(t[i]){
			case '\n':				//newline
				s[j++] = '\\';
				s[j++] = 'n';
				break;
			case '\t':				//tab
				s[j++] = '\\';
				s[j++] = 't';
				break;
			default:				//all other chars
				s[j++] = t[i];
				break;
		}
		s[j] = '\0';
}

void unescape(char *s, char* t)
{
	int i,j;
	for (i = j = 0; t[i] != '\0'; i++)
		switch(t[i]){
			case '\\':				//backslash
				switch(t[++i]){
					case 'n':		//real newline
						s[j++] = '\n';
						break;
					case 't':		//real tab
						s[j++] = '\t';
						break;
					default:		//all other chars
						s[j++] = '\\';
						s[j++] = t[i];
						break;
				}
				break;
			default:				//not a backslash
				s[j++] = t[i];
				break;
		}
		s[j] = '\0';
}

int main()
{
	char to[50], from[50];
	gets(from);
	escape(to,from);
	puts(to);
	gets(from);
	unescape(to,from);
	puts(to);
	return 0;
}
