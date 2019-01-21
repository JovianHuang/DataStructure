#ifndef BPLUSTREE_H
#define BPLUSTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define M (4)
#define LIMIT_M_2 (M % 2 ? (M + 1)/2 : M/2)

typedef struct BPlusNode *BPlusTree, *Position;
typedef int KeyType;
struct BPlusNode {
  int KeyNum;
  KeyType Key[M + 1];
  BPlusTree Children[M + 1];
  BPlusTree Next;
};

/* ��ʼ�� */
BPlusTree Initialize();
/* ���� */
BPlusTree Insert(BPlusTree T, KeyType Key);
/* ɾ�� */
BPlusTree Remove(BPlusTree T, KeyType Key);
/* ���� */
BPlusTree Destroy(BPlusTree T);
/* �����ڵ� */
void Travel(BPlusTree T);
/* ������Ҷ�ڵ������ */
void TravelData(BPlusTree T);

#endif // !BPLUSTREE_H
