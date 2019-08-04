#include<iostream>
using namespace std;

//month search
int main()
{
	int t;
	cin>>t;
	
	const char* p[12];
	const char **i=p;
	*i++="January";
	*i++="February";
	*i++="March";
	*i++="April";
	*i++="May";
	*i++="June";
	*i++="July";
	*i++="Aguest";
	*i++="September";
	*i++="Octorber";
	*i++="November";
	*i++="December";
	
	while(t--)
	{
		int mon;
		cin>>mon;
		i=p;
		
		switch(mon)
		{
			case 1:cout<<*i<<endl;break;
			case 2:cout<<*(i+1)<<endl;break;
			case 3:cout<<*(i+2)<<endl;break;
			case 4:cout<<*(i+3)<<endl;break;
			case 5:cout<<*(i+4)<<endl;break;
			case 6:cout<<*(i+5)<<endl;break;
			case 7:cout<<*(i+6)<<endl;break;
			case 8:cout<<*(i+7)<<endl;break;
			case 9:cout<<*(i+8)<<endl;break;
			case 10:cout<<*(i+9)<<endl;break;
			case 11:cout<<*(i+10)<<endl;break;
			case 12:cout<<*(i+11)<<endl;break;
			default:cout<<"error"<<endl;
		}
	}
	return 0;
}
