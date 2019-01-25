#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <Windows.h>
#include "CollegeInfo.h"
#include "ExternalSorting.h"
#include "UserInterface.h"
#include "BookInfo.h"
#include "SubscriptionInfo.h"
#include "HashFiles.h"

int main(void) {

  // ***********B+树*********** //

  // ***********B+树*********** //


  // ***********外部排序*********** //
  FILE *fi = fopen("books.dat", "rb");
  FILE *fo = fopen("SortedResult.dat", "wb");
  int infoNum[] = { 2631, 65535 };
  NodeInfo nodeinfo = InitializeNodeInfo(infoNum[0], bookName);
  SevenWayMergeSort(fi, fo, nodeinfo);
  fclose(fi);
  fclose(fo);
  FILE *fp = fopen("SortedResult.dat", "rb");
  BOOK node;
  int i = 0;
  while (true) {
    fread(&node, sizeof(BOOK), 1, fp);
    if (feof(fp)) {
      break;
    }
    printf("%d %s %s\n", node.serialNum, node.Name, node.ISBN);
    i++;
  }
  printf("%d", i);
  // ***********外部排序*********** //


  // ***********散列文件*********** //
  //FilePointer fp;
  //fp.source = fopen("university.dat", "rb");
  //fp.bucket = fopen("HashBucket_university.dat", "wb+");
  //fp.index = fopen("HashIndex_university.dat", "wb+");
  //CreateHashFiles(fp, Id);
  //fclose(fp.source);
  //fclose(fp.bucket);
  //fclose(fp.index);
  //FILE *f_bucket = fopen("HashBucket_university.dat", "rb");
  //FILE *f_index = fopen("HashIndex_university.dat", "rb");
  //Bucket *bucket = (Bucket *)malloc(sizeof(Bucket));
  //while (true) {
  //  fread(&bucket, sizeof(Bucket), 1, f_bucket);
  //  if (feof(f_bucket)) {
  //    break;
  //  }
  //  printf("%d\n", bucket->index);
  //  for (int i = 0; i < RECORDNUM; i++) {
  //    printf("%d\t", bucket->records[i].serialNum);
  //  }
  //  printf("\n");
  //  for (int i = 0; i < RECORDNUM; i++) {
  //    printf("%s\t", bucket->records[i].content);
  //  }
  //  printf("next: %d\n", bucket->next);
  //  printf("\n");
  //}
  //int * HashIndex = (int *)malloc(sizeof(int) * BUCKETNUM + 1);
  //fread(&HashIndex, sizeof(HashIndex), 1, f_index);
  //for (int i = 0; i < BUCKETNUM + 1; i++) {
  //  printf("%d %d\n", i, HashIndex[i]);
  //}
  // ***********散列文件*********** //


   //***********倒排表*********** 

   //***********倒排表*********** 

  return 0;
}
