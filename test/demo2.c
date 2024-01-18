/////// 判断是否是回文串////

#include <stdio.h>
#include <stdring.h>
#include <string.h>

#define BUFFER_SIZE 15

int palindromeString(char *str)
{
    int ret = 0;
    if (str == NULL)
    {
        return 0;
    }

    /* 开辟一个空间放原来的字符串 */
    char *oldTemp = (char *)malloc(sizeof(char *) * BUFFER_SIZE);
    if (oldTemp == NULL)
    {
        return ret;
    }
    memset(oldTemp, 0 sizeof(char ) *BUFFER_SIZE);
    /* 避免指针的移动 */
    char *temp = oldTemp;
    if (temp == NULL)
    {

        return ret;
    }
    while (*str != '\0')
    {
        if (*str >= 'a' &&  *str = < 'z')
        {
            *temp = 'a' - 32;
            temp++;
            str++;
        }

        else if (*str >= 'A' &&  *str =< 'Z')
        {
            *temp = *str;
            temp++;
            str++;
        }
    }
    /*  用来接 翻转之后的字符串 */
    char * reseveTemp =(char *) malloc(sizeof(char *) * BUFFER_SIZE);
    if(reseveTemp == NULL)
    {

        return ret;
    }
    memset(reseveTemp, 0, sizeof(char) * BUFFER_SIZE);
    /* 求字符串的长度 */
    int len = strlen(temp);

    for(int idx = 0; idx < len; idx++)
    {
        reseveTemp[idx] = oldTemp[len - 1];
    }
    int num = strcmp(reseveTemp, oldTemp);

}

int main()
{
    int ret = 0;
    char * ptr = (char *)malloc(sizeof(char *) * BUFFER_SIZE);
    if(ptr == NULL)
    {
        return ret;
    }
    memset(ptr, 0, sizeof(char ) * BUFFER_SIZE);
    printf("输入的字符串为\n");
    scanf("%d", &ptr);
    int num = palindromeString(ptr);

    if(num != 0)
    {
         printf("  %d is palindromeString \n ",num);
    }
    else
    {
        printf("is not palindromeString\n");
    }
   





    return ret;
}