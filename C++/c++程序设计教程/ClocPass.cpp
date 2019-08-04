#include <iostream>
using namespace std;

class Counter
{
protected:
	int value;
public:
	Counter(int v):value(v){}
	int increment(){value++;return 1;}
	int getvalue(){return value;}
};

class cycleCounter: public Counter
{
	int min_value,max_value;
public:
	cycleCounter(int v,int minv,int maxv):Counter(v),min_value(minv),max_value(maxv){}
	virtual int increment();
};

class Cloc
{
	cycleCounter hour,minute,second;
public:
	Cloc(cycleCounter h,cycleCounter m,cycleCounter s):hour(h),minute(m),second(s){}
	void time(int s);
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
	/*
	else if(value<=min_value){
		value = value+1+min_value;
		return -1;
	}
	*/
}

void Cloc::time(int s)
{
    for(int i=0;i<s;i++)
    {
    	if(second.increment()==1)
    		if(minute.increment()==1)
				 hour.increment();
	}	
}

//Cloc pass
int main()
{
    int n;
	int hvalue,mvalue,svalue,pass;

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>hvalue>>mvalue>>svalue;
        cycleCounter h(hvalue,0,24);
		cycleCounter m(mvalue,0,60);
		cycleCounter s(svalue,0,60);
        cin>>pass;
        Cloc cl(h,m,s);
    	cl.time(pass);
    	cl.display();
    }
}
