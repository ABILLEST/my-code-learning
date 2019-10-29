#include <stdarg.h>
#include <iostream>
using namespace std;

#define MAX_ARRAY_DIM 8
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

va_list ap;

class myArray
{
public:
    ElemType *base;
    int dim;
    int *bounds;
    int *constants;

    myArray(/* args */);
    ~myArray();
    Status InitArray(myArray &A, int dim, ...);
    Status DestroyArray(myArray &A);
    Status Value(myArray A, ElemType &e, ...);
    Status Assign(myArray &A, ElemType e, ...);
    Status Locate(myArray A, va_list ap1, int &off);
};

myArray::myArray(/* args */)
{
    cout<<"Array constructed"<<endl;
}
myArray::~myArray()
{
    cout<<"Array destructed"<<endl;
}

Status myArray::InitArray(myArray &A, int dim, ...)
{
    if(dim<1 || dim>MAX_ARRAY_DIM) return ERROR;

    A.dim = dim;
    A.bounds = new int[dim];
    if(!A.bounds) return ERROR;
    int elemtotal = 1;
    va_start(ap, dim);
    for(int i=0; i<dim; ++i)
    {
        A.bounds[i] = va_arg(ap, int);
    }
    va_end(ap);
    A.base = new ElemType[elemtotal];
    if(!A.base) return ERROR;

    A.constants = new int[dim];
    if(!A.constants) return ERROR;
    A.constants[dim-1] = 1;
    for(int i=dim-2; i>=0; --i)
        A.constants[i] = A.bounds[i+1] * A.constants[i+1];
    
    return OK;
}

Status myArray::DestroyArray(myArray &A)
{
    if(!A.base) return ERROR;
    delete []A.base;   A.base = NULL;
    if(!A.bounds) return ERROR;
    delete []A.bounds; A.bounds = NULL;
    if(!A.constants) return ERROR;
    delete []A.constants; A.constants = NULL;
    return OK;
}

Status myArray::Locate(myArray A, va_list ap1, int &off)
{
    off = 0;
    int ind;
    for(int i=0; i<A.dim; ++i)
    {
        ind = va_arg(ap, int);
        if(ind<0 || ind>=A.bounds[i])
            return ERROR;
        off += A.constants[i] * ind;
    }
    return OK;
}

Status myArray::Value(myArray A, ElemType &e, ...)
{
    int result, off;
    va_start(ap, e);
    if((result = Locate(A,ap,off))<=0)
        return result;
    e = *(A.base+off);
    return OK;
}

Status myArray::Assign(myArray &A, ElemType e, ...)
{
    int result, off;
    va_start(ap, e);
    if((result = Locate(A,ap,off))<=0)
        return result;
    *(A.base+off) = e;
    return OK;
}

int main()
{

}