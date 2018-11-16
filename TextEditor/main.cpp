#include "TextEdit.h"

int main(int argc, char * argv[]) {
  Text text;
  char filename[] = "text.txt";
  ReadFromFile(text, filename);
  PrintTxt(text);
  //String s = StrIniti();
  //char t[] = "hello word";
  //StrAssign(s, t);
  //InsertARow(text, s, 2);
  //PrintTxt(text);
  //DeleteARow(text, 2);
  //PrintTxt(text);
  return 0;
}