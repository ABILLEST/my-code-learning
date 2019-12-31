#include <iostream>
using namespace std;

#define NOT_FOUND 0

int Binary_Search(int* array, int key)
{
    int low=1,high=array[0],mid;

    while(low<=high)
    {
        mid = (low + high) / 2;
        if(key == array[mid])
            return mid;
        else if(key < array[mid])
            high = mid - 1;
        else low = mid + 1;
    }
    return NOT_FOUND;
}

int main()
{
    int t,n,searchNum;
    
    cin>>n;
    int * nums = new int[n];
    for(int i=1; i<=n; ++i)
    {
        cin>>nums[i];
    }
    nums[0] = n;

    cin>>t;
    for(int i=0; i<t; ++i)
    {
        cin>>searchNum;
        int index = Binary_Search(nums, searchNum);
        if(index)
            cout<<index<<endl;
        else cout<<"error"<<endl;
    }

    return 0;
    
}
