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
  FilePointer fp;
  fp.source = fopen("university.dat", "rb");
  fp.index = fopen("HashIndex.dat", "wb");
  fp.bucket = fopen("HashBucket.dat", "wb");
  CreateHashFiles(fp, Id);
  fp.bucket = fopen("HashBucket.dat", "rb");
  Bucket bucket;
  while (true) {
    fread(&bucket, sizeof(bucket), 1, fp.bucket);
    if (feof(fp.bucket)) {
      break;
    }
    for (int i = 0; i < RECORDNUM && bucket.records[i].serialNum != 0; i++) {
      printf("%d\t", bucket.records[i].serialNum);
    }
    printf("\n");
    for (int i = 0; i < RECORDNUM && bucket.records[i].serialNum != 0; i++) {
      printf("%s\t", bucket.records[i].content);
    }
    printf("\n\n");
  }
  return 0;
}