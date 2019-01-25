#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ExternalSorting.h"
#include "Sort.h"
#include "CollegeInfo.h"
#include "BookInfo.h"
#include "SubscriptionInfo.h"

/* local data type */
static const int WAYNUM = 7;
/* prototype for local functions */

static SegeInfo InitializeSegeInfo(NodeInfo nodeinfo);
static void InternalSort(ExNode * arr, int number, int method);
static void Segement(FILE *fi, SegeInfo segeinfo, NodeInfo nodeinfo);
static void Segement_sub1(FILE *fi, School node, segeinfo segeinfo, nodeinfo nodeinfo);
static void SegeCopy_school(School node, ExNode &sege, nodeinfo nodeinfo);
static void Segement_sub2(FILE *fi, BOOK node, segeinfo segeinfo, nodeinfo nodeinfo);
static void SegeCopy_book(BOOK node, ExNode &sege, nodeinfo nodeinfo);
static void Merge(FILE *fi, FILE *fo, SegeInfo segeinfo, NodeInfo nodeinfo);
static int * ConstructLoser(segeinfo &segeinfo);
static void AdjustLoserTree(int * ls, SegeInfo &segeinfo, int winner);

/* functions definition */

NodeInfo InitializeNodeInfo(int Num, keyNameType keyName) {
  NodeInfo info;
  // TODO: check legality
  info.Num = Num;
  info.keyName = keyName;
  switch (keyName) {
    case schoolName:
    case schoolId:
    case schoolDepartment:
    case schoolLocation:
    case schoolLevel:
      info.Size = sizeof(school);
      break;
    case bookingNum:
    case bookVolume:
    case bookPublisher:
    case bookISBN:
    case bookName:
    case bookAward:
    case bookAuthor:
    case bookGrade:
    case bookPrice:
    case bookEdition:
    case bookPublishedDate:
    case bookCategory:
      info.Size = sizeof(book);
      break;
  }
  return info;
}

void SevenWayMergeSort(FILE *fi, FILE *fo, NodeInfo nodeinfo) {
  SegeInfo segeinfo = InitializeSegeInfo(nodeinfo);
  Segement(fi, segeinfo, nodeinfo);
  Merge(fi, fo, segeinfo, nodeinfo);
}

/* local functions */

static void Segement(FILE *fi, SegeInfo segeinfo, NodeInfo nodeinfo) {
  // 统一接口
  switch (nodeinfo.keyName) {
    case schoolName:
    case schoolId:
    case schoolDepartment:
    case schoolLocation:
    case schoolLevel: {
      School node = InitializeSchoolNode();
      Segement_sub1(fi, node, segeinfo, nodeinfo);
      break;
    }
    case bookingNum:
    case bookVolume:
    case bookPublisher:
    case bookISBN:
    case bookName:
    case bookAward:
    case bookAuthor:
    case bookGrade:
    case bookPrice:
    case bookEdition:
    case bookPublishedDate:
    case bookCategory: {
      BOOK node = InitializeBookNode();
      Segement_sub2(fi, node, segeinfo, nodeinfo);
      break;
    }
  }
}

static SegeInfo InitializeSegeInfo(NodeInfo nodeinfo) {
  SegeInfo segeinfo;
  segeinfo.capacity = nodeinfo.Num / WAYNUM + 1;
  segeinfo.wayNum = WAYNUM;
  segeinfo.sege = (ExNode *)malloc(sizeof(ExNode) * segeinfo.capacity);
  memset(segeinfo.sege, 0, segeinfo.capacity * sizeof(char) * KEYMAXLEN);
  return segeinfo;
}

