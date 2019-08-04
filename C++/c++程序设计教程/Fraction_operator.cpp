#include <iostream>
using namespace std;

class Fraction
{
	int numerator,denominator;
	int common_divisor(int n1,int n2){
		int r;				//计算最大公约数
		while(n2>0)
		{
			r = n1%n2;
			n1 = n2;
			n2 = r;
		} 
		return n1;
	}	
	void contracted(Fraction f){			//分数化简
		int gys = common_divisor(f.denominator,f.numerator);	
		f.denominator /=gys;
		f.denominator /=gys;
	}		
public:
	Fraction(int=0,int=1);
	Fraction(Fraction&);
	Fraction operator + (Fraction);
	Fraction operator - (Fraction);
	Fraction operator * (Fraction);
	Fraction operator / (Fraction);
	void Set(int=0,int=1);
	void disp(){cout<<"fraction="<<numerator<<"/"<<denominator<<endl;}
};

Fraction::Fraction(int n,int d)
{
	numerator=n;
	denominator=d;
}

Fraction::Fraction(Fraction& copy)
{
	numerator=copy.numerator;
	denominator=copy.denominator;
}

Fraction Fraction::operator + (Fraction f)
{
	Fraction result(1,1);
	result.numerator = numerator*f.denominator + denominator*f.numerator;
	result.denominator = denominator*f.denominator;
	return result;
}

Fraction Fraction::operator - (Fraction f)
{
	Fraction result(1,1);
	result.numerator = numerator*f.denominator - denominator*f.numerator;
	result.denominator = denominator*f.denominator;
	return result;
}

Fraction Fraction::operator * (Fraction f)
{
	Fraction result(1,1);
	result.numerator = numerator*f.numerator;
	result.denominator = denominator*f.denominator;
	return result;
}

Fraction Fraction::operator / (Fraction f)
{
	Fraction result(1,1);
	result.denominator = denominator*f.numerator;
	result.numerator = numerator*f.denominator;
	contracted(result);
	return result;
}

int main()
{
	int fz1,fm1,fz2,fm2;
	
	cin>>fz1>>fm1>>fz2>>fm2;
	Fraction f1(fz1,fm1),f2(fz2,fm2),f3(1,1);
	f3=f1+f2;	f3.disp();
	f3=f1-f2;	f3.disp();
	f3=f1*f2;	f3.disp();
	f3=f1/f2;	f3.disp();
	return 0;
}
