#ifndef __TEST_STRING_H_
#define __TEST_STRING_H_


/*strlen 获取字符串的长度*/
int myStrlen(const char *ptr);


/*strcpy 字符串的拷贝*/
char *myStrcpy(char *num1, const char *num2);

/*strcat 字符串的拼接*/
char *myStrcat(char *dest, const char *src);

/*strcmp字符串的比较*/
int myStrcmp(const char *ptr1, const char *ptr2);

#endif
