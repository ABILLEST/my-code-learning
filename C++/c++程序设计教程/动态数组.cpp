# include<iostream>
using namespace std;

//Dynamic arrays
int main()
{
	int t,n;
	char type;
	cin>>t;
	
	while(t--)
	{
		
		cin>>type;
		cin>>n;
		if(type=='I'){
			int sum,avr;
			int *i;
			int *p=new int[n];
			for(i=p;i-p<n;i++) cin>>*i;
			for(i=p;i-p<n;i++) sum+=*i;
			avr = sum/n;
			cout<<avr<<endl;
		} 
		else if(type=='C'){
			char *i;
			char *p=new char[n];
			for(i=p;i-p<n;i++) cin>>*i;
			
			char max=*p;
			for(i=p;i-p<n;i++)
				if(max<*i)
					max = *i;
			cout<<max<<endl;
		} 
		else if(type=='F'){
			float *i;
			float *p=new float[n];
			for(i=p;i-p<n;i++) cin>>*i;
			float min=*p;
				for(i=p;i-p<n;i++)
					if(min>*i)
						min = *i;
			cout<<min<<endl;
		} 
		else cout<<"Type error"<<endl;
		
	 } 
	 return 0;
 } 
