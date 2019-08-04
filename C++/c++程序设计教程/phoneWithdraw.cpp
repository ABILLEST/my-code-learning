#include <iostream>
using namespace std;

class ID
{
		long long cardNum;
		long long phone;
		long long passw;
		long long money;
	public:
		ID();
		long long getCardNum();
		long long getPhone();
		long long getPassw();
		long long getMoney();
		void withdraw(long long);
};

ID::ID()
{
	cin>>cardNum>>phone>>passw>>money;
}

long long ID::getCardNum()
{
	return cardNum;
}

long long ID::getMoney()
{
	return money;
}

long long ID::getPassw()
{
	return passw;
}

long long ID::getPhone()
{
	return phone;
}

void ID::withdraw(long long _wdraw)
{
	money -= _wdraw;
}

//phone withdraw
int main()
{
	int n, k;
	long long cardNum, c;
	long long phone  , pe;
	long long passw  , pw;
	long long money  , m;
	
	//set info
	cin>>n;
	ID *group = new ID[n];
	//cout<<"Group has been set."<<endl;
	ID *p = NULL;
	
	//withdraw
	cin>>k;
	for(int j=0; j<k; j++)
	{
		int flag =0;
		ID* i = NULL;
		p=group;
		cin>>pe>>pw>>m;
		for(i=group; i-group<n; i++)
			if(i->getPhone()==pe){
				flag = 1;
				break;
			}
		if(flag)
		{
			//cin>>pw;
			if(i->getPassw()==pw)
			{
				//cin>>m;
				if(i->getMoney() < m)
				{
					cout<<"¿¨ºÅ"<<i->getCardNum()<<"--Óà¶î²»×ã"<<endl;
				}
				else
				{
					i->withdraw(m);
					cout<<"¿¨ºÅ"<<i->getCardNum()<<"--Óà¶î"<<i->getMoney()<<endl;
				}
			}
			else
			{
				cout<<"ÃÜÂë´íÎó"<<endl;
				continue;
			}
		}
		else 
		{
			cout<<"ÊÖ»úºÅ²»´æÔÚ"<<endl;
			continue;
		}
	}
	
	return 0;
}
