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
  // Prevent the last path from having no content
  //segeinfo.wayNum = nodeinfo.Num % segeinfo.capacity == 0 ?
  //  nodeinfo.Num / segeinfo.capacity : (nodeinfo.Num % (WAYNUM - 1)) == segeinfo.capacity ?
  //  WAYNUM : WAYNUM - 1;
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
      SegeCopy_school(node, segeinfo.sege[j++], nodeinfo);
    }
    char filename[15];
    sprintf(filename, "temp%d.dat", i);
    FILE *fp = fopen(filename, "wb");
    InternalSort(segeinfo.sege, j, i);
    for (int t = 0; t < j; t++) {
      fwrite(&segeinfo.sege[t], sizeof(ExNode), 1, fp);
    }
    fclose(fp);
  }
}

static void SegeCopy_school(School node, ExNode &sege, nodeinfo nodeinfo) {
  switch (nodeinfo.keyName) {
    case schoolName: {
      memcpy(sege.key, node.Name, KEYMAXLEN);
      break;
    }
    case schoolId: {
      memcpy(sege.key, node.Id, KEYMAXLEN);
      break;
    }
    case schoolDepartment: {
      memcpy(sege.key, node.supervisorDepartment, KEYMAXLEN);
      break;
    }
    case schoolLocation: {
      memcpy(sege.key, node.Location, KEYMAXLEN);
      break;
    }
    case schoolLevel: {
      memcpy(sege.key, node.Level, KEYMAXLEN);
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
    char filename[15];
    sprintf(filename, "temp%d.dat", i);
    FILE *fp = fopen(filename, "wb");
    InternalSort(segeinfo.sege, j, i);
    for (int t = 0; t < j; t++) {
      fwrite(&segeinfo.sege[t], sizeof(ExNode), 1, fp);
    }
    fclose(fp);
  }
}

static void SegeCopy_book(BOOK node, ExNode &sege, nodeinfo nodeinfo) {
  switch (nodeinfo.keyName) {
    case bookingNum: {
      memcpy(sege.key, node.bookingNum, KEYMAXLEN);
      break;
    }
    case bookVolume: {
      memcpy(sege.key, node.Volume, KEYMAXLEN);
      break;
    }
    case bookPublisher: {
      memcpy(sege.key, node.publishedDate, KEYMAXLEN);
      break;
    }
    case bookISBN: {
      memcpy(sege.key, node.ISBN, KEYMAXLEN);
      break;
    }
    case bookName: {
      memcpy(sege.key, node.Name, KEYMAXLEN);
      break;
    }
    case bookAward: {
      memcpy(sege.key, node.Award, KEYMAXLEN);
      break;
    }
    case bookAuthor: {
      memcpy(sege.key, node.Author, KEYMAXLEN);
      break;
    }
    case bookGrade: {
      memcpy(sege.key, node.Grade, KEYMAXLEN);
      break;
    }
    case bookPrice: {
      memcpy(sege.key, node.Price, KEYMAXLEN);
      break;
    }
    case bookEdition: {
      memcpy(sege.key, node.Edition, KEYMAXLEN);
      break;
    }
    case bookPublishedDate: {
      memcpy(sege.key, node.publishedDate, KEYMAXLEN);
      break;
    }
    case bookCategory: {
      memcpy(sege.key, node.Category, KEYMAXLEN);
      break;
    }
  }
}

static void InternalSort(ExNode *arr, int number, int method) {
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
  char MAXKEY[] = "尊";
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
        break;
      }
    }
    fread(&segeinfo.sege[pos], sizeof(ExNode), 1, fp[pos]);
    if (feof(fp[pos])) {
      memcpy(segeinfo.sege[pos].key, MAXKEY, KEYMAXLEN);
    }
    AdjustLoserTree(ls, segeinfo, pos);
  }
}

static int * ConstructLoser(segeinfo &segeinfo) {
  char MINKEY[160];
  memset(MINKEY, 0, sizeof(MINKEY));
  memcpy(segeinfo.sege[segeinfo.wayNum].key, MINKEY, KEYMAXLEN);
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
