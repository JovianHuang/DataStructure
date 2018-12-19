#ifndef BITREE_H
#define BITREE_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define MAX 80

#include "Stack.h"
#include "Queue.h"

extern char str[MAX];

typedef int Status;
//typedef struct BiTNode
//{
//    char data;
//    struct BiTNode *lchild,*rchild;//���Һ���ָ��
//} BiTNode,*BiTree;


void fileout();//���ļ��ж�ȡ��
Status CreatBiTree(BiTree &T,int &i);//����������
Status PreOrderTraverse(BiTree T);//����������������ݹ��㷨
Status InOrderTraverse(BiTree T);//�������ĺ�������ݹ��㷨
Status PostOrderTraverse(BiTree T);//�������ĺ�������ݹ��㷨
Status PreOrderTrvs(BiTree p);//�ȸ���������ǵݹ��㷨
Status InOrderTrvs(BiTree p);//����������ǵݹ��㷨
Status LevelOrderTraverse(BiTree T);//�������Ĳ�α����ݹ��㷨
#endif // BITREE_H
