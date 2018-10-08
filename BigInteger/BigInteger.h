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
} Node;
// predefine


// User Functions
Status YesOrNo(void);
// User Functions


// Input Functions
char * ObtainedAsStr(int &size);
// Input Functions


// Output Functions
void PrintList(Node * head);
// Output Functions


// Linked List Operation
Node * NewHead(void);

void AddNode(Node *current, int num);

Node * StrToNum(int size, char * str);

Node * CopyList(Node *source);
// Linked List Operation


// Process Functions
void ClearBuf(void);

void ReadStr(char * source);

Node * Operate(Node *head1, Node *head2, Node *(*operation)(Node *, Node*));

void CarryOrNot(numType &num, numType &carry);

Node * Add(Node *result, Node *head2);

bool Compare(Node *a, Node *b);

Node * Subtract(Node *result, Node *head2);

Node * Multiply(Node *result, Node *head2);
// Process Functions

#endif // !BIGINTEGER_H
