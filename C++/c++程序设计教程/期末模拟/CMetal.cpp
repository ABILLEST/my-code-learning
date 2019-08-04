#include <iostream>
#include <string>
using namespace std;

class CMetal
{
private:
	int hardness, weight, volume;
public:
	CMetal(){}
	CMetal(int,int,int);
	CMetal(CMetal&);
	void display(); 
	friend CMetal& operator + (CMetal&,const CMetal&);
	friend CMetal& operator * (CMetal&,int);
	friend void operator ++ (CMetal&);
	friend void operator -- (CMetal&,int);
};

CMetal::CMetal(int H,int W, int V)
{
	hardness = H;
	weight = W;
	volume = V;
}

void CMetal::display()
{
	cout<<"硬度"<<hardness<<"--重量"<<weight<<"--体积"<<volume<<endl;
}

CMetal::CMetal(CMetal& c)
{
	this->hardness = c.hardness;
	this->weight = c.weight;
	this->volume = c.volume;
}

CMetal& operator + (CMetal& m1,const CMetal& m2)
{
	static CMetal m3;
	m3.hardness = m1.hardness + m2.hardness;
	m3.weight = m1.weight + m2.weight;
	m3.volume = m1.volume + m2.volume;
	return m3;
}

CMetal& operator * (CMetal& m1,int n)
{
	static CMetal m3;
	m3.hardness = m1.hardness;
	m3.weight = m1.weight;
	m3.volume = m1.volume*n;
	return m3;
}

void operator ++ (CMetal& m1)
{
	m1.hardness++;
	m1.weight += 0.1*m1.weight;
	m1.volume += 0.1*m1.volume;
}

void operator -- (CMetal& m1,int)
{
	m1.hardness--;
	m1.weight -= 0.1*m1.weight;
	m1.volume -= 0.1*m1.volume;
}

int main()
{
	int H, W, V,n;
	
	cin>>H>>W>>V;
	CMetal m1(H,W,V);
	
	cin>>H>>W>>V;
	CMetal m2(H,W,V);
	
	CMetal m3 = m1+m2;
	m3.display();
	
	cin>>n;
	m3 = m1*n;
	m3.display();
	
	++m1;
	m1.display();
	
	m2--;
	m2.display();

	return 0;
}
