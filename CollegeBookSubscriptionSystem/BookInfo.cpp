#include <string.h>
#include "BookInfo.h"


BOOK InitializeBookNode(void) {
  BOOK node;
  memset(&node, 0, sizeof(BOOK));
  return node;
}