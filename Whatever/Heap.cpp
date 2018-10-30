#include "Heap.h"
Status filein_1( char chars[])//从文件中读取字符串
{
    FILE *fp;
    int i = 0,j=0;
    fp=fopen("string.txt","r");
    if(fp==NULL)
        printf("can not open \n");
    while(!feof(fp))
    {
        fgets(chars+i,100,fp);
        i = strlen(chars);
        j++;
    }
    fclose(fp);
    return OK;
}

int strlen (char s[])//计算串的长度
{
    int  i = 0;
    while (s[i]!='\0')
        i++;
    return i;
}

Status line(HString &S)//用数组 a 来存放各行的回车符的位置
{
    int i = 0,j = 1;
    S.a[0] = 0;
    for(i = 0; i<S.length; i++)
    {
        if(S.ch[i]=='\n')
        {
            S.a[j] = i;
            j++;
        }
    }
    return j;
}


Status StrAssign(HString &T,char chars[])
{

//生成一个其值等于串常量chars的串T
    char *c,*news;
    c=chars;
    if(T.ch)
        free(T.ch);
    int i = 0;
    while(*c!='\0')
    {
        i++;
        c++;
    }
    T.length = i;
    i = i+1;
    if(!i)
    {
        T.ch=NULL;
        T.length = 0;
    }
    else
    {
        news=(char*)malloc(i*sizeof(char));
        if(news!=NULL)
            T.ch = news;
        for(i=0; i<T.length; i++)
        {
            T.ch[i]=chars[i];
        }
    }
    T.ch[T.length] = '\0';
    return OK;
}


int StrCompare(HString S,HString T)
{
    //若S大于T ，则返回值>0，相等 0，小于是 <0
    int i;
    for(i=0; i<S.length&&i<T.length; i++)
        if(S.ch[i]!=T.ch[i])
            return S.ch[i]-T.ch[i];
    return S.length - T.length;

}

Status ClearString(HString &S)
{
    //将S清空
    if(S.ch)
    {
        free(S.ch);
        S.ch=NULL;
    }
    S.length = 0;
    return OK;
}

Status Concat(HString &T,HString S1,HString S2)
{
    //用T返回由S1和S2的连接
    if(T.ch)
        free(T.ch);
    if(!(T.ch = (char *)malloc((S1.length+S2.length)*sizeof(char))))
        exit(0);
    int i;
    for(i=0; i<T.length; i++)
        T.ch[i] = S1.ch[i];

    T.length = S1.length+S2.length;
    int j;
    for( j=0; i<T.length; j++,i++)
        T.ch[S1.length] = S2.ch[j];

    return OK;

}

Status SubString(HString &Sub,HString S,int pos,int len)
{
    //用Sub返回串S的第pos个字符起长度为len的字符串
    //其中 1≤pos≤StrLength(S) 且 0≤len≤StrLength(S)-pos+1
    int i;
    if(pos<1||pos>S.length||len<0||len>S.length-pos+1)
        return error;
    if(Sub.ch)
        free(Sub.ch);
    if(!len)
    {
        Sub.ch = NULL;
        Sub.length = 0;
    }
    else
    {
        Sub.ch = (char *)malloc(len*sizeof(char));
        for(i=0; i<len; i++,pos++)
            Sub.ch[i] = S.ch[pos];
        Sub.length = len;

    }

    return OK;
}



//11111111插入一串字符：在当前行的字符串S中指定列位置pos插入字符串T。
Status  StringInsert(HString &S)
{
    printf("请输入插入点的位置\n");
    int pos;
    scanf("%d%*c",&pos);
    printf("请输入要插入的句子\n");
    char s[120];
    fgets(s,120,stdin);
    s[strlen(s)-1] = '\0';
    HString T;
    T.ch=NULL;
    StrAssign(T,s);
    StrInsert(S,pos,T);
    printf("插入后：\n");
    printf("%s\n",S.ch);
    return 0;
}
Status StrInsert(HString &S,int pos,HString T)
{
    if(pos<1||pos>S.length)
        return error;
    S.ch = (char *)realloc(S.ch,(S.length+T.length)*sizeof(char));
    int i = S.length;//被插入字符串的最后一个位置
    int j = S.length+T.length;//插入后 串的最后一个位置的数组下标
    int k = pos-1; //被插入的位置的下标
    int m = k+T.length; //被插入的字符串的最后一个串
    while(j>=m)
    {
        S.ch[j] = S.ch[i];
        j--;
        i--;
    }
    for( i = 0; i<T.length; i++)
    {
        S.ch[k] = T.ch[i];
        k++;
    }
    return OK;
}

