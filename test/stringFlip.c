/*输入一个字符串 删掉里面多余的空格 并且将其倒转输出*/

#include <stdio.h>
#include <string.h>

#define BUFFER_SIEZE 30

/*将整个字符串倒转*/
#if 0
void reverse1(char *newary)
{
    int len = strlen(newary); // 求定义数组的长度
    int temp = 0;             // 中间值
    char *right = newary + len - 1;
    char *left = newary;
    while (left <= right)
    {
        temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}

#endif

/*将字符串倒转*/
#if 0
void reverse(char *newary, int start, int end)
{
    // int len = strlen(newary);   //求定义数组的长度
    int temp = 0; // 中间值
    end = end - 1;
    while (start <= end)
    {
        temp = newary[start];
        newary[start] = newary[end];
        newary[end] = temp;
        start++;
        end--;
    }
}

#endif


/*删除空格*/
void deleteSpace(char *ary)
{
    int len = strlen(ary);   
    char pstr = 0;                                // 判断是不是空格
    char count = 0;                               //接不是空格的元素和第一个空格

    /*判断是空格 或者前一个是不是空格*/
    while (pstr < len)
    {
        if (ary[pstr] == ' ')
        {
            if (ary[pstr - 1] != ' ')
            {
                ary[count++] = ary[pstr++];
            }
            else
            {
                pstr++;
            }
        }
        else
        {
            ary[count++] = ary[pstr++];
        }
    }

/*将‘/0’ 赋值给最后一个字符的后一个 （删除最后的空格）*/
    if (ary[count - 1] == ' ')
    {
        count--;
    }
    ary[count] = '\0';
}

int main()
{
#if 1
     int end = 0;
    int start = 0;
    char array[BUFFER_SIEZE] = "i   am   from   china  ";
    deleteSpace(array); 
    int len = strlen(array); 

    /*将消除多余空格后的字符串里面的每一个单词进行翻转*/
    for(end = 0; end <= len; end++)
    {
        if(array[end] == '\0' || array[end] == ' ')
        {
            // reverse(array,start,end);
            reverse1(array);
            start = end + 1; 
        }
    }
     
     reverse(array,0,len);
     printf("%s\n", array);
#endif

#if 0
    char array[BUFFER_SIEZE] = "i   am   from   china  ";
    deleteSpace(array);
    reverse1(array);
    int idx = 0;
    int count = 0;
    int len = strlen(array);
    for (idx = 0; idx <= len; idx++)
    {
        if (array[idx] == ' ' )
        {
            array[count++] = array[idx++];
        }
        else
        {
            idx++;
        }
    }
    printf("array :%s\n",array);

#endif       
 return 0;
}