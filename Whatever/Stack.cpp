#include "Stack.h"


Status InitStack(SqStack &S)//构造一个空栈
{
    S.base=(SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if(!S.base)
        return OVERFLOW;//存储分配失败
    S.top=S.base;
    S.stacksize= STACK_INIT_SIZE;
    return OK;
}//InitStack


Status GetTop(SqStack S,SElemType &e)//若栈不空，则用e返回S的栈顶元素，并返回OK，否则返回ERROR；
{
    if (S.top==S.base) return ERROR;
    e=*(S.top-1);
    return OK;
}//Gettop

Status Push(SqStack &S,SElemType &e)//插入元素e为新的栈顶元素
{
    if(S.top-S.base>=S.stacksize)//栈满，追加存储空间
    {
        S.base=(SElemType *)realloc(S.base,(S.stacksize+STACK_INIT_SIZE)*sizeof(SElemType));
        if(!S.base)
            return OVERFLOW;//存储分配失败
        S.top=S.base+S.stacksize;
        S.stacksize+=STACKINCREMENT;
    }
    *S.top++=e;
    return OK;
}//push

Status Pop(SqStack &S,SElemType &e)//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
{
    if(S.top==S.base)
        return ERROR;
    e=*--S.top;
    return OK;
}//Pop

Status StackEmpty(SqStack S)//判断栈是否为空，如果为空返1，不空则返0
{
    if(S.base==S.top)
        return OK;
    return ERROR;
}//StackEmpty

Status DetroyStack(SqStack &S)//销毁栈S
{
    free(S.base);
    S.base=NULL;
    S.top=NULL;
    S.stacksize=0;
    return OK;
}//DetroyStack




