#include <iostream>
using namespace std;

int main()
{
    int t,n,searchNum,blockNum;
    
    cin>>n;
    int * nums = new int[n+1];
    for(int i=1; i<=n; ++i)
    {
        cin>>nums[i];
    }
    nums[0] = n;

    cin>>blockNum;
    int * biggest = new int[blockNum];
    for(int i=0; i<blockNum; ++i)
    {
        cin>>biggest[i];
    }
    int * index = new int[blockNum];
    index[0] = 1;
    int counter = 1;
    for(int i=1; i<n; ++i)
    {
        if(counter >= blockNum)
            break;
        if(nums[i] > biggest[counter-1])
        {
            index[counter] = i;
            counter++;
        }
    }

    cin>>t;
    for(int i=0; i<t; ++i)
    {
        int j,k;
        bool found=false;
        counter = 0;
        cin>>searchNum;

        //block positioning
        for(j=0; j<blockNum; ++j)
        {
            counter++;
            if(searchNum<=biggest[j])
                break;
        }

        if(j>=blockNum)
        {
            cout<<"error"<<endl;
            continue;
        }

        //search in block
        for(k=index[j]; nums[k]<=biggest[j]; ++k)
        {
            counter++;
            if(nums[k] == searchNum)
            {
                found = true;
                break;
            }
                
        }

        if(found)
            cout<<k<<"-"<<counter<<endl;
        else cout<<"error"<<endl;
    }

    return 0;
    
}
