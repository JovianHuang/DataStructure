#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "String.h"
#include "user.h"
using namespace std;
int main(void) {
  int choice, d;
  char *str = NULL, *c, *s;
  int ans, pos, len;
  printf("1表示输入字符串，2表示从文件读取\n");
  printf("请输入\n");
  scanf("%d", &d);
  if (d == 1) {
    c = (char*)malloc(sizeof(MAXSIZE));
    printf("请输入一串字符串(小于100个字符),#号结束:\n");
    str = String_Create();
  }
  if (d == 2) {
    //c = (char *)malloc(sizeof(1024));
    c = (char *)malloc(1024);
    str = ReadFile(c);
  }
  while (1) {
    printf("***************************\n");
    printf("字符串操作练习:\n");
    printf("1.求串长\n");
    printf("2.串复制\n");
    printf("3.串连接\n");
    printf("4.求子串\n");
    printf("5.比较串\n");
    printf("6.串插入\n");
    printf("7.串删除\n");
    printf("8.串查找\n");
    printf("9.串输出\n");
    printf("10.退出程序\n");
    printf("输入选择:\n");
    scanf("%d", &choice);
    getchar();
    switch (choice) {
      /*case 1:
        ans = String_Length(str);
        printf("串的长度为%d\n", ans);
        break;
      case 2:
        s = String_Copy(c, str);
        printf("目标字符串为:\n");
        String_Show(s);
        break;*/
      case 3:
        printf("输入字串(小于100个字符)\n");
        //c = (char*)malloc(sizeof(MAXSIZE));
        c = (char*)malloc(MAXSIZE);
        fgets(c, 100, stdin);
        c = String_Connect(c, str);
        printf("新的字符串为\n");
        String_Show(c);
        break;
        //case 4:
        //  printf("输入你想求子串所在位置及长度\n");
        //  scanf("%d %d", &pos, &len);
        //  c = String_SubStr(c, str, pos, len);
        //  if (c == NULL)
        //    printf("求子串失败！\n");
        //  else
        //  {
        //    printf("所求子串为:\n");
        //    String_Show(c);
        //  }
        //  break;
        //case 5:
        //  printf("输入字串:\n");
        //  gets_s(c, 100);
        //  ans = String_Compare(c, str);
        //  if (ans > 0)
        //    printf("首字符串大\n");
        //  else if (ans < 0)
        //    printf("第二个字符串大\n");
        //  else
        //    printf("两字符串相等\n");
        //  break;
        //case 6:
        //  printf("输入需在主串中插入的字串\n");
        //  gets_s(c, 100);
        //  printf("输入插入的位置:\n");
        //  scanf("%d", &pos);
        //  str = String_Insert(str, c, pos);
        //  printf("新的字符串为:\n");
        //  String_Show(str);
        //  break;
      case 7:
        printf("输入删除子串的起始位置及长度\n");
        scanf("%d %d", &pos, &len);
        str = String_Delete(str, pos, len);
        break;
        //case 8:
        //  printf("输入要查找的子串:\n");
        //  gets_s(c, 100);
        //  ans = String_Index(str, c, 1);
        //  printf("查找的结果为%d\n", ans);
        //  break;
      case 9:
        String_Show(str);
        break;
      case 10:
        return 0;
        break;
      default:
        printf("选择无效!\n");
        break;
    }
  }
  return 1;
}
