#include "Stack.h"
#include "Queue.h"
Status PrintElement (ElemType e)
{

    printf(" %d ",e);
    return OK;



}

BiTree loadTree() //从文件读取数据，新建树
{

    FILE *fp;
    int x;
    BiTree root;
    root=NULL;
    if((fp=fopen("tree.txt","r"))==NULL)
    {
        printf("open the file if error!\n");
        exit(0);

    }
    while(!feof(fp))
    {
        fscanf(fp,"%d",&x);//从文件读取数据
        if(x==0) break;
        root = Insert(x,root);//将x插入树
    }
    fclose(fp);//关闭文件
    return root ;



}
BiTree Insert(int x,BiTree p) //用插入结点的方法创建树，创建的是二叉排序树
{
    if(p==NULL)
    {
        p = (BiTree)malloc(sizeof(Node));
        p->data= x;
        p->lchild = NULL;
        p->rchild = NULL;

    }
    else
    {

        if(x<p->data)//小于当前结点值的，插入左子树
            p->lchild = Insert(x,p->lchild);
        else
            p->rchild = Insert(x,p->rchild);

    }
    return p;

}
Status PreOrderTraverse(BiTree p,Status (*Visit)(ElemType e))
{
    if(p)
    {
        if(Visit(p->data))
            if(PreOrderTraverse(p->lchild,Visit))
                if(PreOrderTraverse(p->rchild,Visit)) return OK;
        return ERROR;
    }
    else return OK;

}
Status InOrderTraverse(BiTree p,Status (*Visit)(ElemType e))
{
    if(p)
    {
        if(InOrderTraverse(p->lchild,Visit))
            if(Visit(p->data))
                if(InOrderTraverse(p->rchild,Visit)) return OK;
        return ERROR;
    }

    else return OK;
}
Status PostOrderTraverse(BiTree p,Status (*Visit)(ElemType e))
{
    if(p)
    {
        if(PostOrderTraverse(p->lchild,Visit))
            if(PostOrderTraverse(p->rchild,Visit))
                if(Visit(p->data)) return OK;
        return ERROR;
    }

    else return OK;
}
Status LevelOrderTraverse(BiTree p,Status (*Visit)(ElemType e))
{

    SqQueue Q;
    InitQueue(Q);
    if(p)
    {
        EnQueue(Q,p);
        while(QueueEmpty(Q))
        {
            DeQueue(Q,p);
            printf("%d",p->data);
            if(p->lchild)
                EnQueue(Q,p->lchild);
            if(p->rchild)
                EnQueue(Q,p->rchild);
        }
    }
    return OK;
}
Status PreOrderTraverseInStack(BiTree p,Status (*Visit)(ElemType e))
{
    SqStack S;

    InitStack(S);
    if(p)
        Push(S,p);
    while(!StackEmpty(S))
    {
        Pop(S,p);
        Visit(p->data);
        if(p->rchild)
        {
            Push(S,p->rchild);
        }
        if(p->lchild)
        {
            Push(S,p->lchild);
        }
    }
    return OK;
}
Status InOrderTraverseInStack(BiTree p,Status (*Visit)(ElemType e))
{

    SqStack S;
    InitStack(S);


    while(p||!StackEmpty(S))
    {
        if(p)
        {
            Push(S,p);
            p=p->lchild;
        }
        else
        {
            Pop(S,p);
            Visit(p->data);
            p=p->rchild;



        }

    }


    return OK;

}
//void ReadFromFile_infromation(char &a[MAX_NUMBER])
//{
//
//    FILE fp;
//    if((fp=fopen("Text.txt","r"))==NULL)
//    {
//
//        printf("Can not open this file!");
//        exit(0);
//    }
//    fgets(a,MAX_NUMBER,fp);
//    fclose(fp);
//    a[strlen(a)-1]='\0';
//
//
//}










