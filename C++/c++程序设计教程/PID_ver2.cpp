#include <iostream>
#include <string.h>
using namespace std;

int CertCalGroup[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char CertGroup[12]={"10X98765432"};

class CDate
{
protected:
	int year, month, day;
public:
	CDate(){}
	CDate(int,int,int);
	CDate(const CDate& d){year=d.year;month=d.month;day=d.day;}
	int getYear(){return year;}
	int getMonth(){return month;}
	int getDay(){return day;}	
	bool check(); //检验日期是否合法
	bool isLeap();
	virtual void print();
};

class CStudentID
{
private:
	char *p_id, *p_name; //身份证号码，姓名
	CDate birthday; //出生日期
	int registered; //注册成功标志 
public:
	CStudentID(char *p_idval, char *p_nameval, CDate &day); 
	CStudentID(const CStudentID &r); //拷贝构造函数，若r.p_id为15位则升到18位(加年份的19和校验位)
	bool checked() { return registered; }
	~CStudentID(){delete p_id;delete p_name;}
};

CDate::CDate(int y,int m,int d)
{
	year=y; month=m; day=d;
}

bool CDate::check()
{
	
	if(year>0&&year<65532)		//年为正整数
	{
		if(month==1||month==3||month==5
		||month==7||month==8||month==10||month==12)	//大月31天
		{
			if(day>=1&&day<=31)
				return true;
			else 
				return false;
		}
		else if(month==4||month==6||month==9||month==11)//小月30天 
		{
			if(day>=1&&day<=30)
				return true;
			else 
				return false;
		}
		else if(month==2) 		//2月 
		{
			if(!isLeap()) 
			{
				if(day>=1&&day<=28)			//平年28天
					return true;
				else 
					return false;
			}
			else{
				if(day>=1&&day<=29)			//闰年29天
					return true;
				else 
					return false;
			}
		}
		else return false;		//月份错误 
	}
	else return false;		//年份错误 
}

bool CDate::isLeap()
{
	return (year%4 == 0 && year%100 != 0) || year%400 == 0;
}

void CDate::print()
{
	cout<<year<<"年"<<month<<"月"<<day<<"日 "; 
}


CStudentID::CStudentID(char *p_idval, char *p_nameval, CDate &day):birthday(day)
{
	registered=1;	//全部通过则，缺陷：如果下面的逻辑不全面的话，会导致出错不报的情况 
	strcpy(p_id,p_idval);
	strcpy(p_name,p_nameval);
	
	int i,ysum=0,msum=0,dsum=0;
	
	if(!birthday.check())				//出生日期合法性检查 
	{
		cout<<"illegal id"<<endl;
		registered=0;
	}
	int len=strlen(p_id);
	if(len==15)			//15位号检查 
	{
		for(i=0;i<15;++i)				//字符合法性检查 
		{
			if(p_id[i]-'0'<0||p_id[i]-'0'>9)
			{
				cout<<"illegal id"<<endl;
				registered=0;
			}
		}
		for(i=6;i<=7;i++)			//出生日期和身份证出生日期相符检查 
		{
			ysum=ysum*10+(p_id[i]-'0');
		}
		for(i=7;i<=8;i++)			 
		{
			msum=msum*10+(p_id[i]-'0');
		}
		for(i=8;i<=9;i++)			
		{
			dsum=dsum*10+(p_id[i]-'0');
		}
		if(ysum!=(day.getYear()%100)||msum!=day.getMonth()||dsum!=day.getDay())
		{
			cout<<"illegal id"<<endl;
			registered=0;
		}
		
	}
	else if(len==18)		//18位号检查 
	{
		for(i=0;i<15;++i)				//字符合法性检查 
		{
			if(p_id[i]-'0'<0||p_id[i]-'0'>9)
			{
				cout<<"illegal id"<<endl;
				registered=0;
			}
		}
		for(i=6;i<=9;i++)			//出生日期和身份证出生日期相符检查 
		{
			ysum=ysum*10+(p_id[i]-'0');
		}
		for(i=10;i<=11;i++)			 
		{
			msum=msum*10+(p_id[i]-'0');
		}
		for(i=12;i<=13;i++)			
		{
			dsum=dsum*10+(p_id[i]-'0');
		}
		if(ysum!=day.getYear()||msum!=day.getMonth()||dsum!=day.getDay())
		{
			cout<<"illegal id"<<endl;
			registered=0;
		}
	}
	else{
		cout<<"illegal id"<<endl;
		registered=0;
	}
}

CStudentID::CStudentID(const CStudentID &r)
{
	int len=strlen(r.p_id);
	int sum=0;
	char cert;
	
	if(len==15)			//upgrade
	{
		for(int i=0;i<6;i++)
			this->p_id[i]=r.p_id[i];
		this->p_id[6]=r.birthday.getYear()/1000;
		this->p_id[7]=(r.birthday.getYear()/100)%10;
		for(int i=8;i<17;i++)
			this->p_id[i]=r.p_id[i-2];
		for(int i=0;i<17;i++)						//校验位计算 
			sum+=(p_id[i]-'0')*CertCalGroup[i];
		cert=CertGroup[sum%11];
		this->p_id[17]=cert;
	}
	else{
		strcpy(p_id,r.p_id);
		strcpy(p_name,r.p_name);
		this->registered=r.registered;
		this->birthday=r.birthday;
	}
}

int main()
{
	int t;
	int y,m,d;
	char* name[20];
	char* id[50];
	
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>y>>m>>d
			>>name>>id;
		CDate date(y,m,d);
		cin>>name>>id;
		CStudentID s(id,name,date);
		if(s.checked())
			CStudentID s_copy(s);
	}
}
