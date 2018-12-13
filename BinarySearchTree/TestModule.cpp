#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

int main(int argc, char * agrv[]) {
  BSTree t = CreateNewBSTree();
  printf("%d\n", TreeItemCount(t));
  if (AddItem(20, t)) {
    printf("%d\n", TreeItemCount(t));
  }
  if (InTree(20, t)) {
    puts("it's in");
  } else {
    puts("no");
  }
  DeleteAll(t);
  if (TreeIsEmpty(t)) {
    puts("empty");
    printf("%d\n", TreeItemCount(t));
  }
  return 0;
}