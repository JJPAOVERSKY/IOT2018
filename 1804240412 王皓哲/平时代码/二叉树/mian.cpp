#include"head.h"

int main()
{
    BiTree T;
    //��������AB#CD##E##F#GH###
    printf("�����������(��#����)\n");
    CreateBiTree(T);
	printf("\n");
    printf("����������:");
    InOrderTraverse(T);
	printf("\n");
	printf("����������:");
    PreOrderTraverse(T);
	printf("\n");
    printf("����������:");
    PostOrderTraverse(T);
	printf("\n");

		BiThrTree Tr, Thrt;
        cout << "����������������������������������������н���ֵ����$��������\n";
        CreateBiThrTree(Tr);
        if (InOrderThreading(Thrt, Tr) == OK)
				  cout << "�ɹ�������������������\n";
        cout << "�����������������������ǣ�\n";
        InOrderTraverse_Thr(Thrt, PrintElement);
        cout << endl;

	int  w[] = { 5,4,3,2,1 };//������w�洢����Ȩֵ
	int n=5;//��ʾ����w�еĸ���
	HuffmanCode HC = NULL;
	HuffmanTree hTree = create_HuffmanTree(w, n);
	int wpl1 = countWPL1(hTree, n);
	printf("��Ҷ�ӽ�㿪ʼ��������������С��Ȩ·������WPL=%d\n", wpl1);
	int wpl2 = countWPL2(hTree, n);
	printf("�Ӹ���㿪ʼ��������������С��Ȩ·������WPL=%d\n", wpl2);
	printf("\n��Ҷ�ӵ�����������Ϊ��\n");
	HuffmanCoding1(hTree, HC, n);
	printf("\n�Ӹ���㵽Ҷ�ӽ�������Ϊ��\n");
	HuffmanCoding2(hTree, HC, n);
	system("pause");

   return 0;
}
