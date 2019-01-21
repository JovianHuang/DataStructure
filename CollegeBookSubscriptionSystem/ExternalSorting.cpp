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
//  // 求得一个初始归并段，fi 为输入文件指针，f0 为输出文件指针
//  while (wa[ls[0]].segementNum == wa->record) {
//
//  }
//}
//
//static void SelectMinMax(LoserTree &ls, WorkArea wa, int q) {
//  // 从 wa[q] 起到败者树的根比较选择 MINMAX 记录，并由 q 指示它所在的归并段
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
//  // 输入 w 个记录到内存工作区 wa，建得败者树 ls，选出关键字最小的记录并有 s 指示其在 wa 中的位置
//  int i;
//  for (i = 0; i < capacity; i++) {  // 工作区初始化
//    wa[i].segementNum = wa[i].key = ls[i] = 0;
//  }
//  FILE * fi = fopen("aha.txt", "r");
//  for (i = capacity - 1; i >= 0; i--) {
//    if (fscanf(fi, "%d", &wa[i].record) != EOF) {
//      wa[i].key = wa->record; // 提取关键字
//      wa[i].segementNum = 1;
//      SelectMinMax(ls, wa, i);
//    } else {
//      puts("fscanf error");
//    }
//  }
//}
