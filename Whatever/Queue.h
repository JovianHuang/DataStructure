#ifndef QUEUE_H
#define QUEUE_H

#include "BiTreeFunction.h"
typedef struct
{

    SElemtype base;
    int Front;
    int Rear;
//    int  stackSize;   //���д�С
//    int   realSize;   //�������ڵĴ�С
} SqQueue;
//�Թ����е�ADT
//����
void output(SqQueue Q,BiTree e);
Status InitQueue(SqQueue &Q);
Status EnQueue(SqQueue &Q,BiTree e);
Status QueueEmpty(SqQueue Q);
Status DeQueue(SqQueue &Q,BiTree &e);

#endif // QUEUE_H
