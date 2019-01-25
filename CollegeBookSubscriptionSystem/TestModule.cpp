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

  // ***********B+��*********** //
  //int N;
  //BPTree T;
  //Result result;
  //Record record[MAX_KEYNUM + 2];
  //FreadRecord(record, N);
  //KeySort(record, N);
  //CreateBPTree(T, record, N);//�����У��ϢB+����
  //while (1) {
  //  int option, f = 1;
  //  printf("\n-------------------------------\n");
  //  printf("\t1.ѧУ��Ϣ��ѯ\t\t\n");
  //  printf("\t2.ѧУ��Ϣ����\t\t\n");
  //  printf("\t3.ѧУ��Ϣɾ��\t\t\n");
  //  printf("\t4.ѧУ��Ϣ�޸�\t\t\n");
  //  printf("\t0.�˳�\t\t\t\n");
  //  printf("-------------------------------\n");
  //  printf("ѡ��:");
  //  scanf("%d", &option);
  //  getchar();
  //  if (!option) {
  //    exit(0);
  //  }
  //  switch (option) {
  //    case 1: {
  //      printf("������Ҫ��ѯ��ѧУ�룺");
  //      KeyType Id[15];
  //      getString(Id, 15);
  //      result = SearchByInput(T, Id);
  //      if (result.tag == 0) {
  //        printf("����ʧ�ܣ�������\n");
  //        InsertBPLeaf(T, Id, result.pt, result.i);
  //        getName(record[N + f].SchoolName);
  //        getLocation(record[N + f].Place);
  //        getLevel(record[N + f].Level);
  //        result.pt->recptr[result.i] = &record[N + 1];
  //      } else {
  //        printf("ѧУ�� ���ڵ� ��ѧ���\n");
  //        printf("%s ", result.pt->recptr[result.i]->SchoolName);
  //        printf("%s ", result.pt->recptr[result.i]->Place);
  //        printf("%s ", result.pt->recptr[result.i]->Level);
  //      }
  //      break;
  //    }
  //    case 2: {
  //      printf("��������Ҫ�����ѧУ��\n");
  //      KeyType Id2[15];
  //      getString(Id2, 15);
  //      result = SearchByInput(T, Id2);
  //      if (result.tag == 0) {
  //        InsertBPLeaf(T, Id2, result.pt, result.i);
  //        getName(record[N + f].SchoolName);
  //        getLocation(record[N + f].Place);
  //        getLevel(record[N + f].Level);
  //        result.pt->recptr[result.i] = &record[N + 1];
  //        printf("�����\n");
  //        printf("ѧУ�� ���ڵ� ��ѧ���\n");
  //        printf("%s ", result.pt->recptr[result.i]->SchoolName);
  //        printf("%s ", result.pt->recptr[result.i]->Place);
  //        printf("%s ", result.pt->recptr[result.i]->Level);
  //      } else {
  //        printf("�Ѿ�����ͬ������\n");
  //      }
  //      SearchByInput(T, Id2);
  //      break;
  //    }
  //    case 3: {
  //      DeleteUniInfo(T);
  //      break;
  //    }
  //    case 4: {
  //      printf("������Ҫ�޸���Ϣ��ѧУ��ʶ��:");
  //      KeyType Id3[15];
  //      getString(Id3, 15);
  //      result = SearchByInput(T, Id3);
  //      if (result.tag == 1) {
  //        InsertBPLeaf(T, Id3, result.pt, result.i);
  //        printf("ѧУ�� ���ڵ� ��ѧ���\n");
  //        getName(record[N + f].SchoolName);
  //        getLocation(record[N + f].Place);
  //        getLevel(record[N + f].Level);
  //      }
  //      SearchByInput(T, Id3);
  //      printf("ѧУ��ʶ�� ѧУ�� ���ڵ� ��ѧ���\n");
  //      printf("%s %s %s %s\n", result.pt->recptr[result.i]->Id, result.pt->recptr[result.i]->SchoolName, result.pt->recptr[result.i]->Place, result.pt->recptr[result.i]->Level);
  //      break;
  //    }
  //    default: {
  //      printf("��������ȷ��ѡ��\n");
  //      break;
  //    }
  //             f++;
  //  }
  //}
  // ***********B+��*********** //


  // ***********�ⲿ����*********** //
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
  // ***********�ⲿ����*********** //


  // ***********ɢ���ļ�*********** //
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
  // ***********ɢ���ļ�*********** //


   //***********���ű�*********** 
  //InvertedList();
   //***********���ű�*********** 

  return 0;
}
