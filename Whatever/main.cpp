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
  printf("1��ʾ�����ַ�����2��ʾ���ļ���ȡ\n");
  printf("������\n");
  scanf("%d", &d);
  if (d == 1) {
    c = (char*)malloc(sizeof(MAXSIZE));
    printf("������һ���ַ���(С��100���ַ�),#�Ž���:\n");
    str = String_Create();
  }
  if (d == 2) {
    //c = (char *)malloc(sizeof(1024));
    c = (char *)malloc(1024);
    str = ReadFile(c);
  }
  while (1) {
    printf("***************************\n");
    printf("�ַ���������ϰ:\n");
    printf("1.�󴮳�\n");
    printf("2.������\n");
    printf("3.������\n");
    printf("4.���Ӵ�\n");
    printf("5.�Ƚϴ�\n");
    printf("6.������\n");
    printf("7.��ɾ��\n");
    printf("8.������\n");
    printf("9.�����\n");
    printf("10.�˳�����\n");
    printf("����ѡ��:\n");
    scanf("%d", &choice);
    getchar();
    switch (choice) {
      /*case 1:
        ans = String_Length(str);
        printf("���ĳ���Ϊ%d\n", ans);
        break;
      case 2:
        s = String_Copy(c, str);
        printf("Ŀ���ַ���Ϊ:\n");
        String_Show(s);
        break;*/
      case 3:
        printf("�����ִ�(С��100���ַ�)\n");
        //c = (char*)malloc(sizeof(MAXSIZE));
        c = (char*)malloc(MAXSIZE);
        fgets(c, 100, stdin);
        c = String_Connect(c, str);
        printf("�µ��ַ���Ϊ\n");
        String_Show(c);
        break;
        //case 4:
        //  printf("�����������Ӵ�����λ�ü�����\n");
        //  scanf("%d %d", &pos, &len);
        //  c = String_SubStr(c, str, pos, len);
        //  if (c == NULL)
        //    printf("���Ӵ�ʧ�ܣ�\n");
        //  else
        //  {
        //    printf("�����Ӵ�Ϊ:\n");
        //    String_Show(c);
        //  }
        //  break;
        //case 5:
        //  printf("�����ִ�:\n");
        //  gets_s(c, 100);
        //  ans = String_Compare(c, str);
        //  if (ans > 0)
        //    printf("���ַ�����\n");
        //  else if (ans < 0)
        //    printf("�ڶ����ַ�����\n");
        //  else
        //    printf("���ַ������\n");
        //  break;
        //case 6:
        //  printf("�������������в�����ִ�\n");
        //  gets_s(c, 100);
        //  printf("��������λ��:\n");
        //  scanf("%d", &pos);
        //  str = String_Insert(str, c, pos);
        //  printf("�µ��ַ���Ϊ:\n");
        //  String_Show(str);
        //  break;
      case 7:
        printf("����ɾ���Ӵ�����ʼλ�ü�����\n");
        scanf("%d %d", &pos, &len);
        str = String_Delete(str, pos, len);
        break;
        //case 8:
        //  printf("����Ҫ���ҵ��Ӵ�:\n");
        //  gets_s(c, 100);
        //  ans = String_Index(str, c, 1);
        //  printf("���ҵĽ��Ϊ%d\n", ans);
        //  break;
      case 9:
        String_Show(str);
        break;
      case 10:
        return 0;
        break;
      default:
        printf("ѡ����Ч!\n");
        break;
    }
  }
  return 1;
}
