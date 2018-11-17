#include "user.h"
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
char *ReadFile(char *s) {
  FILE *fp;
  if ((fp = fopen("text.txt", "r")) == NULL) {
    printf("无法打开");
    exit(0);
  }
  fgets(s, MAXSIZE, fp);
  fclose(fp);
  return s;
}
void WriteFile(char *s) {
  FILE *fp;
  if ((fp = fopen("text2.txt", "w")) == NULL) {
    printf("无法打开");
    exit(0);
  }
  fputs(s, fp);
  fclose(fp);
}

