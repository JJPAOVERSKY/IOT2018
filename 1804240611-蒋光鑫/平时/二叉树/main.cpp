#include"head.h"

int main()
{
	printf("��������Ҫ�����Ķ������ĸ������: \n");
	Node* root = NULL;
	root = createBinaryTree();
	printf("�����������ɹ�");
	cout << endl;

	cout << "ǰ��������:" << endl;
	preOrderTraverse(root);
	cout << endl;

	cout << "����������:" << endl;
	inOrderTraverse(root);
	cout << endl;

	cout << "����������:" << endl;
	lastOrderTraverse(root);
	cout << endl;

	return 0;
}
