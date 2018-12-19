#include "HuffmanTree.h"

void Huffmanfileout(HFTree &HF)//从文件中读出各个字符及其权值
{
    int a=1;
    FILE *fp;
    HF=(HFTree)malloc((27)*sizeof(HFNode));
    if((fp=fopen("Huffman1.txt","r"))==NULL)
    {
        printf("open the file is error!\n");
        exit(0);
    }
    while(!feof(fp))//从文件读取数据
    {
        fscanf(fp,"%c %d\n",&HF[a].ch,&HF[a].weight);
        a++;
    }
//    for(i=1; i<a; i++)
//    {
//        printf("%c %d\n",HF[i].ch,HF[i].weight);
//    }
    fclose(fp);//关闭文件
}

Status HuffmanCreat(HuffmanTree &HT,HFTree HF,int n)//建立哈夫曼树
{
    int m,i,s1,s2;
    if(n<=1)
        return OK;
    m=2*n-1;
    HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));//0号单元未用
    for(i=1; i<=n; i++) //给HT中每个结点权值赋值，且分别给左右孩子及双亲初始化
    {
        HT[i].weight=HF[i].weight;
        HT[i].parent=0;
        HT[i].lchild=0;
        HT[i].rchild=0;
    }
    for(; i<=m; i++) //给除了叶子结点的其他结点初始化
    {
        HT[i].weight=0;
        HT[i].parent=0;
        HT[i].lchild=0;
        HT[i].rchild=0;
    }
    for(i=n+1; i<=m; i++) //最终结果
    {
        Select(HT,i,s1,s2);
        HT[s1].parent=i;
        HT[s2].parent=i;
        HT[i].lchild=s1;
        HT[i].rchild=s2;
        HT[i].weight=HT[s1].weight+HT[s2].weight;
    }
    for(i=1; i<=m; i++)
    {
        printf("%d \n",HT[i].weight);
    }
    return OK;
}

void Select(HuffmanTree &HT,int k,int &s1,int &s2)//寻找parent为0，权值最小的两个结点
{
    int i;
    for(i=1; HT[i].parent!=0; i++);
    s1=i;
    for(i=1; i<k; i++)
    {
        if(HT[i].parent==0&&HT[i].weight<HT[s1].weight)
        {
            s1=i;//把最小值赋给s1
        }
    }
    HT[s1].parent=k;
    for(i=1; HT[i].parent!=0; i++);
    s2=i;
    for(i=1; i<k; i++)
    {
        if(HT[i].parent==0&&i!=s1&&HT[i].weight<HT[s2].weight)
        {
            s2=i;//把除s1外最小值赋给s2
        }
    }
}

void HuffmanCoding(HuffmanTree HT,HuffmanCode &HC,HFTree HF,int n)//实现n个字符的赫夫曼编码
{
    char* cd;
    int i,start,c,f;
    HC=(HuffmanCode)malloc((n+1)*sizeof(char*));//分配n个字符编码的头指针向量
    cd=(char*)malloc(n*sizeof(char));//分配求编码的工作空间
    cd[n-1]='\0';//编码结束符
    for(i=1; i<=n; ++i)
    {
        start=n-1;
        for(c=i,f=HT[i].parent; f!=0; c=f,f=HT[f].parent) //从叶子到根逆向求编码;f!=0,f不是根节点的父亲
            if(HT[f].lchild==c)
            {
                --start;
                cd[start]='1';
            }
            else
            {
                --start;
                cd[start]='0';
            }
        HC[i]=(char*)malloc((n-start)*sizeof(char));//为第i个字符编码分配空间
        strcpy(HC[i],&cd[start]);//从cd复制编码到HC
    }
    free(cd);//释放工作空间
    for(i=1; i<=n; i++)
    {
        printf("%c %s",HF[i].ch,HC[i]);
        printf("\n");
    }
}

void DecodingHuffmancode(HuffmanTree HT,HFTree HF,char code[],int len,char *result,int n)//实现n个字符的赫夫曼译码
{
    int i=0,j=0,p=2*n-1;
    while(i<len)
    {
        if(code[i]=='0')
        {
            p=HT[p].rchild;
        }
        if(code[i]=='1')
        {
            p=HT[p].lchild;
        }
        if(p<=n)//p<=n则表明p为叶子节点，因为在构建赫夫曼树HT时，HT的m个节点中前n个节点为叶子节点
        {
            result=(char*)malloc(10*sizeof(HFNode));
            result[j]=HF[p].ch;
            j++;
            p=2*n-1;//p重新指向根节点
        }
        i++;
    }
    result[j]='\0';
    printf("%s\n",result);
}





