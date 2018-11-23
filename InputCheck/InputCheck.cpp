#include "InputCheck.h"

bool StrLenIsProper(char *str, unsigned int len) {
  return strlen(str) <= len;
}

bool IsAlphabet(char ch) {
  if (ch < 'A' || ch > 'z') { // 'A', 65; 'z', 122
    return false;
  } else if (ch > 'Z' && ch < 'a') { // 'Z', 90; 'a', 97
    return false;
  }
  return true;
}

bool CaseUnified(char *str, CaseType ct) {
  int i = -1;
  while (str[++i] != '\0') {
    if (!IsAlphabet(str[i])) {
      continue;
    }
    if (str[i] > 'Z' && ct == Upper) {
      return false;
    } else if (str[i] < 'a' && ct == Lower) {
      return false;
    }
  }
  return true;
}

bool IntnumInRange(int num, int lowerLimit, int upperLimit) {
  if (num < lowerLimit) {
    return false;
  } else if (num > upperLimit) {
    return false;
  }
  return true;
}

bool StrnumIsPositive(char * str) {
  if (str[0] == '-') {
    return false;
  }
  return true;
}

bool StrIsPureNum(char * str) {
  int i;
  if (StrnumIsPositive(str)) {
    i = -1;
  } else {
    i = 0;
  }
  while (str[++i] != '\0') {
    if (str[i] < '0' || str[i] > '9') {
      return false;
    }
  }
  return true;
}

//int StrToInt(char * str) {
//  int num = 0;
//  
//  return num;
//}
//
//long long StrToLonglong(char * str) {
//  long long num = 0;
//
//  return num;
//}

void ClearBuffer(void) {
  int ch;
  do {
    ch = getchar();
  } while (ch != EOF && ch != '\0');
}
