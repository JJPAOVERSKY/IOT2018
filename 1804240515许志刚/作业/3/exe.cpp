//��дһ�ݹ��㷨���Ӵ�С���������������������ֵ��С��x�Ĺؼ���
void PrintfBT(BiTree &T,keytype X)
{
	if(!T)
		return;
	PrintfBT(T->right,X);
	if(T->data,key<X)
		return;
	printf("%d",T->data.key);
	PrintfBT(T->left,X);
}