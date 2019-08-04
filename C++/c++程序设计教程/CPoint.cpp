#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

#define pi 3.14

class CPoint
{
protected:
	double x,y;
public:
	void setPoint(double,double);
	void PPrint();
};

class CCircle : public CPoint
{
protected:
	double r;
public:
	double getArea();
	void setCircle(double,double,double);
	void CirPrint();
};

class CCylinder : public CCircle
{
protected:
	double h;
public:
	double getV();
	void setCylinder(double,double,double,double);
	void CyPrint();
};

void CPoint::setPoint(double _x, double _y)
{
	x=_x;	y=_y;
}

void CCircle::setCircle(double _x,double _y,double _r)
{
	x=_x;	y=_y;	r=_r;
}

void CCylinder::setCylinder(double _x,double _y,double _r,double _h)
{
	x=_x;	y=_y;	r=_r;	h=_h;
}

void CPoint::PPrint()
{
	cout<<"("<<x<<","<<y<<")";
}

void CCircle::CirPrint()
{
	cout<<"Circle:";
	PPrint();
	cout<<","<<r<<endl;
}

void CCylinder::CyPrint()
{
	cout<<"Cylinder:";
	PPrint();
	cout<<","<<r<<","<<h<<endl;
}

double CCircle::getArea()
{
	return (pi*r*r);
} 

double CCylinder::getV()
{
	return (getArea()*h);
}

int main()
{
	double x1,y1,r1;
	double x2,y2,r2,h;
	
	cin>>x1>>y1>>r1;
	CCircle cir;
	cir.setCircle(x1,y1,r1);
	cir.CirPrint();
	cout<<"Area:"<<cir.getArea()<<endl;
	
	cin>>x2>>y2>>r2>>h;
	CCylinder cy;
	cy.setCylinder(x2,y2,r2,h);
	cy.CyPrint();
	cout<<"Volume:"<<cy.getV()<<endl;

	return 0;
}
