#include <iostream>
using namespace std;

void BiTreeArray_PreOder(int* arr, int pos, int n)
{   
    if(pos<=n)
    {
        if(arr[pos] != 0)
            cout<<arr[pos]<<" ";
        BiTreeArray_PreOder(arr, pos*2, n);
        BiTreeArray_PreOder(arr, pos*2 +1, n);
    }
}

void BiTreeArray_PreOder(int* arr, int n)
{
    int pos=1;
    BiTreeArray_PreOder(arr, pos, n);
    cout<<endl;
}

int main()
{
    int t, n;

    cin>>t;
    for(int i=0; i<t; ++i)
    {
        cin>>n;
        int *array = new int[n];
        for(int j=1; j<=n; ++j)
        {
            cin>>array[j];
        }
        BiTreeArray_PreOder(array, n);
    }
    return 0;
}