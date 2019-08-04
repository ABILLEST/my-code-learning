#include <iostream>
using namespace std;

class CVehicle
{
protected:
	int max_speed,speed,weight;
public:
	CVehicle(int _max_speed,int _speed,int _weight);
	virtual void display();
};

class CBicycle : virtual public CVehicle
{
protected:
	int height;
public:
	CBicycle(int _height,int _max_speed,int _speed,int _weight);
	void display();
};

class CMotocar : virtual public CVehicle
{
protected:
	int seat_num;
public:
	CMotocar(int _seat_num,int _max_speed,int _speed,int _weight);
	void display();
};

class CMotocycle : public CBicycle, public CMotocar
{
public:
	CMotocycle(int _height,int _seat_num,int _max_speed,int _speed,int _weight);
	void display();
};

CVehicle::CVehicle(int _max_speed,int _speed,int _weight)
{ max_speed=_max_speed; speed=_speed; weight=_weight;}

void CVehicle::display()
{
	cout<<"Vehicle:"<<endl
		<<"max_speed:"<<max_speed<<endl
		<<"speed:"<<speed<<endl
		<<"weight:"<<weight<<endl<<endl;
}

CBicycle::CBicycle(int _height,int _max_speed,int _speed,int _weight)
			:CVehicle(_max_speed,_speed,_weight)
{ height = _height;}

void CBicycle::display()
{
	cout<<"Bicycle:"<<endl
		<<"max_speed:"<<max_speed<<endl
		<<"speed:"<<speed<<endl
		<<"weight:"<<weight<<endl
		<<"height:"<<height<<endl<<endl;
}

CMotocar::CMotocar(int _seat_num,int _max_speed,int _speed,int _weight)
			:CVehicle(_max_speed,_speed,_weight)
{ seat_num=_seat_num;}

void CMotocar::display()
{
	cout<<"Motocar:"<<endl
		<<"max_speed:"<<max_speed<<endl
		<<"speed:"<<speed<<endl
		<<"weight:"<<weight<<endl
		<<"seat_num:"<<seat_num<<endl<<endl;
}

CMotocycle::CMotocycle(int _height,int _seat_num,int _max_speed,int _speed,int _weight)
			:CVehicle(_max_speed,_speed,_weight),CMotocar(_seat_num,_max_speed,_speed,_weight)
			,CBicycle( _height, _max_speed, _speed, _weight)
{}

void CMotocycle::display()
{
	cout<<"Motocycle:"<<endl
		<<"max_speed:"<<max_speed<<endl
		<<"speed:"<<speed<<endl
		<<"weight:"<<weight<<endl
		<<"height:"<<height<<endl
		<<"seat_num:"<<seat_num<<endl<<endl;
}

//multiple inherit2
int main()
{
	int maxs,s,w,h,seatnum;
	
	cin>>maxs>>s>>w;
	CVehicle v(maxs,s,w);
	v.display();
	
	cin>>h;
	CBicycle b(h,maxs,s,w);
	b.display();
	
	cin>>seatnum;
	CMotocar mcar(seatnum,maxs,s,w);
	mcar.display();
	
	CMotocycle mcycle(h,seatnum,maxs,s,w);
	mcycle.display();
}
