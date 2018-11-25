/*
* =========================================================================== *
* @Author: 		JovianHuang
* @StudentID:	416125000301
* @Unit:		Class II, CS, School of IE, Hebei GEO University
* @Description: Implementation and simple application of binary tree (Huffman
                tree and coding).
* @Version:		0.3.4.181123_alpha
* =========================================================================== *
*/

#include "BinaryTree.h"

int main(void) {
  BiTree BT;
  BT = NewNode();
  if (IsEmpty(BT)) {
    puts("empty");
  } else {
    puts("not empty");
  }
  return 0;
}