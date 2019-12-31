#include <iostream>
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
        int Partition(int low, int high);
        void QuickSort(int low, int high);
        void HeapAdjust(int s, int m);
        void HeapSort();
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

void SeqList::list_display()
{
	//cout<<size<<" ";
	for(int i=0;i<=size;i++)
	{
		cout<<list[i]<<" ";
	}
	cout<<endl;
}

void SeqList::ShellInsert(int dk)
{
    int i,j, temp;
    for(i=dk; i<size; ++i)
        if(list[i] > list[i-dk])
        {
            temp = list[i];
            for(j=i-dk; j>=0&&temp>list[j]; j-=dk)
                list[j+dk] = list[j];
            list[j+dk] = temp;
        }
}

//dlta为增量序列，t为其长度
void SeqList::ShellSort(int dlta[], int t)
{
    for(int k=0; k<t; ++k)
    {
        ShellInsert(dlta[k]);
        list_display();
    }
}

int SeqList::Partition(int low, int high)
{
    int pivotkey= list[low];   //枢轴记录
    while(low < high)
    {
        while(low<high && list[high]>=pivotkey)
            --high;
        list[low] = list[high];
        while(low<high && list[low]<=pivotkey)
            ++low;
        list[high] = list[low];
    }
    list[low] = pivotkey;
    list_display();
    return low;
}

void SeqList::QuickSort(int low, int high)
{
    int pivotloc;
    if(low < high)
    {
        pivotloc = Partition(low, high);
        QuickSort(low, pivotloc-1);
        QuickSort(pivotloc+1, high);
    }
}

void SeqList::HeapAdjust(int s, int m)
{
    int rc = list[s];
    for(int j=2*s; j<=m; j*=2)
    {
        if(j<m && list[j]>list[j+1])    //若要改为大顶堆，改变第二个条件判断方向
            ++j;
        if(rc<=list[j]) break;      //若要改为大顶堆，改变方向
        list[s] = list[j];
        s = j;
    }
    list[s] = rc;
}

void SeqList::HeapSort()
{
    for(int i=size/2; i>0; --i)
        HeapAdjust(i ,size);
    list_display();
    for(int i=size; i>1; --i)
    {
        int temp=list[1];
        list[1] = list[i];
        list[i] = temp;
        HeapAdjust(1, i-1);
        list_display();
    }
}

int main()
{
    int t, n, data;
    int *arr;

    //cin >> t;
    //for (int i = 0; i < t; ++i)
    //{
        cin>>n;
        arr = new int[n+1];
        arr[0] = n;
        for(int j=1; j<=n; ++j)
        {
            cin>>arr[j];
        }
        SeqList L(arr, 100, n);
        L.HeapSort();
        cout<<endl;
    //}
    return 0;
}