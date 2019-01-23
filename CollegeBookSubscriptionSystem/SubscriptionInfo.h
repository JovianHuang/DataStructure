#ifndef SUBSCRIPTIONINFO_H
#define SUBSCRIPTIONINFO_H

static const int SCHOOLNAME = 40;
static const int ID = 12;
static const int BOOKINGNUM = 11;
static const int BOOKNAME = 135;
struct subscription {
  int serialNum;
  char schoolName[SCHOOLNAME];
  char Id[ID];
  char bookingNum[BOOKINGNUM];
  char bookName[BOOKNAME];
  int subscriNum;
};

#endif // !SUBSCRIPTIONINFO_H
