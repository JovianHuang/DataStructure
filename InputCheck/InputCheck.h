#ifndef INPUTCHECK_H
#define INPUTCHECK_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef enum casetype {
  Lower,
  Upper
} CaseType;

bool StrLenIsProper(char * str, unsigned int len);

bool IsAlphabet(char ch);

bool CaseUnified(char * str, CaseType ct);

bool IntnumInRange(int num, int lowerLimit, int upperLimit);

bool StrnumIsPositive(char * str);

bool StrIsPureNum(char * str);

void ClearBuffer(void);


#endif // !INPUTCHECK_H
