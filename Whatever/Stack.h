#ifndef STACK_H
#define STACK_H
#include "BiTreeFunction.h"


/*定义结构体*/

//typedef TNode ElemType;  //定义栈内元素类型

// 定义栈的数据结构


typedef struct
{
    SElemtype base;  //栈底指针
    SElemtype top;   //栈顶指针
    int  stackSize;   //栈大小
    int   realSize;   //栈当前大小

} SqStack;
Status Output(SqStack S);
Status InitStack(SqStack &S);
Status Push(SqStack &S,BiTree e);
Status Pop(SqStack &S,BiTree &e);
Status StackEmpty(SqStack S);
Status GetTop(SqStack &S,BiTree &e);
int StackLength(SqStack &S);

#endif // STACK_H
