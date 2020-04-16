//������������BST��Binary Search Tree��
 //�ǿ�BST������
 //1. �ǿ����������м�ֵ��С������ڵ�ļ�ֵ
 //2. �ǿ����������м�ֵ��С������ڵ�ļ�ֵ
 //3. ������������BST

//Ԫ�ز��Һ���--�ݹ鷽��
Position Find��ElementType X,BinTree BST)
{
    if (BST == NULL) return NULL;
    if (X < BST->Data)
            return Find(X,BST->Left); //β�ݹ�
        else if (X > BST->Data)
            return Find(X,BST->Right); //β�ݹ�
        else
            return BST;
}

//Ԫ�ز��Һ���--��������
Position Find��ElementType X,BinTree BST)
{
//   if (BST == NULL) return NULL; //��whileѭ���ظ��ж�
    while (BST != NULL)
    {
        if (X < BST->Data)
            BST = BST->Left;
        else if (X > BST->Data)
            BST = BST->Right;
        else
            return BST;
    }
    return NULL;
}
