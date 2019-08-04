#include <iostream>
#include <string.h>
using namespace std;

class CN; //提前声明
class EN; //提前声明
class Weight
{ //抽象类
protected:
	char kind[20]; //计重类型
	int gram; //克
public:
	Weight (char tk[]="no name", int tg=0)
	{ strcpy(kind, tk);	
	  gram = tg;
	}
	virtual void Print(ostream & out) = 0; //输出不同类型的计重信息
};

class CN: public Weight 
{ //中国计重
	int jin,liang,qian;
	friend class EN; 
public:
	CN(){}
	CN(int,int,int,int,char*);
	CN(CN&);
	void Convert(const int);
	void Print(ostream & out);
};

class EN: public Weight 
{ //英国计重
	int pound,oz,dram;
public:
	EN(){}
	EN(int,int,int,int,char*);
	void Convert(const int);
	operator CN ();
	void Print(ostream & out);
};

CN::CN(int j,int l,int q,int g,char* k) : Weight(k,g)
{
	jin = j;
	liang = l;
	qian = q;
}

CN::CN(CN& cn)
{
	jin = cn.jin;
	liang = cn.liang;
	qian = cn.qian;
	gram = cn.gram;
}

void CN::Convert(const int g)
{
	gram = g;
	int temp;
	
	temp = gram/500;
	jin += temp;
	gram -= temp*500;
	
	temp = gram/50;
	liang += temp;
	gram -= temp*50;
	
	temp = gram/5;
	qian += temp;
	gram -= temp*5;
}

void CN::Print(ostream& out)
{
	out<<kind<<":"<<jin<<"斤"<<liang<<"两"<<qian<<"钱"<<gram<<"克"<<endl;
}

EN::EN(int p,int _oz,int d,int g,char* k) : Weight(k,g)
{
	pound = p;
	oz = _oz;
	dram = d;
}

void EN::Convert(const int g)
{
	gram = g;
	int temp;
	
	temp = gram/512;
	pound += temp;
	gram -= temp*512;
	
	temp = gram/32;
	oz += temp;
	gram -= temp*32;
	
	temp = gram/2;
	dram += temp;
	gram -= temp*2;
}

EN::operator CN ()
{
	CN cn(0,0,0,0,"中国计重");
	gram += pound*512 + oz*32 + dram*2;
	int temp;
	
	temp = gram/500;
	cn.jin += temp;
	gram -= temp*500;
	
	temp = gram/50;
	cn.liang += temp;
	gram -= temp*50;
	
	temp = gram/5;
	cn.qian += temp;
	gram -= temp*5;
	cn.gram = gram;//important 
	
	return cn;
} 

void EN::Print(ostream& out)
{
	out<<kind<<":"<<pound<<"磅"<<oz<<"盎司"<<dram<<"打兰"<<gram<<"克"<<endl;
}

//以全局函数方式重载输出运算符，代码3-5行....自行编写

//重载函数包含两个参数：ostream流对象、Weight类对象，参数可以是对象或对象引用

//重载函数必须调用参数Weight对象的Print方法
ostream& operator << (ostream& out, Weight& w)
{
	w.Print(out);
}


int main()//主函数

{	int tw;

//创建一个中国计重类对象cn

//构造参数对应斤、两、钱、克、类型，其中克和类型是对应基类属性gram和kind

	CN cn(0,0,0,0, "中国计重");

	cin>>tw;

	cn.Convert(tw); //把输入的克数转成中国计重

	cout<<cn;

	

//创建英国计重类对象en

//构造参数对应磅、盎司、打兰、克、类型，其中克和类型是对应基类属性gram和kind

	EN en(0,0,0,0,"英国计重");

	cin>>tw;

	en.Convert(tw); //把输入的克数转成英国计重

	cout<<en;

	cn=en; //把英国计重转成中国计重

	cout<<cn;

return 0;

}