static void Segement_sub1(FILE *fi, School node, segeinfo segeinfo, nodeinfo nodeinfo) {
  for (int i = 0; i < segeinfo.wayNum; i++) {
    int j = 0;
    while (j < segeinfo.capacity) {
      fread(&node, nodeinfo.Size, 1, fi);
      if (feof(fi)) {
        break;
      }
      segeinfo.sege[j].serialNum = node.serialNum;
      SegeCopy_school(node, segeinfo.sege[j], nodeinfo);
      //printf("%d %s\n", segeinfo.sege[j].serialNum, segeinfo.sege[j].key);
      j++;
    }
    printf("排序前分段%d共有%d条数据。\n", i, j);
    char filename[15];
    sprintf(filename, "temp%d.dat", i);
    FILE *fp = fopen(filename, "wb");
    InternalSort(segeinfo.sege, j, i);
    for (int t = 0; t < j; t++) {
      //printf("%d %s\n", segeinfo.sege[t].serialNum, segeinfo.sege[t].key);
      fwrite(&segeinfo.sege[t], sizeof(ExNode), 1, fp);
    }
    printf("排序后分段%d共有%d条数据。\n", i, j);
    fclose(fp);
  }
}

static void SegeCopy_school(School node, ExNode &sege, nodeinfo nodeinfo) {
  switch (nodeinfo.keyName) {
    case schoolName: {
      strcpy(sege.key, node.Name);
      break;
    }
    case schoolId: {
      strcpy(sege.key, node.Id);
      break;
    }
    case schoolDepartment: {
      strcpy(sege.key, node.supervisorDepartment);
      break;
    }
    case schoolLocation: {
      strcpy(sege.key, node.Location);
      break;
    }
    case schoolLevel: {
      strcpy(sege.key, node.Level);
      break;
    }
  }
}

static void Segement_sub2(FILE *fi, BOOK node, segeinfo segeinfo, nodeinfo nodeinfo) {
  for (int i = 0; i < segeinfo.wayNum; i++) {
    int j = 0;
    while (j < segeinfo.capacity) {
      fread(&node, nodeinfo.Size, 1, fi);
      if (feof(fi)) {
        break;
      }
      segeinfo.sege[j].serialNum = node.serialNum;
      SegeCopy_book(node, segeinfo.sege[j++], nodeinfo);
    }
    printf("排序前分段%d共有%d条数据。\n", i, j);
    char filename[15];
    sprintf(filename, "temp%d.dat", i);
    FILE *fp = fopen(filename, "wb");
    InternalSort(segeinfo.sege, j, i);
    for (int t = 0; t < j; t++) {
      fwrite(&segeinfo.sege[t], sizeof(ExNode), 1, fp);
      //printf("%d %s", segeinfo.sege[t].serialNum, segeinfo.sege[t].key);
    }
    printf("排序后分段%d共有%d条数据。\n\n", i, j);
    fclose(fp);
  }
}

static void SegeCopy_book(BOOK node, ExNode &sege, nodeinfo nodeinfo) {
  switch (nodeinfo.keyName) {
    case bookingNum: {
      strcpy(sege.key, node.bookingNum);
      break;
    }
    case bookVolume: {
      strcpy(sege.key, node.Volume);
      break;
    }
    case bookPublisher: {
      strcpy(sege.key, node.Publisher);
      break;
    }
    case bookISBN: {
      strcpy(sege.key, node.ISBN);
      break;
    }
    case bookName: {
      strcpy(sege.key, node.Name);
      break;
    }
    case bookAward: {
      strcpy(sege.key, node.Award);
      break;
    }
    case bookAuthor: {
      strcpy(sege.key, node.Author);
      break;
    }
    case bookGrade: {
      strcpy(sege.key, node.Grade);
      break;
    }
    case bookPrice: {
      strcpy(sege.key, node.Price);
      break;
    }
    case bookEdition: {
      strcpy(sege.key, node.Edition);
      break;
    }
    case bookPublishedDate: {
      strcpy(sege.key, node.publishedDate);
      break;
    }
    case bookCategory: {
      strcpy(sege.key, node.Category);
      break;
    }
  }
}

static void InternalSort(ExNode *arr, int number, int method) {
  switch (method) {
    case 0: {
      printf("\r正在使用快速排序法进行排序。\n");
      QuickSort(arr, number);
      break;
    }
    case 1: {
      printf("\r正在使用选择排序法进行排序。\n");
      SelectionSort(arr, number);
      break;
    }
    case 2: {
      printf("\r正在使用插入排序法进行排序。\n");
      InsertionSort(arr, number);
      break;
    }
    case 3: {
      printf("\r正在使用希尔排序法进行排序。\n");
      ShellSort(arr, number);
      break;
    }
    case 4: {
      printf("\r正在使用堆排序法进行排序。\n");
      HeapSort(arr, number);
      break;
    }
    case 5: {
      printf("\r正在使用归并排序法进行排序。\n");
      MergeSort(arr, number);
      break;
    }
    case 6: {
      printf("\r正在使用冒泡排序法进行排序。\n");
      BubbleSort(arr, number);
      break;
    }
  }
}

