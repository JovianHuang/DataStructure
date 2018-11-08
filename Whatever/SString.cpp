#include "SString.h"

Status StrAssign(SString &T, char chars[])
{
    // ����һ����ֵ����chars�Ĵ�T
    int i;
    if(strlen(chars)>MAXSTRING)
        return ERROR;   //�ж����޳�������
    else
    {
        for(i=1;i<=strlen(chars);i++)
        T[i] = chars[i-1]; //����
    }
    T[0] = '0'+i-1;    //���ַ�����
 return OK;
}


Status StrCopy(SString &T,SString S,int pos,int len)
{
    //�ɴ�S���Ƶô�T
    int i;
    if(S[0]-'0'>MAXSTRING) return ERROR;    //�ж�S[0],���޴洢����
    else
    {
        for(i=1;i<=len;i++)   //����
          T[i] = S[pos-1+i];
    }
     T[0]='0'+len;
  return OK;
}


Status StrEmpyt(SString S){
//�ж��Ƿ�Ϊ��
    if(S[0]=='0')
        return OK;
    else
        return ERROR;
}


int StrCompare(SString S, SString T)
{
//�Ƚϴ�С
     int len,i,flag=0;
     len = S[0]<=T[0]?S[0]:T[0];
     len = len -'0';
     printf("%d\n",len);
    for(i=1; i<=len; i++)
    {
        if(S[i] != T[i]){
            flag= S[i]-T[i];
            break;
        }
    }
    if(!flag&&S[0]!=T[0]) return S[0]-T[0];
    return flag;
}



int StrLength(SString S)
{
//�㳤��
    return S[0]-'0';
}


Status ClearString(SString &S)
{
//��S��Ϊ��
    S[0] = '0';
    return OK;
}


Status Concat(SString &T,SString S1,SString S2)
{
//��T������S1��S2���Ӷ��ɵ��´�����δ�ضϣ��򷵻�TURE�����򷵻�FALSE��
    int i,uncut;
    if(S1[0]-'0'+S2[0]-'0'<=MAXSTRING)   //Ϊ�ض�
    {
        for(i=1;i<=S1[0]-'0';i++)
           T[i] = S1[i];        //��S1���Ƶ�T��
           for(i=1;i<=S2[0]-'0';i++)
            T[S1[0]+i] = S2[i];   //��S2���ӵ�S1����
         T[0] = S1[0]+S2[0]-'0';   //�������Ӻ���ַ���
        uncut = TRUE;
    }
    else if(S1[0]<MAXSTRING)   //�ض�
    {
         for(i=1;i<=S1[0]-'0';i++)
           T[i] = S1[i];        //��S1���Ƶ�T��
        for(i=S1[0]-'0'+1;i<=MAXSTRING;i++)
            T[i] = S2[i-S1[0]];   //��S2���ӵ�S1����
        T[0] = MAXSTRING;
        uncut = FALSE;

    }
    else          // �ضϣ���ȡS1��
    {
        for(i=0;i<=MAXSTRING;i++)
            T[i] = S1[i]; //T[0] == S1[0] ==MAXSTRING
        uncut = FALSE;
    }
    return uncut;
}


Status SubString(SString &Sub,SString S, int pos,int len)
{
    //��Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ���
    //���У�1<=pos<=StrLength(S)��0<=len<=StrLength(S)-pos+1��
    int i;
    if(pos<1||pos>S[0]-'0'||len<0||len>S[0]-'0'-pos+1)   //�ж�pos��λ�ã��Ƿ���ȷ
        return ERROR;
      for(i=1;i<=len;i++)
        Sub[i] = S[pos-1+i];   //���Ƶ�Sub
    Sub[0] ='0'+len;   //�����ַ�������

    return OK;
}  //SubString


int Index(SString S,SString T,int pos)
{
//������S�е�pos���ַ�֮�������T��ȵ��Ӵ�
//�򷵻ص�һ���������Ӵ���S�е�λ�ã����򷵻�0
    int i;
    SString Sub;
    if(pos>0)
    {
        i = pos;
        while(i<=S[0]-T[0]+1)
        {
            SubString(Sub,S,i,T[0]-'0');
         if(StrCompare(Sub,T)!=0)
                i++;
            else
                return i;      //�����Ӵ��������е�λ��

        }
    }
    return 0;              //S�в�������T��ȵ��Ӵ�
}


void get_next(SString T,int next[]){
//��ģʽ��T��next����ֵ����������next
 int i,j;
 i = 1;
 next[1] = 0;
 j = 0;
 while(i<T[0]-'0'){
    if(j==0||T[i]==T[j]){
        i++;
        j++;
        next[i]= j;
    }
    else
        j = next[j];
 }
}//get_next


int Index_KMP(SString S,SString T,int pos,int next[]){
int i,j;
 i = pos;
 j = 1;
 while(i<=S[0]-'0'&&j<=T[0]-'0'){
    if(j == 0 ||S[i] == T[j]){
        i++;
        j++;
    }
    else
        j = next[j];
 }
 if(j>T[0]-'0')
    return i-(T[0]-'0');
  else
    return 0;
}


Status Replace(SString &S,SString T,SString V)
{
//��V�滻����S�г��ֵ�������T��ȵĲ��ص����Ӵ�
//����KMP�㷨
    int next[MAXSTRING],pos;
    pos = 1;
    if(S[0]-'0'==0||T[0]-'0'==0||V[0]-'0'==0)
        return ERROR;   //������Ϊ��
    get_next(T,next); //��ȡnext����
     while(pos<=S[0]-'0'-(T[0]-'0')){

   pos = Index_KMP(S,T,pos,next);
  StrDelete(S,pos,T[0]-'0');
   StrInsert(S,pos,V);
    if(!pos) break;
    pos = pos + T[0]-'0';
   }
   return OK;
}


Status StrInsert(SString &S,int pos,SString T)
{
//���봮T
   int i;
    if(pos<1||pos>S[0]-'0'+1)
        return ERROR;
    else
    {
        if(S[0]-'0'+T[0]-'0'<MAXSTRING)   //δ��ȡ
        {
            for(i=S[0]-'0'; i>=pos; i--)
            {
                S[T[0]-'0'+i] = S[i];  //��posλ��������T�ĳ���
            }
            for(i=0; i<T[0]-'0'; i++)
                S[pos+i] = T[1+i];   //����
            S[0]+=T[0]-'0';    //���¼����ַ�������
        }

        else
        {
//S��ȡ
            if(MAXSTRING-pos+1>=T[0]-'0')
            {
                for(i=MAXSTRING-T[0]+'0'; i>=pos; i--)
                {
                    S[T[0]+i] = S[i];  //��posλ��������T�ĳ���
                }
                for(i=0; i<T[0]-'0'; i++)
                    S[pos+i] = T[1+i];   //����
                S[0]=MAXSTRING;
            }//S����ȡ
            else  //T����ȡ
            {
                for(i=pos; i<=MAXSTRING; i++)
                    S[i] = T[i-pos+1];
                S[0]=MAXSTRING;
            }
        }

    }
}



Status StrDelete(SString &S, int pos,int len)
{
    int i;
    if(pos<1||pos>S[0]-'0'-len+1)
        return ERROR;
    for(i=pos; i<=S[0]; i++)
        S[i] = S[i+len];
    S[0]-=len;

}


