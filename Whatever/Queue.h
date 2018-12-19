#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#define MAXQSIZE 100

#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define TURE 1

#include "Stack.h"

typedef int Status;
//typedef struct
//{
//    int x;//横坐标
//    int y;//纵坐标
//}PosType;

//typedef struct
//{
//    PosType seat;//方块的位置
//    int pre;//本路径中上一方块在队列中的下标
//} QElemType;//方块类型

typedef BiTree QElemType;

typedef struct
{
    QElemType *base;//初始化的动态分配存储空间
    int front;//头指针，若队列不空，指向队列头元素
    int rear;//尾指针，若队列不空，指向队列尾元素的下一位置
} SqQueue;

Status InitQueue(SqQueue &Q);//构造一个空队列Q
Status EnQueue(SqQueue &Q,QElemType e);//插入元素e为Q的新的队尾元素
Status DeQueue(SqQueue &Q,QElemType &e);//若队列不空，则删除Q的对头元素，用e返回其值，并返回OK；否则返回ERROR
Status QueueEmpty(SqQueue Q);//判断队列是否为空，如果为空返1，不空则返0
//Status DestroyQueue(SqQueue &Q);//销毁队列Q

#endif // QUEUE_H
