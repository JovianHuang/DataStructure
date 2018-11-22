#include "UserFunctions.h"

void DisplayWelcome(void) {
  puts("\nWelcome to use Text Editor beta 2.\n");
}

void DisplayFirstLevelMenu(void) {
  puts("\nPlease choose what to do:");
  puts("A) Move row up");
  puts("B) Move row down");
  puts("C) Delete row");
  puts("D) Insert row");
  puts("E) Search string in the text");
  puts("F) Replace in one row");
  puts("G) Count the number of words in a row");
  puts("H) Count the number of words in total");
  puts("I) Count the number of rows in the text");
  puts("J) Count the number of specific character");
  puts("K) Save");
  puts("L) Save As");
  puts("M) Exit this program");
}

bool YesOrNo(void) {
  char temp;
  while (1) {
    puts("'Y' for 'Yes' and 'N' for 'No'");
    scanf("%c%*c", &temp);
    if (temp != 'Y' && temp != 'N') {
      puts("Invalid input! Please try again.");
    } else if (temp == 'N') {
      return false;
    } else {
      return true;
    }
  }
}

