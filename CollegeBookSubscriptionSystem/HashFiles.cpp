#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashFiles.h"
#include "CollegeInfo.h"
#include "BookInfo.h"
#include "SubscriptionInfo.h"

/* local data type */



/* prototype for local functions */


/* functions definition */

static RecordNode InitializeRecordNode(void) {
  RecordNode record;
  record.serialNum = 0;
  record.content[0] = '\0';
  return record;
}

Bucket InitializeBucket(FILE * fo_bucket) {
  Bucket *bucket = (Bucket *)malloc(sizeof(Bucket));
  bucket->recordNum = 0;
  for (int i = 0; i < RECORDNUM; i++) {
    bucket->records[i] = InitializeRecordNode();
  }
  bucket->next = -1;
  for (int i = 0; i < BUCKETNUM; i++) {
    bucket->index = i;
    fwrite(&bucket, sizeof(bucket), 1, fo_bucket);
  }
  return *bucket;
}

int * InitializeHashIndex(FILE * fo_index) {
  int *Index = (int *)malloc(sizeof(int) * (BUCKETNUM + 1));
  for (int i = 0; i < BUCKETNUM; i++) {
    Index[i] = i;
  }
  Index[BUCKETNUM] = -1;
  fwrite(&Index, sizeof(Index), 1, fo_index);
  return Index;
}

void CreateHashFiles(FilePointer fp, RecordNodeType recordnode) {
  int *HashIndex = InitializeHashIndex(fp.index);
  Bucket bucket = InitializeBucket(fp.bucket);
  school node;
  RecordNode record = InitializeRecordNode();
  while (true) {
    fread(&node, sizeof(school), 1, fp.source);
    if (feof(fp.source)) {
      break;
    }
    strcpy(record.content, node.Id);
    record.serialNum = node.serialNum;
    int hashkey = Hash(record);
    fseek(fp.bucket, sizeof(Bucket) * HashIndex[hashkey], 0);
    fread(&bucket, sizeof(Bucket), 1, fp.bucket);
    fseek(fp.bucket, -(int)sizeof(bucket), 1);  // 倒回一个桶的位置
    Insert(bucket, record, HashIndex, fp.bucket);
    fwrite(&HashIndex, sizeof(HashIndex), 1, fp.index);
 }
}

void Insert(Bucket bucket, RecordNode record, int *HashIndex, FILE *fp_bucket) {
  if (bucket.recordNum < RECORDNUM) {
    strcpy(bucket.records[bucket.recordNum].content, record.content);
    bucket.records[bucket.recordNum].serialNum = record.serialNum;
    bucket.recordNum++;
    fwrite(&bucket, sizeof(bucket), 1, fp_bucket);
  } else {
    bucket.recordNum = 0; //建新桶
    for (int i = 0; i < RECORDNUM; i++) {
      bucket.records[i] = InitializeRecordNode();
    }
    strcpy(bucket.records[bucket.recordNum].content, record.content);
    bucket.records[bucket.recordNum].serialNum = record.serialNum;
    bucket.recordNum++;
    int pos_index = bucket.index; // HashIndex 中的位置
    fseek(fp_bucket, -(int)sizeof(bucket), SEEK_END); 
    fread(&bucket.index, sizeof(bucket.index), 1, fp_bucket);
    bucket.index++; // 获取index
    if (bucket.index == 11) {
      bucket.index++;
    }
    bucket.next = HashIndex[pos_index];
    HashIndex[pos_index] = bucket.index;
    fseek(fp_bucket, 0, SEEK_END);
    fwrite(&bucket, sizeof(bucket), 1, fp_bucket);
  }
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

