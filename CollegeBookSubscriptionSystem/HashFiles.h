#ifndef HASHFILES_H
#define HASHFILES_H

static const int RECORDNUM = 7;
static const int BUCKETNUM = 11;
static const int CONTENTMAXLEN = 15;

enum RecordNodeType{
  Id,
  Num
};

typedef struct recordnode {
  int serialNum;
  char content[CONTENTMAXLEN];
} RecordNode;

typedef struct bucket {
  RecordNode records[RECORDNUM];
  int recordNum;
  int next;
} Bucket;

typedef struct filepointer {
  FILE *source;
  FILE *index;
  FILE *bucket;
} FilePointer;

Bucket InitializeBucket(FILE * fo_bucket);
int * InitializeHashIndex(FILE * fo_index);
int Hash(RecordNode record);
void CreateHashFiles(FilePointer fp, RecordNodeType recordnode);
void Insert(Bucket bucket, RecordNode record, int *HashIndex, FILE *fp_bucket);

#endif // !HASHFILES_H
