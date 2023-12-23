#ifndef __CIRCULAR_DOUBLELINKEDLIST_H_
#define __CIRCULAR_DOUBLELINKEDLIST_H_

//  #define ELEMENTTPYE int
#define ELEMENTTPYE void*

// 链表结点
typedef struct CircularDoubleLinkNode
{
    ELEMENTTPYE data;
    // 指向下一个结点的指针
    struct CircularDoubleLinkNode *next;
    //指向前一个结点
    struct CircularDoubleLinkNode *prev;
} CircularDoubleLinkNode;

// 链表
typedef struct CircularDoubleLinkList
{   // 链表的虚拟头结点
    CircularDoubleLinkNode * head;
    //尾指针
    CircularDoubleLinkNode * tail;  //为什么尾指针不需要分配空间？
    //链表长度
    int len;

}CircularDoubleLinkList;
#if 0
typedef struct CircularDoubleLinkList
{
    CircularDoubleLinkNode  * head;
    ELEMENTTPYE data;
    // 指向下一个结点的指针
    struct CircularDoubleLinkNode *next;


}CircularDoubleLinkList ;
#endif

//链表初始化
    int  CircularDoubleLinkListInit(CircularDoubleLinkList ** pList);

//链表头插
    int CircularDoubleLinkListHeadInsert(CircularDoubleLinkList * pList, ELEMENTTPYE val);

//链表尾插
    int CircularDoubleLinkListTailInsert(CircularDoubleLinkList * pList, ELEMENTTPYE val);

//链表指定位置插入
    int CircularDoubleLinkListAppointPosInsert(CircularDoubleLinkList * pList, int pos, ELEMENTTPYE val);

//链表的头删
    int CircularDoubleLinkListHeadDel(CircularDoubleLinkList * pList);

//链表的尾删
    int CircularDoubleLinkListTailDel(CircularDoubleLinkList * pList);

//链表的指定位置删除
    int CircularDoubleLinkListAppintPosDel(CircularDoubleLinkList * pList, int pos);

//链表删除指定数据
    int CircularDoubleLinkListDelAppointData(CircularDoubleLinkList * pList, ELEMENTTPYE val,  int ( *comparFunc)(ELEMENTTPYE, ELEMENTTPYE));

//获取链表的长度
    int CircularDoubleLinkListGetLength(CircularDoubleLinkList * pList, int *pSize);

// 链表的销毁
    int CircularDoubleLinkListDestroy(CircularDoubleLinkList * pList);

//链表的遍历 回调函数
    int linkedListForeach(CircularDoubleLinkList * pList, int(*printFunc)(ELEMENTTPYE));
    
    //链表的遍历 int
    // int linkedListForeach(CircularDoubleLinkList * pList);

//逆序打印 
    int CircularDoubleLinkListReverForeach(CircularDoubleLinkList *pList, int(*printFunc)(ELEMENTTPYE));

#endif
