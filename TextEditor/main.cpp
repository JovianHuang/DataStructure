#include "TextEdit.h"

int main(int argc, char * argv[]) {
  FILE *fp;
  Text text;
  text.rows = 0;
  text.content = NULL;
  String ** moreContent  = NULL;
  if ((fp = fopen("text.txt", "r")) == NULL) {
    puts("This file does not exsits.");
  } else {
    while (!feof(fp)) {
      char temp[1024];
      if (fgets(temp, 1024, fp) != NULL) {
        text.rows++;
        if (text.rows < 2) {
          text.content = (String **)malloc(sizeof(String *) * text.rows);
        } else {
          moreContent = (String **)realloc(text.content, sizeof(String *) * text.rows);
          if (moreContent != NULL) {
            text.content = moreContent;
          }
        }
        String T = StrIniti();
        StrAssign(T, temp);
        String S = T;
        text.content[text.rows - 1] = &S;
      }
    }
  }
  printf("%d\n", text.rows);
  for (int i = 0; i < text.rows; i++) {
    printf("%s\n", text.content[i]->str);
  }
  return 0;
}