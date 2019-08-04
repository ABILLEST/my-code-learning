#include <iostream>
#include <iomanip>
using namespace std;

class Equation
{
	double a,b;
public:
	Equation(int m,int n):a(m),b(n){}
	void set(double m, double n){a=m;b=n;}
	double getX();
};

double Equation::getX()
{
	//double c;
	//c=(-b/a);
	return (-b/a);
	//return (b==0)? 0: c;		//´¦Àí¡°-0¡± 
}


//Equation
int main()
{
	int t;
	double result;
	double a,b;
	
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>a>>b;
		Equation e(a,b);
		//e.set(a,b);
		cout<<fixed<<setprecision(2)<<e.getX()<<endl;
	}

}
