#include "Stack.h"


Status InitStack(SqStack &S)//����һ����ջ
{
    S.base=(SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if(!S.base)
        return OVERFLOW;//�洢����ʧ��
    S.top=S.base;
    S.stacksize= STACK_INIT_SIZE;
    return OK;
}//InitStack


Status GetTop(SqStack S,SElemType &e)//��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR��
{
    if (S.top==S.base) return ERROR;
    e=*(S.top-1);
    return OK;
}//Gettop

Status Push(SqStack &S,SElemType &e)//����Ԫ��eΪ�µ�ջ��Ԫ��
{
    if(S.top-S.base>=S.stacksize)//ջ����׷�Ӵ洢�ռ�
    {
        S.base=(SElemType *)realloc(S.base,(S.stacksize+STACK_INIT_SIZE)*sizeof(SElemType));
        if(!S.base)
            return OVERFLOW;//�洢����ʧ��
        S.top=S.base+S.stacksize;
        S.stacksize+=STACKINCREMENT;
    }
    *S.top++=e;
    return OK;
}//push

Status Pop(SqStack &S,SElemType &e)//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
{
    if(S.top==S.base)
        return ERROR;
    e=*--S.top;
    return OK;
}//Pop

Status StackEmpty(SqStack S)//�ж�ջ�Ƿ�Ϊ�գ����Ϊ�շ�1��������0
{
    if(S.base==S.top)
        return OK;
    return ERROR;
}//StackEmpty

Status DetroyStack(SqStack &S)//����ջS
{
    free(S.base);
    S.base=NULL;
    S.top=NULL;
    S.stacksize=0;
    return OK;
}//DetroyStack




