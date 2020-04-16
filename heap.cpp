//浙江大学 数据结构
//堆/优先队列 Heap

//使用数组表示的完全二叉树
//任一节点根最大/最小

#define MaxData 65535
typedef int ElementType;
//最大堆的定义
typedef struct Heapstruct *MaxHeap;
struct Heapstruct
{
    ElementType *Elements; //存储数组
    int Size; //堆的元素个数 （数组只知道头指针，不知道大小
    int Capacity; //最大容量
};

//最大堆的创建
MaxHeap CreatHeap(int MaxSize)
{
    MaxHeap MH;
    MH = (MaxHeap)malloc(sizeof(Heapstruct));
    MH->Elements = (ElementType*)malloc((MaxSize+1)*sizeof(ElementType));
    MH->Size = 0;
    MH->Capacity = MaxSize;
    MH->Elements[0] = MaxData; //数组首位放置哨兵
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
    for (; MH->Elements[i/2]<item; i /= 2)//从Elements(i)开始逐次取其父节点与item比较，比item小就换到其子节点,i==1时，i/2=0,遇到哨兵元素，控制退出循环
        MH->Elements[i] = MH->Elements[i/2]; //即将小于item的根节点依次换到他的子节点上
    MH->Elements[i] = item; //最后将item插入空出来的节点上
}

//Delete item from Heap if not empty
void DeleteHeap(MaxHeap MH)  //delete 删掉根上data，然后重建heap（1.母节点大于子节点；2.完全树）
{

