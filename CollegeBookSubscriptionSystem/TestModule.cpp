#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Sort.h"
#include "CollegeInfo.h"

int main(void) {
  school school;
  getAllInfo(school);
  printf("%s %s %s %s %s", school.Name, school.Id, school.supervisorDepartment, school.Location, school.Level);
  return 0;
}