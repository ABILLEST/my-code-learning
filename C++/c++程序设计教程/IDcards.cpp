#include <iostream>
using namespace std;

//class reference
class Card
{
protected:
	long long ID;
	char CName;
	unsigned long Counter;
public:
	virtual void initial(long long id,char name,unsigned long c);
	int save(long amount);
	int take(long amount);
	virtual void info();
};

class TCard : public Card
{
protected:
	unsigned long TCounter;
public:
	int transfer(long amount);
	virtual void initial(long long id,char name,unsigned long c,unsigned long tc);
};

class VCard : public Card
{
protected:
	unsigned long Credit;
public:
	int over(long amount);
	virtual void initial(long long id,char name,unsigned long c,unsigned long cre);
};

//class methods realize
void Card::initial(long long id,char name,unsigned long c)
{
	ID = id;
	CName = name;
	Counter = c;
}

int Card::save(long amount)
{
	if(amount>0){
		Counter += amount;
		return 1;
	}
	else return -1;
}

int Card::take(long amount)
{
	if(amount>0){
		if(amount<=Counter){
			Counter-=amount;
			return 1;
		}
	}
	
	return -1;
}

void Card::info()
{
	cout<<ID<<"-"<<CName<<"-"<<Counter<<endl;
}

void TCard::initial(long long id,char name,unsigned long c,unsigned long tc)
{
	ID = id;
	CName = name;
	Counter = c;
	TCounter = tc;
}

int TCard::transfer(long amount)
{
	if(amount>0){
		if(amount<=Counter){
			Counter-=amount;
			TCounter+=amount;
			return 1;
		}
	}
	
	return -1;
}

void TCard::info()
{
	cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<TCounter<<endl;
}

void VCard::initial(long long id,char name,unsigned long c,unsigned long cre)
{
	ID = id;
	CName = name;
	Counter = c;
	Credit = cre;
}

int VCard::over(long amount)
{
	if(amount>0){
		if(amount>Counter&&amount<(Counter+Credit)){
			Credit-=amount-Counter;
			Counter=0;
			return 1;
		}
	}
	return -1;
}

void VCard::info()
{
	cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Credit<<endl;
}

void show(Card& obj)
{	obj.info();}

int main()
{
	long long id;
	char name;
	unsigned long counter,tcounter;
	Card nomal;
	TCard tcard;
	VCard vcard;
	
	cin>>id>>name>>counter;
	nomal.initial(id,name,counter);
	cin>>id>>name>>counter>>tcounter;
	tcard.initial(id,name,counter,tcounter);
	cin>>id>>name>>counter>>cre;
	vcard.initial(id,name,counter,cre);

	return 0;
}
