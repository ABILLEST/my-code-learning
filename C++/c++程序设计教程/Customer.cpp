#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

class Customer
{
public:
	Customer(char* name);
	~Customer();
	static void changeYear(int r){Year=r;}
	void Display();					//output info
private:
	static int TotalCustNum;
	static int Rent;
	static int Year;
	int CustID;
	char* CustName;
};

int Customer::TotalCustNum = 0;
int Customer::Rent = 0;
int Customer::Year=2014;

Customer::Customer(char* s)
{
	CustName = new char[50];
	strcpy(CustName,s);
	TotalCustNum += 1;
	Rent += 150;
	CustID = TotalCustNum;
}

Customer::~Customer()
{
	delete CustName;
}

void Customer::Display()
{
	cout<<CustName<<" "<<Year<<setfill('0')<<setw(4)<<CustID<<" "<<TotalCustNum<<" "<<Rent<<endl;
}

int main()
{
	int t,year;
	char* name=new char[50];
	cin>>t;
	
	for(int i=0; i<t; i++)
	{
		cin>>year;
		
		for(;;)
		{
			cin>>name;
			if(*name=='0') break;
			Customer c(name);
			c.changeYear(year);
			c.Display();
		}
	}
	return 0;
}
