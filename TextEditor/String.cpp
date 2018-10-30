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
  T.length = StrLength(chars);
  T.str = (char *)malloc(T.length * sizeof(char));
  for (int j = 0; j <= T.length; j++) { // inculding the '\0'
    T.str[j] = chars[j];
  }
}

void StrCopy(String &T, String source, int pos, int len) {
  if (!pos) {
    puts("Copy failed, starting position should starts from 1.");
  } else {
    T.length = len; // Copy a string of length 'len'
    T.str = (char *)malloc(T.length * sizeof(char));
    int j;
    for (j = 0; j < T.length; j++) {
      T.str[j] = source.str[j + pos - 1]; // from the specified position 'pos'
    }
    T.str[j] = '\0';
  }
}

int StrCompare(String S, String T) {
  if (!S.str || !T.str) {
    puts("String doesn't exsit.");
    return -1;
  } else {
    return S.length - T.length;
  }
}
