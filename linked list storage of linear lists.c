/*
������ݽṹ�γ�ѧϰ
���Ա����ʽ�洢
*/

//����
typedef struct Lnode *List;  //һ���ṹ��ֻ�������һ���ڵ�
struct Lnode
{
    ElementType Data;
    List Next;
};

struct Lnode L;
List PtrL;

//main operatons

//���
int Length(List L)
{
    List p = L; //pָ���һ���ڵ�
    int i = 0;
    while (p)
    {
        p = p->Next;
        i++��   //��ʱpָ���i���ڵ�
    }
    return i;
}

//�����K���ҽڵ�
List FindKth(int K, List L)
{
    List p = L;
    int i = 1;
    while (i < K && p!= NULL) //p != NULL �� p ��Ч��
    {
        p = p->Next;
        i++��
    }
    if (K == i)
        return p;
    else
        return NULL; //K > Length(L)
}

//�����ݲ��ҽڵ�
int Find(ElementType X, List L)
{
    List p = L;
    while (p->Data != X && p != NULL)
        p = p->Next;
    return p; //���ҵ��������������ڽڵ㣬���򷵻�NULL
}

//i�ڵ�'ǰ'����xֵ�½ڵ�,����������
List Insert(ElementType X, int i, List L)
{
    List s;
 //   s = (List)malloc(sizeof(struct Lnode)); ���ڴ˴����ܻ��ò���������ڴ�й©��
 //   s->Data = X;

    //iΪ1ʱ��ֱ���ڵ�һλ����
    if (i == 1)
    {
        s = (List)malloc(sizeof(struct Lnode));
        s->Data = X;
        s->Next = L;
        return s;
    }

    /*
    List p = L;
    int j =1;
    while (j < i-1 && p != NULL) //��iΪ1,�򲻿�����j==i-1,���޷��ڵ�һλ����Ԫ��
    {
        p = p->Next;
        j++;
    }
    //
    if (j == i-1)
    {
        s = (List)malloc(sizeof(struct Lnode));
        s->Data = X;
        s->Next = p ->Next;
        p ->Next = s;
        return L;
    }
    else
    {
        printf("��������\n");
        return NULL;
    }
    */
    //�ɵ���FindKth()�򻯳���
    List p;
    p = FindKth(i-1,L); //p����λ��ָ���NULL
    if ( p = NULL)
    {
        printf("����i����");
        return NULL;
    }
    else
    {
        s = (List)malloc(sizeof(struct Lnode));
        s->Data = X;
        s->Next = p->Next;
        p->Next = s;
        return L;
    }
}

//ɾ��i���Ľڵ�
List Delete(int i, List L)
{
    List p,s;
    if (i == 1)
    {
        if (L == NULL)
            return NULL;
        p = L->Next;
        free(L);
        return p;
    }

    p = FindKth(i-1,L);
    if (p == NULL)
    {
        printf("��%dλ������\n",i-1);
        return NULL;
    }
    else if (p->Next == NULL)
    {
        printf("��%dλ������\n",i);
        return NULL;
    }
    else
    {
        s = p->Next;
        p->Next = s->Next;
        free(s);
        return L;
    }
}
