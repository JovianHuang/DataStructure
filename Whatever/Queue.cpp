#include "Queue.h"

Status InitQueue(SqQueue &Q)//����һ���ն���
{
    Q.base=(SElemtype)malloc(DEFSIZE*sizeof(Node));

    if(!Q.base) exit(OVERFLOW);//�洢����ʧ��
    Q.Front=Q.Rear=0;
    return OK;
}
Status EnQueue(SqQueue &Q,BiTree e) //����Ԫ��eΪQ���µĶ�βԪ��
{
    if(Q.Rear+1==DEFSIZE)  return ERROR;
    TNode New_e;
    New_e.data=e->data;
    New_e.lchild=e->lchild;
    New_e.rchild=e->rchild;
    Q.base[Q.Rear]=New_e;
    Q.Rear ++;
}
Status QueueEmpty(SqQueue Q)
{
    if(Q.Rear==0)  return 0;
    else if(Q.Rear==Q.Front)
        return 0;

    else return 1;


}
Status DeQueue(SqQueue &Q,BiTree &e)
{
    TNode De_mumber;
    if(Q.Front==Q.Rear)  return ERROR;
    De_mumber=Q.base[Q.Front];
    e->data=De_mumber.data;
    e->lchild=De_mumber.lchild;
    e->rchild=De_mumber.rchild;
    Q.Front =Q.Front +1;
    return OK;



}
