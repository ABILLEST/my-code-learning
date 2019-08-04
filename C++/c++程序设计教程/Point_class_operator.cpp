#include <iostream>
using namespace std;

class Point
{
	int x,y,z;
public:
	Point(int X=0,int Y=0,int Z=0)
	{x=X;y=Y;z=Z;}
	Point(Point& a)
	{x=a.x;y=a.y;z=a.z;}
	friend Point operator ++ (Point &a);
	friend Point operator ++ (Point&,int);//∫Û÷√ 
	friend Point operator -- (Point &a);
	friend Point operator -- (Point&,int);//∫Û÷√ 
	void show()
	{cout<<"x="<<x<<" "<<"y="<<y<<" "<<"z="<<z<<endl;}
};

Point operator ++ (Point &a)
{
	++a.x;
	++a.y;
	++a.z;
	return a; 
}

Point operator ++ (Point& a,int)
{
	Point orig(a.x,a.y,a.z);
	++a.x;
	++a.y;
	++a.z;
	return orig; 
}

Point operator -- (Point &a)
{
	--a.x;
	--a.y;
	--a.z;
	return a; 
}

Point operator -- (Point& a,int)
{
	Point orig(a.x,a.y,a.z);
	--a.x;
	--a.y;
	--a.z;
	return orig; 
}

int main()
{
	int x,y,z;
	cin>>x>>y>>z;
	Point p1(x,y,z),p2(0,0,0);
	
	p1++;
	p1.show();
	p1--;
	p2=p1++;
	p2.show();
	p1--;
	++p1;
	p1.show();
	p1.show();
	p1--;
	p2=p1--;
	p1.show();
	p2.show();
	p1++;
	--p1;
	p1.show();
	p1.show();
	
	return 1;
}
