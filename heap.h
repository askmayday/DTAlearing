#ifndef HEAP_H
#define HEAP_H

typedef int ElementType;
#define ERROR -65535

typedef struct HeapNode *MaxHeap;
struct HeapNode
{
    ElementType *Elements;
    int Size;
    int Capacity;
};

MaxHeap CreatHeap(int MaxSize);
void InsertHeap(MaxHeap H, ElementType item);
ElementType DeleteHeap(MaxHeap H);
void PrintHeap(MaxHeap H);

#endif // HEAP_H
