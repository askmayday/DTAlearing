#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

//�ѵĳ�ʼ��
MaxHeap CreatHeap(int MaxSize)
{
    MaxHeap H = (MaxHeap)malloc(sizeof(struct HeapNode)); //malloc��������void*���ͣ�����Ҫǿ������ת��
    H->Elements = (ElementType*)malloc((MaxSize+1) * sizeof(ElementType));
    H->Elements[0] = 65535;//�ڱ�
    H->Size = 0;
    H->Capacity = MaxSize;
    return H;
}

//�ѵĲ���Ԫ��
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

//�ѵ�ɾ��/�Ƴ�Ԫ��
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
    for (Parent = 1; Parent*2 <= H->Size; Parent = Child)  //��Parent���ӽڵ���Ŵ���Size������ʱParentû�ӽڵ㣬ΪҶ�ӽڵ�
    {
        Child = Parent*2;
        if (H->Elements[Child] < H->Elements[Child+1] && Child != H->Size) //����ѡ��Parent�ϴ�ĺ�����ΪChild
            Child++;
        if (Temp > H->Elements[Child]) //�Ƚ�Temp��Child��ָԪ�صĴ�С����Temp��������ѭ����ֱ�ӽ�Temp�����ʱ�Ŀսڵ�
            break;
        else
            H->Elements[Parent] = H->Elements[Child]; //���򽫸ýڵ�Ľϴ��ӽڵ�ֵ������
    }
    H->Elements[Parent] = Temp;
    return MaxData;
}

//��ӡ��
void PrintHeap(MaxHeap H)
{
    printf("��ǰ��ȫ��Ϊ��\n");
    for (int i=0; i<H->Size; i++)
    {
        if (i==1 || i==3 || i==7)
            printf("\n");
        printf("%d ",H->Elements[i+1]);
    }
    printf("\n");
}
