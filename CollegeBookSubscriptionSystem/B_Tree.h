#pragma once
#include	"windows.h"
#include	"stdio.h"
#include	"conio.h"
#include	"stdlib.h"
#include	"malloc.h"
#include	"time.h"
#include    "string.h"
#include    "errno.h"

#define TRUE 1
#define FALSE 0
#define OVERFLOW -1
#define OK 1
#define ERROR 0
#define M 3//�������
#define Super_Manager_Code 5372  //��������Ա����
#define MAX_NAME_LEN 20//��������
#define MAX_BKNAME_LEN 50
#define OK 1
#define ERROR 0

typedef int KeyType;
typedef int Status;

typedef struct ReaderNode {//������
  int IDnum;                      //ID��
  char reader_name[MAX_NAME_LEN]; //����
  ReaderNode *rnext;              //ָ����һ�������ߵ�ָ��
}ReaderNode, *ReaderType;


typedef ReaderNode Record;			//����Ľ�㶨��Ϊ��¼

typedef struct BTNode {    
  int keynum;			      
  KeyType key[M + 1];		   
  struct BTNode *parent;	   
  struct BTNode *ptr[M + 1]; 
  Record *recptr[M + 1];    
}BTNode, *BTree;			  

typedef struct result {
  BTNode *pt;				  //ָ���ҵ��Ľ��
  int i;					  //1<=i<=m,�ڽ���еĹؼ���λ��
  int tag;				  //1:���ҳɹ���0:����ʧ��
}result, *resultPtr;		  //B���Ĳ��ҽ������



 /*******************************B���ӿڶ���***************************/


result SearchBTree(BTree T, KeyType k);
/*
  ��ʼ����:��T����
  �������:��m��B��T�ϲ��ҹؼ���k������p{pt,i,tag}
*/

Status InsertBTree(BTree &T, KeyType k, BTree q, int i, Record *recptr);
/*
  ��ʼ����:��T����
  �������:��B��T�Ͻ��p->pt��key[i]��key[i+1]֮�����ؼ���k
*/

Status DeleteBTree(BTree &T, KeyType k);
/*
  ��ʼ����:B����p������
  �������:ɾ��B��T�Ͻ��p->pt�Ĺؼ���k
*/

void BTreeTraverse(BTree T, void(*visit)(BTree));
/*
  ��ʼ����:��T����
  �������:����B��
*/

