#include <iostream>
using namespace std;

class CChickProblem
{
	int totalMoney,totalChick,nHen,nCock,nChick;
	static int pHen,pCock;
public:
	CChickProblem(){nHen=0;nChick=0;nCock=1;}
	CChickProblem(int Chick,int Money):totalMoney(Money),totalChick(Chick){nCock=1;}
	CChickProblem(CChickProblem& a);
	~CChickProblem(){}
	void reset(){nHen=0;nChick=0;nCock=1;}
	void getSolution(CChickProblem* copy,int solutions);
	int findSolution();
	void printSolution(){cout<<nCock<<" "<<nHen<<" "<<nChick<<endl;}
};

int CChickProblem::pCock = 5;
int CChickProblem::pHen = 3;

CChickProblem::CChickProblem(CChickProblem& a)
{
	this->nCock=a.nCock;
	this->nHen=a.nHen;
	this->nChick=a.nChick;
}

void CChickProblem::getSolution(CChickProblem* copy,int solutions)
{
	int suc=0;
	while(nCock<totalMoney/pCock)
    {
        nHen=0;
        while(nHen<totalMoney/pHen)
        {
            nChick=totalChick-nCock-nHen;
            if(pCock*nCock+pHen*nHen+nChick/3.0==totalMoney){
            	//printSolution();
            	suc=1;
            	
			}
			if(suc)
			{
				copy->nCock=nCock;
            	copy->nHen=nHen;
            	copy->nChick=nChick;
            	copy++;
            	suc=0;
			}
            nHen++;
        }
        nCock++;
    }	
}

int CChickProblem::findSolution()
{
	int nSolutions=0;
	while(nCock<totalMoney/pCock)
    {
        nHen=0;
        while(nHen<totalMoney/pHen)
        {
            nChick=totalChick-nCock-nHen;
            if(pCock*nCock+pHen*nHen+nChick/3.0==totalMoney){
            	//printSolution();
            	nSolutions++;
			}
            nHen++;
        }
        nCock++;
    }
    reset();
    return nSolutions;
}

int main()
{
	int t;
	int nchick,money,solutions;
	
	cin>>t;
	CChickProblem* sg;
	for(int i=0;i<t;i++)
	{
		cin>>nchick>>money;
		
		CChickProblem s(nchick,money);
		solutions=s.findSolution();			//获取解的个数 
		CChickProblem* sgroup = new CChickProblem[solutions];
		
		s.getSolution(sgroup,solutions);	//传入保存解的动态数组和解的个数 
		
		cout<<solutions<<endl;
		for(int i=0;i<solutions;i++)
			sgroup[i].printSolution();
	}
	
	return 0;
}
