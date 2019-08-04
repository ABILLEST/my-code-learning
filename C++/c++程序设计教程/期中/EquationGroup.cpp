#include <iostream>
#include <iomanip>
using namespace std;

class Equation
{
	double a,b;
public:
	Equation(double m, double n){a=m;b=n;}
	void set(double m, double n){a=m;b=n;}
	double getX();
	double geta(){return a;}
	double getb(){return b;}
	bool root();
};

class EquationGroup
{
	Equation e1,e2,e3;
public:
	EquationGroup(int m1,int n1,int m2,int n2,int m3,int n3):e1(m1,n1),e2(m2,n2),e3(m3,n3){}
	Equation * maxeq();
}; 

double Equation::getX()
{
	double c;
	c=b/a;
	if(b==0)
		return 0;
	return (-c);
}

bool Equation::root()
{
	if(a==0&&b!=0)
		return false;
	return true;
}

Equation* EquationGroup::maxeq()
{
	if(!e1.root())
	{
		if(e2.getX()>e3.getX())
			return &e2;
		else return &e3;
	}
	if(!e2.root())
	{
		if(e1.getX()>e3.getX())
			return &e1;
		else return &e3;
	}
	if(!e3.root())
	{
		if(e2.getX()>e1.getX())
			return &e2;
		else return &e1;
	}
	
	if(e1.getX()>e2.getX()&&e1.getX()>e2.getX())
		return &e1;
	else if(e2.getX()>e1.getX()&&e2.getX()>e3.getX())
		return &e2;
	else if(e3.getX()>e1.getX()&&e3.getX()>e2.getX())
		return &e3;
}

void outMax(EquationGroup* eg)
{
	Equation* max= eg->maxeq();
	if(max->geta()==1)
	{
		cout<<"The max equation is x";
	}
	else if(max->geta()==-1)
	{
		cout<<"The max equation is -x";
	}
	else cout<<"The max equation is "<<max->geta()<<"x";
	if(max->getb()>0)
		cout<<"+";
	else if(max->getb()==0)
		cout<<"=0"<<endl;
	
	cout<<max->getb()<<"=0"<<endl;
}

int main()
{
	int t;
	double a1,b1,a2,b2,a3,b3;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>a1>>b1>>a2>>b2>>a3>>b3;
		EquationGroup eg(a1,b1,a2,b2,a3,b3);
		outMax(&eg);
	}

}
