#ifndef SSTRING_H
#define SSTRING_H
#include"string.h"
#include<stdlib.h>
#include<stdio.h>
#define MAXSTRING 255  //用户可在255以内定义最大串长
#define OK 1
#define ERROR 0
 #define OVERFLOW -2
#define TRUE 1
#define FALSE 0
typedef  char SString[MAXSTRING+1];  //0号单元存放串的长度
typedef int Status;
Status StrAssign(SString &T, char chars[]);
Status StrCopy(SString &T,SString S,int pos,int len);
Status StrEmpyt(SString S);
int StrCompare(SString S,SString T);
int StrLength(SString S);
Status ClearString(SString &S);
Status Concat(SString &T,SString S1,SString S2);
Status SubString(SString &sub,SString S,int pos,int len);
int Index(SString S,SString T,int pos);
Status Replace(SString &S,SString T,SString V);
Status StrInsert(SString &S,int pos,SString T);
Status StrDelete(SString &S,int pos,int len);
void  DestroyString(SString &S);


int Index_KMP(SString S,SString T,int pos,int next[]);
void get_next(SString T,int next[]);



#endif // SSTRING_H
