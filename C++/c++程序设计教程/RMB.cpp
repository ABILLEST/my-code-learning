#include <iostream>
using namespace std;

class RMB
{
	unsigned int yuan,jiao,fen;
public:
	RMB(double r);
	void show()
	{cout<<"yuan="<<yuan<<" jiao="<<jiao<<" fen="<<fen<<endl;}
};

RMB::RMB(double r)
{
	yuan = (r*100)/100;
	jiao = int(((r*100)/10.0)+0.0000001)%10;
	fen = int((r*100)+0.0000001)%10;
}

int main()
{
	int t;
	double amount;
	
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>amount;
		RMB rmb(amount);
		rmb.show();
	}
	
	return 1;
}
