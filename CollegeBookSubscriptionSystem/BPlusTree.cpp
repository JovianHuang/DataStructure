#include "BPlusTree.h"

/* local data type */
static KeyType Unavailable = INT_MIN;

/* prototype for locao functions */

/* functions definition */

/* ��ʼ�� */
extern BPlusTree Initialize() {

  BPlusTree T;
  /* ����� */
  T = MallocNewNode();

  return T;
}

/* ���� */
BPlusTree Insert(BPlusTree T, KeyType Key) {
  return RecursiveInsert(T, Key, 0, NULL);
}

/* ɾ�� */
BPlusTree Remove(BPlusTree T, KeyType Key) {
  return RecursiveRemove(T, Key, 0, NULL);
}

/* ���� */
//BPlusTree Destroy(BPlusTree T) {
//  int i, j;
//  if (T != NULL) {
//    i = 0;
//    while (i < T->KeyNum + 1) {
//      Destroy(T->Children[i]); i++;
//    }
//
//    printf("Destroy:(");
//    j = 0;
//    while (j < T->KeyNum)/*  T->Key[i] != Unavailable*/
//      printf("%d:", T->Key[j++]);
//    printf(") ");
//    free(T);
//    T = NULL;
//  }
//  return T;
//}

/* ���� */
void Travel(BPlusTree T) {
  RecursiveTravel(T, 0);
  printf("\n");
}

/* ������Ҷ�ڵ������ */
void TravelData(BPlusTree T) {
  Position Tmp;
  int i;
  if (T == NULL)
    return;
  printf("All Data:");
  Tmp = T;
  while (Tmp->Children[0] != NULL)
    Tmp = Tmp->Children[0];
  /* ��һƬ��Ҷ */
  while (Tmp != NULL) {
    i = 0;
    while (i < Tmp->ContentNum)
      printf(" %d", Tmp->Key[i++]);
    Tmp = Tmp->Next;
  }
}

/* local functions */

/* ���ɽڵ㲢��ʼ�� */
static BPlusTree MallocNewNode() {
  BPlusTree NewNode;
  int i;
  NewNode = (BPlusTree)malloc(sizeof(struct BPlusNode));
  if (NewNode == NULL)
    exit(EXIT_FAILURE);
  i = 0;
  while (i < M + 1) {
    NewNode->Key[i] = Unavailable;
    NewNode->Children[i] = NULL;
    i++;
  }
  NewNode->Next = NULL;
  NewNode->ContentNum = 0;

  return NewNode;
}

static Position FindMostLeft(Position P) {
  Position Tmp;
  Tmp = P;
  while (Tmp != NULL && Tmp->Children[0] != NULL) {
    Tmp = Tmp->Children[0];
  }
  return Tmp;
}

static Position FindMostRight(Position P) {
  Position Tmp;
  Tmp = P;
  while (Tmp != NULL && Tmp->Children[Tmp->ContentNum - 1] != NULL) {
    Tmp = Tmp->Children[Tmp->ContentNum - 1];
  }
  return Tmp;
}

/* Ѱ��һ���ֵܽڵ㣬��洢�Ĺؼ���δ�������򷵻�NULL */
static Position FindSibling(Position Parent, int i) {
  Position Sibling;
  int Limit;
  Limit = M;
  Sibling = NULL;
  if (i == 0) {
    if (Parent->Children[1]->ContentNum < Limit)
      Sibling = Parent->Children[1];
  } else if (Parent->Children[i - 1]->ContentNum < Limit)
    Sibling = Parent->Children[i - 1];
  else if (i + 1 < Parent->ContentNum && Parent->Children[i + 1]->ContentNum < Limit) {
    Sibling = Parent->Children[i + 1];
  }
  return Sibling;
}

/* �����ֵܽڵ㣬��ؼ���������M/2 ;û�з���NULL*/
static Position FindSiblingKeyNum_M_2(Position Parent, int i, int *j) {
  int Limit;
  Position Sibling;
  Sibling = NULL;
  Limit = LIMIT_M_2;
  if (i == 0) {
    if (Parent->Children[1]->ContentNum > Limit) {
      Sibling = Parent->Children[1];
      *j = 1;
    }
  } else {
    if (Parent->Children[i - 1]->ContentNum > Limit) {
      Sibling = Parent->Children[i - 1];
      *j = i - 1;
    } else if (i + 1 < Parent->ContentNum && Parent->Children[i + 1]->ContentNum > Limit) {
      Sibling = Parent->Children[i + 1];
      *j = i + 1;
    }
  }
  return Sibling;
}

/* ��Ҫ��X����Key��ʱ��i��X��Parent��λ�ã�j��KeyҪ�����λ��
   ��Ҫ��Parent����X�ڵ��ʱ��i��Ҫ�����λ�ã�Key��j��ֵû����
 */
