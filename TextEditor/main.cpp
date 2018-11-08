#include "String.h"
#include "TextEdit.h"

int main(int argc, char * argv[]) {
  String test = StrIniti();
  char s[] =  "hello world";
  StrAssign(test, s);
  char t[] = "the ";
  StrInsert(test, 6, t);
  printf("%s\n", test.str);
  return 0;
}