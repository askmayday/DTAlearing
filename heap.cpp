//�㽭��ѧ ���ݽṹ
//��/���ȶ��� Heap

//ʹ�������ʾ����ȫ������
//��һ�ڵ�����/��С

#define MaxData 65535
typedef int ElementType;
//���ѵĶ���
typedef struct Heapstruct *MaxHeap;
struct Heapstruct
{
    ElementType *Elements; //�洢����
    int Size; //�ѵ�Ԫ�ظ��� ������ֻ֪��ͷָ�룬��֪����С
    int Capacity; //�������
};

//���ѵĴ���
MaxHeap CreatHeap(int MaxSize)
{
    MaxHeap MH;
    MH = (MaxHeap)malloc(sizeof(Heapstruct));
    MH->Elements = (ElementType*)malloc((MaxSize+1)*sizeof(ElementType));
    MH->Size = 0;
    MH->Capacity = MaxSize;
    MH->Elements[0] = MaxData; //������λ�����ڱ�
    return MH;
}

//Insert if not full
void InsertHeap(ElementType item, MaxHeap MH)
{
    int i;
    if (MH->Size == MH->Capacity)
    {
        printf("The Heap is Full !");
        return;
    }
    i = ++MH->Size;
    for (; MH->Elements[i/2]<item; i /= 2)//��Elements(i)��ʼ���ȡ�丸�ڵ���item�Ƚϣ���itemС�ͻ������ӽڵ�,i==1ʱ��i/2=0,�����ڱ�Ԫ�أ������˳�ѭ��
        MH->Elements[i] = MH->Elements[i/2]; //����С��item�ĸ��ڵ����λ��������ӽڵ���
    MH->Elements[i] = item; //���item����ճ����Ľڵ���
}

//Delete item from Heap if not empty
void DeleteHeap(MaxHeap MH)  //delete ɾ������data��Ȼ���ؽ�heap��1.ĸ�ڵ�����ӽڵ㣻2.��ȫ����
{

