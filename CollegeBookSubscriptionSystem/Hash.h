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

HashTable CreateTable(int TableSize);
Index Hash(ElementType key, int TableSize);
bool InsertIntoHash(HashTable H, ElementType Key);
Position Find(HashTable H, ElementType Key);
void DestroyTable(HashTable H);

#endif // !HASH_H
