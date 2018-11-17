#include "UserFunctions.h"

void DisplayWelcome(void) {
  puts("\nWelcome to use Text Editor beta 2.\n");
}

void DisplayFirstLevelMenu(void) {
  puts("\nPlease choose what to do:");
  puts("A) Add Student Informations\t\t\tD) Delete Student Informations");
  puts("S) Search and Output Student Informations\tM) Modify Student Informations");
  puts("P) Print Out All Existing Data\t\t\tE) Exit This System");
}

void DisplayTheSearchMenu(void) {
  puts("\nPlease select the conditions for information search:");
  puts("a) Output all data in descending order of average");
  puts("b) Output all data in descending order of grade");
  puts("c) Output all data in lexicographic order by name");
  puts("d) Output all data in ascending order of student ID");
  puts("e) Output all data in ascending order of age and gender");
  puts("f) Search and output information based on student name");
  puts("g) Search the highest score of a subject and output");
  puts("h) Search students in a grade interval of a subject and output");
  puts("i) Count the proportion of students in each score segment");
  puts("B) Back to previous");
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

