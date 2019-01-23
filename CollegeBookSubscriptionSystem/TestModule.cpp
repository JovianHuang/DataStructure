#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <Windows.h>
#include "CollegeInfo.h"
#include "BPlusTree.h"
#include "ExternalSorting.h"
#include "Hash.h"
#include "UserInterface.h"
#include "BookInfo.h"
#include "SubscriptionInfo.h"

int main(void) {

  //FILE *fi = fopen("subscription.dat", "rb");
  //FILE *fo = fopen("subscription.txt", "w");
  //subscription sub;
  //while (1) {
  //  fread(&sub, sizeof(subscription), 1, fi);
  //  if (feof(fi)) {
  //    break;
  //  }
  //  fprintf(fo, "%d\t%s\t%s\t%s\t%s\t%d\n", sub.serialNum, sub.schoolName, sub.Id, sub.bookName, sub.bookingNum, sub.subscriNum);;
  //}
  //fclose(fo);
  //fclose(fi);

  FILE *fi = fopen("university.dat", "rb");
  FILE *fo = fopen("aha.txt", "w");
  NodeInfo nodeinfo = InitializeNodeInfo(2631, schoolName);
  SevenWayMergeSort(fi, fo, nodeinfo);

  return 0;
}