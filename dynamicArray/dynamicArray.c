#include "dynamicArray.h"
#include <stdlib.h>
#include <string.h>

#define DEFAULT_SIZE 10

#define CHECK_PTR(ptr)   \
    do                   \
    {                    \
        if (ptr == NULL) \
        {                \
            exit(0);     \
        }                \
    } while (0)

enum TATUS_CODE
{
    ON_SUCCESS,
    ON_ERROR,
    MALLOC_ERROR,

};

// 动态数组扩容函数
static int expandCapacity(dynamicArray *pArray);

// 动态数组的缩容
static int shrinkCapacity(dynamicArray *pArray);

// 动态数组的初始化
int dynamicArrayInit(dynamicArray *pArray, int capacity)
{
    // 判空
    CHECK_PTR(pArray);
    // 避免越界
    if (capacity < 0)
    {
        capacity = DEFAULT_SIZE;
    }
    pArray->data = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * capacity);
    if (pArray->data == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(pArray->data, 0, sizeof(pArray->data));
    pArray->len = 0;
    pArray->capacity = capacity;
    return ON_SUCCESS;
}

// 动态数组的扩容
static int expandCapacity(dynamicArray *pArray)
{

    // 需要扩多少容量
    int needExpandCapacity = pArray->capacity + (pArray->capacity >> 1);

    ELEMENTTYPE *temp = pArray->data;
    // 开辟一个新的空间
    pArray->data = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * needExpandCapacity);
    if (pArray->data == NULL)
    {
        return MALLOC_ERROR;
    }
    // 备份之前的数据
    for (int idx = 0; idx < pArray->len; idx++)
    {
        pArray->data[idx] = temp[idx];
    }
    // 释放内存 防止内存泄漏
    if (temp != NULL)
    {
        free(temp);
        temp = NULL;
    }
    // 更新容量
    pArray->capacity = needExpandCapacity;
}

// 动态数组的插入 (默认在末尾插入)
int dynamicArrayInsertData(dynamicArray *pArray, ELEMENTTYPE val)
{
    dynamicArrayAppointPosInsertData(pArray, pArray->len, val);
}
// 动态数组指定位置的插入
int dynamicArrayAppointPosInsertData(dynamicArray *pArray, int pos, ELEMENTTYPE val)
{
    // 判空
    CHECK_PTR(pArray);
    // 判断越界
    if (pos > pArray->len || pos < 0)
    {
        return DEFAULT_SIZE;
    }
    // 判断是否需要扩容
    if (pArray->capacity < ((pArray->len) + (pArray->len >> 1)))
    {
        expandCapacity(pArray);
    }
    // 数据往后移
    for (int idx = pArray->len; idx > pos; idx--)
    {
        pArray->data[idx] = pArray->data[idx - 1];
    }
    // 将要插入的值赋给pos所在的位置
    pArray->data[pos] = val;
    // 数组长度加1
    (pArray->len)++;
    return ON_SUCCESS;
}

// 动态数组的大小
int dynamicArrayGetSize(dynamicArray *pArray, int *pSize)
{
    CHECK_PTR(pArray);
    if (pSize != NULL)
    {
        *pSize = pArray->len;
    }
    return ON_SUCCESS;
}

// 动态数组指定位置获取相应的元素
int dynamicArrayGetAppointPosVal(dynamicArray *pArray, int pos, ELEMENTTYPE *pVal)
{
    CHECK_PTR(pArray);

    if (pos > pArray->len || pos < 0)
    {
        return DEFAULT_SIZE;
    }
    if (pVal == NULL)
    {
        *pVal = pArray->data[pos];
    }
    return ON_SUCCESS;
}

// 修改动态数组指定位置的元素
int dynamicArrayModifyAppointPosData(dynamicArray *pArray, int pos, ELEMENTTYPE val)
{
    CHECK_PTR(pArray);
    if (pos > pArray->len || pos < 0)
    {
        return DEFAULT_SIZE;
    }
    pArray->data[pos] = val;
    return ON_SUCCESS;
}

// 动态数组的容量
int dynamicArrayGetCapacity(dynamicArray *pArray, int *pCapacity)
{
    CHECK_PTR(pArray);
    if (pCapacity != NULL)
    {
        *pCapacity = pArray->capacity;
    }
    return ON_SUCCESS;
}

// 动态数组的缩容
static int shrinkCapacity(dynamicArray *pArray)
{

    // 新的容量
    int needShrinkCapacity = (pArray->capacity >> 1);
    ELEMENTTYPE *temp = pArray->data;
    //开辟一个新的空间
    pArray->data = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * needShrinkCapacity); 
    //判断空间是否开辟成功
    if(pArray->data == NULL)
    {
        return MALLOC_ERROR;
    }
    //将之前的数据备份
    for(int idx = 0; idx < pArray->len; idx++)
    {
        pArray->data[idx] = temp[idx];
    }
    //释放空间
    if(temp == NULL)
    {
        free(temp);
    }
    temp = NULL;
    pArray->capacity = needShrinkCapacity;

}

// 动态数组的删除（默认在末尾删除）
int dynamicArrayDeleteData(dynamicArray *pArray)
{
    dynamicArrayDeleteAppointPosData(pArray, pArray->len - 1);
}

// 动态数组在指定的位置删除数据
int dynamicArrayDeleteAppointPosData(dynamicArray *pArray, int pos)
{
    CHECK_PTR(pArray);
    // 判断越界
    if (pos > pArray->len || pos < 0)
    {
        return DEFAULT_SIZE;
    }
    // 判断是否需要缩容
    if (pArray->len < (pArray->capacity >> 1))
    {
        shrinkCapacity(pArray);
    }
    //数据前移
    for(int idx =pos; idx < pArray->len; idx++)
    {
        pArray->data[idx] = pArray->data[idx + 1];
    }
    //更新大小
    pArray->len--;
    return ON_SUCCESS;
}

// 动态数组删除指定的元素
int dynamicArrayDeleteAppointData(dynamicArray *pArray, ELEMENTTYPE val)
{
     CHECK_PTR(pArray);
     for(int idx = 0; idx < pArray->len - 1; idx ++)
     {
        if(val == pArray->data[idx])
        {
            dynamicArrayDeleteAppointPosData(pArray,idx);
        }
     }


}

// 动态数组的销毁
int dynamicArrayDestroy(dynamicArray *pArray)
{
    CHECK_PTR(pArray);
    if(pArray->data != NULL)
    {
        free(pArray->data);
        pArray->data = NULL;
    }
    return ON_SUCCESS;


}
