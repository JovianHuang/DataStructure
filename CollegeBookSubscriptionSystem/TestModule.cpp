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
  //int N;
  //BPTree T;
  //Result result;
  //Record record[MAX_KEYNUM + 2];
  //FreadRecord(record, N);
  //KeySort(record, N);
  //CreateBPTree(T, record, N);//构造高校信息B+树，
  //while (1) {
  //  int option, f = 1;
  //  printf("\n-------------------------------\n");
  //  printf("\t1.学校信息查询\t\t\n");
  //  printf("\t2.学校信息增加\t\t\n");
  //  printf("\t3.学校信息删除\t\t\n");
  //  printf("\t4.学校信息修改\t\t\n");
  //  printf("\t0.退出\t\t\t\n");
  //  printf("-------------------------------\n");
  //  printf("选项:");
  //  scanf("%d", &option);
  //  getchar();
  //  if (!option) {
  //    exit(0);
  //  }
  //  switch (option) {
  //    case 1: {
  //      printf("请输入要查询的学校码：");
  //      KeyType Id[15];
  //      getString(Id, 15);
  //      result = SearchByInput(T, Id);
  //      if (result.tag == 0) {
  //        printf("查找失败，请输入\n");
  //        InsertBPLeaf(T, Id, result.pt, result.i);
  //        getName(record[N + f].SchoolName);
  //        getLocation(record[N + f].Place);
  //        getLevel(record[N + f].Level);
  //        result.pt->recptr[result.i] = &record[N + 1];
  //      } else {
  //        printf("学校名 所在地 办学层次\n");
  //        printf("%s ", result.pt->recptr[result.i]->SchoolName);
  //        printf("%s ", result.pt->recptr[result.i]->Place);
  //        printf("%s ", result.pt->recptr[result.i]->Level);
  //      }
  //      break;
  //    }
  //    case 2: {
  //      printf("请先输入要插入的学校码\n");
  //      KeyType Id2[15];
  //      getString(Id2, 15);
  //      result = SearchByInput(T, Id2);
  //      if (result.tag == 0) {
  //        InsertBPLeaf(T, Id2, result.pt, result.i);
  //        getName(record[N + f].SchoolName);
  //        getLocation(record[N + f].Place);
  //        getLevel(record[N + f].Level);
  //        result.pt->recptr[result.i] = &record[N + 1];
  //        printf("插入后\n");
  //        printf("学校名 所在地 办学层次\n");
  //        printf("%s ", result.pt->recptr[result.i]->SchoolName);
  //        printf("%s ", result.pt->recptr[result.i]->Place);
  //        printf("%s ", result.pt->recptr[result.i]->Level);
  //      } else {
  //        printf("已经有相同的数据\n");
  //      }
  //      SearchByInput(T, Id2);
  //      break;
  //    }
  //    case 3: {
  //      DeleteUniInfo(T);
  //      break;
  //    }
  //    case 4: {
  //      printf("请输入要修改信息的学校标识码:");
  //      KeyType Id3[15];
  //      getString(Id3, 15);
  //      result = SearchByInput(T, Id3);
  //      if (result.tag == 1) {
  //        InsertBPLeaf(T, Id3, result.pt, result.i);
  //        printf("学校名 所在地 办学层次\n");
  //        getName(record[N + f].SchoolName);
  //        getLocation(record[N + f].Place);
  //        getLevel(record[N + f].Level);
  //      }
  //      SearchByInput(T, Id3);
  //      printf("学校标识码 学校名 所在地 办学层次\n");
  //      printf("%s %s %s %s\n", result.pt->recptr[result.i]->Id, result.pt->recptr[result.i]->SchoolName, result.pt->recptr[result.i]->Place, result.pt->recptr[result.i]->Level);
  //      break;
  //    }
  //    default: {
  //      printf("请输入正确的选项\n");
  //      break;
  //    }
  //             f++;
  //  }
  //}
  // ***********B+树*********** //


  // ***********外部排序*********** //
  FILE *fi = fopen("university.dat", "rb");
  FILE *fo = fopen("SortedResult.dat", "wb");
  int infoNum[] = { 2631, 65535 };
  NodeInfo nodeinfo = InitializeNodeInfo(infoNum[0], schoolId);
  SevenWayMergeSort(fi, fo, nodeinfo);
  fo = fopen("SortedResult.dat", "rb");
  School school;
  while (true) {
    fread(&school, sizeof(School), 1, fo);
    if (feof(fo)) {
      break;
    }
    printf("%d %s %s %s %s %s\n", school.serialNum, school.Name, school.Id, school.supervisorDepartment,school.Location, school.Level);
  }
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
  //InvertedList();
   //***********倒排表*********** 

  return 0;
}
