#include "String.h"

int main(int argc, char * argv[]) {
  char str[] = "HelloWorld";
  String test1 = StrIniti();
  StrAssign(test1, str);
  printf("%s\n", test1.str);
  String test2 = StrIniti();
  //StrCopy(test2, test1, 1, 5);
  printf("%s\n", test2.str);
  int cmp = StrCompare(test1, test2);
  printf("%d", cmp);
  return 0;
}