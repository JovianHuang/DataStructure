#include "BPTbase.h"
#include "CollegeInfo.h"


void FreadRecord(Record record[], int &N)   //���ļ���ȡ��¼�����
{
  FILE *fp = fopen("university.dat", "wb");
  int i = 0, j;
  School node;
  while (true) {
    fread(&node, sizeof(School), 1, fp);
    if (feof(fp)) {
      break;
    }
   
  }
    i++;
  N = i;
  printf("һ������Ϣ��¼��%d\n", i);
  for (j = 1; j <= i; j++)
    printf("%d\t%s\t%s\t%s\t%s\t%s\n", j, record[j].SchoolName, record[j].Id, record[j].Department, record[j].Place, record[j].Level);
  fclose(fp);
}

BPTree InitializeBPNode(void) {
  //��ʼ��
  BPTree  NewNode;
  int i;
  NewNode = (BPTree)malloc(sizeof(BPNode));
  if (NewNode == NULL)
    exit(0);
  i = 1;
  while (i < m + 2) {
    NewNode->key[i][15] = '\0';
    NewNode->children[i] = NULL;
    NewNode->parent = NULL;
    i++;
  }
  NewNode->next = NULL;
  NewNode->keynum = 0;
  return NewNode;
}

void KeySort(Record R[], int N)   //�����۰���ҷ�
{
  //ʹ�ùؼ�������
  int i, j, M, low, high;
  for (i = 2; i < N; i++) {
    R[0] = R[i];    //��R[i]�ݴ�R[0]
    low = 1;
    high = i - 1;
    while (low <= high) {
      M = (low + high) / 2;
      if (strcmp(R[0].Id, R[M].Id) < 0)
        high = M - 1;
      else
        low = M + 1;
    }//while
    for (j = i - 1; j >= high + 1; --j)
      R[j + 1] = R[j];    //��¼����
    R[high + 1] = R[0];   //����
  }//for
}

Status CreateBPTree(BPTree &Tree, Record record[], int &N) {
  //����B+��,n�����
  BPTree ptr;
  int i, j;
  i = 1;
  j = 1;
  Tree = InitializeBPNode();
  ptr = Tree;    //�ƶ�ָ��
  while (i <= m && j <= N) {
    strcpy(ptr->key[i], record[j].Id);   //�ؼ��ָ�ֵ
    ptr->recptr[i] = &record[j++];
    ptr->keynum = i;
    i++;
    if (i > m) {
      i = 1;
      ptr->next = InitializeBPNode();   //��ȡ�µ��ֵܿռ�,ָ����һ���ֵ�
      ptr = ptr->next;
    }
  }    //���Ҷ�Ӳ�

  CreateBPTreeParent(Tree);   //���Ϲ���
  return OK;
}

Status CreateBPTreeParent(BPTree &T) {
  //��������
  BPTree p, parents;
  int i;
  p = T;
  i = 1;
  T = InitializeBPNode();   //��ȡ���׽��
  parents = T;
  while (i <= m && p) {
    strcpy(parents->key[i], p->key[p->keynum]);  //�����ŵ���һ��
    parents->children[i] = p;
    parents->keynum = i;                    //����
    p->parent = parents;
    i++;
    p = p->next;
    if (i > m) {
      i = 1;
      parents->next = InitializeBPNode();   //��ȡ�µ��ֵܿռ�,ָ����һ���ֵ�
      parents = parents->next;
    }
  }//while
  if (!T->next)
    return OK;
  CreateBPTreeParent(T);
}

