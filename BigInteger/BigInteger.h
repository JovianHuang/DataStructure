#ifndef BIGINTEGER_H
#define BIGINTEGER_H

// Standard Header Files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// Standard Header Files


// predefine
#define MAXLEN 1000
typedef enum status {
  OVERFLOW = -2,
  ERROR = -1,
  DONE = 0,
  RUNNING = 1
} Status;
typedef short numType;
typedef struct bigintnode {
  struct bigintnode * prev;
  numType num;
  int length;
  struct bigintnode * next;
} BigIntNode;
// predefine


// User Functions
Status YesOrNo(void);
// User Functions


// Input Functions
char * ObtainedAsStr(int &size);
// Input Functions


// Output Functions
void PrintList(BigIntNode * head);
// Output Functions


// Linked List Operation
BigIntNode * NewHead(void);

void AddNode(BigIntNode *current, int num);

BigIntNode * StrToNum(int size, char * str);
// Linked List Operation


// Process Functions
void ClearBuf(void);

void ReadStr(char * source);

BigIntNode * Addition(BigIntNode *head1, BigIntNode *head2);
// Process Functions

#endif // !BIGINTEGER_H
