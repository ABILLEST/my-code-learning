#include<iostream>
using namespace std;

//mark search
int main()
{
	
	int t,n,result,num;
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		int *mark = new int[n];
		int *p=NULL;
		for(p=mark;p-mark<n;p++)
			cin>>*p;
			
		int m= int(n/2);
		p=mark;
		for(int i=0; i<m;i++) p++;
		//p=mark+((n+1)/2)-1;
		cout<<*(p-1)<<' '<<*(p+1)<<endl;
		
		cin>>num;
		if(m<num)
        	for(int i=m; i<num-1; i++)
        		p++;
        else
            for(int i=num; i<=m; i++)
                p--;
		
		result = *(mark+num-1);
		cout<<*p<<endl;
		delete mark;
	}
	return 0;
}

