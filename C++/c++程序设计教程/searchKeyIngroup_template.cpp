#include <iostream>
using namespace std;

template <class T>
void search(T* group,int n)
{
	int label;
	int found=0;
	for(int j=0;j<n;j++)
	{
		cin>>group[j];
	}
	T key;
	cin>>key;
	
	for(label=0;label<n;label++)
		if(group[label]==key){
			found=1;
			break;
		}
	if(found)
		cout<<label+1<<endl;
	else cout<<"0"<<endl;
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
			search(group,n);
		}
		else if(type=='D')
		{
			double *group = new double[n];
			search(group,n);
		}
		else if(type=='C')
		{
			char *group = new char[n];
			search(group,n);
		}
		else if(type=='S')
		{
			string *group = new string[n];
			search(group,n);
		}
		else cerr<<"Type Error!"<<endl;
	}
}
