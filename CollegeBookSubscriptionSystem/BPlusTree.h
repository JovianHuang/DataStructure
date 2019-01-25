//#ifndef BPLUSTREE_H
//#define BPLUSTREE_H
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//
//static const int M = 4;
//static const int LIMIT_M_2 = (M % 2 ? (M + 1) / 2 : M / 2);
//
//typedef int KeyType;
//typedef struct BPlusNode {
//  int ContentNum;
//  KeyType Key[M + 1];
//  struct BPlusNode * Children[M + 1];
//  struct BPlusNode * Next;
//} *BPlusTree, *Position;
//
//typedef struct indexnode {
//  char * Index[M + 1];
//} IndexNode;
//
//typedef struct datanode {
//  char * Data[M + 1];
//  int dataLocate[M + 1];
//  struct bptnode * sibling;
//} DataNode;
//
//typedef struct bptnode {
//  int ContentNum;
//  union nodetype {
//    IndexNode index;
//    DataNode data;
//  };
//  int tag;
//  struct bptnode * Children[M + 1];
//};
//
///* 初始化 */
//BPlusTree Initialize();
///* 插入 */
//BPlusTree Insert(BPlusTree T, KeyType Key);
///* 删除 */
//BPlusTree Remove(BPlusTree T, KeyType Key);
///* 销毁 */
////BPlusTree Destroy(BPlusTree T);
///* 遍历节点 */
//void Travel(BPlusTree T);
///* 遍历树叶节点的数据 */
//void TravelData(BPlusTree T);
//
//#endif // !BPLUSTREE_H
