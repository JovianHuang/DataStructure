#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "Hash.h"

/* local data type */

/* prototype for local functions */

static int NextPrime(int N);

/* functions definition */

HashTable CreateTable(unsigned TableSize) {
  HashTable H;
  int i;
  H = (HashTable)malloc(sizeof(struct TableNode));
  if (H != NULL) {
    H->TableSize = NextPrime(TableSize);
    H->Heads = (List)malloc(H->TableSize * sizeof(struct ListNode));
    if (H->Heads != NULL) {
      for (i = 0; i < H->TableSize; i++) {
        H->Heads[i].Data[0] = '\0';
        H->Heads[i].Next = NULL;
      }
    } else {
      puts("�ڴ�������00��");
    }
  } else {
    puts("�ڴ�������01��");
  }
  return H;
}

Index Hash(ElementType key, unsigned TableSize) {
  Index pos;
  int tmp = 0;
  for (int i = 0; i < sizeof(key); i++) {
    tmp += key[i];
  }
  pos = tmp % TableSize;
  return pos;
}

Pos FindInHash(HashTable H, ElementType Key) {
  Pos P;
  Index Pos;
  Pos = Hash(Key, H->TableSize); /* Initial hash position */
  P = H->Heads[Pos].Next; /* Starting from the first node of the list */
  /* When it is not at the end of the table and Key is not found */
  while (P && strcmp(P->Data, Key)) {
    P = P->Next;
  }
  return P; /* At this point P or point to the found node, or NULL */
}

bool InsertIntoHash(HashTable H, ElementType Key) {
  Pos P, NewCell;
  Index pos;
  P = FindInHash(H, Key);
  if (!P) { /* Keyword not found, can be inserted */
    NewCell = (Pos)malloc(sizeof(struct ListNode));
    if (NewCell != NULL) {
      strcpy(NewCell->Data, Key);
      pos = Hash(Key, H->TableSize); /* Initial hash position */
      /* Insert NewCell as the first node of the linked list H->Heads[Pos] */
      NewCell->Next = H->Heads[pos].Next;
      H->Heads[pos].Next = NewCell;
    } else {
      return false;
    }
    return true;
  } else { /* The keyword already exists */
    printf("��ֵ�Ѵ���");
    return false;
  }
}

void DestroyTable(HashTable H) {
  int i;
  Pos P, Tmp;
  /* Release the nodes of each linked list */
  for (i = 0; i < H->TableSize; i++) {
    P = H->Heads[i].Next;
    while (P) {
      Tmp = P->Next;
      free(P);
      P = Tmp;
    }
  }
  free(H->Heads); /* Release head node array */
  free(H);        /* Release the hash table node */
}

/* local functions */

static int NextPrime(int N) {
  /* Returns the smallest prime num greater than N and not exceeding MAXTABLESIZE */
  int i, p = (N % 2) ? N + 2 : N + 1; /* Start with the next odd number greater than N */
  while (p <= MAXTABLESIZE) {
    for (i = (int)sqrt(p); i > 2; i--) {
      if (!(p%i)) {/* p is not a prime number */
        break;
      }
    }
    if (i == 2) {/* for ends normally, indicating that p is a prime number */
      break;
    } else {/* Otherwise try the next odd number */
      p += 2;
    }
  }
  return p;
}
