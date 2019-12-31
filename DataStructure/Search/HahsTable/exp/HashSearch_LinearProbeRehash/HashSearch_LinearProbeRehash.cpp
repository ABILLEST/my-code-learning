#include<iostream>
using namespace std;

#define DIVIDER 11
#define ELEMTYPE int

void init(ELEMTYPE* hashtable, int len)
{
    for(int i= 0; i< len; i++)
    {
        hashtable[i] = -1;
    }
}

void build_hashtable_LPR(ELEMTYPE* hashtable, int keyQty, int tableLen)
{
    int data;
    for(int i= 0; i< keyQty; i++)
    {
        cin>>data;
        int loc = data%DIVIDER;
        while(hashtable[loc]!=-1 && loc<=tableLen)  loc = (loc+1) %tableLen;
        hashtable[loc] = data;
    }
}

void output_hashtable(ELEMTYPE* hashtable, int tableLen)
{
    for(int i= 0; i< tableLen; i++)
    {
        if(hashtable[i]!=-1)    
            cout<<hashtable[i]<<" ";
        else cout<<"NULL ";
    }
    cout<<endl;
}

void search_hashtable(ELEMTYPE* hashtable, int key, int tableLen)
{
    int loc, counter=0;
    while(true)
    {
        loc = (key%11 + counter) % tableLen; //positioning
        counter++;
        if(hashtable[loc] == key)
        {
            cout<<"1"<<' '<<counter<<' '<<loc+1<<endl;
            break;
        }
        else if(counter == tableLen || hashtable[loc]==-1)
        {
            cout<<"0"<<' '<<counter<<endl;
            break;
        }
    }
}

int main()
{
    int n, t, k, m, data;

    cin>>t;
    for(int i= 0; i< t; i++)
    {
        cin>>m>>n;
        int *hashtable = new int[m];
        init(hashtable, m);
        build_hashtable_LPR(hashtable, n, m);
        output_hashtable(hashtable, m);

        //search
        cin>>k;
        for(int i= 0; i< k; i++)        
        {
            int counter=0, loc;
            cin>>data;
            search_hashtable(hashtable, data, m);
        }
    }
        
    return 0;
}