/* 删除数组里面重复的元素 输出删除后的数组*/
#include <stdio.h>
#define BUFFER_SIEZ 7

int main()

{ 

#if 1
    /*出现的次数*/
    int targent = 0;
    int array[BUFFER_SIEZ] = {1, 1, 2, 3, 3, 5, 5};
    int len = BUFFER_SIEZ;
    /*循环 让后一个与前一个进行比较 */
    for (int idx = 1; idx < len ; idx++)
    {

        if (array[idx - 1] == array[idx])
        {
            targent++;
        }

        /* 根据重复出现的次数 来判断后面的数往前的位次*/
        array[idx - targent] = array[idx];
    }

    len -= targent;

    for (int idx = 0; idx < len; idx++)
    {
        printf("%d\n", array[idx]);
    }

#endif

#if 0

    int targent = 0;
    int len;
    printf("数组的长度：");
    scanf("%d", &len);

    int array[len];
    printf("输入的数组：");
    for (int idx = 0; idx <len;idx++)
    {
          scanf("%d", array + idx ); 
    }
    for (int idx = 1; idx < len; idx++)
    {

        if (array[idx - 1] == array[idx])
        {
            targent++;
        }

        /* 根据重复出现的次数 来判断后面的数往前的位次*/
        array[idx - targent] = array[idx];
    }

    len -= targent;

    for (int idx = 0; idx < len; idx++)
    {
        printf("%d\n", array[idx]);
    }

#endif
    return 0;
}