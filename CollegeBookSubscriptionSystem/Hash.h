#ifndef HASH_H
#define HASH_H

static const int MAXTABLESIZE = 100000;
static const int KEYLENGTH = 15;
typedef char ElementType[KEYLENGTH + 1]; /* Keyword type string */
typedef int Index;                     /* Hash address type */

typedef struct ListNode {
  ElementType Data;
  struct ListNode * Next;
} *PtrToLNode;
typedef PtrToLNode Position;
typedef PtrToLNode List;

typedef struct TableNode {
  int TableSize;
  List Heads;    /* An array pointing to the head of the list header */
} *HashTable;

/* operation: Create a hash table of size TableSize */
/* preconditions: Pass in a size that is not negative */
/* postconditions: Return pointer: HashTable if it's succeed */
HashTable CreateTable(unsigned TableSize);

/* operation: Calculate the index of an element in the hash table */
/* preconditions: Pass in a key and a size that is not negative */
/* postconditions: Return the index of this element */
Index Hash(ElementType key, unsigned TableSize);

/* operation: Insert an element into the hash table */
/* preconditions: Pointer H is not empty */
/* postconditions: Return boolean true if it is successfully inserted, otherwise, return false */
bool InsertIntoHash(HashTable H, ElementType Key);

/* operation: Find element: key in hash table: H */
/* preconditions: Pointer H is not empty */
/* postconditions: Return the position of this element */
Position FindInHash(HashTable H, ElementType Key);

/* operation: Free up space occupied by the hash table */
/* preconditions: Pointer H is not empty */
/* postconditions: Memory space released successfully */
void DestroyTable(HashTable H);

#endif // !HASH_H
