#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

int main(int argc, char * agrv[]) {
  BSTree t = CreateNewBSTree();
  FILE * fp;
  if ((fp = fopen("NumsInBS.txt", "r")) != NULL) {
    ItemType temp;
    while (!feof(fp)) {
      fscanf(fp, "%d", &temp);
      AddItem(temp, t);
    }
  }
  fclose(fp);
  Traversal(t);
  return 0;
}