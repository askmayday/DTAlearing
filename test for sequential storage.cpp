#include <stdio.h>
#include <stdlib.h> //for malloc����

#define MAXSIZE 100

typedef struct Lnode *List;  //����һ��ָ���������� List
struct Lnode
{
    double Data[MAXSIZE]; //����������������Ա�������
    int Last;                 //last��ʾ��ǰ�������һ��Ԫ�ص�λ��
};

List MakeEmpty();
double FindKth(int K, List L);
int Find(double  X, List L);
void Insert(double X, int i, List L);
void Delete(int i, List L);

int main()
{
    List PtrL;
    PtrL = MakeEmpty();

    //�ֶ���ʼ��list
    for (int i = 0; i < 10; i++)
    {
        PtrL->Data[i] = 0.1 * i;
        printf("PtrL->Data[%d] = %f \n",i,PtrL->Data[i]);
    }
    PtrL->Last = 9;

    //��ӡ����list
    for (int i = 1; i <= PtrL->Last+1; i++)
        printf("����Ԫ�ض��У�%f\n",FindKth(i,PtrL));

    //����Ԫ��1��λ��
    printf("Ԫ��1��λ���ǣ�%d \n",Find(1,PtrL));

    //��list��5λ����1��Ȼ���ӡ������list
    Insert(1,12,PtrL);
    for (int i = 1; i <= PtrL->Last+1; i++)
        printf("����Ԫ�ض��У�%f\n",FindKth(i,PtrL));

    Delete(5,PtrL);
    for (int i = 1; i <= PtrL->Last+1; i++)
        printf("����Ԫ�ض��У�%f\n",FindKth(i,PtrL));

    return 0;
}

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
double FindKth(int K, List L)
{
    //��LΪ�ձ� or L��Ԫ�ظ���С��K
    if (L->Last < 0 || L->Last+1 < K)
        return 3307; //3307Ϊ�쳣��ʶ
    else
        return L->Data[K-1];
}

//�ҳ���L���״γ���Ԫ��X��λ��
int Find(double X, List L)
{
    int i = 0;
    while (i < L->Last+1 )
    {
        if (L->Data[i] == X)
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

//��i��i��1��last+1֮�䣩ǰ����X
void Insert(double X, int i, List L)
{
    if (L->Last+1 == MAXSIZE)
    {
        printf("������\n");
        return;
    }
    if (i > L->Last+2 || i < 1)
    {
        printf("λ�ò��Ϸ�\n");
        return;
    }
    int j;
    for (j = L->Last; j >= i-1; j--)
        L->Data[j+1] = L->Data[j];
    L->Data[i-1] = X;
    L->Last++;
    return;
}

//ɾ����iλԪ��
void Delete(int i, List L)
{
/*    if (L->Last < 0)
    {
        printf("�ձ�\n");
        return;
    }
*/
    if (i > L->Last+1 || i < 1) //��λ�ձ�������i > L->Last+1
    {
        printf("λ�ò��Ϸ�\n");
        return;
    }
    int j;
    for (j = i-1; j <= L->Last; j++ )
        L->Data[j] = L->Data[j+1];
    L->Last--;
    return ;
}
