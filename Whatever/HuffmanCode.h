#ifndef HUFFMANCODE_H
#define HUFFMANCODE_H
#include "BiTreeFunction.h"
typedef struct
{

    unsigned int weight;
    unsigned int parent,lchild,rchild;

} HTNode,*HuffmanTree; //��̬�������鴢��շ�����
typedef struct
{

    char data;
    int weight;

} MumAndWeight;
typedef char **HuffmanCode;
void Select(HuffmanTree HT,int n,int &s1,int &s2);

#endif // HUFFMANCODE_H
