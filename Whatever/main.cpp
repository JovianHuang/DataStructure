#include <iostream>
#include "BiTreeFunction.h"



int main()
{   char a[MAX_NUMBER];
    BiTree root;
    root=loadTree();
    printf("���������");
    PreOrderTraverse(root,PrintElement);
    printf("\n");
    printf("���������");
    InOrderTraverse(root,PrintElement);
    printf("\n");
    printf("���������");
    PostOrderTraverse(root,PrintElement);
    printf("\n");
    printf("���������");
    LevelOrderTraverse(root,PrintElement);
    printf("\n");
    printf("�������(�ǵݹ��㷨)��");
    root=loadTree();
    PreOrderTraverseInStack(root,PrintElement);
    printf("\n");
    root=loadTree();
    printf("�������(�ǵݹ��㷨)��");
    InOrderTraverseInStack(root,PrintElement);
    printf("\n");
    ReadFromFile_weight();
//    HuffmanCodeing
//    ReadFromFile_infromation(a);
}
