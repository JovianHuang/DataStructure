/*
* =========================================================================== *
* @Author: 		JovianHuang
* @StudentID:	416125000301
* @Unit:		Class II, CS, School of IE, Hebei GEO University
* @Description: A simple Text Editor
* @Version:		1.9.21.181117_alpha
* =========================================================================== *
*/
#include "TextEdit.h"
#include "InputCheck.h"

int main(int argc, char * argv[]) {
  Text text;
  char filename[] = "text.txt";
  ReadFromFile(text, filename);
  PrintTxt(text);
  puts("str to search:");
  String S = StrIniti();
  char sts[100];
  fgets(sts, 100, stdin);
  
  StrAssign(S, sts);

  return 0;
}