#include <iostream>
#include <math.h>
using namespace std;

class quanternary
{
	int value;
public:
	quanternary():value(0){}
	quanternary(int n):value(n){}
	void Set(int n){value=n;}
	int getValue(){return value;}
	quanternary operator + (const quanternary &obj);	
};

quanternary quanternary::operator +(const quanternary &obj)
{
	quanternary result;
	int j;
	int dec_this=0,dec_obj=0;
	int temp1=this->value,temp2=obj.value;
	int temp3[10],t3;
	for(int i=0;temp1>0;temp1/=10,i++)
		dec_this=dec_this+(temp1%10)*(int)pow(4,i);
	for(int i=0;temp2>0;temp2/=10,i++)
		dec_obj=dec_obj+(temp2%10)*(int)pow(4,i);
		
	t3=dec_this+dec_obj;
	
	for(j=0;t3>0;t3/=4,++j)
		temp3[j] = t3%4;
	t3=0;
	--j;
	for(;j>=0;--j)
		t3 = t3*10+temp3[j];
	result.value=t3;
	return result;
}

int main()
{
	int n,num;
	quanternary sum;
	
	cin>>n;
	quanternary* qgroup = new quanternary[n];
	for(int i=0;i<n;i++){
		cin>>num;
		qgroup[i].Set(num);
	}
	for(int i=0;i<n;i++){
		sum=sum+qgroup[i];
	}
	cout<<sum.getValue()<<endl;
	return 0;
}
