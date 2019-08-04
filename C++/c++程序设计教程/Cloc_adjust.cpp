#include <iostream>
#include <math.h>
using namespace std;

class Counter
{
protected:
	int value;
public:
	Counter(int v):value(v){}
	int increment(){value++;return 1;}
	int decrement(){value--;return 1;}
	int getvalue(){return value;}
};

class cycleCounter: public Counter
{
	int min_value,max_value;
public:
	cycleCounter(int v,int minv,int maxv):Counter(v),min_value(minv),max_value(maxv){}
	virtual int increment();
	virtual int decrement();
};

class Cloc
{
	cycleCounter hour,minute,second;
public:
	Cloc(cycleCounter h,cycleCounter m,cycleCounter s):hour(h),minute(m),second(s){}
	void change(int s);
	friend Cloc operator ++ (Cloc& a);
	friend Cloc operator -- (Cloc& a,int);//后置 
	void display(){cout<<hour.getvalue()<<":"<<minute.getvalue()<<":"<<second.getvalue()<<endl;}
};

int cycleCounter::increment()
{
	value++;
	if(value<max_value&&value>min_value){
		return 0;
	}
	else if(value>=max_value){
		value -=max_value;
		return 1;
	}
	else if(value<=min_value){
		value = value+1+min_value;
		return -1;
	}
	
}

int cycleCounter::decrement()
{
	value--;
	if(value<max_value&&value>min_value){
		return 0;
	}
	else if(value>=max_value){
		value -=max_value;
		return 1;
	}
	else if(value<=min_value){
		value += max_value;
		return -1;
	}
	
}

//调快 
Cloc operator ++ (Cloc &a)
{
	if(a.second.increment()==1)
		if(a.minute.increment()==1)
			 a.hour.increment();
}

//调慢 
Cloc operator -- (Cloc& a,int)
{
	if(a.second.decrement()==-1)
		if(a.minute.decrement()==-1)
			 a.hour.decrement();
}

//Cloc change
int main()
{
	int hvalue,mvalue,svalue;
	int t;
	int x;
	
	cin>>hvalue>>mvalue>>svalue;
    cycleCounter h(hvalue,0,12);
	cycleCounter m(mvalue,0,60);
	cycleCounter s(svalue,0,60);
	Cloc c(h,m,s);
	 
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>x;
		if(x>0){
			for(int j=0;j<x;j++) 
				++c;
		}
		else{
			int abslt_value = abs(x);
			for(int j=0;j<abslt_value;j++) 
				c--;
		}
		c.display();
	}
	
}
