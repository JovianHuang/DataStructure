#ifndef STRING_H
#define STRING_H
#define MAXSIZE 50
char *String_Create();					//������
int String_Length(char *s);				//�󴮳�
void String_Show(char *s);				//�����
char *String_Copy(char *d, char *s);	//������
char *String_Connect(char *d, char *s);	//������
char *String_SubStr(char *d, char *s, int pos, int len);	//���Ӵ�
int String_Compare(char *d, char *s);	//���Ƚ�
char *String_Insert(char *d, char *s, int pos);		//������
char *String_Delete(char *d, int pos, int len);		//��ɾ��
int String_Index(char *d, char *s, int pos);		//��ƥ��
#endif // STRING_H
