/*
������ݽṹ�γ�ѧϰ
���Ա��˳��洢
*/
#include <stdlib.h> //for malloc����
#define MAXSIZE 100

//���������
typedef struct Lnode *List;  //����һ��ָ���������� PtrL
struct Lnode
{
    ElementType Data[MAXSIZE]; //����������������Ա�������
    int Last;                 //last��ʾ��ǰ�������һ��Ԫ�ص�λ��
};
struct Lnode L;  //Lnode ֻ�ǽṹ�����ƣ�������ǰ��Ҫ�������� struct
/*Ҳ�����ڽṹ�嶨�����ֱ�����������ӱ�����ʼ�����壩��
struct Lnode
{
    ElementType Data[MAXSIZE]; //����������������Ա�������
    int Last;                 //last��ʾ��ǰ�������һ��Ԫ�ص�λ�ã��±꣩
} L;
*/
List PtrL;       //List Ϊtypedef��������ͣ�����ֱ��ʹ��List��������
/* ���ʱ���Ԫ�� L.Data[i] �� PtrL->Date[i]

/*���Ա������
List MakeEmpty();
ElementType FindKth(int K, List L);
int Find(ElememtType X, List L);
void Insert(ElememtType X, int i, List L);
void Delete(int i, List L);
int Length(List L);
*/

//��ʼ���ձ�
List MakeEmpty()
{
    List PtrL;
    PtrL = (List)malloc(sizeof(struct Lnode));//ʹ��mallocΪ�������±����ռ�
                                              // malloc����������Ǽ����ֽ�����
                                              //�����ڷ��ص�ʱ��ǿת��ʵ��ָ�����͵�ָ��
    PtrL->Last = -1; //�ձ�Lastֻ��0��ǰһλ
    return PtrL;
}

//�ҳ����е�Kλ��Ԫ��
ElementType FindKth(int K, List L)
{
    //��LΪ�ձ� or L��Ԫ�ظ���С��K
    if (L->Last < 0 || L->Last+1 > K)
        return NUL; //NULΪ���ַ���NULLΪ��ָ��
    else
        return L->Data[K-1];
}

//�ҳ���L���״γ���Ԫ��X��λ��
int Find(ElememtType X, List L)
{
    int i = 0;
    while (i < L->Last+1 )
    {
        if (L->Date[i] == X)
            return i;         //�ҵ�����X��λ��
        i++;
    }
    return -1; //û�ҵ�
    //��ͬ��
    //while(i < L->Last+1 && L->Date[i] != X)
    //    i++;
    //if (i >L->Last) return -1;
    //else return i;
}

//��i��i��1��last+1֮�䣩����X
void Insert(ElememtType X, int i, List L)
{
    if (L->Last+1 == MAXSIZE)
    {
        printf("������\n",i);
        return;
    }
    if (i > L->Last+2 || i < 1)
    {
        printf("λ�ò��Ϸ�\n",i);
        return;
    }
    int j;
    for (j = L->Last; j >= i-1; j--)
        L->Data[j+1] = L->Data[j];
    L->Data[i-] = X;
    L->Last++;
}

//ɾ����iλԪ��
void Delete(int i, List L)
{
    if (i > L->Last+1 || i < 1)  //��λ�ձ�������i > L->Last+1
    {
        printf("λ�ò��Ϸ�\n");
        return;
    }
    int j;
    for (j = i-1; j <= L->Last; j++ )
        L->Data[j-1] = L->Data[j];
    L->Last--;
    return ;
}