Result SearchByInput(BPTree T, KeyType num[]) {
  Result result;
  int i = 1;
  BPTree ptr;  //pΪ�ƶ�ָ��
  ptr = T;
  while (ptr&&i <= ptr->keynum) {
    if (strcmp(num, ptr->key[i]) == 0) {
      if (!ptr->children[i]) {
        result.tag = 1;
        result.i = i;
        result.pt = ptr;
      } else {
        ptr = ptr->children[i];
        while (ptr->children[ptr->keynum]) {
          ptr = ptr->children[ptr->keynum];
        }
        result.tag = 1;
        result.i = ptr->keynum;
        result.pt = ptr;
      }
      printf("\n������鵽��Ӧ��Ϣ\n");
      break;
    } else if (strcmp(num, ptr->key[i]) < 0) {
      if (!ptr->children[i]) {
        result.i = i;
        result.pt = ptr;
        result.tag = 0;
      }
      ptr = ptr->children[i];
      i = 1;
      continue;
    } else
      i++;
    if (i > ptr->keynum) {
      while (ptr->children[ptr->keynum])
        ptr = ptr->children[ptr->keynum];
      result.i = ptr->keynum + 1;
      result.pt = ptr;
      result.tag = 0;
    }

  }//while
  if (ptr == NULL || i > ptr->keynum) {
    result.tag = 0;
  }
  return result;
}

Status InsertBPLeaf(BPTree &T, KeyType K[], BPTree q, int pos) {
  //��m��B+��T�Ͻ��*q��key[i]��key[i+1]֮�����ؼ���K;
  //���������������˫�������б�Ҫ�Ľ����ѵ�����ʹT����m��B+��
  KeyType x[15];
  BPTree ap;
  int finished, i, s;
  i = pos;
  strcpy(x, K);
  ap = NULL;
  finished = FALSE;
  while (q && !finished) {
    Insert(q, i, x, ap);  //��x��ap�ֱ���뵽q->key[i+1]��q->children[i+1]
    if (q->keynum <= m) finished = TRUE;
    else {
      s = m / 2;//ע��
      Split(q, s, ap);   //��q->key[s+1 ...n],q->children[s..n]��p->recptr[s+1..m]�����½��*ap
      strcpy(q->key[s], x);
      q = q->parent;
      if (q) i = Search(q, x);   //��˫�׽��*q�в���x�Ĳ���λ��
    }
  }
  if (!finished)
    CreateNewRoot(T, ap);
  return OK;
}


Status CreateNewRoot(BPTree &T, BPTree ap) {
  BPTree ptr;
  ptr = InitializeBPNode();
  strcmp(ptr->key[1], T->key[T->keynum]);
  strcmp(ptr->key[2], ap->key[ap->keynum]);
  ptr->keynum = 2;
  T = ptr;
  return OK;
}


Status Split(BPTree &q, int s, BPTree &ap) {
  int i, j;
  ap = InitializeBPNode();
  for (i = s + 1, j = 1; i <= q->keynum; i++, j++) {
    strcpy(ap->key[j], q->key[i]); //��q�ϵĹؼ��ָ�ֵ ��ap��
    ap->keynum = j;
    ap->children[j] = q->children[i];
    ap->recptr[j] = q->recptr[i];
  }
  q->keynum -= j - 1;
  return OK;
}

Status Insert(BPTree &q, int i, KeyType K[], BPTree &ap) {
  //��x��ap�ֱ���뵽q->key[i+1]��q->children[i+1],
  int j;
  BPTree pre;
  if (i <= q->keynum) {
    for (j = q->keynum; j >= i; j--) {
      strcpy(q->key[j + 1], q->key[j]);
      q->recptr[j + 1] = q->recptr[j];
    }
    strcpy(q->key[i], K);   //j jm�ѹؼ��ָ�ֵ��q->key
  } else {//���ֵ�������ұ�
    strcpy(q->key[i], K);   //����
    if (strcmp(K, q->key[q->keynum]) > 0)   //�ķ��ն˽���ֵ
    {
      pre = q->parent;
      while (pre) {
        strcpy(pre->key[pre->keynum], K);
        pre = pre->parent;
      }
    }
  }
  q->keynum += 1;   //����
  q->children[i] = ap;
  return OK;
}

int Search(BPTree q, KeyType K[]) {
  int i = 0;
  if (strcmp(K, q->key[i++]) <= 0)
    return i;
}

