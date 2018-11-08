#ifndef STRING_H
#define STRING_H

/*standard header files*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*standard header files*/

typedef struct {
  char *str;
  /* If it's a non-empty string, allocate the storage area according to 
  the length of the string, otherwise str is NULL */
  int length;
}String;
#define SIZE_STOP 1

String StrIniti(void);
// Operation-result: Initialize the String

int StrLength(char * str);
// Preconditions: char * str already exists
// Operation-result: return the length of string str

void StrAssign(String & T, char * chars);
// Preconditions: chars is a string constant
// Operation-result: Assign the string constant to T

void StrCopy(String & T, String source, int pos, int len);
// Preconditions: String S already exists
// Operation - result: Copy a string of length ¡®len¡¯ from the specified position
  // ¡®pos¡¯ of the current string S, and save it in the target string T.

int StrCompare(String S, String T);
// Preconditions: String T and S already exists
// Operation-result: If S>T, return value > 0. If S<T, return value < 0.

void StrConcat(String & T, String S1, String S2);
// Preconditions: String S1 and S2 already exists

String SubString(String S, int pos, int len);
// Preconditions: String S already exists
// Operation-result: Cut the sub - string

void StrInsert(String &T, int pos, char * s);
// Preconditions: String T already exists
// Operation-result: Insert string s into the String T on the position pos.


#endif // !STRING_H

