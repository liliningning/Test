#ifndef __DYNAMIC_ARRAY_H_
#define  __DYNAMIC_ARRAY_H_

#define ELEMENTTYPE void*

typedef struct dynamicArray
{   
    ELEMENTTYPE *data;
    int len;
    int capacity;
    
} dynamicArray ;

//动态数组的初始化
    int dynamicArrayInit(dynamicArray * pArray, int capacity);

//动态数组的插入 (默认在末尾插入)
    int dynamicArrayInsertData(dynamicArray *pArray, ELEMENTTYPE val);

//动态数组指定位置的插入 
    int dynamicArrayAppointPosInsertData(dynamicArray *pArray, int pos, ELEMENTTYPE val);

//动态数组的大小
    int dynamicArrayGetSize(dynamicArray * pArray,int* pSize);

//修改动态数组指定位置的元素
    int dynamicArrayModifyAppointPosData(dynamicArray * pArray,int pos, ELEMENTTYPE val);

//动态数组的容量
    int dynamicArrayGetCapacity(dynamicArray * pArray, int * pCapacity);

// 动态数组的删除（默认在末尾删除）
    int dynamicArrayDeleteData(dynamicArray * pArray);

// 动态数组在指定的位置删除数据
    int dynamicArrayDeleteAppointPosData(dynamicArray * pArray,int pos);

//动态数组删除指定的元素
    int dynamicArrayDeleteAppointData(dynamicArray * pArray, ELEMENTTYPE val);

//动态数组指定位置获取相应的元素
    int dynamicArrayGetAppointPosVal(dynamicArray * pArray, int pos , ELEMENTTYPE *pVal);

//动态数组的销毁
    int dynamicArrayDestroy(dynamicArray * pArray);



#endif











