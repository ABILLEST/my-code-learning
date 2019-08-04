#include<iostream>
using namespace std;

struct Exam
{
	long studentNum;
	string str1;
	string str2;
	string str3;
};

int isCopy(Exam *a, Exam *b)
{
	int nsame;
	int anslen1,anslen2;
	
	string *p1=&a->str1;
	string *p2=&b->str1;
	for(nsame=0,anslen1=0,anslen2=0;*p1!='\0'&&*p2!='\0';p1++,p2++)
	{
		if(*p1==*p2) nsame++;
		anslen1++,anslen2++;
	};
	if((nsame*10/anslen1)>=9||(nsame*10/anslen2)>=9)
		return 1;
	
	p1=a->str2;
	p2=b->str2;
	for(nsame=0,anslen1=0,anslen2=0;*p1!='\0'&&*p2!='\0';p1++,p2++)
	{
		anslen1++,anslen2++;
		if(*p1==*p2) nsame++;
	};
	if((nsame*10/anslen1)>=9||(nsame*10/anslen2)>=9)
		return 2;
	
	p1=a->str3;
	p2=b->str3;	
	for(nsame=0,anslen1=0,anslen2=0;*p1!='\0'&&*p2!='\0';p1++,p2++)
	{
		if(*p1==*p2) nsame++;
		anslen1++,anslen2++;
	};
	if((nsame*10/anslen1)>=9||(nsame*10/anslen2)>=9)
		return 3;
		
	return 0;
}

//isCopy
int main()
{
	int t,i;
	cin>>t;
	Exam *stu = new Exam[t];
	Exam *s=NULL,*d=NULL;
	
	for(s=stu; s-stu<t; s++)
	{
		cin >>s->studentNum
			>>s->str1
			>>s->str2
			>>s->str3;
	}
	
	for(s=stu; s-stu<t-1; s++)
		for(d=s+1; d-stu<t; d++)
		{
			int quesNum=isCopy(s,d);
			if(quesNum)
			{
				cout<<s->studentNum<<" "
					<<d->studentNum<<" "
					<<quesNum<<endl;
			}
		}
	
	return 0;
}
