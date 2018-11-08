#include "SString.h"

void Interface(void){  //主界面
    int option,pos,col,len;
    SString S,T,V;
    char chars[256];
    while(1){
            MainMenu();//菜单
    scanf("%d",&option);   //输入选项
    if(!option) break;   //0为退出
    switch(option){
 case 1:   //直接输入
          printf("请输入字符串\n");
          getchar();
          Mygets(chars);
          StrAssign(S,chars);
          Menu();
          scanf("%d",&option); //再次选择
          switch(option){
      case 1:printf("请输入在哪列插入\n");
             printf("列：");
             scanf("%d",&col);
             printf("请输入要插入的字符串\n");
             printf("字符串：");
             getchar();
             Mygets(chars);
             StrAssign(T,chars);
             StrInsert(S,col,T);
             Output(S);
             break;
      case 2:printf("请输入在哪列开始删除\n");
             printf("列：");
             scanf("%d",&col);
             printf("请输入要删除的长度\n");
             printf("长度：");
             scanf("%d",&len);
             StrDelete(S,col,len);
             Output(S);
             break;

      case 3:printf("请输入要查找的字符串\n");
             printf("字符串：");
             getchar();
             Mygets(chars);
             StrAssign(T,chars);
             pos = Index(S,T,1);//第一个字符
             printf("%d,",pos);
             break;
      case 4:printf("请输入被替换的字符串\n");
             printf("字符串：");
             getchar();
             Mygets(chars);
             StrAssign(T,chars);
             printf("请输入代替的字符串\n");
             printf("字符串：");
             Mygets(chars);
             StrAssign(V,chars);
             Replace(S,T,V);
             Output(S);
             break;
      case 5:printf("请输入在哪列开始复制\n");
             printf("列：");
             scanf("%d",&col);
             printf("请输入要复制的长度\n");
             printf("长度：");
             scanf("%d",&len);
             StrCopy(T,S,col,len);
             Output(T);
             break;

          }
          break;//case 1
// case 2:  //从文件读取

     }//switch
    }//while
}


void Mygets(char chars[]){
//自定义的获取字符
  int len;
  fgets(chars,255,stdin);
  len = strlen(chars);
   chars[len-1] = '\0';
}

void Output(SString S){
//显示字符串
  int i;
 for(i=1;i<=S[0]-'0';i++)
    printf("%c",S[i]);
  printf("\n");
}

void Fread(SString S){
//从文件中读取

}

void MainMenu(void){
printf("***************\n");
printf("1.新的字符串\n"); //现在输入
printf("2.已有字符串\n"); //从文件读取
printf("***************\n");
}


void Menu(void){
printf("***************\n");
printf("1.插入\n");
printf("2.删除\n");
printf("3.查找\n");
printf("4.替换\n");
printf("5.复制\n");
printf("6.显示\n");
printf("7.统计\n");
printf("8.移动\n");
printf("***************\n");
}
