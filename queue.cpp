/*
浙大数据结构课程学习
队列的实现
*/
#include <stdio.h>
#include <stdlib.h>


#define MAXSIZE 10
#define ERROR 533 //wrong code
typedef int ElementType;
//队列的数组实现
struct Qnode
{
    ElementType Data[MAXSIZE];
    int Front; //指向队列首元素前一位（初始-1）
    int Rear;  //指向队列末元素一位（初始-1）
};
typedef struct Qnode *Queue;

//创建空队列
Queue CreateQueue()
{
    Queue Temp;
    Temp = (Queue)malloc(sizeof(struct Qnode));
    Temp->Front = -1;
    Temp->Rear = -1;
    return Temp;
}
//入队(不改变头指针，故无需返回值)
void InQueue(ElementType item, Queue Q)
{
    //判满，循环队列,空一位及认为队列满
    if ((Q->Rear+1)%MAXSIZE == Q->Front)
    {
        printf("队列满！");
        return ;
    }
    Q->Rear = (Q->Rear+1)%MAXSIZE;
    Q->Data[Q->Rear] = item;
}
//出队
ElementType OutQueue(Queue Q)
{
    //判空，Rear == Front
    if (Q->Rear == Q->Front)
    {
        printf("队列空！");
        return ERROR;
    }
    Q->Front = (Q->Front+1)%MAXSIZE;
    return Q->Data[Q->Front+1];
}

//队列的链式实现
typedef struct Node *Pnode;
typedef struct LQnode *LQueue;
struct Node
{
    ElementType Data;
    Pnode Next;
};

struct LQnode
{
    Pnode Front;
    Pnode Rear;
};

//Create
LQueue CreateLQ()
{
    LQueue PtrLQ = (LQueue)malloc(sizeof(struct LQnode));
    Pnode PtrN = (Pnode)malloc(sizeof(struct Node));//队头空节点
    PtrLQ->Front = PtrLQ->Rear = PtrN;
    PtrN->Next = NULL;
    return PtrLQ;
}

//入队
void InLQ(ElementType item, LQueue LQ)
{
    Pnode PtrN = (Pnode)malloc(sizeof(struct Node));
    PtrN->Data = item;
    PtrN->Next = NULL;
    LQ->Rear->Next = PtrN; //队尾插入新节点
    LQ->Rear = PtrN; //Rear指向新队尾
}

//出队列
ElementType OutLQ(LQueue LQ)
{
    //判空
 //   if (LQ->Rear == LQ->Front) //错误判别
    if (LQ->Front->Next == NULL)
    {
        printf("队列空！");
        return ERROR;
    }
    Pnode PtrN;
    ElementType item;
    PtrN = LQ->Front->Next;
    LQ->Front->Next = PtrN->Next;
    item = PtrN->Data;
    free(PtrN);
    return item;
}

//打印队列
void PrintLQ(LQueue LQ)
{
    Pnode PtrN = LQ->Front;
    if (PtrN->Next == NULL)
    {
        printf("队列空");
        return;
    }
    while (LQ->Rear != PtrN)
    {
        PtrN = PtrN->Next;
        printf("%d\n",PtrN->Data);
    }
    return;
}

int main()
{
    LQueue PtrLQ = CreateLQ();
    for (int i=0;i<MAXSIZE;i++)
        InLQ(i,PtrLQ);
    PrintLQ(PtrLQ);

    printf("OutLQ\n");
    while (PtrLQ->Front->Next != NULL)
        printf("%d\n",OutLQ(PtrLQ));
    printf("%d\n",OutLQ(PtrLQ));
    return 0;
}