static Position InsertElement(int isKey, Position Parent, Position X, KeyType Key, int i, int j) {
  int k;
  if (isKey) {
    /* ����key */
    k = X->ContentNum - 1;
    while (k >= j) {
      X->Key[k + 1] = X->Key[k]; k--;
    }
    X->Key[j] = Key;
    if (Parent != NULL)
      Parent->Key[i] = X->Key[0];
    X->ContentNum++;
  } else {
    /* ����ڵ� */
    /* ����Ҷ�ڵ�������� */
    if (X->Children[0] == NULL) {
      if (i > 0)
        Parent->Children[i - 1]->Next = X;
      X->Next = Parent->Children[i];
    }
    k = Parent->ContentNum - 1;
    while (k >= i) {
      Parent->Children[k + 1] = Parent->Children[k];
      Parent->Key[k + 1] = Parent->Key[k];
      k--;
    }
    Parent->Key[i] = X->Key[0];
    Parent->Children[i] = X;

    Parent->ContentNum++;

  }
  return X;
}

static Position RemoveElement(int isKey, Position Parent, Position X, int i, int j) {

  int k, Limit;

  if (isKey) {
    Limit = X->ContentNum;
    /* ɾ��key */
    k = j + 1;
    while (k < Limit) {
      X->Key[k - 1] = X->Key[k]; k++;
    }

    X->Key[X->ContentNum - 1] = Unavailable;

    Parent->Key[i] = X->Key[0];

    X->ContentNum--;
  } else {
    /* ɾ���ڵ� */

    /* �޸���Ҷ�ڵ������ */
    if (X->Children[0] == NULL && i > 0) {
      Parent->Children[i - 1]->Next = Parent->Children[i + 1];
    }
    Limit = Parent->ContentNum;
    k = i + 1;
    while (k < Limit) {
      Parent->Children[k - 1] = Parent->Children[k];
      Parent->Key[k - 1] = Parent->Key[k];
      k++;
    }

    Parent->Children[Parent->ContentNum - 1] = NULL;
    Parent->Key[Parent->ContentNum - 1] = Unavailable;

    Parent->ContentNum--;

  }
  return X;
}

/* Src��Dst���������ڵĽڵ㣬i��Src��Parent�е�λ�ã�
 ��Src��Ԫ���ƶ���Dst�� ,n���ƶ�Ԫ�صĸ���*/
static Position MoveElement(Position Src, Position Dst, Position Parent, int i, int n) {
  KeyType TmpKey;
  Position Child;
  int j, SrcInFront;

  SrcInFront = 0;

  if (Src->Key[0] < Dst->Key[0])
    SrcInFront = 1;

  j = 0;
  /* �ڵ�Src��Dstǰ�� */
  if (SrcInFront) {
    if (Src->Children[0] != NULL) {
      while (j < n) {
        Child = Src->Children[Src->ContentNum - 1];
        RemoveElement(0, Src, Child, Src->ContentNum - 1, Unavailable);
        InsertElement(0, Dst, Child, Unavailable, 0, Unavailable);
        j++;
      }
    } else {
      while (j < n) {
        TmpKey = Src->Key[Src->ContentNum - 1];
        RemoveElement(1, Parent, Src, i, Src->ContentNum - 1);
        InsertElement(1, Parent, Dst, TmpKey, i + 1, 0);
        j++;
      }

    }

    Parent->Key[i + 1] = Dst->Key[0];
    /* ����Ҷ�ڵ��������� */
    if (Src->ContentNum > 0)
      FindMostRight(Src)->Next = FindMostLeft(Dst);

  } else {
    if (Src->Children[0] != NULL) {
      while (j < n) {
        Child = Src->Children[0];
        RemoveElement(0, Src, Child, 0, Unavailable);
        InsertElement(0, Dst, Child, Unavailable, Dst->ContentNum, Unavailable);
        j++;
      }

    } else {
      while (j < n) {
        TmpKey = Src->Key[0];
        RemoveElement(1, Parent, Src, i, 0);
        InsertElement(1, Parent, Dst, TmpKey, i - 1, Dst->ContentNum);
        j++;
      }

    }

    Parent->Key[i] = Src->Key[0];
    if (Src->ContentNum > 0)
      FindMostRight(Dst)->Next = FindMostLeft(Src);

  }

  return Parent;
}

static BPlusTree SplitNode(Position Parent, Position X, int i) {
  int j, k, Limit;
  Position NewNode;

  NewNode = MallocNewNode();

  k = 0;
  j = X->ContentNum / 2;
  Limit = X->ContentNum;
  while (j < Limit) {
    if (X->Children[0] != NULL) {
      NewNode->Children[k] = X->Children[j];
      X->Children[j] = NULL;
    }
    NewNode->Key[k] = X->Key[j];
    X->Key[j] = Unavailable;
    NewNode->ContentNum++; X->ContentNum--;
    j++; k++;
  }

  if (Parent != NULL)
    InsertElement(0, Parent, NewNode, Unavailable, i + 1, Unavailable);
  else {
    /* �����X�Ǹ�����ô�����µĸ������� */
    Parent = MallocNewNode();
    InsertElement(0, Parent, X, Unavailable, 0, Unavailable);
    InsertElement(0, Parent, NewNode, Unavailable, 1, Unavailable);

    return Parent;
  }

  return X;
}