//插入一行文本    插入一行：在当前行处插入一新行。
Status Insert_a_line(HString &S)
{
    printf("你想要在第几行之前插入新的一行?\n");
    int x;
    scanf("%d%*c",&x);
    int pos = S.a[x-1];//得到插入点的位置
    if(x>1)
        pos = pos+2;
    else pos = pos +1;
    printf("请输入你想要插入的句子\n");
    char chars1[100];
    fgets(chars1,100,stdin);
    HString T;
    StrAssign(T,chars1);
    StrInsert(S,pos,T);
    line(S);
    printf("%s",S.ch);
    return OK;
}
//222222删除一串字符：从当前行的字符串S的指定列位置pos处删除一串长度为len的字符串。
Status StringDelete(HString &S)
{
    printf("输入删除点的起始位置 和 被删除字符串的长度 中间以回车隔开，例如\n1\n30\n");
    int pos,len;
    scanf("%d%*c%d%*c",&pos,&len);
    StrDelete(S,pos,len);
    printf("删除之后：\n");
    char *c=S.ch;
    while(*c!='\0')
    {
        printf("%c",*c);
        c++;
    }

    return 0;
}
Status StrDelete(HString &S,int pos,int len)
{
    if(pos>S.length)
        return error;

    int i = pos-1;//被删除的起始位置的下标
    int j = i+len; //被移动位置的下标
    int k = 0;  //用来计算移动的次数
    for( k =1 ; k<=S.length-len; k++)
    {
        S.ch[i] = S.ch[j];
        i++;
        j++;
    }
    while(i<S.length)
    {
        S.ch[i]='\0';
        i++;
    }
    S.length = S.length-len;
    return OK;

}
//删除行：删除当前行。
Status Delete_a_line(HString &S)
{
    printf("您想要删除第几行？\n");
    int x;
    scanf("%d%*c",&x);
    int pos = S.a[x-1];
    int len = S.a[x] - S.a[x-1] + 1;
    StrDelete (S,pos,len);
    S.length = S.length - len;
    S.ch[S.length] = '\0';
    printf("%s",S.ch);
    return OK;
}


//33333333333查找
//简单的查找不需要替换
Status search_1(HString S)
{
    printf("输入你想要查找的字符串\n");
    char s[120];
    fgets(s,120,stdin);
    s[strlen(s)-1] = '\0';
    HString T;
    T.ch = NULL;
    StrAssign(T,s);
    int next[50];//用来存放T的回溯位置
    get_next(T,next);
    int pos = KMP(S,T,1,next);
    search(S.a,S,pos);
    return 0;
}
Status search(int a[],HString S,int pos)
{
    //a是 用来 记录回车符 的数组  pos是经过kmp算法之后  找到的位置
    int i = 0;
    int j;
    while(1)
    {
        if(a[i]<=pos&&pos<=a[i+1])
        {
            j = a[i];

            printf("您所查询的句子在本文第 %d 行\n",i+1);
            printf("您所查询的句子所在的行内容为：\n");
            while(j<=a[i+1])
            {
                if(S.ch[j]!='\n')
                    printf("%c",S.ch[j]);
                j++;
            }
            printf("\n");
            break;
        }
        else
            i++;
    }
    return OK;
}

