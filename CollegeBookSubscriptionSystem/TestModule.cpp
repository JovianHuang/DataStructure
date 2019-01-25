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
#include "BPTbase.h"

static void ClearBuffer(void) {
  char temp;
  do {
    temp = getchar();
  } while (temp != '\n' && temp != EOF);
}

static void getString(char * st, int len) {
  int i = 0;
  char temp;
  while (true) {
    temp = getchar();
    if (temp == '\n' || i == len) {
      break;
    } else if (temp == ' ') {
      ClearBuffer();
      break;
    }
    st[i++] = temp;
  }
  st[i] = '\0';
}


int main(void) {

  // ***********B+树*********** //

  // ***********B+树*********** //


  // ***********外部排序*********** //
  FILE *fi = fopen("university.dat", "rb");
  FILE *fo = fopen("SortedResult.dat", "wb");
  int infoNum[] = { 2631, 65535 };
  NodeInfo nodeinfo = InitializeNodeInfo(infoNum[0], schoolId);
  SevenWayMergeSort(fi, fo, nodeinfo);
  fo = fopen("SortedResult.dat", "rb");
  //School school;
  //while (true) {
  //  fread(&school, sizeof(School), 1, fo);
  //  if (feof(fo)) {
  //    break;
  //  }
  //  printf("%d %s %s %s %s %s\n", school.serialNum, school.Name, school.Id, school.supervisorDepartment,school.Location, school.Level);
  //}
  fclose(fi);
  fclose(fo);
  // ***********外部排序*********** //


  // ***********散列文件*********** //
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
  // ***********散列文件*********** //


   //***********倒排表*********** 

   //***********倒排表*********** 

  return 0;
}
