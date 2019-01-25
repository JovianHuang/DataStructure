#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SubscriptionInfo.h"

typedef struct {
  int Number;
  char Schoolname[26];
  char Schoolnum[15];
  char Quarter[50];  //征订号
  int  Quantity;
}ElemRec;  //元素记录

typedef struct {
  char quarter[50]; //征订号
  char Schoolname[50][26];  //学校名字
  int keynum;
}InList;

static void getString(char * st, int len);
static void ClearBuffer(void);

void InvertedList(void) { //List1
  FILE *fi;
  ElemRec List1[501];
  InList List2[100];
  int i = 1, n, j = 1, line, pos = 1, flag = 1;


  if ((fi = fopen("sub_info.txt", "rb")) == NULL) {
    printf("can not open the file\n");
    exit(0);
  }
  printf("学号 学校名 标识码 征订号 书的数量(倒序表（一），什么学校订阅了什么图书)\n");
  while (fread(&List1[i], sizeof(ElemRec), 1, fi) == 1) {
    printf("%d %s %s %s %d\n", List1[i].Number, List1[i].Schoolname, List1[i].Schoolnum, List1[i].Quarter, List1[i].Number);

    i++;
  }
  n = i - 1;    //订阅信息的数量
  i = 1;
  j = 1;
  strcpy(List2[j].quarter, List1[i].Quarter);
  i += 1;
  j += 1;

  while (i <= n) {
    for (pos = 1; pos <= i - 1; pos++) {
      if (strcmp(List1[pos].Quarter, List1[i].Quarter) != 0) {
        flag = 1;
      }
      else {
        flag = 0;
        break;
      }
    }//for
    if (flag == 1) {
      strcpy(List2[j].quarter, List1[pos].Quarter);
      j++;
    }
    i++;
  }
  line = j - 1;  //倒排表的行数
  for (i = 1; i < 100; i++)
    List2[i].keynum = 0;  //初始化
  i = 1;
  j = 1;
  pos = 1;

  while (i <= n) {
    while (j <= line) {
      if (strcmp(List1[i].Quarter, List2[j].quarter) == 0) {
        strcpy(List2[j].Schoolname[List2[j].keynum], List1[i].Schoolname);
        List2[j].keynum += 1;
        break;
      }
      j++;
    }
    j = 1;
    i++;
  }

  printf("征订号  学校名字（倒排表(二),什么书对应什么学校）\n");
  for (i = 1; i <= line; i++) {
    printf("%s ", List2[i].quarter);
    for (j = 0; j < List2[i].keynum; j++)
      printf("%s    ", List2[i].Schoolname[j]);
    printf("\n");
  }
  printf("\n\n\n\n");
  printf(">------查询界面------<\n");
  while (1) {
    printf("请输入你要查询的征订号（以回车结束）\n");
    char quarter[15];
    int option;
    printf("征订号:");
    getString(quarter, 15);
    if (strlen(quarter) == 10) {
      for (i = 1; i <= line; i++) {
        if (strcmp(quarter, List2[i].quarter) == 0) {
          for (j = 0; j < List2[i].keynum; j++)
            printf("%s ", List2[i].Schoolname[j]);
        }
      }
    }
    else {
      printf("请重新输入征订号（格式出错）\n");
    }
    printf("继续？（1：继续 0：退出）\n");
    scanf("%d", &option);
    if (!option)break;

  }
  fclose(fi);
}


/* local functions */
static void getString(char * st, int len) {
  int i = 0;
  char temp;
  while (true) {
    temp = getchar();
    if (temp == '\n' || i == len) {
      break;
    }
    else if (temp == ' ') {
      ClearBuffer();
      break;
    }
    st[i++] = temp;
  }
  st[i] = '\0';
}

static void ClearBuffer(void) {
  char temp;
  do {
    temp = getchar();
  } while (temp != '\n' && temp != EOF);
}