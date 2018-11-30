#ifndef STACK_H
#define STACK_H
#include "BiTreeFunction.h"


/*����ṹ��*/

//typedef TNode ElemType;  //����ջ��Ԫ������

// ����ջ�����ݽṹ


typedef struct
{
    SElemtype base;  //ջ��ָ��
    SElemtype top;   //ջ��ָ��
    int  stackSize;   //ջ��С
    int   realSize;   //ջ��ǰ��С

} SqStack;
Status Output(SqStack S);
Status InitStack(SqStack &S);
Status Push(SqStack &S,BiTree e);
Status Pop(SqStack &S,BiTree &e);
Status StackEmpty(SqStack S);
Status GetTop(SqStack &S,BiTree &e);
int StackLength(SqStack &S);

#endif // STACK_H
