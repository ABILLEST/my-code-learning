#include<iostream>
#include<cmath>
using namespace std;

//function pointer
int main()
{
	int square(int n);
	float squareRoot(float n);
	char* upper(char *s);
	
	int t,n;
	float f;
	char type;
	char *str = new char[50];
	int (*i)(int n)=square;
	float (*fp)(float n)=squareRoot;
	char* (*s)(char *s);
	s=upper;
	cin>>t;
	
	while(t--)
	{
		cin>>type;
		switch(type)
		{
			case 'I':
				cin>>n;
				n=(*i)(n);
				cout<<n<<endl;
				break;
				
			case'F':
				cin>>f;
				f=(*fp)(f);
				cout<<f<<endl;
				break;
				
			case'S':
				cin>>str;
				(*s)(str);
				cout<<str<<endl;
				break;
			default:
				cout<<"error"<<endl;
				break;
		}
	}
	return 0;
 } 
 
 int square(int n)
 {
 	n = n*n;
 	return n;
 }
 
 float squareRoot(float n)
 {
 	n = sqrt(n);
 	return n;
 }
 
 char* upper(char *s)
 {
 	char *p=NULL;
 	for(p=s;*p!='\0';p++)
 		if(*p>='a'&&*p<='z')
 			*p -= 32;
 			
 	return s;
 }
