#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

class Student
{
	char* name;
	int year,month,day;
public:
	Student(){}
	Student(char *_name,int y,int m,int d);
	Student(Student &s);
	void set(char *_name,int y,int m,int d);
	char* getName(){ return name;}
	int operator - ( Student& obj);
	int isLeap(int y);
};

Student::Student(char *_name,int y,int m,int d)
{
	name=_name;
	year = y;
	month = m;
	day = d;
}

Student::Student(Student &s)
{
	int namelen = strlen(s.name);
	name = new char[namelen];
	year = s.year;
	month = s.month;
	day = s.day;
}

void Student::set(char *_name,int y,int m,int d)
{
	name = _name;
	year = y;
	month = m;
	day = d;
}

int Student::operator - ( Student& obj)
{
	int days=0, flag=1;  
    const int primeMonth[12]={31,29,31,30,31,30,31,31,30,31,30,31};  
    const int notPrimeMonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};  
     
    Student tmp;  
    if ((year>obj.year)|| (year==obj.year&&month>obj.month)||
		(year==obj.year&&month==obj.month&&day>obj.day))  
    {  
        tmp=*this;  
        *this=obj;  
        obj=tmp;  
    }   
     
    int maxmonth,minmonth;  
    if (obj.month< month)  
    {  
        maxmonth= month;  
        minmonth=obj.month;  
        flag=-1;  
    } 
    else  
    {  
        maxmonth=obj.month;  
        minmonth= month;  
        flag=1;  
    }  
 
    //从 year开始累加到obj.year 
    for(int j= year;j<obj.year;++j)  
    {  
        if (isLeap(j)==1)  
            days+=366;   
        else  
            days+=365;  
    }
 
    //从minmonth累加到maxmonth,分闰年和平年
    int day1;  
    if(isLeap(obj.year)==1)  
    {   
        for(int i=minmonth;i<maxmonth;i++)  
        {  
            day1=primeMonth[i-1]*flag;  
            days=days+day1;  
        }  
        days=days+obj.day- this->day;  
    }
    else  
    {  
        for (int i=minmonth;i<maxmonth;i++)  
        {  
            day1=notPrimeMonth[i-1]*flag;  
            days=days+day1;  
        }  
        days=days+obj.day-this->day;  
    }  
    return days;
}

int Student::isLeap(int y)
{
	if ((year%4==0&&year%100!=0)||(year%400==0))  
        return 1;
    else  
        return 0;  
}

int main()
{
	int t,y,m,d,maxDiff;
	
	char *maxname1 = new char[50];
	char *maxname2 = new char[50];
	cin>>t;
	
	//input
	Student *s = new Student[t];
	for(int i=0;i<t;i++)
	{
		char *name = new char[50];
		cin>>name>>y>>m>>d;
		s[i].set(name,y,m,d);
	}
	
	//processing
	for(int i=0;i<t-1;i++)
		for(int j=i+1;j<t;j++)
		{
			int dayDiff;
			dayDiff = abs(s[i]-s[j]);
			if(dayDiff>maxDiff){
				maxDiff = dayDiff;
				maxname1=s[i].getName();
				maxname2=s[j].getName();
			}		
		}
		
	//output
	cout<<maxname1<<"和"<<maxname2<<"年龄相差最大，为"<<maxDiff<<"天。"<<endl; 
}
