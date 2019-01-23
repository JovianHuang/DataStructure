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
static void InternalSort(char ** arr, int number, int method);
static void Segement(FILE *fi, SegeInfo segeinfo, NodeInfo nodeinfo);
static void Segement_sub1(FILE *fi, School node, segeinfo segeinfo, nodeinfo nodeinfo);
static void SegeCopy_school(School node, ExNode sege, nodeinfo nodeinfo);
static void Segement_sub2(FILE *fi, BOOK node, segeinfo segeinfo, nodeinfo nodeinfo);
static void SegeCopy_book(BOOK node, ExNode sege, nodeinfo nodeinfo);
//static void Merge(FILE *fi, FILE *fo, SegeInfo segeinfo, NodeInfo nodeinfo);
static int * ConstructLoser(int wayNum, ExNode *seges);
static void AdjustLoserTree(int * ls, ExNode * seges, int wayNum, int winner);

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
  //Merge(fi, fo, segeinfo, nodeinfo);
}

/* local functions */

static void Segement(FILE *fi, SegeInfo segeinfo, NodeInfo nodeinfo) {
  // 统一接口
  //char **sege = (char **)malloc(sizeof(char*) * capacity);
  //for (i = 0; i < capacity; i++) {
  //  sege[i] = (char *)malloc(sizeof(char) * KEYMAXLEN);
  //}
  //for (i = 0; i < segeinfo.wayNum; i++) {
  //  //memset(sege, 0, capacity * sizeof(char) * KEYMAXLEN);
  //  j = 0;
  //  while (j < segeinfo.capacity) {
  //    fscanf(fi, "%s", &sege[j++]);
  //    if (feof(fi)) {
  //      break;
  //    }
  //  }
  //  char filename[15];
  //  sprintf(filename, "temp%d.txt", i);
  //  FILE *fp = fopen(filename, "w");
  //  InternalSort(sege, j, i);
  //  for (int t = 0; t < j; t++) {
  //    fprintf(fp, "%d ", sege[t]);
  //  }
  //  fclose(fp);
  //}
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
  // Prevent the last path from having no content
  segeinfo.wayNum = nodeinfo.Num % segeinfo.capacity == 0 ?
    nodeinfo.Num / segeinfo.capacity : (nodeinfo.Num / (WAYNUM - 1)) == segeinfo.capacity ?
    WAYNUM : WAYNUM - 1;
  /*segeinfo.sege = (char **)malloc(sizeof(char*) * segeinfo.capacity);
  for (int i = 0; i < segeinfo.capacity; i++) {
    segeinfo.sege[i] = (char *)malloc(sizeof(char) * KEYMAXLEN);
  }*/
  segeinfo.sege = (ExNode *)malloc(sizeof(ExNode) * segeinfo.capacity);
  memset(segeinfo.sege, 0, segeinfo.capacity * sizeof(char) * KEYMAXLEN);
  return segeinfo;
}

static void Segement_sub1(FILE *fi, School node, segeinfo segeinfo, nodeinfo nodeinfo) {
  for (int i = 0; i < segeinfo.wayNum; i++) {
    int j = 0;
    while (j < segeinfo.capacity) {
      fread(&node, nodeinfo.Size, 1, fi);
      SegeCopy_school(node, segeinfo.sege[j++], nodeinfo);
      printf("%s", segeinfo.sege[j - 1]);
      if (feof(fi)) {
        break;
      }
    }
    //char filename[15];
    //sprintf(filename, "temp%d.txt", i);
    //FILE *fp = fopen(filename, "w");
    //InternalSort(segeinfo.sege, j, i);
  }
}

static void SegeCopy_school(School node, ExNode sege, nodeinfo nodeinfo) {
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

}

static void SegeCopy_book(BOOK node, ExNode sege, nodeinfo nodeinfo) {
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
      strcpy(sege.key, node.publishedDate);
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

// TODO
//static void Merge(FILE *fi, FILE *fo, SegeInfo segeinfo, NodeInfo info) {
//  FILE **fp = (FILE **)malloc(sizeof(FILE *) * wayNum);
//  char filename[15];
//  int i;
//  for (i = 0; i < wayNum; i++) {
//    sprintf(filename, "temp%d.txt", i);
//    fp[i] = fopen(filename, "a+");
//  }
//  ExNode *seges = (ExNode *)malloc(sizeof(ExNode) * wayNum + 1);
//  for (i = 0; i < wayNum; i++) {
//    fscanf(fp[i], "%d", &seges[i].key);
//  }
//  int *ls = ConstructLoser(wayNum, seges);
//  char MAXKEY[160];
//  memset(MAXKEY, '~', sizeof(MAXKEY));
//  while (strcmp(seges[ls[0]].key, MAXKEY) != 0) {
//    int pos;
//    pos = ls[0];
//    fprintf(fo, "%d ", seges[pos].key);
//    printf("%d ", seges[pos].key);
//    fscanf(fp[pos], "%d", &seges[pos].key);
//    if (feof(fp[pos])) {
//      strcpy(seges[ls[0]].key, MAXKEY);
//    }
//    AdjustLoserTree(ls, seges, wayNum, pos);
//  }
//}

static void InternalSort(char ** arr, int number, int method) {
  switch (method) {
    case 0: {
      BubbleSort(arr, number);
      break;
    }
    case 1: {
      SelectionSort(arr, number);
      break;
    }
    case 2: {
      InsertionSort(arr, number);
      break;
    }
    case 3: {
      ShellSort(arr, number);
      break;
    }
    case 4: {
      HeapSort(arr, number);
      break;
    }
    case 5: {
      MergeSort(arr, number);
      break;
    }
    case 6: {
      QuickSort(arr, number);
      break;
    }
  }
}

static int * ConstructLoser(int wayNum, ExNode *seges) {
  char MINKEY[160];
  memset(MINKEY, 0, sizeof(MINKEY));
  strcpy(seges[wayNum].key, MINKEY);
  int i;
  int *ls = (int *)malloc(sizeof(int) * wayNum);
  for (i = 0; i < wayNum; i++) {
    ls[i] = wayNum;
  }
  for (i = wayNum - 1; i >= 0; i--) {
    AdjustLoserTree(ls, seges, wayNum, i);
  }
  return ls;
}

static void AdjustLoserTree(int * ls, ExNode * seges, int wayNum, int winner) {
  int t = (winner + wayNum) / 2;
  while (t > 0) {
    if (seges[winner].key > seges[ls[t]].key) {
      int tmp = ls[t];
      ls[t] = winner;
      winner = tmp;
    }
    t = t / 2;
  }
  ls[0] = winner;
}
