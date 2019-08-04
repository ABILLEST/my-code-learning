#include <iostream>
#include <iomanip>
#include <cmath> 
using namespace std;

#define pi 3.14

//-----类定义------
class Point
{
	
		double x,y;
	public:
		Point();
		Point(double,double);
		~Point();
		void setPoint(double _x,double _y);
		double GetX();
		double GetY();
};


class Circle
{
	private:
		double x,y;
		double r;
	public:
		Circle(double,double,double);
		~Circle();
		void setCenter(double _x,double _y);
		void setRadius(double _r);
		double getArea();
		double getLength();
		int contain(Point *p);
};

//----类实现------
Point::Point()
{
	x=0,y=0;
}

Point::Point(double _x,double _y)
{
	x = _x;
	y = _y;
}

Point::~Point()
{
	cout<<"point clear"<<endl;
	x=0,y=0;
}

void Point::setPoint(double _x,double _y)
{
	x=_x;
	y=_y;
};

double Point::GetX()
{
	return x;
}; 

double Point::GetY()
{
	return y;
}; 

Circle::Circle(double _x,double _y,double _r)
{
	x=_x;
	y=_y;
	r=_r;
}

Circle::~Circle()
{
	cout<<"circle clear"<<endl;
	x=0,y=0,r;
}

void Circle::setCenter(double _x,double _y)
{
	x=_x;
	y=_y;
};

void Circle::setRadius(double _r)
{
	r=_r;
};

double Circle::getArea()
{
	return (pi*r*r);
};

double Circle::getLength()
{
	return (2*pi*r);
};

int Circle::contain(Point *p)
{
	double dis;
	dis = sqrt((p->GetX()-x)*(p->GetX()-x) + (p->GetY()-y)*(p->GetY()-y));
	if(dis<=r) return 1;
	else return 0;
};

//-----主函数-----
//isContain
int main()
{
	int n;
	double x1,x2,y1,y2,r;
	
	cin>>x1>>y1;
	Point p(x1,y1);
	Point *p1= &p;
	
//1
/*	cout<<fixed<<setprecision(2)<<c.getArea()<<" "<<c.getLength()<<endl;
	if(c.contain(p)==1)
		cout<<"yes"<<endl;
	else if(c.contain(p)==0)
		cout<<"no"<<endl;
	else cout<<"error"<<endl;
*/		

//2
	cin>>n;
	Point* group = new Point[n];
	Point* p2 = NULL;
	
	for(p2=group; p2-group<n; p2++)
	{
		cin>>x1>>y1;
		p2->setPoint(x1,y1);
	}
	
	cin>>x2>>y2>>r;
	Circle c(x2,y2,r);

	if(c.contain(p1)==1)
		cout<<"in"<<endl;
	else if(c.contain(p1)==0)
		cout<<"out"<<endl;
	else cout<<"error"<<endl;
	
	for(p2=group; p2-group<n; p2++)
	{
		if(c.contain(p2)==1)
			cout<<"in"<<endl;
		else if(c.contain(p2)==0)
			cout<<"out"<<endl;
		else cout<<"error"<<endl;
	}
	


	//delete []group;
	return 0;
	
}
