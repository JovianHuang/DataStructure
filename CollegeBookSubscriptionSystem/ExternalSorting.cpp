#include <stdio.h>
#include "ExternalSorting.h"
#include "Sort.h"

/* local data type */
typedef int LoserTree[7];

/* prototype for local functions */

//static void get_run(LoserTree &ls, WorkArea &wa);
//static void SelectMinMax(LoserTree &ls, WorkArea wa, int q);
//static void ConstructLoser(LoserTree &ls, WorkArea &wa);

/* functions definition */

//void ReplaceSelectionSort(LoserTree &ls, WorkArea &wa, FILE *fi, FILE *fo) {
//  ConstructLoser(ls, wa);
//  int rmax;
//  wa[0].record = rmax = 1;
//  while (wa[0].record <= rmax) {
//    get_run(ls, wa);
//    
//  }
//}

void SevenWayMergeSort(FILE *fi) {

}

/* local functions */
//static void get_run(LoserTree &ls, WorkArea &wa) {
//  // ���һ����ʼ�鲢�Σ�fi Ϊ�����ļ�ָ�룬f0 Ϊ����ļ�ָ��
//  while (wa[ls[0]].segementNum == wa->record) {
//
//  }
//}
//
//static void SelectMinMax(LoserTree &ls, WorkArea wa, int q) {
//  // �� wa[q] �𵽰������ĸ��Ƚ�ѡ�� MINMAX ��¼������ q ָʾ�����ڵĹ鲢��
//  int t, p;
//  for (t = (capacity + q) / 2, p = ls[t]; t > 0; t = t / 2, p = ls[t]) {
//    if (wa[p].segementNum < wa[q].segementNum || wa[p].segementNum == wa[q].segementNum && wa[p].key < wa[q].key) {
//      int temp = q;
//      q = ls[t];
//      ls[t] = temp;
//    }
//    ls[0] = q;
//  }
//}
//
//static void ConstructLoser(LoserTree &ls, WorkArea &wa) {
//  // ���� w ����¼���ڴ湤���� wa�����ð����� ls��ѡ���ؼ�����С�ļ�¼���� s ָʾ���� wa �е�λ��
//  int i;
//  for (i = 0; i < capacity; i++) {  // ��������ʼ��
//    wa[i].segementNum = wa[i].key = ls[i] = 0;
//  }
//  FILE * fi = fopen("aha.txt", "r");
//  for (i = capacity - 1; i >= 0; i--) {
//    if (fscanf(fi, "%d", &wa[i].record) != EOF) {
//      wa[i].key = wa->record; // ��ȡ�ؼ���
//      wa[i].segementNum = 1;
//      SelectMinMax(ls, wa, i);
//    } else {
//      puts("fscanf error");
//    }
//  }
//}
