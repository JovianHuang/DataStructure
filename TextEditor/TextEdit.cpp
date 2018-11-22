#include "TextEdit.h"

void ReadFromFile(Text &text, char *filename) {
  FILE *fp;
  text.rows = 0;
  text.content = NULL;
  String ** moreContent = NULL;
  if ((fp = fopen(filename, "r")) == NULL) {
    puts("This file does not exsits.");
    exit(1);
  } else {
    const int remain = 1;
    while (!feof(fp)) {
      char temp[1024];
      String *S = NULL;
      if (fgets(temp, 1024, fp) != NULL) {
        text.rows++;
        if (text.rows < 2) {
          text.content = (String **)malloc(sizeof(String *) * (text.rows + remain));
        } else {
          moreContent = (String **)realloc(text.content, sizeof(String *) * (text.rows + remain));
          if (moreContent != NULL) {
            text.content = moreContent;
          }
        }
        String *T = (String *)malloc(sizeof(String));
        T->str = NULL;
        StrAssign(*T, temp);
        S = T;
      }
      text.content[text.rows] = S;
    }
  }
  fclose(fp);
}

bool SaveToFile(Text text, char *filename) {
  FILE *fp;
  if ((fp = fopen(filename, "r+")) == NULL) {
    puts("File does not exist.");
    return false;
  } else {
    for (int i = 0; i < text.rows; i++) {
      fputs(text.content[i]->str, fp);
    }
  }
  fclose(fp);
  return true;
}

bool SaveAsFile(Text text, char *filename) {
  FILE *fp;
  if ((fp = fopen(filename, "r")) != NULL) {
    puts("A file with the same name already exists");
    return false;
  } else {
    fp = fopen(filename, "w");
    for (int i = 1; i <= text.rows; i++) {
      fputs(text.content[i]->str, fp);
    }
  }
  fclose(fp);
  return true;
}

bool RowNumIsLegal(const Text text, int row) {
  if (row > 0 && row < text.rows) {
    return true;
  }
  return false;
}

int PrintRow(Text text, int row) {
  if (RowNumIsLegal(text, row)) {
    printf("%d: %s", row, text.content[row]->str);
    return row;
  } else {
    puts("No such row, please ensure again.");
    return -1;
  }
}

int PrintTxt(Text text) {
  for (int i = 1; i <= text.rows; i++) {
    printf("%d: %s",i, text.content[i]->str);
  }
  printf("\n\n");
  return text.rows;
}

void Swap(Text &T, int row1, int row2) {
  String * temp;
  temp = T.content[row1];
  T.content[row1] = T.content[row2];
  T.content[row2] = temp;
}

bool MoveUp(Text &T, int row, int times) {
  if (RowNumIsLegal(T, row - times)) {
    puts("Exceeding the range of existing lines.");
    return false;
  }
  for (int i = 0; i < times; i++) {
    Swap(T, row - 1, row);
    row--;
  }
  return true;
}

bool MoveDown(Text &T, int row, int times) {
  if (RowNumIsLegal(T, row + times)) {
    puts("Exceeding the range of existing lines.");
    return false;
  }
  for (int i = 0; i < times; i++) {
    Swap(T, row, row + 1);
    row++;
  }
  return true;
}

int CountNumOfWordsInRow(const Text T, int row) {
  return T.content[row]->length;
}

int CountNumOfSpecificChar(const Text T, char ch) {
  int sum = 0;
  for (int i = 1; i < T.rows; i++) {
    for (int j = 0; j < T.content[i]->length; j++) {
      if (T.content[i]->str[j] == ch) {
        sum++;
      }
    }
  }
  return sum;
}

int CountNumOfWordsInTotal(const Text T) {
  int sum = 0;
  for (int i = 1; i <= T.rows; i++) {
    sum += T.content[i]->length;
  }
  return sum;
}

int CountNumOfRows(const Text T) {
  return T.rows;
}

bool DeleteARow(Text &T, int row) {
  if (row < 1 || row > T.rows) {
    puts("Exceeding the range of existing lines.");
    return false;
  }
  for (int i = row; i < T.rows; i++) {
    Swap(T, i, i + 1);
  }
  free(T.content[T.rows]);
  T.rows--;
  const int remain = 1;
  String ** newBlock= (String **)realloc(T.content, sizeof(String *) * (T.rows+ remain));
  if (newBlock == NULL) {
    puts("Insufficient allocateable memory.");
    return false;
  }
  T.content = newBlock;
  return true;
}

bool InsertARow(Text &T, String &newRow, int row) {
  if (!RowNumIsLegal(T, row)) {
    return false;
  }
  T.rows++;
  const int remain = 1;
  String ** newBlock = (String **)realloc(T.content, sizeof(String *) * (T.rows + remain));
  if (newBlock == NULL) {
    puts("Insufficient allocateable memory.");
    return false;
  }
  T.content = newBlock;
  T.content[T.rows] = &newRow;
  for (int i = T.rows; i > row; i--) {
    Swap(T, i, i - 1);
  }
  return true;
}

bool SearchStr(Text T, String S, int row) {
  if (!RowNumIsLegal(T, row)) {
    return false;
  }
  for (int i = row; i < T.rows; i++) {
    int pos = IndexKMP(*T.content[i], S, 0);
    if (pos != -1) {
      PrintRow(T, i);
      return true;
    }
  }
  puts("Search term not found.");
  return false;
}

bool ReplaceStr(String &S1, String S2, char * r) {
  int pos = IndexKMP(S1, S2, 0);
  if (pos) {
    StrDelete(S1, pos, S2.length);
    StrInsert(S1, pos, r);
    return true;
  } else {
    return false;
  }
}
