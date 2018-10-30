#include "Heap.h"
#include "String.h"

int main()
{
    char chars[MAX];
    filein_1(chars);
//将从文件中独到的文章建立成堆的形式
    HString S;
    S.ch = NULL;
    StrAssign(S,chars);
    line(S);

    printf("从文件中读取到的文章：\n");
    printf("%s\n",S.ch);
    printf("请选择你要进行的操作\n");
    printf("1.插入\n2/删除\n3.查找\n4.复制\n5.统计\n6.移动行\n7.显示文本\n");
    int x;
    scanf("%d",&x);
    while(x!=0)
    {
        switch(x)
        {
        case 1:
            printf("1.在当前行的字符串S中指定列位置pos插入字符串T\n2.插入一行：在当前行处插入一新行\n");
            int n;
            scanf("%d%*c",&n);
            if(n==1)
            StringInsert(S);
            else
            Insert_a_line(S);

            line(S);
            break;
        case 2:
            printf("1.从当前行的字符串S的指定列位置pos处删除一串长度为len的字符串\n2.删除指定行\n");
            int q;
            scanf("%d%*c",&q);
            if(q==1)
                 StringDelete(S);
            else
                Delete_a_line(S);
            line(S);
            break;
        case 3:
            printf("请选择\n1.简单查找不需要替换\n2.查找并替换\n");
            int m;
            scanf("%d%*c",&m);

            if(m==1)
                search_1(S);
            else
                search_2(S);

            line(S);
            break;

        case 4:StringCopy(S);break;
        case 5:printf("1.统计指定行的字符数目和统计行数 \n2.统计总字符数和统计各类字符数。\n");
               int w;
               scanf("%d%*c",&w);
               if(w==1)
                  Statistics_row_characters (S);
               else
                Statistics_characters(S);
               break;

        case 6:Move(S);break;

        }
        printf("继续操作吗？输入 0 结束程序\n");
        scanf("%d%*c",&x);
    }


//printf("%d\n",S.length);
////printf("%s",S.ch);
//    k = line(S);
//    printf("%s\n",S.ch);
//    Move(S);
////
//////替换
//    char chars1[100];
//    fgets(chars1,100,stdin);
//    chars1[strlen(chars1)-1] = '\0';
//    HString T;
//    T.ch=NULL;
//    StrAssign(T,chars1);
//    int next[100] ;
//    get_next(T,next);
//    int pos;
//    pos = KMP(S,T,1,next);
//    printf("%d\n",pos);
//    search(S.a,S,pos);
//    replace_string (pos,S,chars1);
//    printf("%s",S.ch);
//Delete_a_line(S);
//printf_all(S);
//Statistics_characters (S);


//statistics(T);


    return 0;

}
