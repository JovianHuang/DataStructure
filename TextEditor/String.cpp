#include "String.h"

String StrIniti(void) {
  String *string = (String *)malloc(sizeof(String));
  string->length = 0;
  string->str = NULL;
  return *string;
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
    return -99;
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
  String frontSub = SubString(T, 0, pos);
  String rearSub = SubString(T, pos, T.length - pos);
  String S = StrIniti();
  StrAssign(S, s);
  StrConcat(T, frontSub, S);
  String temp = StrIniti();
  StrCopy(temp, T, 1, T.length);
  StrConcat(T, temp, rearSub);
}

void StrDelete(String &T, int pos, int len) {
  int endPos = pos + len; // The end position of the substring that should be deleted
  int rearSubLen = T.length - endPos; // len of rear substring
  String rearSub = SubString(T, endPos, rearSubLen);
  String frontSub = SubString(T, 0, pos);
  StrConcat(T, frontSub, rearSub);
}

void GetNext(String T, int next[]) {
  int i , j;
  next[0] = -1;
  for (j = 1; j < T.length; j++) {
    i = next[j - 1];
    while ((i >= 0) && (T.str[i + 1] != T.str[j])) {
      i = next[i];
    }
    if (T.str[i + 1] == T.str[j]) {
      next[j] = i + 1;
    } else {
      next[j] = -1;
    }
  }
}

int IndexKMP(String S, String T, int pos) {
  if (S.length < T.length) {
    return -1;
  }
  int *next = (int *)malloc(sizeof(int) * T.length);
  GetNext(T, next);
  int s, t;
  s = t = 0;
  while (s < S.length && t < T.length) {
    if (S.str[s] == T.str[t]) {
      s++; t++;
    } else if (t >0) {
      t = next[t - 1] + 1;
    } else {
      s++;
    }
  }
  return (t == T.length) ? (s - T.length) : -1;
}
