#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Sort.h"
#include "CollegeInfo.h"

int main(int argc, char * argv[]) {
  School college[2700];
  FILE *fp = fopen("university.txt", "r");
  int i = 0;
  while (!feof(fp) && i < 2700) {
    fscanf(fp, "%d%s%s%s%s%s", &college[i].serialNum, college[i].Name, college[i].Id,
      college[i].supervisorDepartment, college[i].Location, college[i].Level);
    i++;
  }
  fclose(fp);
  int j = i - 1;
  i = 0;
  FILE *fp1 = fopen("university.bat", "rb");
  while (i < j) {
    fwrite(&college[i++], sizeof(school), 1, fp1);
  }
  for (i = 0; i < j; i++) {
    printf("%d %s\n", college[i].serialNum, college[i].Name);
  }
  puts("done");
  fclose(fp1);
  return 0;
}