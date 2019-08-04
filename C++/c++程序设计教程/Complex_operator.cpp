#include <iostream>
using namespace std;

class Complex
{
	float Real,Image;
public:
	Complex(float x=0,float y=0){Real=x;Image=y;}
	Complex(Complex&);
	Complex operator + (Complex);
	Complex operator - (Complex);
	Complex operator * (Complex);
	void Set(int=0,int=1);
	void show()
	{cout<<"Real="<<Real<<" Image="<<Image<<endl;}
};

Complex::Complex(Complex &c)
{
	Real = c.Real;
	Image = c.Image;
}

Complex Complex::operator + (Complex c)
{
	Complex result;
	result.Real= Real + c.Real;
	result.Image= Image + c.Image;
	return result;
}

Complex Complex::operator - (Complex c)
{
	Complex result;
	result.Real= Real - c.Real;
	result.Image= Image - c.Image;
	return result;
}

Complex Complex::operator * (Complex c)
{
	Complex result;
	result.Real= Real*c.Real - Image*c.Image;
	result.Image= Real*c.Image + Image*c.Real;
	return result;
}

int main()
{
	float r1,i1,r2,i2;
	
	cin>>r1>>i1>>r2>>i2;
	Complex c1(r1,i1),c2(r2,i2),c3(0,0);
	c3=c1+c2;	c3.show();
	c3=c1-c2;	c3.show();
	c3=c1*c2;	c3.show();
	return 0;
}
