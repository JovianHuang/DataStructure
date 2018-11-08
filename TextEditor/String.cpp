#include "String.h"

String StrIniti(void) {
  String string;
  string.length = 0;
  string.str = NULL;
  return string;
}

int StrLength(char * str) {
  int i;
  char *c;
  for (i = 0, c = str; *c; i++, c++); // strlen
  return i;
}

void StrAssign(String &T, char * chars) {
  if (T.str) {
    free(T.str);
  }
  int len = StrLength(chars);
  T.str = (char *)malloc((len + SIZE_STOP) * sizeof(char));
  T.length = len;
  for (int j = 0; j <= T.length; j++) { // inculding the '\0'
    T.str[j] = chars[j];
  }
}

void StrCopy(String &T, String source, int pos, int len) {
  if (!pos) {
    puts("Copy failed, starting position should starts from 1.");
  } else {
    T.length = len; // Copy a string of length 'len'
    T.str = (char *)malloc((T.length + SIZE_STOP) * sizeof(char));
    int j;
    for (j = 0; j < T.length; j++) {
      T.str[j] = source.str[j + pos - 1]; // from the specified position 'pos'
    }
    T.str[j] = '\0';
  }
}

int StrCompare(String S, String T) {
  if (S.str && T.str) {
    return S.length - T.length;
  } else {
    puts("String doesn't exsit.");
  }
}

void StrConcat(String &T, String S1, String S2) {
  int len = S1.length + S2.length;
  if (T.str) {
    free(T.str);
  }
  T.str = (char *)malloc((len +SIZE_STOP) * sizeof(char));
  T.length = len;
  int i;
  for (i = 0; i < S1.length; i++) {
    T.str[i] = S1.str[i];
  }
  for (int j = 0; j < S2.length; j++, i++) {
    T.str[i] = S2.str[j];
  }
  T.str[i] = '\0';
}

String SubString(String S, int pos, int len) {
  String sub = StrIniti();
  sub.length = len;
  sub.str = (char *)malloc((len + SIZE_STOP) * sizeof(char));
  int i;
  for (i = 0; i < len; i++) {
    sub.str[i] = S.str[pos++];
  }
  sub.str[i] = '\0';
  return sub;
}

void StrInsert(String &T, int pos, char * s) {
  String FrontSub = SubString(T, 0, pos);
  String RearSub = SubString(T, pos, T.length - pos);
  String S = StrIniti();
  StrAssign(S, s);
  StrConcat(T, FrontSub, S);
  String temp = StrIniti();
  StrCopy(temp, T, 1, T.length);
  StrConcat(T, temp, RearSub);
}

void StrDelete(String &T, int pos, int len) {
  
}
