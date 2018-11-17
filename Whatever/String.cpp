#include "String.h"
#include <stdio.h>
#include <stdlib.h>
//������
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
    printf("���볤�ȴ���100!\n");
  else
    *(s + i) = '\0';
  return s;
}
//�󴮳�
int String_Length(char *s) {
  int l = 0;
  while (*s != '\0') {
    l++;
    s++;
  }
  return l;
}
//���ĸ���
char *String_Copy(char *d, char *s) {
  char *c;
  c = d;
  return c;
}
//������
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

  for (; *d != '\0'; h++, d++)//������
  {
    *h = *d;
  }
  *h = '\0';
  //return c;
  return s;
}
//���Ӵ�
char *String_SubStr(char *d, char *s, int pos, int len) {
  char *c1, *c2 = NULL;
  int l, i;
  c2 = (char*)malloc(MAXSIZE);
  c1 = s;
  d = c2;
  l = String_Length(s);
  if (pos > l || pos < 1)			//����λ�÷Ƿ�
    return NULL;
  if (len < 0)					//���볤�ȷǷ�
    return NULL;
  c1 = c1 + pos - 1;
  for (i = 1; i <= len && *c1 != '\0'; i++)	//���ִ�
  {
    *c2++ = *c1++;
  }
  *c2 = '\0';					//��Ҫ���ǽ�β����
  return d;
}
//���Ƚ�
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
  if (*c1 == '\0' && *c2 == '\0')		//�����ַ���������ʱ�������ַ������
    return 0;
  else if (*c2 == '\0')				//�ڶ����ַ����Ƚ��������һ���ַ�����
    return 1;
  else
    return -1;
}
//���봮
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
//��ɾ��
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
//�Ӵ���λ
int String_Index(char *d, char *s, int pos) {
  int i = pos - 1, j = 0, ld, ls, b = 0;
  ld = String_Length(d);
  ls = String_Length(s);
  while (i < ld && j < ls) {
    if (*(d + i) == *(s + j))	//��ǰ�ַ���ȣ������ƥ��
    {
      i++;
      j++;
    } else					//��һ��ƥ��
    {
      i = i - j + 1;
      j = 0;
    }
  }
  //	if(j == ls)			//ƥ��ɹ�
  //     �� printf("�ַ�������/n");
  //		return (i - ls + 1);
  //		��
  //
  //	else
  //    printf("�ַ���������/n");
  return 0;
}
//�����
void String_Show(char *s) {
  while (putchar(*s++));
  printf("\n");
}
