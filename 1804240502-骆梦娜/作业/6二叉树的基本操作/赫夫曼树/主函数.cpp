#include"start.h"
int main()
{
	int  w[] = { 5,4,3,2,1 };//用数组w存储各个权值
	int n = 5;//表示数组w中的个数

	HuffmanCode HC = NULL;
	HuffmanTree hTree = create_HuffmanTree(w, n);
	int wpl1 = countWPL1(hTree, n);
	printf("从叶子结点开始遍历二叉树求最小带权路径长度WPL=%d\n", wpl1);

	int wpl2 = countWPL2(hTree, n);
	printf("从根结点开始遍历二叉树求最小带权路径长度WPL=%d\n", wpl2);

	printf("\n从叶子到根结点编码结果为：\n");
	HuffmanCoding1(hTree, HC, n);

	printf("\n从根结点到叶子结点编码结果为：\n");
	HuffmanCoding2(hTree, HC, n);

	system("pause");
	return 0;
}

