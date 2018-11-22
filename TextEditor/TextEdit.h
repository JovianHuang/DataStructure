#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include "String.h"
#include <stdbool.h>

typedef struct {
  int rows;
  String * *content;
}Text;

void ReadFromFile(Text & text, char * filename);


bool SaveToFile(Text &text, char * filename);

bool SaveAsFile(Text &text, char * filename);

bool RowNumIsLegal(const Text text, int row);

int PrintRow(Text text, int row);

int PrintTxt(Text text);

void Swap(Text & T, int row1, int row2);

bool MoveUp(Text & T, int row, int times);

bool MoveDown(Text & T, int row, int times);

int CountNumOfWordsInRow(const Text T, int row);

int CountNumOfSpecificChar(const Text T, char ch);

int CountNumOfWordsInTotal(const Text T);

int CountNumOfRows(const Text T);

bool DeleteARow(Text & T, int row);

bool InsertARow(Text & T, String &newRow, int row);

bool SearchStr(Text T, String S, int row);

bool ReplaceStr(String & S1, String S2, char * r);


#endif // !TEXTEDIT_H

