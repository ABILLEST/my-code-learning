#include<iostream>
#include <iomanip>
using namespace std;

//money exchange
int main()
{
	
	int t;
	double num,result;
	char hb;
	const double *p = NULL;
	cin>>t;
	
	const double d=6.2619;
	const double e=6.6744;
	const double y=0.0516;
	const double h=0.8065;
	
	while(t--)
	{
		cin>>hb>>num;
		switch(hb)
		{
			case'D':
			case'd':p=&d;break;
			case'E':
			case'e':p=&e;break;
			case'Y':
			case'y':p=&y;break;
			case'H':
			case'h':p=&h;break;
		}
		result = *p * num;
		cout<<fixed<<setprecision(4)<<result<<endl;
	}
	return 0;
}

