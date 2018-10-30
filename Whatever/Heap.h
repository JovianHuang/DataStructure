#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define error 0
#define H 100
typedef struct {
char *ch;
int length;
int a[H];
}HString;

typedef  int Status;
Status filein_1( char chars[]);
int strlen (char s[]);
Status line(HString &S);

Status StrAssign(HString &T,char chars[]);
Status SubString(HString &Sub,HString S,int pos,int len);
Status Concat(HString &T,HString S1,HString S2);
Status ClearString(HString &S);
int StrCompare(HString S,HString T);

Status  StringInsert(HString &S);
Status StrInsert(HString &S,int pos,HString T);

Status StringDelete(HString &S);
Status StrDelete (HString &S,int pos,int len);

Status search_1(HString S);
Status search_2(HString &S);
void get_next(HString T,int next[]);
int KMP(HString S,HString T,int pos,int next[]);
Status search(int a[],HString T,int pos);
Status replace_string (int pos,HString &S,char s1[]);

Status StringCopy(HString S);
Status StrCopy( HString &T, HString S, int pos, int len);

Status printf_all(HString S );
Status Insert_a_line(HString &S);
Status Delete_a_line(HString &S);
Status Statistics_characters (HString S);
int KMP_2(HString S,HString T,int pos,int next[]);
Status Statistics_row_characters (HString S);
Status StrDelete_2(HString &S,int pos,int len,char s[]);
Status Delete_a_line_2(HString &s,int x );
Status Move(HString &S);
Status Delete_a_line_2(HString &S,int x ,char s[120]);
Status Insert_a_line_2(HString &S,int len,char s[120]);
Status StrInsert_2(HString &S,int pos,int len,char s[120]);

#endif // HEAP_H
