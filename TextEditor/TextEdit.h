#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include "String.h"

typedef struct {
  int rows;
  String * *content;
}Text;

#endif // !TEXTEDIT_H
