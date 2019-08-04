#include <iostream>
#include <string>
using namespace std;

template<class T>
class BoundArray
{
private:
	T* array;
	int length;
public:
	BoundArray(){}
	BoundArray(int,T*);
	~BoundArray();
	void sort();
	void search(T);
	void print();
};

template<class T>
BoundArray<T>::BoundArray(int len,T* arr)
{
	length = len;
	//array = new T[length];
	array = arr;	//Ç³¿½±´ 
}

template<class T>
void BoundArray<T>::sort()
{
	for(int i=0;i<length;i++)
		for(int j=i+1;j<length;j++)
			if(array[i]>array[j]){
				T temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
}

template<class T>
void BoundArray<T>::search(T target)
{
	bool found=false;
	for(int i=0;i<length;i++)
		if(array[i]==target){
			found=1;
			cout<<i<<endl;
			break;
		}
	if(!found)
		cout<<-1<<endl;
}

template<class T>
void BoundArray<T>::print()
{
	for(int i=0;i<length;i++)
		cout<<array[i]<<" ";
	cout<<endl;
}

template<class T>
BoundArray<T>::~BoundArray()
{
	delete []array;
	length=0;
}

int main()
{
	int t,n;
	char type;
	cin>>t;
	
	for(int i=0;i<t;i++)
	{
		cin>>type;
		if(type=='I')
		{
			int find;
			//input
			cin>>n;
			int* arr = new int[n];
			for(int i=0;i<n;i++)
				cin>>arr[i];
			
			BoundArray<int> iArray(n,arr);
			iArray.sort();
			iArray.print();
			cin>>find;
			iArray.search(find);
		}
		else if(type=='D')
		{
			double find;
			//input
			cin>>n;
			double* arr = new double[n];
			for(int i=0;i<n;i++)
				cin>>arr[i];
			
			BoundArray<double> DArray(n,arr);
			DArray.sort();
			DArray.print();
			cin>>find;
			DArray.search(find);
		}
		else if(type=='C')
		{
			char find;
			//input
			cin>>n;
			char* arr = new char[n];
			for(int i=0;i<n;i++)
				cin>>arr[i];
			
			BoundArray<char> CArray(n,arr);
			CArray.sort();
			CArray.print();
			cin>>find;
			CArray.search(find);
		}
	}
	
	return 0;
}
