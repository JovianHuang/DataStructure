#include "HuffmanTree.h"

void Huffmanfileout(HFTree &HF)//���ļ��ж��������ַ�����Ȩֵ
{
    int a=1;
    FILE *fp;
    HF=(HFTree)malloc((27)*sizeof(HFNode));
    if((fp=fopen("Huffman1.txt","r"))==NULL)
    {
        printf("open the file is error!\n");
        exit(0);
    }
    while(!feof(fp))//���ļ���ȡ����
    {
        fscanf(fp,"%c %d\n",&HF[a].ch,&HF[a].weight);
        a++;
    }
//    for(i=1; i<a; i++)
//    {
//        printf("%c %d\n",HF[i].ch,HF[i].weight);
//    }
    fclose(fp);//�ر��ļ�
}

Status HuffmanCreat(HuffmanTree &HT,HFTree HF,int n)//������������
{
    int m,i,s1,s2;
    if(n<=1)
        return OK;
    m=2*n-1;
    HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));//0�ŵ�Ԫδ��
    for(i=1; i<=n; i++) //��HT��ÿ�����Ȩֵ��ֵ���ҷֱ�����Һ��Ӽ�˫�׳�ʼ��
    {
        HT[i].weight=HF[i].weight;
        HT[i].parent=0;
        HT[i].lchild=0;
        HT[i].rchild=0;
    }
    for(; i<=m; i++) //������Ҷ�ӽ�����������ʼ��
    {
        HT[i].weight=0;
        HT[i].parent=0;
        HT[i].lchild=0;
        HT[i].rchild=0;
    }
    for(i=n+1; i<=m; i++) //���ս��
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

void Select(HuffmanTree &HT,int k,int &s1,int &s2)//Ѱ��parentΪ0��Ȩֵ��С���������
{
    int i;
    for(i=1; HT[i].parent!=0; i++);
    s1=i;
    for(i=1; i<k; i++)
    {
        if(HT[i].parent==0&&HT[i].weight<HT[s1].weight)
        {
            s1=i;//����Сֵ����s1
        }
    }
    HT[s1].parent=k;
    for(i=1; HT[i].parent!=0; i++);
    s2=i;
    for(i=1; i<k; i++)
    {
        if(HT[i].parent==0&&i!=s1&&HT[i].weight<HT[s2].weight)
        {
            s2=i;//�ѳ�s1����Сֵ����s2
        }
    }
}

void HuffmanCoding(HuffmanTree HT,HuffmanCode &HC,HFTree HF,int n)//ʵ��n���ַ��ĺշ�������
{
    char* cd;
    int i,start,c,f;
    HC=(HuffmanCode)malloc((n+1)*sizeof(char*));//����n���ַ������ͷָ������
    cd=(char*)malloc(n*sizeof(char));//���������Ĺ����ռ�
    cd[n-1]='\0';//���������
    for(i=1; i<=n; ++i)
    {
        start=n-1;
        for(c=i,f=HT[i].parent; f!=0; c=f,f=HT[f].parent) //��Ҷ�ӵ������������;f!=0,f���Ǹ��ڵ�ĸ���
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
        HC[i]=(char*)malloc((n-start)*sizeof(char));//Ϊ��i���ַ��������ռ�
        strcpy(HC[i],&cd[start]);//��cd���Ʊ��뵽HC
    }
    free(cd);//�ͷŹ����ռ�
    for(i=1; i<=n; i++)
    {
        printf("%c %s",HF[i].ch,HC[i]);
        printf("\n");
    }
}

void DecodingHuffmancode(HuffmanTree HT,HFTree HF,char code[],int len,char *result,int n)//ʵ��n���ַ��ĺշ�������
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
        if(p<=n)//p<=n�����pΪҶ�ӽڵ㣬��Ϊ�ڹ����շ�����HTʱ��HT��m���ڵ���ǰn���ڵ�ΪҶ�ӽڵ�
        {
            result=(char*)malloc(10*sizeof(HFNode));
            result[j]=HF[p].ch;
            j++;
            p=2*n-1;//p����ָ����ڵ�
        }
        i++;
    }
    result[j]='\0';
    printf("%s\n",result);
}





