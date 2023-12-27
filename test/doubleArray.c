/*将二维数组翻转 行和列互换*/


#include <stdio.h>

#define ROW 3
#define COLUMN 3

int main()
{
    int array[ROW][COLUMN] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int num = 0;
    int count = 0;
    /*打印原来的数组*/
    for (int row = 0; row < ROW; row++)
    {
        for (int col = 0; col < COLUMN; col++)
        {
            printf("array[%d][%d]%d\n", row, col, array[row][col]);
            count++;
            if (count % 3 == 0)
            {
                printf("\n");
            }
        }
    }

    /*将行和列互换*/
    for (int row = 0; row < ROW; row++)
    {
        for (int col = row; col < COLUMN; col++)
        {
            num = array[row][col];
            array[row][col] = array[col][row];
            array[col][row] = num;
        }
    }
    /*打印互换后的数组*/
    for (int row = 0; row < ROW; row++)
    {
        for (int col = 0; col < COLUMN; col++)
        {
            printf("array[%d][%d] %d\n", row, col, array[row][col]);
            count++;
            if (count % 3 == 0)
            {
                printf("\n");
            }
        }
    }

    return 0;
}