#include "BiTree.h"


Status CreatBiTree(BiTree &T,int &i)//创建二叉树
{
    if(str[i]==' ')
    {
        T=NULL;//如果根节点为空，则返回NULL
        i++;
    }
    else
    {
        if(!(T=(BiTree)malloc(sizeof(BiTNode))))
            exit(OVERFLOW);
        T->data=str[i];//生成根节点
        i++;
        CreatBiTree(T->lchild,i);//构造左子树
        CreatBiTree(T->rchild,i);//构造右子树
    }
    return OK;
}
void fileout()//从文件中读取树
{
    FILE *fp;
    if((fp=fopen("tree.txt","r"))==NULL)
    {
        printf("open the file is error!\n");
        exit(0);
    }
    while(!feof(fp))
    {
        fgets(str,MAX,fp);//从文件读取数据
    }
    fclose(fp);//关闭文件
}


//BiTree loadTree()//从文件读取数据读取树
//{
//    FILE *fp;
//    int x;
//    BiTree root;
//    root=NULL;
//    if((fp=fopen("tree.txt","r"))==NULL)
//    {
//        printf("open the file is error!\n");
//        exit(0);
//    }
//    while(!feof(fp))
//    {
//        fscanf(fp,"%d",&x);//从文件读取数据
//        if(x==0)
//            break;
//        root=insert(x,root);//将x插入树
//    }
//    fclose(fp);//关闭文件
//    return root;
//}
//
//BiTree insert(int x,BiTree p)//用插入节点的方法创建树
//{
//    if(p==NULL)
//    {
//        p=(BiTNode*)malloc(sizeof(BiTNode));
//        p->data=x;
//        p->lchild=NULL;
//        p->rchild=NULL;
//    }
//    else
//    {
//        if(x<p->data)//小于当前结点值的插入左子树
//            p->lchild=insert(x,p->lchild);
//        else//大于当前结点值的插入左子树
//            p->rchild=insert(x,p->rchild);
//    }
//    return p;
//}

Status Visit(char e)//访问二叉树
{
    if(e==' ')
    {
        return ERROR;
    }
    else
    {
        printf("%c",e);
    }
    return OK;
}

Status PreOrderTraverse(BiTree T)//二叉树的先序遍历递归算法
{
    if(T)
    {
        printf("%c",T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
    return OK;
}

Status InOrderTraverse(BiTree T)//二叉树的中序遍历递归算法
{
    if(T)
    {
        InOrderTraverse(T->lchild);
        printf("%c",T->data);
        InOrderTraverse(T->rchild);
    }
    return OK;
}

Status PostOrderTraverse(BiTree T)//二叉树的后序遍历递归算法
{
    if(T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        printf("%c",T->data);
    }
    return OK;
}


Status PreOrderTrvs(BiTree p)//先根序遍历，非递归算法
{
    SqStack S;//栈中元素是BiTree类型
    InitStack(S);
    while(p!=NULL || !StackEmpty(S))
    {
        if(p!= NULL)
        {
            printf("%c", p->data);
            Push(S,p);
            p = p->lchild;
        }
        else    // p==NULL是递归出口
        {
            Pop(S,p);
            p = p->rchild;
        }
    }
    DetroyStack(S);
    free(p);//malloc获取的空间记得释放
    return OK;
}

Status InOrderTrvs(BiTree p)//中序遍历，非递归算法
{
    SqStack S;//栈中元素是BiTree类型
    InitStack(S);
    while(p!=NULL || !StackEmpty(S))
    {
        if(p!= NULL)
        {
            Push(S,p);
            p = p->lchild;
        }
        else    // p==NULL是递归出口
        {
            Pop(S,p);
            printf("%c", p->data);
            p = p->rchild;
        }
    }
    DetroyStack(S);
    free(p);//malloc获取的空间记得释放
    return OK;
}

//Status LevelOrderTraverse(BiTree T)//二叉树的层次遍历递归算法
//{
//    if (T)
//    {
//        BiTNode *Q[100];//假设不溢出
//        int front = -1,rear = -1;
//        if (T)
//        {
//            Q[++rear] = T;
//            printf("%c", T->data);
//            while (front!= rear)
//            {
//                BiTNode *p;
//                if (!(p = (BiTNode *)malloc(sizeof(BiTNode))))
//                {
//                    exit(OVERFLOW);
//                }
//                p = Q[++front];
//                if (p->lchild)
//                {
//                    Q[++rear] = p->lchild;
//                    printf("%c",p->lchild->data);
//                }
//                if (p->rchild)
//                {
//                    Q[++rear] = p->rchild;
//                    printf("%c",p->rchild->data);
//                }
//            }
//        }
//    }
//    return OK;
//}

Status LevelOrderTraverse(BiTree p)//二叉树的层次遍历递归算法
{
    SqQueue Q;
    InitQueue(Q);//构造一个空队列Q
    if(p!=NULL)
    {
        EnQueue(Q,p);
        while(!QueueEmpty(Q))
        {
            DeQueue(Q,p);
            printf("%c",p->data);
            if(p->lchild)
            {
                EnQueue(Q,p->lchild);
            }
            if(p->rchild)
            {
                EnQueue(Q,p->rchild);
            }
        }
    }
    //DestroyQueue(Q);//销毁栈S
    free(p);//malloc获取的空间记得释放
    return OK;
}








