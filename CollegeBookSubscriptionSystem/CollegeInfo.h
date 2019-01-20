#ifndef COLLEGEINFO_H
#define COLLEGEINFO_H

static const int LEN_SCHOOLNAME = 40;
static const int LEN_ID = 12;
static const int LEN_DEPARTMENT = 40;
static const int LEN_LOCATION = 10;
static const int LEN_LEVEL = 10;

typedef struct school {
  int serialNum;          
  char Name[LEN_SCHOOLNAME + 1];  // One Chinese character occupies two bytes
  char Id[LEN_ID];
  char supervisorDepartment[LEN_DEPARTMENT + 2];
  char Location[LEN_LOCATION + 1];
  char Level[LEN_LEVEL + 1];
} School;

void getName(char * collegeName);
void getId(char * collegeId);
void getDepartment(char * collegeDepartment);
void getLocation(char * collegeLocation);
void getLevel(char * collegeLevel);
void getAllInfo(School & college);


#endif // !COLLEGEINFO_H