//ɾ������
Status SearchInBPTree(BPTree &T, KeyType k[], BPTree &q, int &i) {
  BPTree ptr;
  ptr = T;
  int j;
  for (j = 1; j <= ptr->keynum;) {
    if (strcmp(k, ptr->key[j]) <= 0) {
      if (ptr->children[j])
        ptr = ptr->children[j];
      else {
        if (strcmp(k, ptr->key[j]) == 0) {
          i = j;
          q = ptr;
          return 0;
        } else {
          i = j - 1;
          q = ptr;
          return 0;
        }
      }
      j = 1;
    } else if (j == ptr->keynum&&strcmp(ptr->key[j], k) < 0) {
      while (ptr->children[ptr->keynum])
        ptr = ptr->children[ptr->keynum];
      q = ptr;
      i = ptr->keynum;//i�ǲ����ǰһ��λ��  ��
      return 0;
    } else
      j++;
  }
  return OK;
}

//ɾ������
Status DeleteUniInfo(BPTree &T)  //delete_one_information
{
  while (1) {
    printf("������Ҫɾ����ѧУ��ʶ�룺");
    KeyType num[15];
    fgets(num, 15, stdin);
    num[strlen(num) - 1] = '\0';
    int n;
    n = strlen(num);
    if (n == 10) {
      DeleteInfo(T, num);  //delete_one_infor
      break;
    } else
      printf("����������Ҫɾ����ѧУ��ʾ��\n");
  }
  return OK;
}

Status DeleteInfo(BPTree &T, char num[])  //delete_one_infor
{
  int i;
  BPTree q;
  int flag = 1;
  SearchInBPTree(T, num, q, i);//i  i+1��q��Ҫɾ����λ��
  DeletePos(T, i, flag);//delete_q_i
  int finished = FALSE;
  while (!finished) {
    if (flag)//���ɾ�Ĳ������ؼ���
    {
      if (q->keynum < (m / 2)) {
        BPTree p;
        if (q->next)
          p = q->next;
        else {

          SearchLeft(q, p); //���������ֵ�ȥ
        }
        if (p->keynum > (m / 2))//��һ��������q
        {
          BorrowToOther(p, q);
          Return_Borrow(q);//�޸�q�ĸ��ڵ�����ؼ��֡�

          if (p != T && p->keynum >= (m / 2)) {
            finished = TRUE;
            flag = 1;
          } else {
            q = p;
            flag = 1;
            finished = FALSE;
          }

        } else {//�ϲ�p��q��
          Combine(p, q);   //�ϲ�
          char x[50];
          Return_Combine(q, x);//�޸�q�ĸ��ڵ�����ؼ��֡�
          q = p->parent;

          if (q != T && q->keynum >= (m / 2)) {
            finished = TRUE;
          } else if (q == T) {
            finished = TRUE;
          } else {
            if (strcmp(x, q->key[q->keynum]) == 0) {
              finished = FALSE;
              flag = 1;
            } else if (strcmp(x, q->key[q->keynum]) > 0) {
              finished = FALSE;
              flag = 1;
            } else if (strcmp(q->key[q->keynum], x) < 0 && strcmp(q->next->key[1], x) >= 0) {
              finished = FALSE;
              flag = 0;
            }
          }
        }
      } else {
        finished = TRUE;
      }
    } else {//ɾ�������Ĺؼ���
      if (q->keynum < (m / 2)) {
        BPTree p;
        if (q->next) {
          p = q->next;
        } else {
          SearchLeft(q, p);//�����ֵ�ȥ
        }
        if (p->keynum > (m / 2)) {
          //��p��һ�������� q
          BorrowToOther(p, q);
          Return_Borrow(q);//�޸�q�ĸ��ڵ�����ؼ��֡�
          if (p != T && p->keynum >= (m / 2)) {
            finished = TRUE;
          } else {
            finished = FALSE;
            q = p;
            flag = 1;
          }
        } else {
          Combine(p, q);
          char x[50];
          Return_Combine(q, x);//�޸�q�ĸ��ڵ�����ؼ��֡�
          q = p->parent;
          if (q != T && q->keynum >= (m / 2)) {
            finished = TRUE;
          } else if (q == T)
            finished = TRUE;
          else {
            if (strcmp(x, q->key[q->keynum]) == 0) {
              finished = FALSE;
              flag = 1;
            } else if (strcmp(x, q->key[q->keynum]) > 0)  //���ֵ�
            {
              finished = FALSE;
              flag = 1;
            } else if (strcmp(q->key[q->keynum], x) < 0 && strcmp(q->next->key[1], x) >= 0) // ���ؼ���
            {
              finished = FALSE;
              flag = 0;
            }
          }
        }
      } else {
        char x[50];
        Return_Max(q, x);//�޸�q�ĸ��ڵ�����ؼ��֡�
        q = q->parent;
        finished = TRUE;
      }

    }
  }
  return OK;
}


