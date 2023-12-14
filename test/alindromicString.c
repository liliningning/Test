#include <stdio.h>

int main()
{

    int len;
    printf("数组的长度：");
    scanf("%d", &len);
    char invert[len];
    char array[len];
    printf("array:");
    for (int idx = 0; idx < len; idx++)
    {
        scanf("%s", array + idx);
    }

    for (int idx = 0; idx < len; idx++)
    {

        invert[idx] = array[len - idx - 1];
        printf("%c\t", invert[idx]);

        // printf("%c\t",array[len - idx -1]);
    }
    printf("\n");
    return 0;
}
