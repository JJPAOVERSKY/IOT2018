#include"head.h"


//����������
Node* createBinaryTree()
{
	Node* p;
	TelemType ch;
	cin >> ch;
	if (ch == 0)     //������㷨��Ĭ�ϰ��к��ӽ����д�ģ����û�У������������������ֱ�ֵΪ0
	{
		p = NULL;
	}
	else
	{
		p = (Node*)malloc(sizeof(Node));
		p->data = ch;                   //�ȴ����м���
		p->Left = createBinaryTree();  //����ݹ鴴��������
		p->Right = createBinaryTree();  //���ݹ鴴��������
	}
	return p;
}

//�������
void preOrderTraverse(Node* root)
{
	if (root)
	{
		cout << root->data << ' ';//������������
		preOrderTraverse(root->Left);//�������������
		preOrderTraverse(root->Right);//�������������
	}
}

//�������
void inOrderTraverse(Node* root)
{
	if (root)
	{
		inOrderTraverse(root->Left);//�������������
		cout << root->data << ' ';//������������
		inOrderTraverse(root->Right); // �������������
	}
}

//�������
void lastOrderTraverse(Node* root)
{
	if (root)
	{
		lastOrderTraverse(root->Left);//�������������
		lastOrderTraverse(root->Right);// �������������
		cout << root->data << ' ';//������������
	}
}
