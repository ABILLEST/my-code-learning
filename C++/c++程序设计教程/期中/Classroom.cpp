#include <iostream>
#include <string>
using namespace std;

class Classroom
{
	string name;
	int containABT,state;
	static int empty,full;
public:
	Classroom(){empty++;state=0;}
	void set(string n,int c){name=n;containABT=c;}
	int ask(int classpeople);
	static int getEmpty(){return empty;}
	static int getFull(){return full;}
	string getName(){return name;}
};

int Classroom::empty = 0;
int Classroom::full = 0;

int Classroom::ask(int classpeople)
{
	if(classpeople<=containABT&&state==0)
	{
		state = 1;
		empty--;
		full++;
		return 1;
	}
	else return -1;
}

int main()
{
	int t,n;
	int flag;
	string name;
	int cont,request;
	
	cin>>t;
	Classroom* cp = new Classroom[t];
	for(int i=0;i<t;i++)
	{
		cin>>name>>cont;
		cp[i].set(name,cont);
	}
	
	cin>>n;
	for(int j=0;j<n;j++)
	{
		cin>>request;
		flag=0;
		for(int i=0;i<t;i++)
		{
			if(cp[i].ask(request)==1)
			{
				cout<<"Classroom "<<cp[i].getName()
				<<" is allocated for "<<request<<endl;
				flag=1;
				break;
			}	
		}
		if(!flag) cout<<"No classroom for "<<request<<endl;
	}
	cout<<"The number of free classroom is "<<cp->getEmpty()<<endl;
	cout<<"The number of busy classroom is "<<cp->getFull()<<endl;
}
