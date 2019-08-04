#include <iostream>
using namespace std;

#define add_mode 1
#define sub_mode 0

class Complex
{
	double rp;
	double ip;
	int mode;
	public:
		Complex();
		Complex(double,double);
		Complex(Complex &c);
		Complex add(Complex);
		Complex sub(Complex);
		void print();
};

Complex::Complex()
{
	rp=1, ip=1;
}

Complex::Complex(double r, double i)
{
	rp = r;
	ip = i;
}

Complex::Complex(Complex &c)
{
	rp = c.rp;
	ip = c.ip;
}

Complex Complex::add(Complex c)
{
	Complex sum;
	sum.rp= rp + c.rp;
	sum.ip= ip + c.ip;
	return sum;
}

Complex Complex::sub(Complex c)
{
	Complex remainder;
	remainder.rp = rp - c.rp;
	remainder.ip = ip - c.ip;
	return remainder;
}

void Complex::print()
{
	if(rp!=0){
		if(ip>0&&ip!=1){
			cout<<rp<<"+"<<ip<<"i";
		}
		else if(ip==0){
			cout<<rp;
		}
		else if(ip==1){
			cout<<rp<<"+i";
		}
		else{
			cout<<rp<<ip<<"i";
		}
	}
	else
	{
		if(ip!=0&&ip!=1){
			cout<<ip<<"i";
		}
		else if(ip==1){
			cout<<"i";
		} 
		else{
			cout<<0;
		}
	}	
}

//complex calculate
int main()
{
	int t;
	double rp1,ip1,rp2,ip2;
	cin>>t;
	
	
	
	for(int i=0; i<t; i++)
	{
		cin>>rp1>>ip1>>rp2>>ip2;
		Complex a(rp1,ip1),b(rp2,ip2),result;
		
		
		cout<<"sum:";
		result = a.add(b);
		result.print();
		cout<<endl;
		
		cout<<"remainder:";
		result = a.sub(b);
		result.print();
		cout<<endl;
	}
	return 0;
}
