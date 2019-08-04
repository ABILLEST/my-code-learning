#include <iostream>
#include <string>
using namespace std;

template<class T>
class CMatrix
{
private:
	T **m;
	int row,column;
public:
	CMatrix(){}
	CMatrix(int,int);
	~CMatrix();
	void swap(T& a, T& b);
	void transport();
	void print();
};

template<class T>
CMatrix<T>::CMatrix(int r,int c):row(r),column(c)
{
	int i,j;
	m = new T*[r];
	for (i = 0; i < r; ++i)
	{
	    m[i] = new T[c];
	}
	
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			cin>>m[i][j];
}

template<class T>
void CMatrix<T>::swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
	return;
}

template<class T>
void CMatrix<T>::transport()
{
	int temp = row;
	row = column;
	column = temp;
	
	T** new_m = new T*[row];
	for (int i=0;i<row;++i)
	{
		new_m[i] = new T[column];
	}
	
	for(int i=0;i<row;i++)
		for (int j=0;j<column; j++)
		{
			new_m[i][j]=m[j][i];
		}
	m = new_m;
	return;
}

template<class T>
void CMatrix<T>::print()
{
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			cout<<m[i][j]<<" ";
		}
		printf("\n");
		//cout<<endl;
	}		
}

template<class T>
CMatrix<T>::~CMatrix()
{
	delete []m;
	row=0;
	column=0;
}

int main()
{
	int t,r,c;
	char type;
	cin>>t;
	
	for(int i=0;i<t;i++)
	{
		cin>>type;
		if(type=='I')
		{
			cin>>r>>c;
			CMatrix<int> int_matrix(r,c);
			int_matrix.transport();
			int_matrix.print();
		}
		else if(type=='D')
		{
			cin>>r>>c;
			CMatrix<double> double_matrix(r,c);
			double_matrix.transport();
			double_matrix.print();
		}
		else if(type=='C')
		{
			cin>>r>>c;
			CMatrix<char> char_matrix(r,c);
			char_matrix.transport();
			char_matrix.print();
		}
	}
	
	return 0;
}
