#include "SString.h"

void Interface(void){  //������
    int option,pos,col,len;
    SString S,T,V;
    char chars[256];
    while(1){
            MainMenu();//�˵�
    scanf("%d",&option);   //����ѡ��
    if(!option) break;   //0Ϊ�˳�
    switch(option){
 case 1:   //ֱ������
          printf("�������ַ���\n");
          getchar();
          Mygets(chars);
          StrAssign(S,chars);
          Menu();
          scanf("%d",&option); //�ٴ�ѡ��
          switch(option){
      case 1:printf("�����������в���\n");
             printf("�У�");
             scanf("%d",&col);
             printf("������Ҫ������ַ���\n");
             printf("�ַ�����");
             getchar();
             Mygets(chars);
             StrAssign(T,chars);
             StrInsert(S,col,T);
             Output(S);
             break;
      case 2:printf("�����������п�ʼɾ��\n");
             printf("�У�");
             scanf("%d",&col);
             printf("������Ҫɾ���ĳ���\n");
             printf("���ȣ�");
             scanf("%d",&len);
             StrDelete(S,col,len);
             Output(S);
             break;

      case 3:printf("������Ҫ���ҵ��ַ���\n");
             printf("�ַ�����");
             getchar();
             Mygets(chars);
             StrAssign(T,chars);
             pos = Index(S,T,1);//��һ���ַ�
             printf("%d,",pos);
             break;
      case 4:printf("�����뱻�滻���ַ���\n");
             printf("�ַ�����");
             getchar();
             Mygets(chars);
             StrAssign(T,chars);
             printf("�����������ַ���\n");
             printf("�ַ�����");
             Mygets(chars);
             StrAssign(V,chars);
             Replace(S,T,V);
             Output(S);
             break;
      case 5:printf("�����������п�ʼ����\n");
             printf("�У�");
             scanf("%d",&col);
             printf("������Ҫ���Ƶĳ���\n");
             printf("���ȣ�");
             scanf("%d",&len);
             StrCopy(T,S,col,len);
             Output(T);
             break;

          }
          break;//case 1
// case 2:  //���ļ���ȡ

     }//switch
    }//while
}


void Mygets(char chars[]){
//�Զ���Ļ�ȡ�ַ�
  int len;
  fgets(chars,255,stdin);
  len = strlen(chars);
   chars[len-1] = '\0';
}

void Output(SString S){
//��ʾ�ַ���
  int i;
 for(i=1;i<=S[0]-'0';i++)
    printf("%c",S[i]);
  printf("\n");
}

void Fread(SString S){
//���ļ��ж�ȡ

}

void MainMenu(void){
printf("***************\n");
printf("1.�µ��ַ���\n"); //��������
printf("2.�����ַ���\n"); //���ļ���ȡ
printf("***************\n");
}


void Menu(void){
printf("***************\n");
printf("1.����\n");
printf("2.ɾ��\n");
printf("3.����\n");
printf("4.�滻\n");
printf("5.����\n");
printf("6.��ʾ\n");
printf("7.ͳ��\n");
printf("8.�ƶ�\n");
printf("***************\n");
}
