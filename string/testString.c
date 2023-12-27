#include "testString.h"
/*strlen*/
int myStrlen(const char *ptr)
{
    int count = 0;
    // if (ptr == NULL)
    if (!ptr)
    {
        return count;
    }
    const char *temPtr = ptr;
    while (*temPtr != '\0')
    {
        count++;
        temPtr++;
    }
    return count;
}
/*strcpy*/
char *myStrcpy(char *num1, const char *num2)

{

    if (!num2 || !num1 )
    {
        return 0;
    }
    char *myptr = num1;
    while  (*num2 != '\0')
    {
        *num1 = *num2;
        num1++;
        num2++;
    }
    return myptr;
}

/*strcat*/
char *myStrcat(char *dest, const char *src)
{


    
    // if (ptr == NULL)
    // if (!dest || !src)
    // {
    //     return 0;
    // }
    char *ptrs = dest;
    while (*dest)
    {
        dest++;
    }
    while (*dest++ = *src++)
    {
    }
    return ptrs;
}
/*strcmp*/
int myStrcmp(const char *ptr1, const char *ptr2)
{

    int count = 0;
    // if (ptr == NULL)
    if (!ptr1 || !ptr2)
    {
        return count;
    }
    while (*ptr1 == *ptr2)
    {
        *ptr1++;
        *ptr2++;
    }
    if (*ptr1 > *ptr2)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
