#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fixed.h"

#define MAX 120
typedef char SString[MAX+1];//0�Ŵ�Ŵ�����󳤶�
void filein(SString S);
void printf_string(SString S);
int strlen (SString s);
int StrLength(SString S);

#endif // STRING_H
