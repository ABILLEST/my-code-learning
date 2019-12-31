#include <iostream>
#include <string>
using namespace std;

class SeqList
{
	private:
		int *list;
		int maxsize;
		int size;
	public:
		SeqList();
		SeqList(int *l, int ms, int s);
		~SeqList();
		int list_size();
		int list_insert(int i, int item);
		int list_del(int i);
		int list_get(int i);
		void list_display();
        void ShellInsert(int dk);
        void ShellSort(int dlta[], int t);
};

SeqList::SeqList(int *l, int ms=1000, int s=0)
{
	list = l;
	maxsize = ms;
	size = s;
}

SeqList::~SeqList()
{
	delete []list;
}

int SeqList::list_size()
{
	return size;
}

int SeqList::list_insert(int i, int item)
{
	if(i>0&&i<=size&&(size+1<=maxsize))
	{
		for(int j=size; j>i-1; j--)
		{
			list[j] = list[j-1];
		}
		list[i-1] = item;
		size+=1;
		return 0;
	}
	else if(i==size+1)
	{
		list[i-1] = item;
		size+=1;
	}
	else return -1;
}

void SeqList::list_display()
{
	//cout<<list_size()<<" ";
	for(int i=0;i<size;i++)
	{
		cout<<list[i]<<" ";
	}
	cout<<endl;
}

void SeqList::ShellInsert(int dk)
{
    int i,j;
    for(i=dk; i<=size; ++i)
        if(list[i] < list[i-dk])
        {
            list[0] = list[i];
            for(j=i-dk; j>0&&list[0]<list[i]; j-=dk)
                list[j+dk] = list[j];
            list[j+dk] = list[0];
        }
}

//dlta为增量序列，t为其长度
void SeqList::ShellSort(int dlta[], int t)
{
    for(int k=0; k<t; ++k)
        ShellInsert(dlta[k]);
}

int main()
{
    int t, n, data;
    string str;
    int *arr;

    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int count;
        cin>>n;
        arr = new int[n+1];
        int gap[n];
        gap[0] = n;
        for(count=1; count<n; ++count)
        {
            if(gap[count-1]/2<=0) break;
            gap[count] = gap[count-1]/2;
            
        }
        arr[0]=n;
        for(int j=1; j<=n; ++j)
        {
            cin>>arr[j];
        }
        SeqList L(arr, 100, n+1);
        L.ShellSort(gap, count);
        L.list_display();
    }
    return 0;
}