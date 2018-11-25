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

Status IsEmpty(BiTree BT) {
  if (BT) { // which means BT is not a null pointer, return false
    return FALSE;
  } else {
    return TRUE;
  }
}

   

