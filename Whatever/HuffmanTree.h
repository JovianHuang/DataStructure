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
}HTNode,*HuffmanTree;//��̬��������洢�շ�����
typedef char **HuffmanCode;//��̬��������洢�շ����������



void Huffmanfileout(HFTree &HF);//���ļ��ж��������ַ�����Ȩֵ
Status HuffmanCreat(HuffmanTree &HT,HFTree HF,int n);//������������
void Select(HuffmanTree &HT,int k,int &s1,int &s2);//Ѱ��parentΪ0��Ȩֵ��С���������
void HuffmanCoding(HuffmanTree HT,HuffmanCode &HC,HFTree HF,int n);//ʵ��n���ַ��ĺշ�������
void DecodingHuffmancode(HuffmanTree HT,HFTree HF,char code[],int len,char *result,int n);//ʵ��n���ַ��ĺշ�������




#endif // HUFFMANTREE_H