Status  DeletePos(BPTree &q, int i, int &flag)//delete_q_i
{//��q��iλ��ɾȥ���
  int j;
  if (i == q->keynum)
    flag = 0;
  for (j = i; j < q->keynum; j++) {
    strcpy(q->key[j], q->key[j + 1]);
    q->children[j] = q->children[j + 1];
    q->recptr[j] = q->recptr[j + 1];

  }
  q->keynum--;
  return OK;
}

Status BorrowToOther(BPTree &p, BPTree &q) //Borrow_p_to_q
{
  int i;
  if (strcmp(p->key[p->keynum], q->key[1]) < 0)//˵�� p��q�����ֵ�
  {
    for (i = q->keynum + 1; i > 1; i--) {
      strcpy(q->key[i], q->key[i - 1]);
      q->children[i] = q->children[i - 1];
      q->recptr[i] = q->recptr[i - 1];
    }
    q->keynum++;
    strcpy(q->key[1], p->key[p->keynum]);
    q->children[1] = p->children[p->keynum];
    q->recptr[1] = p->recptr[p->keynum];
    p->keynum--;

  } else {
    strcpy(q->key[q->keynum + 1], p->key[1]);
    q->children[q->keynum + 1] = p->children[1];
    q->recptr[q->keynum + 1] = p->recptr[1];
    q->keynum++;
    for (i = 1; i < p->keynum; i++) {
      strcpy(p->key[i], p->key[i + 1]);
      p->children[i] = p->children[i + 1];
      p->recptr[i] = p->recptr[i + 1];
    }
    p->keynum--;
  }
  return OK;
}



Status Return_Borrow(BPTree &q) {
  BPTree parents;
  parents = q->parent;
  int i;
  for (i = 1; i <= parents->keynum; i++) {
    if (strcmp(parents->key[i], q->key[q->keynum]) == 0)//����Ǵ����ֵܽ�Ļ�  q�����ؼ���û�иı�  ����q�ĸ��׽�� �����޸����ؼ���
    {
      BPTree p;
      p = parents->children[i - 1];
      strcpy(parents->key[i - 1], p->key[p->keynum]);

      break;
    } else if (strcmp(parents->key[i], q->key[q->keynum]) > 0) {
      strcpy(parents->key[i - 1], q->key[q->keynum]);
      break;
    }

  }

  if (i > parents->keynum) {// ���ұ����ֵܽ��
    strcpy(parents->key[parents->keynum], q->key[q->keynum]);
  }
  return OK;
}

Status Return_Max(BPTree &q, char x[]) {  //���ظ���,��Ϊɾ�������ֵ
  BPTree parents;
  parents = q->parent;
  int i;
  strcpy(x, parents->key[parents->keynum]);
  for (i = 1; i <= parents->keynum; i++) {
    if (strcmp(parents->key[i], q->key[q->keynum]) > 0) {
      strcpy(parents->key[i], q->key[q->keynum]);
      break;
    }

  }
  return OK;
}

