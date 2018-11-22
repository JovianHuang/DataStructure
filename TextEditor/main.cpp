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
#include "UserFunctions.h"

int main(int argc, char * argv[]) {
  Text text;
  puts("Please enter the file name you wanna read in.");
  puts("The length of the name is no greater than 20.");
  char filename[20];
  fgets(filename, 20, stdin);
  filename[strlen(filename) - 1] = '\0';
  ReadFromFile(text, filename);
  PrintTxt(text);
  bool go_on = true;
  char choice[10];
  while (go_on) {
    DisplayFirstLevelMenu();
    scanf("%s", &choice);
    ClearBuffer();
    if (!StrLenIsProper(choice, 2)) {
      puts("Invalid input! Please try again.");
      continue;
    }
    switch (choice[0]) {
      case 'A':
      {
        int row, times;
        puts("Please enter the row you wanna move.");
        scanf("%d", &row);
        puts("Please enter the times you wanna move.");
        scanf("%d", &times);
        MoveUp(text, row, times);
        PrintTxt(text);
        break;
      }
      case 'B':
      {
        int row, times;
        puts("Please enter the row you wanna move.");
        scanf("%d", &row);
        puts("Please enter the times you wanna move.");
        scanf("%d", &times);
        MoveDown(text, row, times);
        PrintTxt(text);
        break;
      }
      case 'C':
      {
        int row;
        puts("Please enter the row you wanna delete:");
        scanf("%d", &row);
        DeleteARow(text, row);
        PrintTxt(text);
        break;
      }
      case 'D':
      {
        puts("Please enter content you wanna insert:");
        String newStr = StrIniti();
        char str[100];
        fgets(str, 100, stdin);
        StrAssign(newStr, str);
        int row;
        puts("Please enter the row position you wanna insert:");
        scanf("%d", &row);
        InsertARow(text, newStr, row);
        PrintTxt(text);
        break;
      }
      case 'E':
      {
        puts("Please enter content you wanna search:");
        String item = StrIniti();
        char str[100];
        fgets(str, 100, stdin);
        str[strlen(str) - 1] = '\0';
        StrAssign(item, str);
        SearchStr(text, item, 1);
        break;
      }
      case 'F':
      {
        int row;
        puts("Please enter the row position that you wanna replace some contents:");
        scanf("%d%*c", &row);
        puts("Please enter the content you wanna be replaced:");
        String beReplaced = StrIniti();
        char str[100];
        fgets(str, 100, stdin);
        str[strlen(str) - 1] = '\0';
        StrAssign(beReplaced, str);
        puts("Please enter the new content.");
        char newcontent[100];
        fgets(newcontent, 100, stdin);
        newcontent[strlen(newcontent) - 1] = '\0';
        ReplaceStr(*text.content[row], beReplaced, newcontent);
        PrintTxt(text);
        break;
      }
      case 'G':
      {
        int row;
        puts("Please enter the row you wanna statistic:");
        scanf("%d", &row);
        int num = CountNumOfWordsInRow(text, row);
        printf("Number of words in this row:%d\n", num);
        break;
      }
      case 'H':
      {
        int num = CountNumOfWordsInTotal(text);
        printf("Number of words in total:%d\n", num);
        break;
      }
      case 'I':
      {
        int num = CountNumOfRows(text);
        printf("Number of rows in this text:%d\n", num);
        break;
      }
      case 'J':
      {
        char ch;
        puts("Please enter the character you wanna statistic");
        ch = getchar();
        int num = CountNumOfSpecificChar(text, ch);
        printf("Number of this character:%d\n", num);
        break;
      }
      case 'K':
      {
        if (SaveToFile(text, filename)) {
          puts("The text have been save to the original file");
        }
        break;
      }
      case 'L':
      {
        puts("The filename you wanna save as");
        char newfilename[20];
        fgets(newfilename, 20, stdin);
        newfilename[strlen(newfilename) - 1] = '\0';
        if (SaveToFile(text, newfilename)) {
          printf("The text have been save as %s", newfilename);
        }
        break;
      }
      case 'M':
      {
        exit(1);
      }
      default:
      {
        puts("Invalid input! Please try again.");
        break;
      }
    }
  }
  return 0;
}
