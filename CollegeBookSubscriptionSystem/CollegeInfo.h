#ifndef COLLEGEINFO_H
#define COLLEGEINFO_H

static const int LEN_SCHOOLNAME = 40;
static const int LEN_ID = 12;
static const int LEN_DEPARTMENT = 25;
static const int LEN_LOCATION = 25;
static const int LEN_LEVEL = 5;

typedef struct school {
  int serialNum;          
  char Name[LEN_SCHOOLNAME];  // One Chinese character occupies two bytes
  char Id[LEN_ID];
  char supervisorDepartment[LEN_DEPARTMENT];
  char Location[LEN_LOCATION];
  char Level[LEN_LEVEL];
} School;

School InitializeSchoolNode(void);
void getName(char * collegeName);
void getId(char * collegeId);
void getDepartment(char * collegeDepartment);
void getLocation(char * collegeLocation);
void getLevel(char * collegeLevel);
void getAllInfo(School & college);


#endif // !COLLEGEINFO_H


