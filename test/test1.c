/* 定义一个目标数然后 得到是那两个数的相加的到 并且得到两个数的下标  */
#include <stdio.h>
#include <stdlib.h>


int main()
{
    int len; // 数组的长度
    int target = 0;
    printf("输入相加的目标和: \n");
    scanf("%d", &target);

    printf("输入的数组长度: \n");
    scanf("%d", &len);
    int *ptr = (int *)malloc(sizeof(int) * len); // 动态分配数组长度  指针即数组
    free(ptr);

    printf("输入的元素: \n");
    for (int idx = 0; idx < len; idx++)
    {
        scanf("%d", ptr + idx); // 键盘输入数组里面的元素
    }

    for (int idx = 0; idx < len; idx++) // 第一个数的遍历
    {
        for (int sub = 1; sub < len; sub++) // 第二个数的遍历
        {

            if (target == *(ptr + idx) + *(ptr + sub) && idx < sub)
            {
                printf("idx %d , sub %d\n", idx, sub); // 输出的是数组下标
            }
        }
    }

    return 0;
  
    
}
