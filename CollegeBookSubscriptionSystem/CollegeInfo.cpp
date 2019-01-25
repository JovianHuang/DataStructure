#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CollegeInfo.h"

/* local data type */


/* prototype for local functions */

static void getString(char * st, int len);
static void ClearBuffer(void);

/* functions definition */

School InitializeSchoolNode(void) {
  School node;
  memset(&node, 0, sizeof(School));
  return node;
}

void getName(char * collegeName) {
  printf("������ѧУ���ƣ�");
  getString(collegeName, LEN_SCHOOLNAME);
}

void getId(char * collegeId) {
  printf("������ѧУ��ʶ�룺");
  getString(collegeId, LEN_ID);
}

void getDepartment(char * collegeDepartment) {
  printf("������ѧУ�����ܲ��ţ�");
  getString(collegeDepartment, LEN_DEPARTMENT);
}

void getLocation(char * collegeLocation) {
  printf("������ѧУ���ڵأ�");
  getString(collegeLocation, LEN_LOCATION);
}

void getLevel(char * collegeLevel) {
  printf("������ѧУ��ѧ��Σ�");
  getString(collegeLevel, LEN_LEVEL);
}

void getAllInfo(School & college) {
  getName(college.Name);
  getId(college.Id);
  getDepartment(college.supervisorDepartment);
  getLocation(college.Location);
  getLevel(college.Level);
}


/* local functions */

static void getString(char * st, int len) {
  int i = 0;
  char temp;
  while (true) {
    temp = getchar();
    if (temp == '\n' || i == len) {
      break;
    } else if (temp == ' '){
      ClearBuffer();
      break;
    }
    st[i++] = temp;
  }
  st[i] = '\0';
}

static void ClearBuffer(void) {
  char temp;
  do {
    temp = getchar();
  } while (temp != '\n' && temp != EOF);
}
