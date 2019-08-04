#include <iostream>
using namespace std;

template <class T>
void vote(T* group,int n)
{
	for(int j=0;j<n;j++)
	{
		cin>>group[j];
	}
	
	int counts[n];
	int index=0, nCount=0, maxCount=0;
	for(int p=0; p<n; p++)//记录每个元素的出现的个数 
	{
		for(int q=0; q<n; q++)
		{
			if(group[p]==group[q])
				nCount++;
		}
		/* 
		if(nCount>maxCount)
        {
            maxCount=nCount;
            index=p;
        }
        */
        counts[p]=nCount;
        nCount=0;
	}
	
	int maxIdx=0;
	for(int i=0;i<n;i++)
	{
		if(counts[i]>counts[maxIdx])
			maxIdx=i;
	}
	maxCount=counts[maxIdx];
	
	if (maxCount == 1)
	{
		printf("众数不存在!\n");
	}
	else {
		for (int i=0;i<n;i++)//去重（去掉同个数字）
		{
			for (int j=0;j<n;j++)
			{
				if (i!=j && group[i] == group[j] && counts[i] == maxCount)
				{
					counts[j] = 0;
				}
			}
		}
 
		for (int i=0;i<n;i++)//输出
		{
			if (counts[i] == maxCount)
			{
				cout<<group[i]<<" "<<maxCount<<endl;
			}
		}
	}
	
	//cout<<group[index]<<" "<<maxCount<<endl;
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
			vote(group,n);
		}
		else if(type=='C')
		{
			char *group = new char[n];
			vote(group,n);
		}
		else if(type=='S')
		{
			string *group = new string[n];
			vote(group,n);
		}
		else cerr<<"Type Error!"<<endl;
	}
}
