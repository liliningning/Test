/* 删除数组里面重复的元素 输出删除后的数组*/
#include <stdio.h>
#define BUFFER_SIEZ 7

int main()
{ /*出现的次数*/
    int targent = 0;
    int array[BUFFER_SIEZ] = {1, 1, 2, 3, 3, 4, 5};
    int len = BUFFER_SIEZ;
    /*循环 让后一个与前一个进行比较 */
    for (int idx = 1; idx < len; idx++)   
    {

        if (array[idx - 1] == array[idx])
        {
            targent++;
            len--;
            /*从idx的位置开始往后移*/
            for (int sub = idx; sub < len; sub++)
            {
                /*删除重复的 让后一个的值赋给前一个*/
                array[sub] = array[sub + 1];
            }
        }
    }

    for (int idx = 0; idx < len; idx++)
    {
        printf("%d\n", array[idx]);
    }
    return 0;

    
}