static void Merge(FILE *fi, FILE *fo, SegeInfo segeinfo, NodeInfo nodeinfo) {
  FILE **fp = (FILE **)malloc(sizeof(FILE *) * segeinfo.wayNum);
  char filename[15];
  int i;
  for (i = 0; i < segeinfo.wayNum; i++) {
    sprintf(filename, "temp%d.dat", i);
    fp[i] = fopen(filename, "rb+");
  }
  for (i = 0; i < segeinfo.wayNum; i++) {
    fread(&segeinfo.sege[i], sizeof(ExNode), 1, fp[i]);
  }
  int *ls = ConstructLoser(segeinfo);
  char MAXKEY[] = "鐏鐏鐏鐏鐏鐏鐏鐏鐏鐏鐏鐏鐏鐏鐏鐏";
  while (strcmp(segeinfo.sege[ls[0]].key, MAXKEY) != 0) {
    int pos;
    pos = ls[0];
    int location = segeinfo.sege[pos].serialNum;
    fseek(fi, (location - 1) * nodeinfo.Size, 0);
    switch (nodeinfo.keyName) {
      case schoolName:
      case schoolId:
      case schoolDepartment:
      case schoolLocation:
      case schoolLevel: {
        School node;
        fread(&node, nodeinfo.Size, 1, fi);
        fwrite(&node, nodeinfo.Size, 1, fo);
        //printf("%d %s %s %s %s %s\n", node.serialNum, node.Name, node.Id, node.supervisorDepartment, node.Location, node.Level);
        break;
      }
      case bookingNum:
      case bookVolume:
      case bookPublisher:
      case bookISBN:
      case bookName:
      case bookAward:
      case bookAuthor:
      case bookGrade:
      case bookPrice:
      case bookEdition:
      case bookPublishedDate:
      case bookCategory: {
        BOOK node;
        fread(&node, nodeinfo.Size, 1, fi);
        fwrite(&node, nodeinfo.Size, 1, fo);
 /*       printf("%d %s %s %s %s %s %s %s %s %s %s %s %s\n", node.serialNum, node.bookingNum, node.bookingNum, node.Publisher,
          node.ISBN, node.Name, node.Award, node.Author, node.Grade, node.Price, node.Edition, node.publishedDate, node.Category);
 */       break;
      }
    }
    fread(&segeinfo.sege[pos], sizeof(ExNode), 1, fp[pos]);
    if (feof(fp[pos])) {
      strcpy(segeinfo.sege[pos].key, MAXKEY);
    }
    AdjustLoserTree(ls, segeinfo, pos);
  }
  for (i = 0; i < segeinfo.wayNum; i++) {
    fclose(fp[i]);
  }
}

static int * ConstructLoser(segeinfo &segeinfo) {
  char MINKEY[160];
  for (int i = 0; i < 160; i++) {
    MINKEY[i] = 0;
  }
  strcpy(segeinfo.sege[segeinfo.wayNum].key, MINKEY);
  int i;
  int *ls = (int *)malloc(sizeof(int) * segeinfo.wayNum);
  for (i = 0; i < segeinfo.wayNum; i++) {
    ls[i] = segeinfo.wayNum;
  }
  for (i = segeinfo.wayNum - 1; i >= 0; i--) {
    AdjustLoserTree(ls, segeinfo, i);
  }
  return ls;
}

static void AdjustLoserTree(int * ls, SegeInfo &segeinfo, int winner) {
  int t = (winner + segeinfo.wayNum) / 2;
  while (t > 0) {
    if (strcmp(segeinfo.sege[winner].key, segeinfo.sege[ls[t]].key) > 0) {
      int tmp = ls[t];
      ls[t] = winner;
      winner = tmp;
    }
    t = t / 2;
  }
  ls[0] = winner;
}
