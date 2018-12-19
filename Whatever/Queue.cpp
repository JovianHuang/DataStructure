#include "Queue.h"

//ѭ�����еĻ�������

Status InitQueue(SqQueue &Q)//����һ���ն���Q
{
    Q.base=(QElemType*)malloc(MAXQSIZE*sizeof(QElemType));
    if(!Q.base)
        return OVERFLOW;//�洢����ʧ��
    Q.front=Q.rear=0;
    return OK;
}

Status EnQueue(SqQueue &Q,QElemType e)//����Ԫ��eΪQ���µĶ�βԪ��
{
    if(Q.rear==MAXQSIZE)
        return ERROR;//������
    Q.base[Q.rear]=e;
    Q.rear=Q.rear+1;
    return OK;
}

Status DeQueue(SqQueue &Q,QElemType &e)//�����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR
{
    if(Q.front==Q.rear)
        return ERROR;
    e=Q.base[Q.front];
    Q.front=Q.front+1;
            return OK;
}

Status QueueEmpty(SqQueue Q)//�ж϶����Ƿ�Ϊ�գ����Ϊ�շ�1��������0
{
    if(Q.rear==Q.front)
        return OK;
    return ERROR;
}

//Status DestroyQueue(SqQueue &Q)//���ٶ���Q
//{
//    if(Q.front!=NULL)
//    {
//        free(Q.front);
//    }
//    Q.front=Q.rear=NULL;
//    return OK;
//}





