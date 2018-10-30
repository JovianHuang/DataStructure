#include "Heap.h"
Status filein_1( char chars[])//���ļ��ж�ȡ�ַ���
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

int strlen (char s[])//���㴮�ĳ���
{
    int  i = 0;
    while (s[i]!='\0')
        i++;
    return i;
}

Status line(HString &S)//������ a ����Ÿ��еĻس�����λ��
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

//����һ����ֵ���ڴ�����chars�Ĵ�T
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
    //��S����T ���򷵻�ֵ>0����� 0��С���� <0
    int i;
    for(i=0; i<S.length&&i<T.length; i++)
        if(S.ch[i]!=T.ch[i])
            return S.ch[i]-T.ch[i];
    return S.length - T.length;

}

Status ClearString(HString &S)
{
    //��S���
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
    //��T������S1��S2������
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
    //��Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���ַ���
    //���� 1��pos��StrLength(S) �� 0��len��StrLength(S)-pos+1
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



//11111111����һ���ַ����ڵ�ǰ�е��ַ���S��ָ����λ��pos�����ַ���T��
Status  StringInsert(HString &S)
{
    printf("�����������λ��\n");
    int pos;
    scanf("%d%*c",&pos);
    printf("������Ҫ����ľ���\n");
    char s[120];
    fgets(s,120,stdin);
    s[strlen(s)-1] = '\0';
    HString T;
    T.ch=NULL;
    StrAssign(T,s);
    StrInsert(S,pos,T);
    printf("�����\n");
    printf("%s\n",S.ch);
    return 0;
}
Status StrInsert(HString &S,int pos,HString T)
{
    if(pos<1||pos>S.length)
        return error;
    S.ch = (char *)realloc(S.ch,(S.length+T.length)*sizeof(char));
    int i = S.length;//�������ַ��������һ��λ��
    int j = S.length+T.length;//����� �������һ��λ�õ������±�
    int k = pos-1; //�������λ�õ��±�
    int m = k+T.length; //��������ַ��������һ����
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

//����һ���ı�    ����һ�У��ڵ�ǰ�д�����һ���С�
Status Insert_a_line(HString &S)
{
    printf("����Ҫ�ڵڼ���֮ǰ�����µ�һ��?\n");
    int x;
    scanf("%d%*c",&x);
    int pos = S.a[x-1];//�õ�������λ��
    if(x>1)
        pos = pos+2;
    else pos = pos +1;
    printf("����������Ҫ����ľ���\n");
    char chars1[100];
    fgets(chars1,100,stdin);
    HString T;
    StrAssign(T,chars1);
    StrInsert(S,pos,T);
    line(S);
    printf("%s",S.ch);
    return OK;
}
//222222ɾ��һ���ַ����ӵ�ǰ�е��ַ���S��ָ����λ��pos��ɾ��һ������Ϊlen���ַ�����
Status StringDelete(HString &S)
{
    printf("����ɾ�������ʼλ�� �� ��ɾ���ַ����ĳ��� �м��Իس�����������\n1\n30\n");
    int pos,len;
    scanf("%d%*c%d%*c",&pos,&len);
    StrDelete(S,pos,len);
    printf("ɾ��֮��\n");
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

    int i = pos-1;//��ɾ������ʼλ�õ��±�
    int j = i+len; //���ƶ�λ�õ��±�
    int k = 0;  //���������ƶ��Ĵ���
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
//ɾ���У�ɾ����ǰ�С�
Status Delete_a_line(HString &S)
{
    printf("����Ҫɾ���ڼ��У�\n");
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


//33333333333����
//�򵥵Ĳ��Ҳ���Ҫ�滻
Status search_1(HString S)
{
    printf("��������Ҫ���ҵ��ַ���\n");
    char s[120];
    fgets(s,120,stdin);
    s[strlen(s)-1] = '\0';
    HString T;
    T.ch = NULL;
    StrAssign(T,s);
    int next[50];//�������T�Ļ���λ��
    get_next(T,next);
    int pos = KMP(S,T,1,next);
    search(S.a,S,pos);
    return 0;
}
Status search(int a[],HString S,int pos)
{
    //a�� ���� ��¼�س��� ������  pos�Ǿ���kmp�㷨֮��  �ҵ���λ��
    int i = 0;
    int j;
    while(1)
    {
        if(a[i]<=pos&&pos<=a[i+1])
        {
            j = a[i];

            printf("������ѯ�ľ����ڱ��ĵ� %d ��\n",i+1);
            printf("������ѯ�ľ������ڵ�������Ϊ��\n");
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
    //���ַ���T������S�ĵ�pos���ַ�֮���λ��
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

//�����ַ������滻��
Status search_2(HString &S)
{

    char chars1[100];
    printf("������ҵ��ַ���\n");
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
        printf("�öβ���������Ҫ�滻���ַ���\n");
    else
    printf("�����滻����ַ���\n");
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


//44444444444����
//�ӵ�ǰ���ַ���S��ָ��λ��pos����ʼ���Ƴ���Ϊlen���ַ�����������Ŀ���ַ���T��
Status StringCopy(HString S)
{
    HString T;
    printf("���뿪ʼ���Ƶ��λ�� �� ���ȡ��м��Իس������� ���磺\n 1\n10\n");
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
    printf("�ӵ�ǰ���ַ���S��ָ��λ�� %d ����ʼ���Ƴ���Ϊ %d ���ַ���Ϊ\n",pos,len);
    printf("%s",T.ch);
    printf("\n");
    return OK;
}


//��ʾ�ı��֣����һ�к���������С����һ������ͨ���кŲ��Ҹ���λ�ý�����������������ʱ�������ʽΪ��(�кţ��ַ�������)
Status printf_all(HString S )
{
    printf("����Ҫ����ڼ��У��������к�\n");
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

////����һ���ı�    ����һ�У��ڵ�ǰ�д�����һ���С�
//Status Insert_a_line(HString &S)
//{
//    printf("����Ҫ�ڵڼ���֮ǰ�����µ�һ��?\n");
//    int x;
//    scanf("%d%*c",&x);
//    int pos = S.a[x-1];//�õ�������λ��
//    if(x>1)
//        pos = pos+2;
//    else pos = pos +1;
//    printf("����������Ҫ����ľ���\n");
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
////ɾ���У�ɾ����ǰ�С�
//Status Delete_a_line(HString &S)
//{
//    printf("����Ҫɾ���ڼ��У�\n");
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


//5555555555ͳ�ƹ���
//ͳ��ָ���е��ַ���Ŀ��
//ͳ��������

//ͳ�����ַ����ȣ�
//ͳ�Ƹ����ַ�����

Status Statistics_row_characters (HString S)
{
    int k;
    k = line(S);
    printf("����һ���� %d ��\n",k);
    printf("����Ҫ��ѯ�ڼ��У�\n�����ַ�����Ϊ��\t");
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
    printf("����һ���� %d ���ַ�\n",S.length);
    printf("ͳ�Ƹ����ַ���:\n");
    printf("����������Ҫ��ѯ���ַ���:\n");
    char chars[100];
    fgets(chars,100,stdin);
    chars[strlen(chars)-1] = '\0';
    int next_T[100];
    HString T;
    StrAssign(T,chars);
    get_next(T,next_T);
    printf("���ַ������ֵĴ���Ϊ��%d\n", KMP_2( S,T,1,next_T));
    return OK;
}

int KMP_2(HString S,HString T,int pos,int next[])
{
    //���ַ���T������S�ĵ�pos���ַ�֮���λ��
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
    return k;//���� ���ҵ��ַ������ֵĴ�����
}


//66666666666�ƶ�����
//��������һ�С�����һ��

Status Move(HString &S)
{
    printf("����Ҫ�ƶ���һ�У�\n");
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
        i = pos;//��ɾ������ʼλ�õ��±�
    else i = pos+1;
    int j = i+len-1; //���ƶ�λ�õ��±�
    int k = 0;  //���������ƶ��Ĵ���
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
    printf("����Ҫ�ڵڼ���֮ǰ�����µ�һ��?\n");
    line(S);
    int x;
    scanf("%d%*c",&x);
    int pos = S.a[x-1];//�õ�������λ��
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
    int i = S.length;//�������ַ��������һ��λ��
    int j = S.length+strlen(s);//����� �������һ��λ�õ������±�
    int k;
    if(pos==1)
        k = pos-1;//-1; //�������λ�õ��±�
    else k = pos;
    int m = k+strlen(s); //��������ַ��������һ����
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

