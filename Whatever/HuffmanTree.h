#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define MAX 80

typedef int Status;

typedef struct
{
    char ch;
    int weight;
} HFNode,*HFTree;

typedef struct
{
    int weight;
    int parent,lchild,rchild;
}HTNode,*HuffmanTree;//动态分配数组存储赫夫曼树
typedef char **HuffmanCode;//动态分配数组存储赫夫曼树编码表



void Huffmanfileout(HFTree &HF);//从文件中读出各个字符及其权值
Status HuffmanCreat(HuffmanTree &HT,HFTree HF,int n);//建立哈夫曼树
void Select(HuffmanTree &HT,int k,int &s1,int &s2);//寻找parent为0，权值最小的两个结点
void HuffmanCoding(HuffmanTree HT,HuffmanCode &HC,HFTree HF,int n);//实现n个字符的赫夫曼编码
void DecodingHuffmancode(HuffmanTree HT,HFTree HF,char code[],int len,char *result,int n);//实现n个字符的赫夫曼译码




#endif // HUFFMANTREE_H
