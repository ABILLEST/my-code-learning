#include <iostream>
using namespace std;

template <class T>
void combineOut(T &tld,T &ytj,int n)
{
	//ÊäÈëÒĞÌì½£ 
	for(int j=0;j<n;j++)
	{
		cin>>ytj[j];
	}
	//ÊäÈëÍÀÁúµ¶ 
	for(int j=0;j<n;j++)
	{
		cin>>tld[j];
	}
	
	for(int j=0;j<n;j++)
	{
		cout<<tld[j];
	}
	for(int j=0;j<n;j++)
	{
		cout<<ytj[j];
	}
	cout<<endl;
}

//function template 
int main()
{
	int t,n;
	char type;
	cin>>t;
	
	for(int i=0;i<t;i++)
	{
		cin>>type>>n;
		if(type=='I')
		{
			int *tld = new int[n];
			int *ytj = new int[n];
			combineOut(tld,ytj,n);
		}
		else if(type=='D')
		{
			double *tld = new double[n];
			double *ytj = new double[n];
			combineOut(tld,ytj,n);
		}
		else if(type=='C')
		{
			char *tld = new char[n];
			char *ytj = new char[n];
			combineOut(tld,ytj,n);
		}
		else cerr<<"Type Error!"<<endl;
	}
}
