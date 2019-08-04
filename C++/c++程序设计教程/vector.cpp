#include <iostream>
#include <string.h> 
#include <math.h>
using namespace std;

static double PI = 3.1415926;

class vector
{
	int x,y;
public:
	vector(){}
	vector(int _x,int _y):x(_x),y(_y){}
	void set(int _x,int _y){x=_x;y=_y;}
	int operator / (const vector &obj);
};

int vector::operator / (const vector &obj)
{
	double result1 = atan2(y, x);
	double result2 = atan2(obj.y, obj.x);
	int a = (result1-result2)*180/PI;
}

int main()
{
	int t,x,y,maxAngle;
	cin>>t;
	//input
	vector* vgroup = new vector[t];
	for(int i=0;i<t;i++)
	{
		cin>>x>>y;
		vgroup[i].set(x,y);
	}
	
	//processing
	for(int i=0;i<t-1;i++)
		for(int j=i+1;j<t;j++)
		{
			unsigned int angle;
			angle = abs(vgroup[i] / vgroup[j]);
			if(angle>maxAngle)
				maxAngle = angle;	 
		}
	
	//output
	cout<<"角度相差最大为"<<maxAngle<<"度。"<<endl;
}
