#include <iostream>
using namespace std;
 
class Student
{
	public:
		void set();
		void print();
	private:
		char name[100];
		char gender[100];
		char college[100];
		char major[100];
		char dom[100];
		char stuNum[100];
		char phone[100];
};

void Student::set()
{
	cin>>name>>stuNum>>college>>major>>gender>>dom>>phone;
}

void Student::print()
{
	cout<<name<<" "<<stuNum<<" "<<college<<" "<<major<<" "<<gender<<" "<<dom<<" "<<phone<<" "<<endl;
}

//student info(class)
int main()
{
	int t;
	cin>>t;
	Student* s = new Student[t];
	
	for(int i=0; i<t; i++)
		s[i].set();

	for(int i=0; i<t; i++)
		s[i].print();
	return 0;
}
