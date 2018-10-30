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

String StrIniti(void);

int StrLength(char * str);

void StrAssign(String & T, char * chars);

void StrCopy(String & T, String source, int pos, int len);

int StrCompare(String S, String T);


#endif // !STRING_H

