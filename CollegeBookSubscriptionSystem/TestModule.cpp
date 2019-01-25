#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <Windows.h>
#include "CollegeInfo.h"
#include "BPlusTree.h"
#include "ExternalSorting.h"
#include "UserInterface.h"
#include "BookInfo.h"
#include "SubscriptionInfo.h"
#include "HashFiles.h"

int main(void) {



  //FilePointer fp;
  //fp.source = fopen("university.dat", "rb");
  //fp.bucket = fopen("HashBucket_university.dat", "wb+");
  //fp.index = fopen("HashIndex_university.dat", "wb+");

  //CreateHashFiles(fp, Id);
  //fseek(fp.bucket, 0, 0);
  //fseek(fp.index, 0, 0);
  //Bucket bucket;
  //while (true) {
  //  fread(&bucket, sizeof(Bucket), 1, fp.bucket);
  //  if (feof(fp.bucket)) {
  //    break;
  //  }
  //  printf("%d\n", bucket.index);
  //  for (int i = 0; i < RECORDNUM; i++) {
  //    printf("%d\t", bucket.records[i].serialNum);
  //  }
  //  printf("\n");
  //  for (int i = 0; i < RECORDNUM; i++) {
  //    printf("%s\t", bucket.records[i].content);
  //  }
  //  printf("next: %d\n", bucket.next);
  //  printf("\n");
  //}
  //int * HashIndex = (int *)malloc(sizeof(int) * BUCKETNUM + 1);
  //fread(&HashIndex, sizeof(HashIndex), 1, fp.index);
  //for (int i = 0; i < BUCKETNUM + 1; i++) {
  //  printf("%d %d\n", i, HashIndex[i]);
  //}

  //InvertedList();

  return 0;
}
