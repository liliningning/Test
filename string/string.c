#include "testString.h"
#include <stdio.h>
#include <string.h>

#define BUFFER_SIEZ 6
#define BUFFER_SIEZ1 7

int main()
{
 #if 0
    int len = 0;
    char *ptr = "hello\0  world";
    //char *ptr = NULL;
    // len = strlen(ptr);  //系统函数
    len = myStrlen(ptr);
    printf("len %d\n", len);
#endif
#if 1
    char num1[BUFFER_SIEZ] = {0};
    char num2[BUFFER_SIEZ1] = "hello";
    myStrcpy(num1, num2);
    printf("%s\n", num1);
#endif

#if 0
    myStrcat(num1, num2);
    printf("%s\n", num1);
#endif
#if 1
    char num3[BUFFER_SIEZ1] = "world";
    int ret = myStrcmp(num2, num3);
    printf("ret %d\n", ret);
#endif







    return 0;
}