//��q�����ֵ�ȥ
Status SearchLeft(BPTree q, BPTree &p) {
  BPTree parent;
  parent = q->parent;
  int i;
  for (i = 1; i <= parent->keynum; i++) {
    if (strcmp(parent->key[i], q->key[q->keynum]) == 0) {
      i = i - 1;
      if (parent->children[i]) {
        p = parent->children[i];
        break;
      }

    }
  }
  return OK;
}


Status Combine(BPTree &p, BPTree &q) {
  int i, j;
  if (strcmp(p->key[1], q->key[q->keynum]) > 0)//p��q���ұ�
  {
    for (i = q->keynum + 1, j = 1; j <= p->keynum; i++, j++) {
      strcpy(q->key[i], p->key[j]);
      q->children[i] = p->children[j];
      q->recptr[i] = p->recptr[j];
    }
    q->keynum += p->keynum;
    p->keynum = 0;
  } else //p�����q��
  {
    int n;
    n = p->keynum + q->keynum;
    for (i = n, j = q->keynum; j >= 1; i--, j--) {
      strcpy(q->key[i], q->key[j]);
      q->children[i] = q->children[j];
      q->recptr[i] = q->recptr[j];
    }
    for (i = 1; i <= p->keynum; i++) {
      strcpy(q->key[i], p->key[i]);
      q->children[i] = p->children[i];
      q->recptr[i] = q->recptr[j];
    }
    q->keynum = q->keynum + p->keynum;
    p->keynum = 0;

  }
  return 0;
}

Status Return_Combine(BPTree &q, char x[]) {// ���� p�ϲ����� q ��  �޸�q�ĸ��ڵ�����ؼ��֡�
  BPTree parent;
  parent = q->parent;

  strcpy(x, parent->key[parent->keynum]);
  int i;
  int j;
  for (i = 1; i <= parent->keynum; i++) {
    if (strcmp(q->key[q->keynum], parent->key[i]) == 0) {
      BPTree p;
      p = parent->children[i];
      if (p->keynum == 0)//˵�� �ϲ� ��p��q���ұ�
      {
        i -= 1;
        BPTree p1, p2;
        p1 = parent->children[i];
        p2 = p1->next;
        p1->next = p2->next;
        free(p2);
        strcpy(parent->key[i], q->key[q->keynum]);
        for (j = i + 1; j < parent->keynum; j++) {
          strcpy(parent->key[j], parent->key[j + 1]);
          parent->children[j] = parent->children[j + 1];
        }
        parent->keynum--;
      } else   //�ϲ� �� p ��q�����
      {
        i -= 1;
        j = i;
        BPTree p1;
        p1 = parent->children[i];
        i = i - 1;
        BPTree p2;
        p2 = parent->children[i];
        p2->next = p1->next;
        free(p1);
        for (; j < parent->keynum; j++) {
          strcpy(parent->key[j], parent->key[j + 1]);
          parent->children[j] = parent->children[j + 1];
          parent->recptr[j] = parent->recptr[j];
        }
        parent->keynum--;
      }
      return 0;
    }
  }
  BPTree p1;
  p1 = parent->next;
  if (i > parent->keynum) {
    if (strcmp(q->key[q->keynum], p1->key[1]) == 0)//˵����ϵ��� q ���ұߵ����ֵ�
    {
      for (j = 1; j < p1->keynum; j++) {
        strcpy(p1->key[j], p1->key[j + 1]);
        p1->children[j] = p1->children[j + 1];
        p1->recptr[j] = p1->recptr[j + 1];
      }
    }
    p1->keynum--;
    strcpy(x, p1->key[1]);
  }
  return OK;
}


Status ModifyBptree(BPTree &T) {
  Record rec;
  Result pos;
  getId(rec.SchoolName);
  pos = SearchByInput(T, rec.Id);
  while (1) {
    printf("+");
    int n;
    n = strlen(rec.Id);
    if (n == 10) {
      DeleteInfo(T, rec.Id);  //delete_one_infor
      break;
    } else
      printf("����������ѧУ��ʶ��\n");
  }
  return OK;
}
