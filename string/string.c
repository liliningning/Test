#include "testString.h"
#include <stdio.h>

#define BUFFER_SIEZ 20
#define BUFFER_SIEZ1 10

int main()
{
    char *ptr = "hello world";
    int len = myStrlen(ptr);
    printf("len %d\n", len);

    char num1[BUFFER_SIEZ] = {0};
    char num2[BUFFER_SIEZ1] = "hello";
    myStrcpy(num1, num2);
    printf("%s\n", num1);

    myStrcat(num1, num2);
    printf("%s\n", num1);

    char num3[BUFFER_SIEZ1] = "world";
    int ret = myStrcmp(num2, num3);
    printf("ret %d\n", ret);

    return 0;
    
}
