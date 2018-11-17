#ifndef STRING_H
#define STRING_H
#define MAXSIZE 50
char *String_Create();					//创建串
int String_Length(char *s);				//求串长
void String_Show(char *s);				//输出串
char *String_Copy(char *d, char *s);	//串复制
char *String_Connect(char *d, char *s);	//串连接
char *String_SubStr(char *d, char *s, int pos, int len);	//求子串
int String_Compare(char *d, char *s);	//串比较
char *String_Insert(char *d, char *s, int pos);		//串插入
char *String_Delete(char *d, int pos, int len);		//串删除
int String_Index(char *d, char *s, int pos);		//串匹配
#endif // STRING_H
