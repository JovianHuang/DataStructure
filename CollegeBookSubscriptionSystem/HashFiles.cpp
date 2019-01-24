#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashFiles.h"

/* local data type */

/* prototype for local functions */



/* functions definition */

static RecordNode InitializeRecordNode(void) {
  RecordNode record;
  record.serialNum = 0;
  record.content[0] = '\0';
  return record;
}

Bucket InitializeBucket(void) {
  Bucket bucket;
  bucket.recordNum = 0;
  for (int i = 0; i < RECORDNUM; i++) {
    bucket.records[i] = InitializeRecordNode();
  }
  bucket.next = -1;
  return bucket;
}

void CreateHashFiles(char * filename) {
  FILE *fo = fopen(filename, "");
}

int Hash(RecordNode record) {
  int i = 0;
  int temp = 0;
  while (record.content[i] != '\0') {
    temp += record.content[i++];
  }
  return temp % BUCKETNUM;
}

/* local functions */