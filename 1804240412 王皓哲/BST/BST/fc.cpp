#include"bst.h"

void menu()														
{
	printf ("\n");
	printf ("*19,38,12,40,41,39,54,76,35,47,80,14,9,44,60\n");
	printf ("1����������������\n");
	printf ("2�������������������\n");
	printf ("3��ɾ��54\n");
	printf ("4������\n");
	printf ("0���˳�\n");
	printf ("������Ҫִ�еĲ�����ţ�\n");
}

void CreateBSTree(BSTree &T)
{
	int i,a[15]={19,38,12,40,41,39,54,76,35,47,80,14,9,44,60};
	T=NULL;
	for(i=0;i<15;i++)
	{
		InsertBST(T,a[i]);
	}
}

bool InsertBST (BSTree &T,ElemType e)
{
	BSTree p,s;
	if(!SearchBST(T,e,NULL,p))
	{
		s= new BiTNode;
		if(!s)
			exit(1);
		s->data=e;
		s->lchild=s->rchild=NULL;
		if(!p)
			T=s;		
		else if(e<p->data)
			p->lchild=s;
		else
			p->rchild=s;
		return true;
	}
	else
		return false;
}

bool SearchBST (BSTree T, ElemType kval, BSTree f, BSTree &p )	//pΪ��Ԫ�ؽ�㣬fָ����˫�ף���ʼΪNULL
{// ��ָ��T��ָ����������еݹ���ҹؼ��ֵ���kval������Ԫ��,�����ҳɹ�,��ָ��pָ�������Ԫ�ؽ��,������TRUE,����ָ��pָ�����·���Ϸ��ʵ����һ����㲢����FALSE,ָ��fָ��T��˫��,���ʼ����ֵΪNULL
	if (!T)
	{
		p = f;
		return false;		// ���Ҳ��ɹ�
	}
	else if ( kval == T->data)
	{
		p = T;
		return true; // ���ҳɹ�
	}
	else if ( kval < T->data)
		return SearchBST (T->lchild, kval, T, p ); 	// �������������м����������ý��
	else 
		return SearchBST (T->rchild, kval, T, p );// �������������м����������ý��
} 	

void Inorder (BSTree T,void (*Visit)(BSTree))
{
	if(T)
	{
		Inorder(T->lchild,Visit);
		Visit(T);
		Inorder(T->rchild,Visit);
	}
}

void Visit(BSTree T)
{
	if(T)
		printf("%3d",T->data);
}

bool DeleteBST (BSTree &T, int kval)
{
	if(!T)
		return false;
	else
	{
		if(kval==T->data)
		{
			DeleteNode(T);
			return true;
		}
		else if(kval<T->data)
			return DeleteBST(T->lchild,kval);
		else
			return DeleteBST(T->rchild,kval);
	}
}

void DeleteNode(BSTree &p)
{
	BSTree s=NULL,q=NULL;
	if(!p->rchild)
	{
		q=p;
		p=p->lchild;
		delete q;
	}
	else if(!p->lchild)
	{
		q=p;
		p->rchild;
		delete q;
	}
	else
	{
		q=p;
		s=p->lchild;
		while(!s)
		{
			q=s;
			s=s->rchild;
		}
		p->data=s->data;
		if(q!=p)
			q->rchild=s->lchild;
		else
			q->lchild=s->lchild;
		delete s;
	}
}

void Destroy(BSTree *T)
{
	if(T==NULL)
		return ;
	if(*T==NULL)
		return ;
	Destroy(&(*T)->lchild);
	Destroy(&(*T)->rchild);
	DestroyNode(*T);
	*T=NULL;
	return ;
}

void DestroyNode (BSTree T)
{
	delete T;
	return ;
}