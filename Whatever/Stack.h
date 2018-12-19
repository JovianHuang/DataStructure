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
//    int x;  //当前方块的行号
//    int y; //当前方块的列号
//}PoseType;
//
//typedef struct
//{
//    int ord; //道路块在此路径上的序号
//    PoseType seat;//道路块在迷宫上的坐标位置
//    int di;//从此道路块走向下一通道块的方向
//}SElemType;

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild,*rchild;//左右孩子指针
} BiTNode,*BiTree;

typedef BiTree SElemType;

typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
} SqStack;

Status InitStack(SqStack &S);//构造一个空栈
Status GetTop(SqStack S,SElemType &e);//若栈不空，则用e返回S的栈顶元素，并返回OK，否则返回ERROR；
Status Push(SqStack &S,SElemType &e);//插入元素e为新的栈顶元素
Status Pop(SqStack &S,SElemType &e);//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
Status StackEmpty(SqStack S);//判断栈是否为空，如果为空返0，不空则返1
Status DetroyStack(SqStack &S);//销毁栈S
#endif // STACK_H
