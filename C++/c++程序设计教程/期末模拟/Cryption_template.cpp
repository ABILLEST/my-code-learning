#include <iostream>
#include <string>
using namespace std;

//只支持整数类型的加密类界面
template<class T>
class Cryption { 

	T ptxt[100];	//明文
	T ctxt[100];	//密文
	T key;	//密钥
	int len;	//长度

public:
	Cryption(T tk, T tt[], int tl); //参数依次对应密钥、明文、长度
	void Encrypt(); //加密
	void Print() //打印，无需改造
	{	int i;
		for (i=0; i<len-1; i++)
			cout<<ctxt[i]<<" ";
		cout<<ctxt[i]<<endl;
	}
	T Max(T* txt,int n);
};

template<class T>
Cryption<T>::Cryption(T tk, T tt[], int tl)
{
	key = tk;
	len = tl;
	for(int i=0;i<len;i++)
		ptxt[i] = tt[i];
}

template<class T>
void Cryption<T>::Encrypt()
{
	T max_value = Max(ptxt,len);
	for(int i=0;i<len;i++)
	{
		ctxt[i] = key + (max_value - ptxt[i]);
	}
}

template <class T>
T Cryption<T>::Max(T* txt,int n)
{
	T max_value = txt[0];	//重要！找一串数据中最大值要先给存放最大值的变量赋初值！ 
	
	for(int i=0;i<n;i++)
		if(txt[i]>max_value)
			max_value = txt[i];
	return max_value;
}


int main()
{	
	int i;
	int length; //长度
	int ik, itxt[100];
	double dk, dtxt[100];
	char ck, ctxt[100];

	//整数加密

	cin>>ik>>length;

	for (i=0; i<length; i++)
		cin>>itxt[i];

	Cryption<int> ic(ik, itxt, length);

	ic.Encrypt();

	ic.Print();

	//浮点数加密

	cin>>dk>>length;

	for (i=0; i<length; i++)
		cin>>dtxt[i];

	Cryption<double> dc(dk, dtxt, length);

	dc.Encrypt();

	dc.Print();

	//字符加密

	cin>>ck>>length;

	for (i=0; i<length; i++)
		cin>>ctxt[i];

	Cryption<char> cc(ck, ctxt, length);

	cc.Encrypt();

	cc.Print();

	return 0;

}
