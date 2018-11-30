#ifndef BITREEFUNCTION_H
#define BITREEFUNCTION_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*****************定义****************/
#define OK 1       //正常
#define ERROR 0   //出错
#define OVERFLOW -2      //内存申请不成功
#define DEFSIZE 10       //栈的默认大小
#define INCREAMSIZE 10   //每次当栈空间满是，增量
#define MAX_NUMBER 1000
/************定义类型*****************/
typedef int Status;   //定义状态
typedef int ElemType ;
typedef struct Node //结点结构
{
    ElemType data;
    struct Node*lchild;//左孩子
    struct Node*rchild;//右孩子
} TNode,*BiTree,*SElemtype;
/**--------------------函数声明------------------------**/
BiTree Insert(int x,BiTree p);
BiTree loadTree();
Status PrintElement (ElemType e);
Status InOrderTraverse(BiTree p,Status (*Visit)(ElemType e));//中序遍历，递归算法
Status PreOrderTraverse(BiTree p,Status (*Visit)(ElemType e));//先序遍历，递归算法
Status PostOrderTraverse(BiTree p,Status (*Visit)(ElemType e));//后序遍历，递归算法
Status LevelOrderTraverse(BiTree p,Status (*Visit)(ElemType e));//层序遍历
Status PreOrderTraverseInStack(BiTree p,Status (*Visit)(ElemType e));
Status InOrderTraverseInStack(BiTree p,Status (*Visit)(ElemType e));
Status ReadFromFile_weight();



#endif // BITREEFUNCTION_H
