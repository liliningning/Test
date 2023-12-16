#include <stdio.h>
#include <string.h>

#define BUFFER_SIEZE 30

#if 0
void deleteSpace(char *newary)
{
    int idx = 0;
    int jdx = 0;
    for (idx = 0; newary[idx] != 32; idx++)
    {
        if (newary[idx] == 32 && newary[idx + 1] == 32)
        {
            for (jdx = idx; newary[jdx] != 32; jdx++)
            {

                if (newary[jdx] != 32)
                break;                
                    for(jdx; newary[jdx] != 32; jdx++)
                    {
                    newary[idx + 1] = newary[jdx];
                    idx++;
                    }
                }
            }
        }
    }

#endif

#if 1

/*将整个字符串倒转*/
void reverse(char *newary)
{
    int len = strlen(newary);   //求定义数组的长度
    int temp = 0;                //中间值
    char *left = newary;
    char *right = len + newary - 1;
    
    while (left < right)
    {
        temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}

#endif

int main()
{
    char array[BUFFER_SIEZE] = "i am from china";
    reverse(array);
    printf("%s\n", array);

    return 0;
}