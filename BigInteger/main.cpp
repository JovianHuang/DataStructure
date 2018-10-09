#include "BigInteger.h"

int main(void) {
  DisplayWelcome();
  puts("Please choose what to do: ");
  puts("a) Read two Big Integer from keyboard");
  puts("b) Read two Big Integer from files");
  int c;
  c = getchar();
  ClearBuf();
  Node *head1;
  Node *head2;
  switch (c) {
    case 'a': 
    {
      int size1 = 0;
      int size2 = 0;
      puts("Please enter the first BigInterger:");
      char *str1 = ReadFromKeyboard(size1);
      head1 = StrToNum(size1, str1);
      puts("Please enter the second BigInterger:");
      char *str2 = ReadFromKeyboard(size2);
      head2 = StrToNum(size2, str2);
      break;
    }
    case 'b':
    {
      int size1 = 0;
      int size2 = 0;
      puts("Please enter the first BigInterger:");
      FILE *fp1 = fopen("source1.txt", "r");
      char *str1 = ReadFromFile(fp1, size1);
      head1 = StrToNum(size1, str1);
      fclose(fp1);
      puts("Please enter the second BigInterger:");
      FILE *fp2 = fopen("source2.txt", "r");
      char *str2 = ReadFromFile(fp2, size1);
      head2 = StrToNum(size2, str2);
      fclose(fp2);
      break;
    }
    default:
      puts("EROOR INPUT!");
      return 0;
  }

  puts("Please choose what to do: ");
  puts("a) Addition");
  puts("b) Subtraction");
  puts("c) Multiplcation");
  c = getchar();
  ClearBuf();
  Node *result;
  switch (c) {
    case 'a':
    {
      result = CopyList(head1);
      result = Add(result, head2);
      break;
    }
    case 'b':
    {
      result = CopyList(head1);
      result = Subtract(result, head2);
      break;
    }
    case 'c':
    {
      result = Multiply(head1, head2);
    }
    default:
      puts("EROOR INPUT!");
      return 0;
  }

  puts("Please choose what to do: ");
  puts("a) Print result into screen");
  puts("b) Output result to file");
  c = getchar();
  ClearBuf();
  switch (c) {
    case 'a':
    {
      PrintList(result);
      break;
    }
    case 'b':
    {
      OutputToFile(result);
      break;
    }
    default:
      puts("EROOR INPUT!");
      return 0;
  }
  return 0;
}