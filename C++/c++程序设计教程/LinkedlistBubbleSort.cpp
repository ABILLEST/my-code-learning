#include<iostream>
using namespace std;

//Á´±íÅÅÐò Linkedlist Bubble Sort
struct Student
{
	long score;
	Student* next;
};

Student* head;

Student* Create()
{
	Student* pS;        
	Student* pEnd;      
	pS=new Student;     
	cin>>pS->score;
	head=NULL;          
	pEnd=pS;
	
	while(pS->score!=0){
	if(head==NULL)
	  head=pS;
	else
	  pEnd->next=pS;
	
	pEnd=pS;
	pS=new Student;
	cin>>pS->score;
	}
	
	pEnd->next=NULL;
	delete pS;
	return(head);
}

void ShowList(Student* head)
{
	while(head){
	cout<<head->score<<" ";
	head=head->next;
	}
}

void sort(Student* head)
{
	Student* pS1;
	Student* pS2;
	
	for(pS1=head;pS1;pS1=pS1->next)
		for(pS2=pS1->next;pS2;pS2=pS2->next)
			if(pS1->score>pS2->score){
				long temp=pS1->score;
				pS1->score=pS2->score;
				pS2->score=temp;
			}
}

int main()
{
	sort(Create()); 
 	ShowList(head);
}
