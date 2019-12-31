#define   OK                    1
#define   ERROR                 0
#define   OVERFLOW             -2
#define   TRUE                  1
#define   FALSE                 0
typedef   int   Status;//为了方便算法可用性，算法的Status可以通过这里可改
#include <iostream>
#include <cstdlib>
using namespace std;
typedef struct{//项的表示，多项式的项作为LinkList的数据元素
    float coef;//系数
    int expn;//指数
}term, ElemType;//两个类型：term用于本ADT，ElemType为LinkList的数据对象名
typedef struct LNode{//节点类型
    ElemType  data;//这里表示了每一项，其指数和系数
    struct LNode *next;
}*Link,*Position;
typedef struct{//链表类型
    Link head, tail;//分别指向线性链表中的头结点和最后一个结点
    int len;//指示线性链表中数据元素的个数
}LinkList;//每一项组成一个列表
typedef LinkList polynomial;

Status InitList(LinkList *L)
{ /* 构造一个空的线性链表 */
    Link p;
    p = (Link)malloc(sizeof(LNode)); /* 生成头结点 */
    if (p)
    {
        p->next = NULL;
        (*L).head = (*L).tail = p;
        (*L).len = 0;
        return OK;
    }
    else
        return ERROR;//内存分配不够
}
Status MakeNode(Link *p, ElemType e)
{ /* 分配由p指向的值为e的结点，并返回OK；若分配失败。则返回ERROR */
    *p = (Link)malloc(sizeof(LNode));
    if (!*p)
        return ERROR;
    (*p)->data = e;
    return OK;
}

Status InsFirst(LinkList *L, Link h, Link s) /* 形参增加L,因为需修改L */
{ /* h指向L的一个结点，把h当做头结点，将s所指结点插入在第一个结点之前 */
    s->next = h->next;
    h->next = s;
    if (h == (*L).tail) /* h指向尾结点 */
        (*L).tail = h->next; /* 修改尾指针 */
    (*L).len++;
    return OK;
}

Position GetHead(LinkList L)
{ /* 返回线性链表L中头结点的位置 */
    return L.head;
}
Status SetCurElem(Link p, ElemType e)
{ /* 已知p指向线性链表中的一个结点，用e更新p所指结点中数据元素的值 */
    p->data = e;
    return OK;
}

Status LocateElemP(LinkList L, ElemType e, Position *q, int(*compare)(ElemType, ElemType))
{ /* 若升序链表L中存在与e满足判定函数compare()取值为0的元素，则q指示L中 */
    /* 第一个值为e的结点的位置，并返回TRUE；否则q指示第一个与e满足判定函数 */
    /* compare()取值>0的元素的前驱的位置。并返回FALSE。（用于一元多项式） */
    Link p = L.head, pp;
    do
    {
        pp = p;
        p = p->next;
    } while (p && (compare(p->data, e)<0)); /* 没到表尾且p->data.expn<e.expn */
    if (!p || compare(p->data, e)>0) /* 到表尾或compare(p->data,e)>0 */
    {
        *q = pp;
        return FALSE;
    }
    else /* 找到 */
    {/* 没到表尾且p->data.expn=e.expn */
        *q = p;
        return TRUE;
    }
}
Status Remove_Polyn(LinkList *L, Link q)
{ //由于项的指数为0，删除掉已有的项
    Link p, h;
    h = L->head;
    while (h->next != q)
    {
        h = h->next;
    }
    //找到了
    if (q == L->tail)
    {//删除的如果是表尾，改变表尾
        L->tail = h;
    }
    h->next = q->next;
    free(q);
    L->len--;
    return OK;
}
int cmp(term a, term b) // CreatPolyn()的实参
{ // 依a的指数值<、=或>b的指数值，分别返回-1、0或+1
    if (a.expn == b.expn)
        return 0;
    else
        return (a.expn - b.expn) / abs(a.expn - b.expn);
}
void CreatPolyn(polynomial &p,int m)
{//输入m项的系数和指数，建立表示一元多项式的有序链表P
    InitList(&p);//初始化多项式链表
    Link h = GetHead(p);//设置头结点的数据元素
    ElemType e;//头结点设置
    Position q,s;
    e.coef = 0.0; e.expn = -1; SetCurElem(h, e);//设置头结点的元素
    for (int i = 1; i <= m; ++i)//依次输入m个非零项
    {
        cout << "第"<<i<<"项"<<"的系数:";
        cin >> e.coef;
        cout << "第" << i << "项" << "的指数:";
        cin >> e.expn;
        if (!LocateElemP(p, e,&q, cmp))//当前链表中不存在该指数项
        {
            if (e.coef != 0)//不等于才插入
                if (MakeNode(&s, e))InsFirst(&p,q,s);//生成结点并插入链表
        }
        else//当前链表中存在该指数项,增加其系数
        {
            q->data.coef = q->data.coef + e.coef;
            //如果合起来等于0，则删除掉
            if (q->data.coef == 0)
                Remove_Polyn(&p, q);//删除掉当前节点
        }
    }
}
Status ListTraverse(LinkList L, void(*visit)(ElemType))
{ /* 依次对L的每个数据元素调用函数visit()。一旦visit()失败，则操作失败 */
    Link p = L.head->next;
    int j;
    for (j = 1; j <= L.len; j++)
    {
        visit(p->data);
        p = p->next;
    }
    cout << "\b ";
    if (L.len == 0)
        cout << "0";
    return OK;
}
void visit(ElemType e)
{
    if (e.coef > 0 && e.coef != 1 && e.expn != 0)
    {
        if (e.expn > 0)
            cout << e.coef << "x^" << e.expn << "+";
        else
            cout << e.coef << "x^(" << e.expn << ")+";
    }
    else if (e.coef < 0 && e.expn != 0)
    {
        if (e.expn > 0)
            cout << "(" << e.coef << ")x^" << e.expn << "+";
        else
            cout << "(" << e.coef << ")x^(" << e.expn << ")+";
    }
    else if (e.coef == 1 && e.expn != 0)
    {
        if (e.expn > 0)
            cout << "x^" << e.expn << "+";
        else
            cout << "x^(" << e.expn << ")+";
    }
    else if (e.expn == 0 && e.coef != 0)
        cout << e.coef<<"+";
    else 
        cout << "";//考虑用户输入可能有系数为0的情况，情况太多，避免万一

}
Position NextPos(Link p)
{ /* 已知p指向线性链表L中的一个结点，返回p所指结点的直接后继的位置 */
    /* 若无后继，则返回NULL */
    return p->next;
}
ElemType GetCurElem(Link p)
{ /* 已知p指向线性链表中的一个结点，返回p所指结点中数据元素的值 */
    return p->data;
}
Status DelFirst(LinkList *L, Link h, Link *q) /* 形参增加L,因为需修改L */
{ /* h指向L的一个结点，把h当做头结点，删除链表中的第一个结点并以q返回。 */
    /* 若链表为空(h指向尾结点)，q=NULL，返回FALSE */
    *q = h->next;
    if (*q) /* 链表非空 */
    {
        h->next = (*q)->next;
        if (!h->next) /* 删除尾结点 */
            (*L).tail = h; /* 修改尾指针 */
        (*L).len--;
        return OK;
    }
    else
        return FALSE; /* 链表空 */
}

