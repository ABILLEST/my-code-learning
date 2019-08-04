#include<iostream>
#include<string.h>
using namespace std;
//Substitude

class getValue{
	int i,j;
	char key[10],code[100];
	public:

		void body(const char*KEY, const char*CODE);
		
	
};



void getValue::body(const char*KEY, const char*CODE){
	strcpy(key,KEY);
	strcpy(code,CODE);
	for (i = 0; code[i] != '\0'; i++){
		for (j = 0; j < 10; j++)
			if (code[i] == key[j])
				if (j+1 == 10)	cout<<"0";
				else			cout<<j+1;
	}
}
		
int main()
{
	getValue a;
	a.body("TRADINGFEW","LGXWEV");
	return 0;
}
