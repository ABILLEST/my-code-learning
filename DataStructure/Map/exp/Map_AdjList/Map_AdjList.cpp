#include <iostream>
using namespace std;

class AdjNode
{
public :
    int info;
    char data;
    AdjNode* next;
    AdjNode(){}
    AdjNode(int in, char ch)
    {
        info= in;
        data= ch;
        next= NULL;
    }
};
 
int find(AdjNode* ve[], int n, char ch)
{
    for(int i= 0; i< n; i++)
      if(ve[i]->data == ch)
        return i;
    return -1;
}


int main()
{
    int t;
    cin>>t;
     
    for(int i=0; i<t; ++i)
    {
        int n, k;
        cin>>n>>k;
        int pos1 = 0;
        AdjNode* vec[n];
        AdjNode* ve[n];
         
         
        for(int i= 0; i< n; i++)
        {
            char ch;
            cin>>ch;
             
            vec[i] = new AdjNode(i, ch);
            ve[i] = vec[i];
        }
         
        for(int i= 0; i< k; i++)
        {
            char a, b;
            cin>>a>>b;
             
            int pos1 = find(vec, n, a);
            int pos2 = find(vec, n, b);
            ve[pos1]->next = new AdjNode(pos2, b);
            ve[pos1] = ve[pos1]->next;
        }
         
        for(int i= 0;  i< n; i++)
        {
            cout<<i<<' '<<vec[i]->data<<'-';
             
            AdjNode* p = vec[i]->next;
            while(p){
                cout<<p->info<<'-';
                p = p->next;
            }
            cout<<'^'<<endl;
        }
    } 

    return 0;
}