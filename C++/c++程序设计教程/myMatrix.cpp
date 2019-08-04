#include <iostream>
#include <string.h> 
using namespace std;

class myMatrix
{
	int r,c;
	int **m;
public:
	myMatrix(){}
	myMatrix(int _r,int _c);
	void set(int _r,int _c);
	myMatrix operator * (const myMatrix &obj);
	void show();
};

myMatrix::myMatrix(int _r,int _c):r(_r),c(_c)
{
	int i,j;
	m = new int*[_r];
	for (i = 0; i < _r; ++i)
	{
	    m[i] = new int[_c];
	}
	for(i=0;i<_r;i++)
		for(j=0;j<_c;j++)
			m[i][j]=0;
}

void myMatrix::set(int _r,int _c)
{
	int i,j;
	r=_r;
	c=_c;
	m = new int*[_r];
	for (i = 0; i < _r; ++i)
	{
	    m[i] = new int[_c];
	}
	for(i=0;i<_r;i++)
		for(j=0;j<_c;j++)
			cin>>m[i][j];
}

myMatrix myMatrix::operator * (const myMatrix &obj)
{
	int i=0,j=0,p,q;
	myMatrix result(obj.r,obj.c);
	
	for(p=0;p<obj.r;p++)
		for(q=0;q<obj.c;q++)
		{
			for(i=0;i<obj.r;i++)
				result.m[p][q] += this->m[p][i] * obj.m[i][q];
		}

	return result;
}

void myMatrix::show()
{
	for(int i=0;i<r;i++){
		for(int j=0;j<r;j++){
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}		
}

//myMatrix
int main()
{
	int c,n;
	cin>>c>>n;
	
	myMatrix result;
	myMatrix *mm = new myMatrix[c];
	for(int i=0;i<c;i++)
	{
		mm[i].set(n,n);
	}
	result = mm[0] * mm[1];
	for(int i=2;i<c;i++)
	{
		//result = mm[i] * mm[i+1];
		result = result * mm[i];
	}
	
	result.show();
}
