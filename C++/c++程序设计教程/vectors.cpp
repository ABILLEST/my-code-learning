#include <iostream>
#include <string.h> 
#include <math.h>
using namespace std;

static double PI = 3.1415926;

class vector
{
	int x,y;
	int *vec;
public:
	vector(){}
	vector(int v[10]);
	vector(vector& v);
	//vector(int _x,int _y):x(_x),y(_y){}
	void set(int _x,int _y){x=_x;y=_y;}
	vector operator + (vector& v);
	vector operator - (vector& v);
	int operator / (const vector &obj);
	friend ostream& operator << (ostream& out, vector& v);
};

vector::vector(int v[10])
{
	vec = new int[10];
	for(int i=0;i<10;i++)
		vec[i] = v[i];
}

vector::vector(vector& v)
{
	x=v.x;
	y=v.y;
	vec = new int[10];
	for(int i=0;i<10;i++)
		vec[i] = v.vec[i];
}

vector vector::operator + (vector& v)
{
	vector result(*this);
	for(int i=0;i<10;i++)
		result.vec[i] = this->vec[i]+v.vec[i];
	return result;
}

vector vector::operator - (vector& v)
{
	vector result(*this);
	for(int i=0;i<10;i++)
		result.vec[i] = this->vec[i]-v.vec[i];
	return result;
}

int vector::operator / (const vector &obj)
{
	double result1 = atan2(y, x);
	double result2 = atan2(obj.y, obj.x);
	int a = (result1-result2)*180/PI;
}

ostream& operator << (ostream& out, vector& v)
{
	for(int i=0;i<10;i++)
		printf("%d ",v.vec[i]);
	printf("\n");
}

int main()
{
	int v[10];
	
	for(int i=0;i<10;i++)
		cin>>v[i];
	vector V1(v);
	
	for(int i=0;i<10;i++)
		cin>>v[i];
	vector V2(v);
	
	vector V3;
	V3 = V1+V2;
	cout<<V3;
	V3 = V1-V2;
	cout<<V3;
	
	return 1;
}
