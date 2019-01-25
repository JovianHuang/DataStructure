#ifndef BPTBASE_H
#define BPTBASE_H

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define OK 1
#define m 20
#define FALSE 0
#define ERROR 0
#define TRUE 1
#define MAX_KEYNUM  3000
//University Information
typedef char KeyType;
typedef int Status;
typedef struct {
  char SchoolName[25];
  char SchoolNum[15];
  char Department[20];
  char Place[20];
  char Level[15];
}Record;     //记录信息

typedef struct BPNode {
  int keynum;
  struct BPNode *parent;
  KeyType key[m + 2][15];      //零号元素未用
  struct BPNode *children[m + 1];
  struct BPNode *next;
  Record *recptr[m + 1];  //指向记录
}BPNode, *BPTree;

typedef struct {
  BPNode *pt;   //指向与Key对应的结点
  int i;
  int tag;
}Result;     //输出结果类型


void FreadRecord(Record R[], int &N);
BPTree MallocNewNode(void);
BPTree Initialize(void);
void KeySort(Record R[], int N);
Status CreateBPTree(BPTree &T, Record R[], int N);
Status CreateBPTreeParent(BPTree &T);
Result SearchUnByInput(BPTree T, KeyType num[]);
Status InsertBPLeaf(BPTree &T, KeyType K[], BPTree q, int pos);
Status Insert(BPTree &q, int i, KeyType K[], BPTree &ap);
Status split(BPTree &q, int s, BPTree &ap);
int Search(BPTree q, KeyType K[]);
Status NewRoot(BPTree &T, BPTree ap);

Status Return_Combine(BPTree &q, char x[]);
Status Combine(BPTree &p, BPTree &q);
Status SearchLeft(BPTree q, BPTree &p);
Status Return_Max(BPTree &q, char x[]);
Status Return_Borrow(BPTree &q);
Status BorrowToOther(BPTree &p, BPTree &q);
Status  DeletePos(BPTree &q, int i, int &flag);
Status DeleteInfo(BPTree &T, char num[]);
Status DeleteUniInfo(BPTree &T);
Status SearchFromBPTree(BPTree &T, KeyType k[], BPTree &q, int &i);

Status ModifyBptree(BPTree &T);
#endif // BPTBASE_H
