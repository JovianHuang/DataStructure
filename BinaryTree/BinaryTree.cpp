#include "BinaryTree.h"

BiTree NewNode(void) {
  BiTree node = (BiTree)malloc(sizeof(BTNode));
  node->sign = node->info.depth = 0;
  node->LChild = node->RChild = NULL;
  return node;
}

Status PrintNode(BiTree node) {
  if (!node) {
    return ERROR;
  }
  if (node->sign) { // which means the info is stored item
    printf("Item is %d\n", node->info.item);
  } else {
    printf("Depth is %d\n", node->info.depth);
  }
  return SUCCESS;
}

Status IsExisting(BiTree BT) {
  if (BT) { // which means BT is not a null pointer, return false
    return FALSE;
  } else {
    return TRUE;
  }
}

void InorderTraversal(BiTree BT) {
  if (BT) {
    InorderTraversal(BT->LChild);
    printf("%d ", BT->info.item); 
    InorderTraversal(BT->RChild);
  }
}

void PreorderTraversal(BiTree BT) {
  if (BT) {
    printf("%d ", BT->info.item);
    PreorderTraversal(BT->LChild);
    PreorderTraversal(BT->RChild);
  }
}

void PostorderTraversal(BiTree BT) {
  if (BT) {
    PostorderTraversal(BT->LChild);
    PostorderTraversal(BT->RChild);
    printf("%d ", BT->info.item);
  }
}

//void LevelorderTraversal(BiTree BT) {
//  Queue Q;
//  BiTree T;
//
//  if (!BT) return; /* 若是空树则直接返回 */
//
//  Q = CreateQueue(); /* 创建空队列Q */
//  AddQ(BT, Q);
//  while (!IsEmpty(Q)) {
//    T = DeleteQ(Q);
//    printf("%d ", T->Data); /* 访问取出队列的结点 */
//    if (T->LChild)   AddQ(Q, T->LChild);
//    if (T->RChild)  AddQ(Q, T->RChild);
//  }
//}


