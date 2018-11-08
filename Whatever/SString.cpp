#include "SString.h"

Status StrAssign(SString &T, char chars[])
{
    // 生成一个其值等于chars的串T
    int i;
    if(strlen(chars)>MAXSTRING)
        return ERROR;   //判断有无超定义域
    else
    {
        for(i=1;i<=strlen(chars);i++)
        T[i] = chars[i-1]; //复制
    }
    T[0] = '0'+i-1;    //计字符个数
 return OK;
}


Status StrCopy(SString &T,SString S,int pos,int len)
{
    //由串S复制得串T
    int i;
    if(S[0]-'0'>MAXSTRING) return ERROR;    //判断S[0],有无存储错误
    else
    {
        for(i=1;i<=len;i++)   //复制
          T[i] = S[pos-1+i];
    }
     T[0]='0'+len;
  return OK;
}


Status StrEmpyt(SString S){
//判断是否为空
    if(S[0]=='0')
        return OK;
    else
        return ERROR;
}


int StrCompare(SString S, SString T)
{
//比较大小
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
//算长度
    return S[0]-'0';
}


Status ClearString(SString &S)
{
//将S清为空
    S[0] = '0';
    return OK;
}


Status Concat(SString &T,SString S1,SString S2)
{
//用T返回由S1和S2联接而成的新串。若未截断，则返回TURE，否则返回FALSE。
    int i,uncut;
    if(S1[0]-'0'+S2[0]-'0'<=MAXSTRING)   //为截断
    {
        for(i=1;i<=S1[0]-'0';i++)
           T[i] = S1[i];        //把S1复制到T中
           for(i=1;i<=S2[0]-'0';i++)
            T[S1[0]+i] = S2[i];   //把S2连接到S1后面
         T[0] = S1[0]+S2[0]-'0';   //计算连接后的字符数
        uncut = TRUE;
    }
    else if(S1[0]<MAXSTRING)   //截断
    {
         for(i=1;i<=S1[0]-'0';i++)
           T[i] = S1[i];        //把S1复制到T中
        for(i=S1[0]-'0'+1;i<=MAXSTRING;i++)
            T[i] = S2[i-S1[0]];   //把S2连接到S1后面
        T[0] = MAXSTRING;
        uncut = FALSE;

    }
    else          // 截断（仅取S1）
    {
        for(i=0;i<=MAXSTRING;i++)
            T[i] = S1[i]; //T[0] == S1[0] ==MAXSTRING
        uncut = FALSE;
    }
    return uncut;
}


Status SubString(SString &Sub,SString S, int pos,int len)
{
    //用Sub返回串S的第pos个字符起长度为len的子串。
    //其中，1<=pos<=StrLength(S)且0<=len<=StrLength(S)-pos+1。
    int i;
    if(pos<1||pos>S[0]-'0'||len<0||len>S[0]-'0'-pos+1)   //判断pos的位置，是否正确
        return ERROR;
      for(i=1;i<=len;i++)
        Sub[i] = S[pos-1+i];   //复制到Sub
    Sub[0] ='0'+len;   //计入字符串长度

    return OK;
}  //SubString


int Index(SString S,SString T,int pos)
{
//若主串S中第pos个字符之后存在与T相等的子串
//则返回第一个这样的子串在S中的位置，否则返回0
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
                return i;      //返回子串在主串中的位置

        }
    }
    return 0;              //S中不存在于T相等的子串
}


void get_next(SString T,int next[]){
//求模式串T的next函数值并存入数组next
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
//用V替换主串S中出现的所有与T相等的不重叠的子串
//下面KMP算法
    int next[MAXSTRING],pos;
    pos = 1;
    if(S[0]-'0'==0||T[0]-'0'==0||V[0]-'0'==0)
        return ERROR;   //串各不为空
    get_next(T,next); //获取next函数
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
//插入串T
   int i;
    if(pos<1||pos>S[0]-'0'+1)
        return ERROR;
    else
    {
        if(S[0]-'0'+T[0]-'0'<MAXSTRING)   //未截取
        {
            for(i=S[0]-'0'; i>=pos; i--)
            {
                S[T[0]-'0'+i] = S[i];  //在pos位置往后移T的长度
            }
            for(i=0; i<T[0]-'0'; i++)
                S[pos+i] = T[1+i];   //插入
            S[0]+=T[0]-'0';    //重新计算字符串长度
        }

        else
        {
//S截取
            if(MAXSTRING-pos+1>=T[0]-'0')
            {
                for(i=MAXSTRING-T[0]+'0'; i>=pos; i--)
                {
                    S[T[0]+i] = S[i];  //在pos位置往后移T的长度
                }
                for(i=0; i<T[0]-'0'; i++)
                    S[pos+i] = T[1+i];   //插入
                S[0]=MAXSTRING;
            }//S被截取
            else  //T被截取
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


