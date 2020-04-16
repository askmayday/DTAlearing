#ifndef BTTRAVERSAL_H
#define BTTRAVERSAL_H

//�������Ķ���
typedef struct TreeNode *BinTree;
struct TreeNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

//�ݹ�ʵ��
//ǰ����������ڵ�->������->������
void PreOrderTraversal(BinTree BT);
//���������������->���ڵ�->������
void InOrderTraversal(BinTree BT);
//���������������->������->���ڵ�
void PostOrderTraserval(BinTree BT);
//�ǵݹ�ʵ��
//�������
void InOrderTraversal2(BinTree BT);
//ǰ�����
void PreOrderTraversal2(BinTree BT);

#endif // BTTRAVERSAL_H
