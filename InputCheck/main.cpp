#include "InputCheck.h"

int main(void) {
  char test[20];
  fgets(test, 20, stdin);
  test[strlen(test) - 1] = '\n';
  if (StrIsPureNum(test)) {
    puts("yes");
  } else {
    puts("no");
  }
  return 0;
}