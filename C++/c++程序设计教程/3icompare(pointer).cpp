#include<iostream>
using namespace std;

//3int compare
int main()
{
	
	int t,a,b,c,q;
	int *p1=&a,*p2=&b,*p3=&c;
	cin>>t;
	
	while(t--)
	{
		cin>>*p1;
		cin>>*p2;
		cin>>*p3;
		
		if(*p1>*p2) {q=*p1,*p1=*p2,*p2=q;}
		if(*p2>*p3) {q=*p2,*p2=*p3,*p3=q;}
		if(*p1>*p2) {q=*p1,*p1=*p2,*p2=q;}
		
		cout<<*p3<<' '<<*p2<<' '<<*p1<<' '<<endl;
	}
	return 0;
}

