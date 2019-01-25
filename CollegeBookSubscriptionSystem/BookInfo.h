#ifndef BOOKINFO_H
#define BOOKINFO_H

static const int LEN_BOOKINGNUM = 11;
static const int LEN_VOLUME = 10;
static const int LEN_PUBLISHER = 35;
static const int LEN_ISBN = 15;
static const int LEN_NAME = 135;
static const int LEN_AWARD = 160;
static const int LEN_AUTHOR = 135;
static const int LEN_GRADE = 31;
static const int LEN_PRICE = 10;
static const int LEN_EDITION = 10;
static const int LEN_PULISHEDDATE = 12;
static const int LEN_CATEGORY = 10;
typedef struct book {
  int serialNum;
  char bookingNum[LEN_BOOKINGNUM];   // ±¾¼¾Õ÷¶©ºÅ
  char Volume[LEN_VOLUME];  // ·Ö²á
  char Publisher[LEN_PUBLISHER + 1];
  char ISBN[LEN_ISBN];
  char Name[LEN_NAME];
  char Award[LEN_AWARD];
  char Author[LEN_AUTHOR];
  char Grade[LEN_GRADE];
  char Price[LEN_PRICE];
  char Edition[LEN_EDITION];
  char publishedDate[LEN_PULISHEDDATE];
  char Category[LEN_CATEGORY];
} BOOK;

BOOK InitializeBookNode(void);


#endif // !BOOKINFO_H


