#ifndef HASHFILES_H
#define HASHFILES_H

static const int RECORDNUM = 7;
static const int BUCKETNUM = 11;
static const int CONTENTMAXLEN = 15;

typedef struct recordnode {
  int serialNum;
  char content[CONTENTMAXLEN];
} RecordNode;

typedef struct bucket {
  RecordNode records[RECORDNUM];
  int recordNum;
  int next;
} Bucket;



#endif // !HASHFILES_H
