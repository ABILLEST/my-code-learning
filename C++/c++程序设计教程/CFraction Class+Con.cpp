#include <iostream>
#include <stdio.h>
using namespace std;

//-----类定义------
class CFraction
 {
 private:
      int fz, fm;
 public:
      CFraction(int fz_val, int fm_val);
      CFraction add(const CFraction &r);
      CFraction sub(const CFraction &r);
      CFraction mul(const CFraction &r);
      CFraction div(const CFraction &r);
      int getFz();
      int getFm();
      int getGCD(int n1,int n2); 
      void print();
      void set(int _fz, int _fm);
 };
 
 //----类实现------
CFraction::CFraction(int fz_val, int fm_val)
{
	fz = fz_val;
	fm = fm_val;
}

CFraction CFraction::add(const CFraction &r)
{
	CFraction c(1,1);
/*	int trans, tf, fzAdd, yf;
	tf = fm * r.fm / getGCD(fm,r.fm);
	fz = (tf/fm) * fz;
	trans = (tf/r.fm) * r.fz;
	fzAdd = fz+trans;
	yf=getGCD(tf,fzAdd);
	fz = fzAdd/yf;
	fm = tf/yf;
*/
	c.fz = fz*r.fm + fm*r.fz;
	c.fm = fm*r.fm;
	return c;
}

CFraction CFraction::sub(const CFraction &r)
{
	//CFraction c(1,1);
	int trans, tf, fzSub, yf;
	tf = fm * r.fm / getGCD(fm,r.fm);
	fz = (tf/fm) * fz;
	trans = (tf/r.fm) * r.fz;
	fzSub = fz-trans;
	if(fzSub<0){
		fzSub *= (-1);
		yf=getGCD(tf,fzSub);
		fz = (-1)*fzSub/yf;
		fm = tf/yf;
	}
	else{
		yf=getGCD(tf,fzSub);
		fz = fzSub/yf;
		fm = tf/yf;
	}
}

CFraction CFraction::mul(const CFraction &r)
{
	CFraction c(1,1);
/*	fm *= r.fm;
	fz *= r.fz;
	int gys = getGCD(fm,fz);	
	fm /= gys;
	fz /= gys;
*/
	c.fz = fz*r.fz;
	c.fm = fm*r.fm;
	return c;
}


CFraction CFraction::div(const CFraction &r)
{
	fm *= r.fz;
	fz *= r.fm;
	int gys = getGCD(fm,fz);	
	fm /= gys;
	fz /= gys;
}

int CFraction::getFz()
{
	return fz;
}

int CFraction::getFm()
{
	return fm;
}

void CFraction::set(int _fz, int _fm)
{
	fz = _fz;
	fm = _fm;
}

void CFraction::print()
{
	cout<<fz<<"/"<<fm<<" ";
}
int CFraction::getGCD(int n1,int n2)
{
	int r;
	while(n2>0)
	{
		r = n1%n2;
		n1 = n2;
		n2 = r;
	} 
	return n1;
}

//-----主函数-----
//CFraction Class+Con
int main()
{
	int t;
	int fz1,fm1,fz2,fm2;
	
	cin>>t;
//1
/*	
	for(int i=0; i<t; i++){
		scanf("%d/%d",&fz1,&fm1);
		scanf("%d/%d",&fz2,&fm2);
		CFraction cf1(fz1,fm1),cf2(fz2,fm2);
		cf1.add(cf2);	cf1.print();	cf1.set(fz1,fm1);
		cf1.sub(cf2);	cf1.print();	cf1.set(fz1,fm1);
		cf1.mul(cf2);	cf1.print();	cf1.set(fz1,fm1);
		cf1.div(cf2);	cf1.print();	cf1.set(fz1,fm1);
	}
*/

//2
	for(int i=0; i<t; i++) 
	{
		cin>>fz1>>fm1>>fz2>>fm2;
		CFraction cf1(fz1,fm1), cf2(fz2,fm2), cf3(1,1);
		cf1.print();	cf2.print(); cout<<endl;
		cf3 = cf1.add(cf2);	 cf3.print();cout<<endl;
		cf3 = cf1.mul(cf2);	cf3.print();cout<<endl;
	}
	
	
	return 0;
} 
