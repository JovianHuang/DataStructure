#include "BigInteger.h"

int main(void) {
  /*int size1 = 0;
  int size2 = 0;
  puts("Please enter the first BigInterger:");
  char *str1 = ObtainedAsStr(size1);
  Node * head1 = StrToNum(size1, str1);
  puts("Please enter the second BigInterger:");
  char *str2 = ObtainedAsStr(size2);
  Node * head2 = StrToNum(size2, str2);*/


  //// test module1
  //FILE *fp;
  //fp = fopen("source.txt","r");
  //char *source = (char *)malloc(sizeof(char) * MAXLEN);
  //printf("fp: %#p\n", fp);
  //int c;
  //int i = 0;
  //while ((c = fgetc(fp)) != '\n' && c != EOF) {
  //  printf("fp: %#p\n", fp);
  //  source[i++] = c;
  //  source[i] = '\0';
  //  printf("source: %s\n", source);
  //}
  //source[i] = '\0';
  //printf("source: %s\n", source);
  //printf("fp: %#p\n", fp);
  //// test module

  // test module2
  int size = 0;
  FILE *fp;
  fp = fopen("source.txt", "r");
  char *str = ReadFromFile(fp, size);
  Node * head1 = StrToNum(size, str);
  fclose(fp);
  PrintList(head1);
  // test module2

  return 0;
}