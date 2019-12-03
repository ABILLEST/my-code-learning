#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n;
    int TotalTimeA=0, TotalTimeB=0, TotalTimeC=0;
    int avrA=0, avrB=0, avrC=0;
    int sizeA=0, sizeB=0, sizeC=0;
    cin>>n;

    queue<int> qa,qb,qc;
    char type[n];
    int timelist[n];

    for(int i=0; i<n; ++i)
    {
        cin>>type[i];
    }

    for(int i=0; i<n; ++i)
    {
        cin>>timelist[i];
    }

    for(int i=0; i<n; ++i)
    {
        switch (type[i])
        {
        case 'A':
            qa.push(timelist[i]);
            break;
        case 'B':
            qb.push(timelist[i]);
            break;
        case 'C':
            qc.push(timelist[i]);
            break;
        
        default:
            break;
        }
    }

    sizeA = qa.size();
    sizeB = qb.size();
    sizeC = qc.size();

    while(!qa.empty())
    {
        TotalTimeA += qa.front();
        qa.pop();
    }
    while(!qb.empty())
    {
        TotalTimeB += qb.front();
        qb.pop();
    }
    while(!qc.empty())
    {
        TotalTimeC += qc.front();
        qc.pop();
    }

    avrA = TotalTimeA/sizeA;
    avrB = TotalTimeB/sizeB;
    avrC = TotalTimeC/sizeC;

    cout<<avrA<<endl<<avrB<<endl<<avrC<<endl;

    return 0;
    
}
