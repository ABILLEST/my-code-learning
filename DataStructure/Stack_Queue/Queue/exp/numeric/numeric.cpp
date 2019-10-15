#include <queue>
#include <iostream>
#include <iomanip>
#include <stack>
using namespace std;

int main()
{

    int t, k;
    double num_to_be_convert;
    cin>>t;

    for(int i=0; i<t; ++i)
    {
        stack<int> intPartList;
        
        queue<double> decPartList;

        cin>>num_to_be_convert>>k;
        
        int intPart = int(num_to_be_convert);
        double decPart = num_to_be_convert - intPart;

        while(intPart>0)
        {
            int temp = intPart % k;
            intPartList.push(temp);
            intPart /= k;
        }

        while(decPart<1)
        {
            decPart *= k;
            int temp = int(decPart);
            decPartList.push(temp);
        }

        while(!intPartList.empty())
        {
            int temp = intPartList.top();
            intPartList.pop();
            if(k>10)
            {
                switch (temp)
                {
                case 10:
                    cout<<"A";
                    break;
                case 11:
                    cout<<"B";
                    break;
                case 12:
                    cout<<"C";
                    break;
                case 13:
                    cout<<"D";
                    break;
                case 14:
                    cout<<"E";
                    break;
                case 15:
                    cout<<"F";
                    break;
                
                default:
                    break;
                }
                    
            }
            else cout<<temp;
        }
            

        cout<<".";
        int decCount=0;;
        while (!decPartList.empty())
        {
            int temp = decPartList.front();
            cout<<temp;
            decCount++;
            decPartList.pop();
        }
        while(decCount<3)  {
            cout<<'0';decCount++;}
        cout<<endl;
    }

    return 0;
    
}