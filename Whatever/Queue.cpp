#include "Queue.h"

//循环队列的基本操作

Status InitQueue(SqQueue &Q)//构造一个空队列Q
{
    Q.base=(QElemType*)malloc(MAXQSIZE*sizeof(QElemType));
    if(!Q.base)
        return OVERFLOW;//存储分配失败
    Q.front=Q.rear=0;
    return OK;
}

Status EnQueue(SqQueue &Q,QElemType e)//插入元素e为Q的新的队尾元素
{
    if(Q.rear==MAXQSIZE)
        return ERROR;//队列满
    Q.base[Q.rear]=e;
    Q.rear=Q.rear+1;
    return OK;
}

Status DeQueue(SqQueue &Q,QElemType &e)//若队列不空，则删除Q的对头元素，用e返回其值，并返回OK；否则返回ERROR
{
    if(Q.front==Q.rear)
        return ERROR;
    e=Q.base[Q.front];
    Q.front=Q.front+1;
            return OK;
}

Status QueueEmpty(SqQueue Q)//判断队列是否为空，如果为空返1，不空则返0
{
    if(Q.rear==Q.front)
        return OK;
    return ERROR;
}

//Status DestroyQueue(SqQueue &Q)//销毁队列Q
//{
//    if(Q.front!=NULL)
//    {
//        free(Q.front);
//    }
//    Q.front=Q.rear=NULL;
//    return OK;
//}





