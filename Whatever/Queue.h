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
//    int x;//������
//    int y;//������
//}PosType;

//typedef struct
//{
//    PosType seat;//�����λ��
//    int pre;//��·������һ�����ڶ����е��±�
//} QElemType;//��������

typedef BiTree QElemType;

typedef struct
{
    QElemType *base;//��ʼ���Ķ�̬����洢�ռ�
    int front;//ͷָ�룬�����в��գ�ָ�����ͷԪ��
    int rear;//βָ�룬�����в��գ�ָ�����βԪ�ص���һλ��
} SqQueue;

Status InitQueue(SqQueue &Q);//����һ���ն���Q
Status EnQueue(SqQueue &Q,QElemType e);//����Ԫ��eΪQ���µĶ�βԪ��
Status DeQueue(SqQueue &Q,QElemType &e);//�����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR
Status QueueEmpty(SqQueue Q);//�ж϶����Ƿ�Ϊ�գ����Ϊ�շ�1��������0
//Status DestroyQueue(SqQueue &Q);//���ٶ���Q

#endif // QUEUE_H