/* �ϲ��ڵ�,X����M/2�ؼ��֣�S�д��ڻ����M/2���ؼ���*/
static Position MergeNode(Position Parent, Position X, Position S, int i) {
  int Limit;

  /* S�Ĺؼ�����Ŀ����M/2 */
  if (S->ContentNum > LIMIT_M_2) {
    /* ��S���ƶ�һ��Ԫ�ص�X�� */
    MoveElement(S, X, Parent, i, 1);
  } else {
    /* ��Xȫ��Ԫ���ƶ���S�У�����Xɾ�� */
    Limit = X->ContentNum;
    MoveElement(X, S, Parent, i, Limit);
    RemoveElement(0, Parent, X, i, Unavailable);

    free(X);
    X = NULL;
  }

  return Parent;
}

static BPlusTree RecursiveInsert(BPlusTree T, KeyType Key, int i, BPlusTree Parent) {
  int j, Limit;
  Position Sibling;

  /* ���ҷ�֧ */
  j = 0;
  while (j < T->ContentNum && Key >= T->Key[j]) {
    /* �ظ�ֵ������ */
    if (Key == T->Key[j])
      return T;
    j++;
  }
  if (j != 0 && T->Children[0] != NULL) j--;

  /* ��Ҷ */
  if (T->Children[0] == NULL)
    T = InsertElement(1, Parent, T, Key, i, j);
  /* �ڲ��ڵ� */
  else
    T->Children[j] = RecursiveInsert(T->Children[j], Key, j, T);

  /* �����ڵ� */

  Limit = M;

  if (T->ContentNum > Limit) {
    /* �� */
    if (Parent == NULL) {
      /* ���ѽڵ� */
      T = SplitNode(Parent, T, i);
    } else {
      Sibling = FindSibling(Parent, i);
      if (Sibling != NULL) {
        /* ��T��һ��Ԫ�أ�Key����Child���ƶ���Sibing�� */
        MoveElement(T, Sibling, Parent, i, 1);
      } else {
        /* ���ѽڵ� */
        T = SplitNode(Parent, T, i);
      }
    }

  }

  if (Parent != NULL)
    Parent->Key[i] = T->Key[0];


  return T;
}


static BPlusTree RecursiveRemove(BPlusTree T, KeyType Key, int i, BPlusTree Parent) {

  int j, NeedAdjust;
  Position Sibling, Tmp;

  Sibling = NULL;

  /* ���ҷ�֧ */
  j = 0;
  while (j < T->ContentNum && Key >= T->Key[j]) {
    if (Key == T->Key[j])
      break;
    j++;
  }

  if (T->Children[0] == NULL) {
    /* û�ҵ� */
    if (Key != T->Key[j] || j == T->ContentNum)
      return T;
  } else
    if (j == T->ContentNum || Key < T->Key[j]) j--;



  /* ��Ҷ */
  if (T->Children[0] == NULL) {
    T = RemoveElement(1, Parent, T, i, j);
  } else {
    T->Children[j] = RecursiveRemove(T->Children[j], Key, j, T);
  }

  NeedAdjust = 0;
  /* ���ĸ�������һƬ��Ҷ���������������2��M֮�� */
  if (Parent == NULL && T->Children[0] != NULL && T->ContentNum < 2)
    NeedAdjust = 1;
  /* �����⣬���з���Ҷ�ڵ�Ķ�������[M/2]��M֮�䡣(����[]��ʾ����ȡ��) */
  else if (Parent != NULL && T->Children[0] != NULL && T->ContentNum < LIMIT_M_2)
    NeedAdjust = 1;
  /* ���Ǹ�����Ҷ�йؼ��ֵĸ���Ҳ��[M/2]��M֮�� */
  else if (Parent != NULL && T->Children[0] == NULL && T->ContentNum < LIMIT_M_2)
    NeedAdjust = 1;

  /* �����ڵ� */
  if (NeedAdjust) {
    /* �� */
    if (Parent == NULL) {
      if (T->Children[0] != NULL && T->ContentNum < 2) {
        Tmp = T;
        T = T->Children[0];
        free(Tmp);
        return T;
      }

    } else {
      /* �����ֵܽڵ㣬��ؼ�����Ŀ����M/2 */
      Sibling = FindSiblingKeyNum_M_2(Parent, i, &j);
      if (Sibling != NULL) {
        MoveElement(Sibling, T, Parent, j, 1);
      } else {
        if (i == 0)
          Sibling = Parent->Children[1];
        else
          Sibling = Parent->Children[i - 1];

        Parent = MergeNode(Parent, T, Sibling, i);
        T = Parent->Children[i];
      }
    }

  }


  return T;
}

static void RecursiveTravel(BPlusTree T, int Level) {
  int i;
  if (T != NULL) {
    printf("  ");
    printf("[Level:%d]-->", Level);
    printf("(");
    i = 0;
    while (i < T->ContentNum)/*  T->Key[i] != Unavailable*/
      printf("%d:", T->Key[i++]);
    printf(")");

    Level++;

    i = 0;
    while (i <= T->ContentNum) {
      RecursiveTravel(T->Children[i], Level);
      i++;
    }


  }
}
