# include<iostream>
using namespace std;

//3to1
int main()
{
	int t,trans;
	int a1,a2,a3,b1,b2,b3;
	cin>>t;
	
	while(t--)
	{
		char *p1 = new char[10];
		char *p2 = new char[10];
		char *p3 = new char[10];
		char *i=NULL;
		cin>>p1>>p2>>p3;
		
		cin>>a1>>b1>>a2>>b2>>a3>>b3;
		if(b1>10) b1=b1%10;//overflow protection
		if(b2>10) b2=b2%10;
		if(b3>10) b3=b3%10;
		if(a1>b1){trans=a1;a1=b1;b1=trans;}
		if(a2>b2){trans=a2;a2=b3;b2=trans;}
		if(a3>b3){trans=a3;a3=b3;b3=trans;}
		
		int l=(b1-a1+1)+(b2-a2+1)+(b3-a3+1)+1;
		char *pn = new char[l];
		char *ipn=pn;
		for(i=p1+a1-1;i-p1<b1;i++)//combine
			*ipn++ = *i;
		for(i=p2+a2-1;i-p2<b2;i++)
			*ipn++ = *i;
		for(i=p3+a3-1;i-p3<b3;i++)
			*ipn++ = *i;
		*ipn = '\0';
		
		for(i=pn;i-pn<l;i++) cout<<*i;//output
		cout<<endl;
	 } 
	 return 0;
 } 
