#include <iostream>
#include <string>
using namespace std;

class Animal
{
protected:
	string name;
	int age,weight;
public:
	Animal(string n,int a):name(n),age(a){}
	virtual void speak()=0;
};

class Tiger:public Animal
{
public:
	Tiger(string n,int a):Animal(n,a){}
	virtual void speak(){cout<<"Hello,I am "<<name<<",AOOO."<<endl;}
};

class Pig:public Animal
{
public:
	Pig(string n,int a):Animal(n,a){}
	virtual void speak(){cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;}
};

class Dog:public Animal
{
public:
	Dog(string n,int a):Animal(n,a){}
	virtual void speak(){cout<<"Hello,I am "<<name<<",WangWang."<<endl;}
};

class Duck:public Animal
{
public:
	Duck(string n,int a):Animal(n,a){}
	virtual void speak(){cout<<"Hello,I am "<<name<<",GAGA."<<endl;}
};


int main()
{
	int t,age;
	string type,name;
	cin>>t;
	
	Animal *p;
	for(int i=0;i<t;i++)
	{
		cin>>type>>name>>age;
		if(type=="Tiger")
		{
			p = new Tiger(name,age);
			p->speak();
		}
		else if(type=="Pig")
		{
			p = new Pig(name,age);
			p->speak();
		}
		else if(type=="Dog")
		{
			p = new Dog(name,age);
			p->speak();
		}
		else if(type=="Duck")
		{
			p = new Duck(name,age);
			p->speak();
		}
		else cout<<"There is no "<<type<<" in our Zoo."<<endl;
	}
}
