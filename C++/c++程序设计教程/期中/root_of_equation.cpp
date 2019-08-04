#include <iostream>
#include <iomanip>
using namespace std;

class Equation
{
	double a,b;
public:
	Equation(int m,int n):a(m),b(n){}
	~Equation(){cout<<"Equation destructed"<<endl;}
	void set(double m, double n){a=m;b=n;}
	double getX();
	bool root();
};

double Equation::getX()
{
	//double c;
	//c=(-b/a);
	return (-b/a);
	//return (b==0)? 0: c;		//处理“-0” 
}

//方程有无解 
bool Equation::root()
{
	if(a==0&&b!=0)
		return false;
	return true;
}

//输出求根信息 
void solve(Equation& e)
{
	if(e.root())
		cout<<fixed<<setprecision(2)<<e.getX()<<endl;
	else
		cout<<"no root"<<endl;
}

//root of equation
int main()
{
	double a1,b1,a2,b2,a3,b3;
	
	cin>>a1>>b1
		>>a2>>b2
		>>a3>>b3;
	Equation e1(a1,b1);
	Equation e2(a2,b2);
	Equation e3(a3,b3);
	solve(e1);
	solve(e2);
	solve(e3);
}
