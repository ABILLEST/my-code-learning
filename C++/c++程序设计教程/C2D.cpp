#include <iostream>
#include <math.h>
using namespace std;

class C2D
{
protected:
	double x,y;
public:
	C2D(double _x,double _y);
	virtual double getDistance(double _x,double _y);				//计算改点到原点的距离 
};

class C3D : public C2D
{
	double z;
public:
	C3D(double _x,double _y,double _z);
	virtual double getDistance(double x1,double y1,double z1);				//计算改点到原点的距离 	
};

C2D::C2D(double _x,double _y)
{
	x=_x; y=_y;
}

double C2D::getDistance(double x1,double y1)
{
	return (sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1)));
}

C3D::C3D(double _x,double _y,double _z) : C2D( _x, _y)
{
	z=_z;
}

double C3D::getDistance(double x1,double y1,double z1)
{
	return (sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1)+(z-z1)*(z-z1)));
}

int main()
{
	int x1,y1;
	int x2,y2,z2;
	int x3,y3,z3;
	
	cin>>x1>>y1
		>>x2>>y2>>z2
		>>x3>>y3>>z3;
		
	C2D p1(x1,y1);
	C3D p2(x2,y2,z2);
	C3D p3(x3,y3,z3);
	
	cout<<p1.getDistance(0,0)<<endl
		<<p2.getDistance(0,0,0)<<endl
		<<p3.getDistance(0,0,0)<<endl;
		
	p1 = p3;
	cout<<p1.getDistance(0,0)<<endl;
} 
