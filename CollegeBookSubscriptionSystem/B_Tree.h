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
#define M 3//定义阶数
#define Super_Manager_Code 5372  //超级管理员密码
#define MAX_NAME_LEN 20//姓名长度
#define MAX_BKNAME_LEN 50
#define OK 1
#define ERROR 0

typedef int KeyType;
typedef int Status;

typedef struct ReaderNode {//借阅者
  int IDnum;                      //ID号
  char reader_name[MAX_NAME_LEN]; //姓名
  ReaderNode *rnext;              //指向下一个借阅者的指针
}ReaderNode, *ReaderType;


typedef ReaderNode Record;			//将书的结点定义为记录

typedef struct BTNode {    
  int keynum;			      
  KeyType key[M + 1];		   
  struct BTNode *parent;	   
  struct BTNode *ptr[M + 1]; 
  Record *recptr[M + 1];    
}BTNode, *BTree;			  

typedef struct result {
  BTNode *pt;				  //指向找到的结点
  int i;					  //1<=i<=m,在结点中的关键字位序
  int tag;				  //1:查找成功，0:查找失败
}result, *resultPtr;		  //B树的查找结果类型



 /*******************************B树接口定义***************************/


result SearchBTree(BTree T, KeyType k);
/*
  初始条件:树T存在
  操作结果:在m阶B数T上查找关键字k，返回p{pt,i,tag}
*/

Status InsertBTree(BTree &T, KeyType k, BTree q, int i, Record *recptr);
/*
  初始条件:树T存在
  操作结果:在B树T上结点p->pt的key[i]和key[i+1]之间插入关键字k
*/

Status DeleteBTree(BTree &T, KeyType k);
/*
  初始条件:B树上p结点存在
  操作结果:删除B树T上结点p->pt的关键字k
*/

void BTreeTraverse(BTree T, void(*visit)(BTree));
/*
  初始条件:树T存在
  操作结果:遍历B树
*/

