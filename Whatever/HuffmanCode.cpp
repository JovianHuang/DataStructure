#include "HuffmanCode.h"

Status ReadFromFile_weight()
{
    MumAndWeight Inf[26];
    int i;
    FILE *fp;
    if((fp=fopen("Weight.txt","r"))==NULL)
    {

        printf("File open error!");
        exit(0);
    }
    for(i=0; i<26; i++)
    {
        fscanf(fp,"%c ",&Inf[i].data);
        fscanf(fp,"%d ",&Inf[i].weight);


    }
    fclose(fp);
    for(i=0; i<26; i++)
    {


        printf("%c%d ",Inf[i],Inf[i]);
    }

}
void Huffmancoding(HuffmanTree &HT,HuffmanCode &HC,MumAndWeight *w,int n)
{
//w存放了n个字符的权值(均>0)，构造赫夫曼树HT，并求出n个字符的赫夫曼编码HC。
    int m,s1,s2,i;
    HuffmanTree p;
    if (n<=1) return;
    m=2*n-1;
    HT = (HuffmanTree)malloc((m+1)*sizeof(HTNode));//0号单元未用
    for(p=HT,i=1; i<=n; ++i,++p,++w)
    {
        p->parent=0;
        p->lchild=0;
        p->rchild=0;
        p->weight=w->weight;
    }
    for(; i<m; ++i,++p)
    {
        p->parent=0;
        p->lchild=0;
        p->rchild=0;
        p->weight=0;


    }
    for(i=n+1; i<=m; ++i)
    {

        Select(HT,i-1,s1,s2);
        HT[s1].parent=i;
        HT[s2].parent=i;
        HT[i].lchild=s1;
        HT[i].rchild=s2;
        HT[i].weight = HT[s1].weight+HT[s2].weight;

    }
    /*===========从叶子到根逆向求每个字符的赫夫曼编码============*/
    char *cd;
    int start,f,c;
    HC = (HuffmanCode)malloc((n+1)*sizeof(char*));
    cd = (char*)malloc(n*sizeof(char));
    cd[n-1]='\0';
    for(i=1; i<=n; i++)
    {
        start=n-1;
        for(c=i,f=HT[i].parent; f!=0; c=f,f=HT[f].parent)
        {
            if(HT[i].lchild==c) cd[--start] = '0';
            else cd[--start] = '1';
        }
        HC[i]=(char*)malloc((n-start)*sizeof(char));
        strcpy(HC[i],&cd[start]);



    }




}
void Select(HuffmanTree HT,int n,int &s1,int &s2)
{
    int i,min1=99999,min2=99999;
    for(i=1; i<=n; i++)
    {
        if(HT[i].weight<min1&&HT[i].parent==0)
        {
            min1=HT[i].weight;
            s1=i;

        }
    }
    for(i=1; i<=n; i++)
    {
        if(HT[i].weight<min2&&HT[i].parent==0&&HT[i].weight!=min1)
        {
            min2=HT[i].weight;
            s2=i;
        }
    }
}
