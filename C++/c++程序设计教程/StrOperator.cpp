#include <iostream>
#include <string.h> 
using namespace std;

class Str
{
	int length;
	char *p;
public:
	Str();
	Str(char *s);
	Str(const Str &obj);
	~Str();
	friend Str operator + (const Str &s1, const Str &s2);
	friend Str operator - (const Str &s1, const Str &s2);
	void operator = (const Str &obj);
	void show()
	{
		cout<<"length="<<length<<' '<<p<<endl;
	}
};

Str::Str()
{
	length = 50;
	p = new char[length];
}

Str::Str(char *s)
{
	length = strlen(s);
	p=s;
}

Str::Str(const Str &obj)
{
	length = strlen(obj.p);
	p = new char[length];
	if(p!=0)
		strcpy(p,obj.p);
}

Str::~Str()
{
	delete p;
}

void Str::operator = (const Str &obj)
{
	length = obj.length;
	p=obj.p;
}

Str operator + (const Str &s1, const Str &s2)
{
	int i,j;
	Str s3(s1);
	for(i=0;s1.p[i];i++) ;
	for(j=0;s2.p[j];i++,j++)
		s3.p[i] = s2.p[j];
	s3.p[i] = '\0';
	s3.length = s1.length+s2.length;
	return s3;
}

Str operator - (const Str &s1, const Str &s2)
{
	int j;
	Str s3(s1);
	char *pos = strstr(s1.p,s2.p);
	if(pos)
	{
		for(;*(pos+s2.length);pos++)
		*(pos) = *(pos+s2.length);
		*pos = '\0';
		s3.length = s1.length-s2.length;
		return s3;
	}
	else return s3;
}

// 
int main()
{
	char *s1 = new char[50];
	char *s2 = new char[50];
	
	//input
	cin.getline(s1,50);
	cin.getline(s2,50);
	
	//processing
	Str str1(s1);
	Str str2(s2);
	Str str3 = str1+str2;
	Str str4 = str1-str2;
	
	//output
	str3.show();
	str4.show();
	
	return 0;
}
