#ifndef QUEUE_H
#define QUEUE_H

#include "BiTreeFunction.h"
typedef struct
{

    SElemtype base;
    int Front;
    int Rear;
//    int  stackSize;   //队列大小
//    int   realSize;   //队列现在的大小
} SqQueue;
//迷宫队列的ADT
//队列
void output(SqQueue Q,BiTree e);
Status InitQueue(SqQueue &Q);
Status EnQueue(SqQueue &Q,BiTree e);
Status QueueEmpty(SqQueue Q);
Status DeQueue(SqQueue &Q,BiTree &e);

#endif // QUEUE_H