void get_next(HString T,int next[])
{
    int i = 0;
    int j = -1;
    next[0] = -1;
    while(i<T.length)
    {
        if(j==-1||T.ch[i]==T.ch[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];

    }
}


int KMP(HString S,HString T,int pos,int next[])
{
    //求字符串T在主串S的第pos个字符之后的位置
    //i<=pos<=S.length
    int i = pos -1;
    int j = 0;
    while(i<S.length&&j<T.length)
    {
        if(j == -1||S.ch[i]==T.ch[j])
        {
            i++;
            j++;
        }
        else
            j = next[j];
    }
    if(j>T.length-1)
        return i - T.length + 1;
    else
        return error;
}

//查找字符串并替换；
Status search_2(HString &S)
{

    char chars1[100];
    printf("输入查找的字符串\n");
    fgets(chars1,100,stdin);
    chars1[strlen(chars1)-1] = '\0';
    HString T;
    T.ch=NULL;
    StrAssign(T,chars1);
    int next[100] ;
    get_next(T,next);
    int pos;
    pos = KMP(S,T,1,next);
    printf("%d\n",pos);
    search(S.a,S,pos);
    replace_string (pos,S,chars1);
    return 0;
}
Status replace_string (int pos,HString &S,char s1[])
{
    if(!pos)
        printf("该段不存在你所要替换的字符串\n");
    else
    printf("输入替换后的字符串\n");
    int i = pos -1 ;
    int j = 0;
    char s2[100];
    fgets(s2,100,stdin);
    s2[strlen(s2)-1] = '\0';
    if(strlen(s1)==strlen(s2))
    {
        while(j<strlen(s2))
        {
            S.ch[i] = s2[j];
            i++;
            j++;

        }
    }
    else
    {
        StrDelete (S,pos,strlen(s1));
        HString T;
        StrAssign(T,s2);
        StrInsert(S,pos,T);
    }
    printf("%s",S.ch);
    return OK;
}


//44444444444复制
//从当前行字符串S的指定位置pos处开始复制长度为len的字符串，保存在目标字符串T。
Status StringCopy(HString S)
{
    HString T;
    printf("输入开始复制点的位置 和 长度、中间以回车符隔开 例如：\n 1\n10\n");
    int pos,len;
    scanf("%d%*c%d%*c",&pos,&len);
    StrCopy(T,S,pos,len);
    return 0;
}
Status StrCopy( HString &T, HString S, int pos, int len)
{
    int i = pos-1;
    int j = 0;
    T.ch = (char *)malloc(len*sizeof(char));
    while(j<len)
    {
        T.ch[j] = S.ch[i];
        i++;
        j++;
    }
    T.ch[j] = '\0';
    printf("从当前行字符串S的指定位置 %d 处开始复制长度为 %d 的字符串为\n",pos,len);
    printf("%s",T.ch);
    printf("\n");
    return OK;
}


//显示文本分：输出一行和输出所有行。输出一整行是通过行号查找该行位置进行输出，输出所有行时，输出格式为：(行号：字符串内容)
Status printf_all(HString S )
{
    printf("您想要输出第几行？请输入行号\n");
    int x;
    scanf("%d",&x);
    int i = S.a[x-1];
    while(i<=S.a[x])
    {
        if(S.ch[i]!='\n')
            printf("%c",S.ch[i]);
        i++;
    }
    return OK;
}

////插入一行文本    插入一行：在当前行处插入一新行。
//Status Insert_a_line(HString &S)
//{
//    printf("你想要在第几行之前插入新的一行?\n");
//    int x;
//    scanf("%d%*c",&x);
//    int pos = S.a[x-1];//得到插入点的位置
//    if(x>1)
//        pos = pos+2;
//    else pos = pos +1;
//    printf("请输入你想要插入的句子\n");
//    char chars1[100];
//    fgets(chars1,100,stdin);
//    HString T;
//    StrAssign(T,chars1);
//    StrInsert(S,pos,T);
//    line(S);
//    printf("%s",S.ch);
//    return OK;
//}
//
//
////删除行：删除当前行。
//Status Delete_a_line(HString &S)
//{
//    printf("您想要删除第几行？\n");
//    int x;
//    scanf("%d%*c",&x);
//    int pos = S.a[x-1];
//    int len = S.a[x] - S.a[x-1] + 1;
//    StrDelete (S,pos,len);
//    S.length = S.length - len;
//    S.ch[S.length] = '\0';
//    printf("%s",S.ch);
//    return OK;
//}


//5555555555统计功能
//统计指定行的字符数目；
//统计行数；

//统计总字符数等；
//统计各类字符数。

Status Statistics_row_characters (HString S)
{
    int k;
    k = line(S);
    printf("该文一共有 %d 行\n",k);
    printf("您想要查询第几行？\n该行字符总数为；\t");
    int x;
    scanf("%d%*c",&x);
    if(x<1||x>k)  return error;
    else
    {
        int i = S.a[x-1],j = S.a[x];
        printf("%d\n",j - i);
    }
    return OK;
}

Status Statistics_characters (HString S)
{
    printf("该文一共有 %d 个字符\n",S.length);
    printf("统计各类字符数:\n");
    printf("请输入你想要查询的字符串:\n");
    char chars[100];
    fgets(chars,100,stdin);
    chars[strlen(chars)-1] = '\0';
    int next_T[100];
    HString T;
    StrAssign(T,chars);
    get_next(T,next_T);
    printf("该字符串出现的次数为：%d\n", KMP_2( S,T,1,next_T));
    return OK;
}

int KMP_2(HString S,HString T,int pos,int next[])
{
    //求字符串T在主串S的第pos个字符之后的位置
    //i<=pos<=S.length
    int i = pos -1;
    int j = 0,k = 0;
    while(i<S.length)
    {
        if(j == -1||S.ch[i]==T.ch[j])
        {
            if(j+1 == T.length)
            {
                k++;
                j = -1;
            }
            else k = k;
            i++;
            j++;
        }
        else
            j = next[j];
    }
    return k;//返回 查找的字符串出现的次数；
}


//66666666666移动操作
//包括上移一行、下移一行

Status Move(HString &S)
{
    printf("您想要移动哪一行？\n");
    int x;
    scanf("%d%*c",&x);
    char s[120];
    int len = Delete_a_line_2(S,x,s);
    printf("%s\n",S.ch);
    Insert_a_line_2(S,len,s);
    return OK;
}
Status StrDelete_2(HString &S,int pos,int len,char s[120])
{
    if(pos>S.length)
        return error;
    int i;
    if(pos ==0)
        i = pos;//被删除的起始位置的下标
    else i = pos+1;
    int j = i+len-1; //被移动位置的下标
    int k = 0;  //用来计算移动的次数
    int p = 0 ,q = S.length-len;
    for( k =1 ; k<q; k++)
    {
        if(p<=len-2)
        {
            s[p] = S.ch[i];
            p++;
        }

        else s[p] = s[p];

        S.ch[i] = S.ch[j];
        i++;
        j++;

    }
    s[p] = '\0';//
    return OK;

}


Status Delete_a_line_2(HString &S,int x ,char s[120])
{
    int pos = S.a[x-1];
    int len = S.a[x] - S.a[x-1] + 1;

    StrDelete_2(S,pos,len,s);
    S.length = S.length - len;
    S.ch[S.length] = '\0';

    return len;
}
Status Insert_a_line_2(HString &S,int len,char s[120])
{
    printf("你想要在第几行之前插入新的一行?\n");
    line(S);
    int x;
    scanf("%d%*c",&x);
    int pos = S.a[x-1];//得到插入点的位置
    pos = pos +1;

    StrInsert_2(S,pos,len,s);
    line(S);
    printf("%s",S.ch);
    return OK;
}

Status StrInsert_2(HString &S,int pos,int len,char s[120])
{
    if(pos<1||pos>S.length)
        return error;
    int i = S.length;//被插入字符串的最后一个位置
    int j = S.length+strlen(s);//插入后 串的最后一个位置的数组下标
    int k;
    if(pos==1)
        k = pos-1;//-1; //被插入的位置的下标
    else k = pos;
    int m = k+strlen(s); //被插入的字符串的最后一个串
    while(j>=m)
    {
        S.ch[j] = S.ch[i];
        j--;
        i--;
    }

    for( i = 0; i<strlen(s); i++)
    {
        S.ch[k] = s[i];
        k++;
    }
    return OK;
}