void FreeNode(Link *p)
{ /* 释放p所指结点 */
    free(*p);
    *p = NULL;
}
Status ListEmpty(LinkList L)
{ /* 若线性链表L为空表，则返回TRUE，否则返回FALSE */
    if (L.len)
        return FALSE;
    else
        return TRUE;
}
Status Append(LinkList *L, Link s)
{ /* 将指针s(s->data为第一个数据元素)所指(彼此以指针相链,以NULL结尾)的 */
    /* 一串结点链接在线性链表L的最后一个结点之后,并改变链表L的尾指针指向新 */
    /* 的尾结点 */
    int i = 1;
    (*L).tail->next = s;
    while (s->next)
    {
        s = s->next;
        i++;
    }
    (*L).tail = s;
    (*L).len += i;
    return OK;
}
void AddPolyn(polynomial &Pa, polynomial &Pb)
{//多项式加法:Pa = Pa+Pb,利用两个多项式的结点构成“和多项式”
    Position ha, hb, qa=NULL, qb=NULL;
    term a, b;
    ha = GetHead(Pa); hb = GetHead(Pb);//ha和hb分别指向Pa和Pb的头结点
    if (Pa.len != 0 && Pb.len != 0)
    {
        qa = NextPos(ha); qb = NextPos(hb);//qa和qb分别指向Pa和Pb中的当前结点
        //此时qa和qb都是指向多项式第一项
        while (qa && qb)
        {//qa和qb非空
            a = GetCurElem(qa);
            b = GetCurElem(qb); // a和b为两表中当前比较元素
            float sum;
            switch (cmp(a, b))//比较两者的指数值
            {
            case -1://多项式中PA中的结点的指数小
                ha = qa;	//暂存qas
                qa = NextPos(ha);
                break;
            case 0://两者指数值相等
                sum = a.coef + b.coef;
                if (sum != 0)
                {
                    //修改pa指向的该结点的系数值
                    qa->data.coef = sum;
                    //下一个
                    ha = qa;
                }
                else
                {
                    //删除结点
                    DelFirst(&Pa, ha, &qa);
                    FreeNode(&qa);
                }
                DelFirst(&Pb, hb, &qb);//也删除掉qb的结点
                //都往后移动一位
                qb = NextPos(hb);
                qa = NextPos(ha);
                break;
            case 1://多项式PB中的当前结点指数值小
                DelFirst(&Pb, hb, &qb);//把当前结点从PB中删除，并用qb指向当前结点用以插入
                InsFirst(&Pa, ha, qb);//插入在ha前
                qb = NextPos(hb);
                qa = NextPos(ha);
                break;
            }//switch
        }//while
        if (!ListEmpty(Pb))Append(&Pa, qb);//连接Pb中剩余结点
        FreeNode(&hb);//释放Pb的头结点
    }//A,B不为空
    if (Pa.len == 0)
    {
        Pa = Pb;//相加结果就是B
    }
    if (Pb.len == 0)
    {
        //相加结果就是A
    }   
    //其中一个已经空了

}//AddPolyn


int main()
{
    cout << "***************************************************************************" << endl;
    cout << "                   《数据结构》<C语言版本>严蔚敏 吴伟名 编著              " << endl;
    cout << "                                编写年月2016年3月                         " << endl;
    cout << "                                 编写者:YuYunTan                          " << endl;
    cout << "                                 一元多项式相加                           " << endl;
    cout << "***************************************************************************" << endl;

    polynomial A, B;
    cout << "请输入第一个多项式的项数为：";
    int length;
    cin >> length;
    CreatPolyn(A, length);
    //显示A出来
    cout << "PA(x) = ";
    ListTraverse(A, visit);
    cout << endl;
    //输入B
    cout << "请输入第二个多项式的项数为：";
    cin >> length;
    CreatPolyn(B, length);
    //输出B
    cout << "PB(x) = ";
    ListTraverse(B, visit);
    cout << endl;
    //假设以上输入成功
    //进行相加
    AddPolyn(A, B);
    //这时候A是合并后的结果
    cout << "PA(x)+PB(x) = ";
    ListTraverse(A, visit);
    cout << endl;
    system("pause");
    return 0;
}