#include <iostream>
#include <iomanip>
using namespace std;

static double PI = 3.1415926;

class Shape
{
public:
	virtual double area()=0;	
	virtual void set1(double)=0;
	virtual void set2(double,double)=0;
};

class Circle : public Shape
{
	double r;
public:
	Circle(){}
	virtual void set2(double,double){}
	virtual void set1(double _r){r=_r;}
	virtual double area();
};

class Square : public Shape
{
	double a;
public:
	virtual void set2(double,double){}
	virtual void set1(double _a){a=_a;}
	virtual double area();	
};

class Rectangle : public Shape
{
	double l,w;
public:
	virtual void set1(double){}
	virtual void set2(double _l,double _w){l=_l; w=_w;}
	virtual double area();
};

double Circle::area()
{
	return (PI*r*r);
}

double Square::area()
{
	return a*a;
}

double Rectangle::area()
{
	return l*w;
}

//
int main()
{
	int t;
	double r,a,l,w;
	cin>>t;
	
	//input
	Shape* p[3];
	Circle* cp = new Circle[t];
	Square* sp = new Square[t];
	Rectangle* rp = new Rectangle[t];
	for(int i=0;i<t;i++)
	{
		cin>>r>>a>>l>>w;
		p[i] = &cp[i];
		p[i]->set1(r);
		p[i] = &sp[i];
		p[i]->set1(a);
		p[i] = &rp[i];
		p[i]->set2(l,w);
	}
	
	
	//output
	for(int i=0;i<t;i++)
	{
		cout<<fixed<<setprecision(2)<<cp[i].area()<<endl
			<<fixed<<setprecision(2)<<sp[i].area()<<endl
			<<fixed<<setprecision(2)<<rp[i].area()<<endl;
	}
}
