#include <iostream>
using namespace std;

//优化方法：重载运算符比较两生日大小 

class Birth
{
	int year,month,day;
public:
	Birth(){} 
	Birth(int y,int m,int d):year(y),month(m),day(d){}
	Birth(Birth& b){year=b.year;month=b.month;day=b.day;}
	void set(int y,int m,int d){year=y;month=m;day=d;}
	friend long long password(Birth& date,int x);
	int getY(){return year;}
	int getM(){return month;}
	int getD(){return day;}
};

long long password(Birth& date,int x)
{
	return (date.year*x*x+date.month*x+date.day);
}

//Oldest Birth
int main()
{
	int t,x,n;
	int y,m,d;
	int miny,minm,mind;
	Birth* p = NULL;
	Birth min;
	
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n>>x;
		p = new Birth[n];
		//input
		for(int j=0;j<n;j++)
		{
			cin>>y>>m>>d;
			p[j].set(y,m,d);
		}
		
		min=p[0];
		//find the oldest birthday
		for(int j=0;j<n;j++)
		{
			if(min.getY()>p[j].getY())
			{
				min=p[j];
				continue;
			}
			else if(min.getY()==p[j].getY())
			{
				if(min.getM()>p[j].getM())
				{
					min=p[j];
					continue;
				}
				else if(min.getM()==p[j].getM())
				{
					if(min.getD()>p[j].getD())
					{
						min=p[j];
						continue;
					}
				}
			}
		}
		cout<<"The password is "<<password(min,x)<<endl;
	}	
}
