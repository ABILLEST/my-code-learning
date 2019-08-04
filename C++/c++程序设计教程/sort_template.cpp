#include <iostream>
using namespace std;

template <class T>
void sort(T* group,int n)
{
	for(int j=0;j<n;j++)
	{
		cin>>group[j];
	}
	
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(group[i]>group[j]){
                T tmp=group[j];
                group[j]=group[i];
                group[i]=tmp;
            }
            
    for(int j=0;j<n;j++)
	{
		cout<<group[j]<<" ";
	}
	cout<<endl;
}

int main()
{
	int t,n;
	char type;
	cin>>t;
	
	for(int q=0;q<t;q++)
	{
		cin>>type>>n;
		if(type=='I')
		{
			int *group = new int[n];
			sort(group,n);
		}
		else if(type=='D')
		{
			double *group = new double[n];
			sort(group,n);
		}
		else if(type=='C')
		{
			char *group = new char[n];
			sort(group,n);
		}
		else if(type=='S')
		{
			string *group = new string[n];
			sort(group,n);
		}
		else cerr<<"Type Error!"<<endl;
	}
}
