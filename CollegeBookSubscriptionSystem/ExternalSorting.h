#ifndef EXTERNALSORTING_H
#define EXTERNALSORTING_H

static const int KEYMAXLEN = 160;

enum  keyNameType {
  schoolName = 0,
  schoolId,
  schoolDepartment,
  schoolLocation,
  schoolLevel,
  bookingNum,
  bookVolume,
  bookPublisher,
  bookISBN,
  bookName,
  bookAward,
  bookAuthor,
  bookGrade,
  bookPrice,
  bookEdition,
  bookPublishedDate,
  bookCategory
};
typedef struct nodeinfo{
  int Num;
  int Size;
  keyNameType keyName;
} NodeInfo;

typedef struct exnode{
  char key[KEYMAXLEN];
} ExNode;
typedef struct segeinfo {
  int capacity;
  int wayNum;
  ExNode *sege;
} SegeInfo;

NodeInfo InitializeNodeInfo(int infoNum, keyNameType keyName);
void SevenWayMergeSort(FILE *fi, FILE *fp, NodeInfo info);

#endif // !EXTERNALSORTING_H
