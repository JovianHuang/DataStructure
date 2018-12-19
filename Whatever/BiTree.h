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
//    struct BiTNode *lchild,*rchild;//左右孩子指针
//} BiTNode,*BiTree;


void fileout();//从文件中读取树
Status CreatBiTree(BiTree &T,int &i);//创建二叉树
Status PreOrderTraverse(BiTree T);//二叉树的先序遍历递归算法
Status InOrderTraverse(BiTree T);//二叉树的后序遍历递归算法
Status PostOrderTraverse(BiTree T);//二叉树的后序遍历递归算法
Status PreOrderTrvs(BiTree p);//先根序遍历，非递归算法
Status InOrderTrvs(BiTree p);//中序遍历，非递归算法
Status LevelOrderTraverse(BiTree T);//二叉树的层次遍历递归算法
#endif // BITREE_H
