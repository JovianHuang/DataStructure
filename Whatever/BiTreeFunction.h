#ifndef BITREEFUNCTION_H
#define BITREEFUNCTION_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*****************����****************/
#define OK 1       //����
#define ERROR 0   //����
#define OVERFLOW -2      //�ڴ����벻�ɹ�
#define DEFSIZE 10       //ջ��Ĭ�ϴ�С
#define INCREAMSIZE 10   //ÿ�ε�ջ�ռ����ǣ�����
#define MAX_NUMBER 1000
/************��������*****************/
typedef int Status;   //����״̬
typedef int ElemType ;
typedef struct Node //���ṹ
{
    ElemType data;
    struct Node*lchild;//����
    struct Node*rchild;//�Һ���
} TNode,*BiTree,*SElemtype;
/**--------------------��������------------------------**/
BiTree Insert(int x,BiTree p);
BiTree loadTree();
Status PrintElement (ElemType e);
Status InOrderTraverse(BiTree p,Status (*Visit)(ElemType e));//����������ݹ��㷨
Status PreOrderTraverse(BiTree p,Status (*Visit)(ElemType e));//����������ݹ��㷨
Status PostOrderTraverse(BiTree p,Status (*Visit)(ElemType e));//����������ݹ��㷨
Status LevelOrderTraverse(BiTree p,Status (*Visit)(ElemType e));//�������
Status PreOrderTraverseInStack(BiTree p,Status (*Visit)(ElemType e));
Status InOrderTraverseInStack(BiTree p,Status (*Visit)(ElemType e));
Status ReadFromFile_weight();



#endif // BITREEFUNCTION_H
