#include <iostream>
using namespace std;
 
class CStack
{
public:
    CStack();
    CStack(int s);
    CStack(CStack &r_s);
    int get(int index);
    void push(int n);
    int isEmpty();
    int isFull();
    int pop();
    ~CStack();
private:
    int *a;
    int size;
    int top;
};
 
CStack::CStack()
{
    cout<<"Constructor."<<endl;
    a = new int[10];
}
 
CStack::CStack(int s)
{
    size=s;
    cout<<"Constructor."<<endl;
    a = new int[size];
}
 
int CStack::get(int index)
{
    return (*(a+index));
}
 
void CStack::push(int n)
{   
    *(a+top) = n;
    top++;
     
}
 
int CStack::isEmpty()
{
    if(!top) 
        return 1;
    else
        return 0;
}
 
int CStack::isFull()
{
    if(top==size) 
        return 1;
    else
        return 0;
}
 
int CStack::pop()
{
    top--;
    return (*(a+top));
}
 
CStack::~CStack()
{
    cout<<"Destructor."<<endl;
    delete a;
}
 
//CStack class
int main()
{
    int t, size, n;
    cin>>t;
     
    for(int i=0; i<t; i++)
    {
        cin>>size;
        CStack s(size);
        //if(s.isEmpty())
            for(; !s.isFull();)
            {
                cin>>n;
                s.push(n);
            }
        for(; !s.isEmpty();)
            {
                cout<<s.pop()<<" ";
            }
    }
     
    return 0;
}
