#include <iostream>
#include <string>
using namespace std;

template<class T>
class CList
{
private:
	T value[100];
	int length;
public:
	CList(){}
	CList(int);
	~CList(){}
	void init(T*);
	void insert(int idx, T insValue);
	void dlt(int idx);
	void print();
};

template<class T>
CList<T>::CList(int l)
{
	//set length
	if(l<=100)
		length = l;
	else
		length = 100;
	
	//input
//	for(int i=0;i<length;i++)
//	{
//		cin>>value[i];
//	}
}

template<class T>
void CList<T>::init(T* _value)
{
	int i;
	for(int j=0;j<length;j++)
		value[j] = _value[j];
	for(i=0;i<length;i++);
	for(i++;i<100;i++)
		value[i]=-1;
}

template<class T>
void CList<T>::insert(int idx,T insValue)
{
	T* temp = new T[length+1];
	//save
	for(int i=idx;i<length;i++)
		temp[i] = value[i];
	//insert
	value[idx] = insValue;
	//copy back
	for(int i=idx+1;i<=length;i++)
		value[i] = temp[i-1];
	
	length++;
}

template<class T>
void CList<T>::dlt(int idx)
{
	T* temp = new T[length+1];
	//save
	for(int i=idx+1;i<length;i++)
		temp[i] = value[i];
	//copy back
	for(int i=idx;i<length;i++)
		value[i] = temp[i+1];
	
	length--;
}

template<class T>
void CList<T>::print()
{
	for(int i=0;i<length;i++)
		cout<<value[i]<<" ";
	cout<<endl;
}

int main()
{
	int n, inIdx,insertI,dltIdx;
	double insertD;
	int vi[100];
	double vd[100];
	cin>>n;
	CList<int> list1(n);
	for(int i=0;i<n;i++)
	{
		cin>>vi[i];
	}
	cin>>inIdx>>insertI
		>>dltIdx;
	list1.init(vi);
	list1.insert(inIdx,insertI);
	list1.dlt(dltIdx);
	list1.print();
	
	cin>>n;
	CList<double> list2(n);
	for(int i=0;i<n;i++)
	{
		cin>>vd[i];
	}
	cin>>inIdx>>insertD
		>>dltIdx;
	list2.init(vd);
	list2.insert(inIdx,insertD);
	list2.dlt(dltIdx);
	list2.print();
	
	return 0;
}
