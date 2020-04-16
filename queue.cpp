/*
������ݽṹ�γ�ѧϰ
���е�ʵ��
*/
#include <stdio.h>
#include <stdlib.h>


#define MAXSIZE 10
#define ERROR 533 //wrong code
typedef int ElementType;
//���е�����ʵ��
struct Qnode
{
    ElementType Data[MAXSIZE];
    int Front; //ָ�������Ԫ��ǰһλ����ʼ-1��
    int Rear;  //ָ�����ĩԪ��һλ����ʼ-1��
};
typedef struct Qnode *Queue;

//�����ն���
Queue CreateQueue()
{
    Queue Temp;
    Temp = (Queue)malloc(sizeof(struct Qnode));
    Temp->Front = -1;
    Temp->Rear = -1;
    return Temp;
}
//���(���ı�ͷָ�룬�����践��ֵ)
void InQueue(ElementType item, Queue Q)
{
    //������ѭ������,��һλ����Ϊ������
    if ((Q->Rear+1)%MAXSIZE == Q->Front)
    {
        printf("��������");
        return ;
    }
    Q->Rear = (Q->Rear+1)%MAXSIZE;
    Q->Data[Q->Rear] = item;
}
//����
ElementType OutQueue(Queue Q)
{
    //�пգ�Rear == Front
    if (Q->Rear == Q->Front)
    {
        printf("���пգ�");
        return ERROR;
    }
    Q->Front = (Q->Front+1)%MAXSIZE;
    return Q->Data[Q->Front+1];
}

//���е���ʽʵ��
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
    Pnode PtrN = (Pnode)malloc(sizeof(struct Node));//��ͷ�սڵ�
    PtrLQ->Front = PtrLQ->Rear = PtrN;
    PtrN->Next = NULL;
    return PtrLQ;
}

//���
void InLQ(ElementType item, LQueue LQ)
{
    Pnode PtrN = (Pnode)malloc(sizeof(struct Node));
    PtrN->Data = item;
    PtrN->Next = NULL;
    LQ->Rear->Next = PtrN; //��β�����½ڵ�
    LQ->Rear = PtrN; //Rearָ���¶�β
}

//������
ElementType OutLQ(LQueue LQ)
{
    //�п�
 //   if (LQ->Rear == LQ->Front) //�����б�
    if (LQ->Front->Next == NULL)
    {
        printf("���пգ�");
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

//��ӡ����
void PrintLQ(LQueue LQ)
{
    Pnode PtrN = LQ->Front;
    if (PtrN->Next == NULL)
    {
        printf("���п�");
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
