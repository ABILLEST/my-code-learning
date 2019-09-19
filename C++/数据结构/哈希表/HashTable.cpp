#include <iostream>
using namespace std;

#define SUCCESS 1
#define UNSUCCESS 0
#define DUPLICATE -1
#define ElemType int
#define MAXSIZE 10

typedef struct
{
	char ch[MAXSIZE];
	int num;
}Keytype;

typedef struct
{
	ElemType *elem;
	int count;
	int sizeindex;
}HashTable;

/*
paras:
	p: 若查找成功，则以p指示待查数据元素在表中的位置；
		否则，以p指示插入位置 
	c：统计冲突次数，初值为0	 
*/
int SearchHash(HashTable H, Keytype K, int &p, int &c)
{
	p = Hash(K);
	while(H.elem[p])
}
