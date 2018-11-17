#include "String.h"
#include <stdio.h>
#include <stdlib.h>
//创建串
char *String_Create() {
  char *s, ch;
  int i = 0;
  s = (char*)malloc(MAXSIZE);
  ch = getchar();
  while (ch != '#') {
    *(s + i) = ch;
    i++;
    ch = getchar();
  }
  if (i > MAXSIZE / 2)
    printf("输入长度大于100!\n");
  else
    *(s + i) = '\0';
  return s;
}
//求串长
int String_Length(char *s) {
  int l = 0;
  while (*s != '\0') {
    l++;
    s++;
  }
  return l;
}
//串的复制
char *String_Copy(char *d, char *s) {
  char *c;
  c = d;
  return c;
}
//串连接
char *String_Connect(char *d, char *s) {
  char *c = NULL;
  char *h = NULL;
  int l, i, n;
  l = String_Length(d);
  i = String_Length(s);
  c = (char*)realloc(s, sizeof(char)*(i + l + 2));
  if (c != NULL) {
    s = c;
    c = (c + i);
    //h = c + i;
  }

  for (; *d != '\0'; h++, d++)//串连接
  {
    *h = *d;
  }
  *h = '\0';
  //return c;
  return s;
}
//求子串
char *String_SubStr(char *d, char *s, int pos, int len) {
  char *c1, *c2 = NULL;
  int l, i;
  c2 = (char*)malloc(MAXSIZE);
  c1 = s;
  d = c2;
  l = String_Length(s);
  if (pos > l || pos < 1)			//输入位置非法
    return NULL;
  if (len < 0)					//输入长度非法
    return NULL;
  c1 = c1 + pos - 1;
  for (i = 1; i <= len && *c1 != '\0'; i++)	//求字串
  {
    *c2++ = *c1++;
  }
  *c2 = '\0';					//不要忘记结尾符号
  return d;
}
//串比较
int String_Compare(char *d, char *s) {
  char *c1, *c2;
  c1 = d;
  c2 = s;
  while (*c1 != '\0' || *c2 != '\0') {
    if (*c1 > *c2)
      return 1;
    else if (*c1 < *c2)
      return -1;
    c1++;
    c2++;
  }
  if (*c1 == '\0' && *c2 == '\0')		//两个字符处都结束时，则两字符串相等
    return 0;
  else if (*c2 == '\0')				//第二个字符串先结束，则第一个字符串大
    return 1;
  else
    return -1;
}
//插入串
char *String_Insert(char *d, char *s, int pos) {
  int i, ld, ls;
  char *c1 = NULL, *c2 = NULL;
  ld = String_Length(d);
  ls = String_Length(s);
  c1 = String_SubStr(c1, s, 0, pos);
  c2 = String_SubStr(c2, s, pos, ls - pos);
  s = String_Connect(d, c1);
  s = String_Connect(c2, s);
  return s;
}
//串删除
char *String_Delete(char *d, int pos, int len) {
  int ld;
  char *c1 = NULL, *c2 = NULL, *c3 = NULL;
  ld = String_Length(d);
  c1 = String_SubStr(c1, d, 0, pos);
  c2 = String_SubStr(c2, d, pos, len);
  c3 = String_SubStr(c3, d, pos + len, ld - pos - len);
  d = String_Connect(c3, c1);
  return d;
}
//子串定位
int String_Index(char *d, char *s, int pos) {
  int i = pos - 1, j = 0, ld, ls, b = 0;
  ld = String_Length(d);
  ls = String_Length(s);
  while (i < ld && j < ls) {
    if (*(d + i) == *(s + j))	//当前字符相等，则继续匹配
    {
      i++;
      j++;
    } else					//下一趟匹配
    {
      i = i - j + 1;
      j = 0;
    }
  }
  //	if(j == ls)			//匹配成功
  //     ｛ printf("字符串存在/n");
  //		return (i - ls + 1);
  //		｝
  //
  //	else
  //    printf("字符串不存在/n");
  return 0;
}
//输出串
void String_Show(char *s) {
  while (putchar(*s++));
  printf("\n");
}
