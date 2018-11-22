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
  puts("The text is as follows.");
  PrintTxt(text);
  bool go_on = true;
  char choice;
  while (go_on) {
    DisplayFirstLevelMenu();
    scanf("%c", &choice);
    ClearBuffer();
    switch (choice) {
      case 'A':
      {
        int row, times;
        puts("Please enter the row you wanna move.");
        scanf("%d", &row);
        puts("Please enter the times you wanna move.");
        scanf("%d", &times);
        MoveUp(text, row, times);
        break;
      }
      case 'B':
      {
        break;
      }
      case 'C':
      {
        int row;
        puts("Please enter the row you wanna delete:");
        scanf("%d", &row);
        DeleteARow(text, row);
        puts("The text now is as follows");
        PrintTxt(text);
        break;
      }
      case 'D':
      {
        break;
      }
      case 'E':
      {

        break;
      }
      case 'F':
      {
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
        ClearBuffer();
        break;
      }
      case 'K':
      {
        puts("The text have been save to the original file");
        SaveToFile(text, filename);
        break;
      }
      case 'L':
      {
        puts("The filename you wanna save as");
        char newfilename[20];
        SaveAsFile(text, newfilename);
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
