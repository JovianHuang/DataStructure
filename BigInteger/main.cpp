#include "BigInteger.h"

int main(void) {
  int size1 = 0;
  int size2 = 0;
  puts("Please enter the first BigInterger:");
  char *str1 = ObtainedAsStr(size1);
  Node * head1 = StrToNum(size1, str1);
  puts("Please enter the second BigInterger:");
  char *str2 = ObtainedAsStr(size2);
  Node * head2 = StrToNum(size2, str2);


  // test module
  Node * result = Operate(head1, head2, Multiply);
  PrintList(result);
  // test module

  return 0;
}