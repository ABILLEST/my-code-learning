#include <iostream>
#include <string>
using namespace std;

class PhoneNumber
{
	long long num;
	char type;
public:
	PhoneNumber(long long _num,char _type):num(_num),type(_type){};
	long long getNum(){return num;}
	char getType(){return type;}
};

class Mobile
{
	PhoneNumber n;
	int state;
	string name;
public:
	Mobile(long long _num,char _type,int s,string n);
	~Mobile();
	void print();
	int search(long long _num);
};

Mobile::Mobile(long long _num,char _type,int s,string n):n(_num,_type)
{

	state = s;
	name = n;
	cout<<_num<<" constructed."<<endl;
}

Mobile::~Mobile()
{
	cout<<n.getNum()<<" destructed."<<endl;
}

void Mobile::print()
{
	cout<<"Phone="<<n.getNum()
		<<"--Type="<<n.getType()
		<<"--State=";
	if(state==1)
		cout<<"use";
	else if(state==0)
		cout<<"unuse";
	cout<<"--Owner="<<name<<endl;
}

int Mobile::search(long long _num)
{
	if(n.getNum()==_num)
		return 1;
	else 
		return 0;
}



int main()
{
	int t,state;
	long long num,searchNum;
	char type;
	string name;
	
	cin>>num>>type>>state>>name;
	Mobile m1(num,type,state,name);
	cin>>num>>type>>state>>name;
	Mobile m2(num,type,state,name);
	cin>>num>>type>>state>>name;
	Mobile m3(num,type,state,name);
	
	cin>>t;
	for(int i=0; i<t; i++)
	{
		cin>>searchNum;
		if(m1.search(searchNum))
			m1.print();
		else if(m2.search(searchNum))
			m2.print();
		else if(m3.search(searchNum))
			m3.print();
		else cout<<"wrong number."<<endl;
	}
}
