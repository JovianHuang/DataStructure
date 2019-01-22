#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "CollegeInfo.h"
#include "BPlusTree.h"
#include "ExternalSorting.h"
#include "Hash.h"
#include "UserInterface.h"
#include "BookInfo.h"
#include "SubscriptionInfo.h"
#include "Sort.h"

int main(void) {
  FILE *fi, *fo;
  fi = fopen("aha.txt", "r");
  fo = fopen("aha_sorted.txt", "w");
  SevenWayMergeSort(fi, fo, 24);
  fclose(fi);
  fclose(fo);
  return 0;
}