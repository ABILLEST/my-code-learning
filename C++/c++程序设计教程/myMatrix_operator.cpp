#include <iostream>
using namespace std;

class myMatrix
{
	int r,c;
	int **m;
public:
	myMatrix(){}
	myMatrix(int _r,int _c);
	void set(int _r,int _c);
	myMatrix operator + (const myMatrix &obj);
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

myMatrix myMatrix::operator + (const myMatrix &obj)
{
	int i=0,j=0,p,q;
	myMatrix result(obj.r,obj.c);
	
	for(p=0;p<obj.r;p++)
		for(q=0;q<obj.c;q++)
			result.m[p][q] = this->m[p][q] + obj.m[p][q];
		
	return result;
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
		for(int j=0;j<c;j++){
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}		
}

int main()
{
	int t,r,c;
	
	
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>r>>c;
		myMatrix m1,m2,result(r,c);
		m1.set(r,c);
		m2.set(r,c);
		result=m1+m2;
		result.show();
	}
	return 0;
}
