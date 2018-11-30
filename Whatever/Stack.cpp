#include "Stack.h"

Status InitStack(SqStack &S)
{
    S.base=(SElemtype)malloc(DEFSIZE*sizeof(Node));
    if(!S.base)  exit(OVERFLOW);
    S.top=S.base;
    S.stackSize=DEFSIZE;
    S.realSize=0;
    return OK;
}
Status Push(SqStack &S,BiTree e)
{
//    TNode p;
//    p.data=e->data;
//    p.lchild=e->lchild;
//    p.rchild=e->rchild;
    if(S.top-S.base>=S.stackSize)
    {
        S.base=(SElemtype)realloc(S.base,(S.stackSize+INCREAMSIZE)*sizeof(Node));
        if(!S.base)  exit(OVERFLOW);
        S.top=S.base+S.stackSize;
        S.stackSize=S.stackSize+INCREAMSIZE;
    }
    *S.top++=*e;
    S.realSize++;


}
Status Pop(SqStack &S,BiTree &e)
{
    TNode p;

    if(S.top==S.base)
    {
        exit(ERROR);
    }
    e=--S.top;
//    e->data=p.data;
//    e->lchild=p.lchild;
//    e->rchild=p.rchild;
    S.realSize--;
    return OK;
}
Status StackEmpty(SqStack S)
{

    if(S.realSize>0)
        return 0;
    else
        return 1;

}
Status GetTop(SqStack &S,BiTree &e)
{
    TNode p;
    if(S.base==S.top)
    {
        exit(ERROR);
    }
    p = *(S.top-1);
    e->data=p.data;
    e->lchild=p.lchild;
    e->rchild=p.rchild;
    return OK;
}
int StackLength(SqStack &S)
{
    return S.realSize;
}
