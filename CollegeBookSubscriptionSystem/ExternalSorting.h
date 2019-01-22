#ifndef EXTERNALSORTING_H
#define EXTERNALSORTING_H

static const int WAYNUM = 7;
typedef struct {
  int key;
} ExNode;

void SevenWayMergeSort(FILE *fi, FILE *fp, int size);

#endif // !EXTERNALSORTING_H
