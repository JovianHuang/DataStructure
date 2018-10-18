#include "File.h"

void Filein(int maze[N][N])
{
    FILE *fp;
    int i,j;
    fp=fopen("Mazein.txt","r");
    if(fp==NULL)
    {
        printf("open file error!");
        exit(0);
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {fscanf(fp,"%d",maze[i][j]);}
    }
    printf("read success!");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        { printf("%d",maze[i][j]);}
    }

}
