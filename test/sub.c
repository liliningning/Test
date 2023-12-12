#include <stdio.h>
#include <stdlib.h>
int main()
{
    int targent = 0;
    printf("targent: \n");
    scanf("%d", &targent);

    int len;
    printf("输入数组元素的个数: \n");
    scanf("%d", &len);

    int *ptr = (int *)malloc(sizeof(int) * len);
    free(ptr);

    printf("输入的元素：\n");
    for (int idx = 0; idx < len; idx++)
    {
        scanf("%d", ptr + idx);
    }

    for (int idx = 0; idx < len; idx++)
    {
        for (int sub = 1; sub < len; sub++)
        {
            if (targent == *(ptr + idx) + *(ptr + sub) && idx < sub)
            {
                printf("idx %d  sub %d\n", idx, sub);
            }
        }
    }
    return 0;
    
}