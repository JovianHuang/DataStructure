#ifndef USER_H
#define USER_H

#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef int Status;

//typedef struct
//{
//    int x;  //��ǰ������к�
//    int y; //��ǰ������к�
//}PoseType;
//
//typedef struct
//{
//    int ord; //��·���ڴ�·���ϵ����
//    PoseType seat;//��·�����Թ��ϵ�����λ��
//    int di;//�Ӵ˵�·��������һͨ����ķ���
//}SElemType;

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild,*rchild;//���Һ���ָ��
} BiTNode,*BiTree;

typedef BiTree SElemType;

typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
} SqStack;

Status InitStack(SqStack &S);//����һ����ջ
Status GetTop(SqStack S,SElemType &e);//��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR��
Status Push(SqStack &S,SElemType &e);//����Ԫ��eΪ�µ�ջ��Ԫ��
Status Pop(SqStack &S,SElemType &e);//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
Status StackEmpty(SqStack S);//�ж�ջ�Ƿ�Ϊ�գ����Ϊ�շ�0��������1
Status DetroyStack(SqStack &S);//����ջS
#endif // STACK_H
