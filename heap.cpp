#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

//堆的初始化
MaxHeap CreatHeap(int MaxSize)
{
    MaxHeap H = (MaxHeap)malloc(sizeof(struct HeapNode)); //malloc函数返回void*类型，故需要强制类型转换
    H->Elements = (ElementType*)malloc((MaxSize+1) * sizeof(ElementType));
    H->Elements[0] = 65535;//哨兵
    H->Size = 0;
    H->Capacity = MaxSize;
    return H;
}

//堆的插入元素
void InsertHeap(MaxHeap H, ElementType item)
{
    if (H->Size == H->Capacity)
    {
        printf("the heap is full");
        return;
    }
    int i = ++H->Size;
    for ( ; H->Elements[i/2] < item; i /= 2)
        H->Elements[i] = H->Elements[i/2];
    H->Elements[i] = item;
}

//堆的删除/推出元素
ElementType DeleteHeap(MaxHeap H)
{
    if (H->Size == 0)
    {
        printf("the heap is empty");
        return ERROR;
    }
    ElementType MaxData,Temp;
    int Parent,Child;
    MaxData = H->Elements[1];
    Temp = H->Elements[H->Size--];
    for (Parent = 1; Parent*2 <= H->Size; Parent = Child)  //当Parent的子节点序号大于Size，即此时Parent没子节点，为叶子节点
    {
        Child = Parent*2;
        if (H->Elements[Child] < H->Elements[Child+1] && Child != H->Size) //首先选出Parent较大的孩子作为Child
            Child++;
        if (Temp > H->Elements[Child]) //比较Temp和Child所指元素的大小，若Temp大则跳出循环，直接将Temp赋予此时的空节点
            break;
        else
            H->Elements[Parent] = H->Elements[Child]; //否则将该节点的较大子节点值赋予它
    }
    H->Elements[Parent] = Temp;
    return MaxData;
}

//打印堆
void PrintHeap(MaxHeap H)
{
    printf("当前完全树为：\n");
    for (int i=0; i<H->Size; i++)
    {
        if (i==1 || i==3 || i==7)
            printf("\n");
        printf("%d ",H->Elements[i+1]);
    }
    printf("\n");
}
