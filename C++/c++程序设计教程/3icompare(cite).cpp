#include<iostream>
using namespace std;

//3i compare(cite)
int main()
{
	void compare(int &d, int &e, int &f);
	
	int t,a,b,c;
	int &d=a,&e=b,&f=c;
	cin>>t;
	
	while(t--)
	{
		cin>>d;
		cin>>e;
		cin>>f;
		
		compare(d,e,f);
		
		cout<<f<<' '<<e<<' '<<d<<' '<<endl;
	}
	return 0;
}

void compare(int &d, int &e, int &f)
{
	int q;
	if(d>e) {q=d,d=e,e=q;}
	if(e>f) {q=e,e=f,f=q;}
	if(d>e) {q=d,d=e,e=q;}
}
