#include <iostream>
#include "BiTreeFunction.h"



int main()
{   char a[MAX_NUMBER];
    BiTree root;
    root=loadTree();
    printf("先序遍历：");
    PreOrderTraverse(root,PrintElement);
    printf("\n");
    printf("中序遍历：");
    InOrderTraverse(root,PrintElement);
    printf("\n");
    printf("后序遍历：");
    PostOrderTraverse(root,PrintElement);
    printf("\n");
    printf("层序遍历：");
    LevelOrderTraverse(root,PrintElement);
    printf("\n");
    printf("先序遍历(非递归算法)：");
    root=loadTree();
    PreOrderTraverseInStack(root,PrintElement);
    printf("\n");
    root=loadTree();
    printf("中序遍历(非递归算法)：");
    InOrderTraverseInStack(root,PrintElement);
    printf("\n");
    ReadFromFile_weight();
//    HuffmanCodeing
//    ReadFromFile_infromation(a);
}
