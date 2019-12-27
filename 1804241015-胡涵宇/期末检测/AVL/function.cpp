#include"head.h"


//Ȩֵ�ǰ�����ȡ��Ҽ����������
//LL��ת����ʱ��parentȨֵΪ-2,����˳ʱ����ת
void clockwise_rotate(AVLNode* &parent, AVLNode* &root)
{
	AVLNode* subL = parent->lchild;                //�ĸ��ڵ�Ľṹ��ϵ���
	AVLNode* subLR = subL->rchild;
	AVLNode* pparent = parent->parent;

	parent->lchild = subLR;                        //�϶�Ҫ���ļ�����ϵ����
	parent->parent = subL;
	subL->rchild = parent;

	if (subLR)  subLR->parent = parent;         //parent����������֦����ôparent����֦�����������֦��
	if (pparent)                                  //���parent���Ǹ��ڵ�
	{
		if (parent == pparent->lchild)  pparent->lchild = subL;
		else  pparent->rchild = subL;	          //����parent����˫�׵���֦����֦������subL������߻����ұ�
		subL->parent = pparent;                   //subL��˫�ױ����parentԭ����˫��
	}
	else 
	{
		subL->parent = NULL;
		root = subL; 
	}                            //���parent�Ǹ��ڵ㣬��ôsubLֱ�ӱ�ɸ��ڵ�

	parent->balance_factor = 0;                   //Ȩֵ����
	subL->balance_factor = 0;
}


//RR��ת����ʱ��parentȨֵΪ2��������ʱ����ת
void counter_clockwise_rotate(AVLNode* &parent, AVLNode* &root)
{
	AVLNode* subR = parent->rchild;
	AVLNode* subRL = subR->lchild;
	AVLNode* pparent = parent->parent;

	parent->rchild = subRL;
	parent->parent = subR;
	subR->lchild = parent;

	if (subRL)  subRL->parent = parent;
	if (pparent)
	{
		if (parent == pparent->lchild)  pparent->lchild = subR;
		else  pparent->rchild = subR;
		subR->parent = pparent;
	}
	else
	{
		subR->parent = NULL;
		root = subR;
	}

	parent->balance_factor = 0;
	subR->balance_factor = 0;
}


//LR��ת����ʱ��parentȨֵΪ-2
//subL��ȨֵΪ1��subLR��ȨֵΪ1����subLR���ұ߲��룩           
//���ߣ�subL��ȨֵΪ1��subLR��ȨֵΪ-1(��sublR����߲���)
void counter_and_clock(AVLNode* &parent, AVLNode* &root)
{
	AVLNode* subL = parent->lchild;
	AVLNode* subLR = subL->rchild;
	int subLR_bf = subLR->balance_factor;

	counter_clockwise_rotate(subL, root);
	clockwise_rotate(parent, root);

	if (subLR_bf == -1)  parent->balance_factor = 1;
	else if (subLR_bf == 1) subL->balance_factor = -1;
}


void clock_and_counter(AVLNode* &parent, AVLNode* &root)
{
	AVLNode* subR = parent->rchild;
	AVLNode* subRL = subR->lchild;
	int subRL_bf = subRL->balance_factor;

	clockwise_rotate(subR, root);
	counter_clockwise_rotate(parent, root);

	if (subRL_bf == 1)  parent->balance_factor = -1;
	else if (subRL_bf == -1)  subR->balance_factor = 1;
}


AVLNode* Insert(AVLNode* root, int key)
{
	int flag = 1;
	AVLNode* p;
	p = (AVLNode*)malloc(sizeof(AVLNode));
	AVLNode* parent;
	parent = root;
	if (!root) {                                                 //����ڿ����ϲ���ڵ㣬�������Ǹ��ڵ�
		p->data = key;
		p->balance_factor = 0;
		p->parent = NULL;
		p->lchild = NULL;
		p->rchild = NULL;
		root = p;
		printf("����ɹ���\n");
	}
	else {                                                       //����������
		while(1)
		{
			if (key < parent->data)                              //�ȵ�ǰ���С
			{
				if (parent->lchild == NULL)                             
				{
					p->data = key;                               //û�о�ֱ�Ӳ���
					p->balance_factor = 0;
					p->parent = parent;
					parent->lchild = p;
					p->lchild = NULL;
					p->rchild = NULL;
					printf("�ɹ����룡\n");
					break;
				}
				else { parent = parent->lchild; }                //����֦������֦��
			}
			else if (key > parent->data)                         //�ȵ�ǰ����
			{
				if ( parent->rchild == NULL )		
				{
					p->data = key;                               //û����֦��ֱ�Ӳ���
					p->balance_factor = 0;
					p->parent = parent;
					parent->rchild = p;
					p->lchild = NULL;
					p->rchild = NULL;
					printf("�ɹ����룡\n");
					break;
				}
				else { parent = parent->rchild; }                 //����֦�����ұ���
			}
			else {                                                //���������ǰ���ֵ��ͬ��������
				printf("��������������Ѿ����ڣ�\n");
				flag = 0;                                         //��Ǳ�Ϊ0����ִ��ƽ�������޸ĺ���ת���裬ֱ���˳�����
				break;
			}
		}
	}

	if (flag == 1)                                                  //�ɹ�����֮��,�޸�ƽ������
	{
		while (parent)
		{
			if (p == parent->lchild)  parent->balance_factor--;
			else if (p == parent->rchild)  parent->balance_factor++;

			if (parent->balance_factor == 1 || parent->balance_factor == -1)   //�������֮��ƽ������Ϊ0��������ƽ�⣩����ô�ܺã����ò���
			{                                                                  //�������֮��ƽ�����Ӵ�0�䵽��1��-1��ƽ�ⱻ�ƻ�������ô�����޸�ƽ������
				p = parent;                                                    //ֱ���Ѹ��ڵ��޸���  ����  ������ƻ�������ĳ���ڵ�ƽ�⡱Ϊֹ
				parent = parent->parent;
			}
			else if (parent->balance_factor == 2 || parent->balance_factor == -2)
			{                                                                  //�޸�ƽ�����ӵ�ʱ���������bfΪ2����-2��,����������ж�Ӧ����ת
				if (parent->balance_factor == 2 && p->balance_factor == 1)  counter_clockwise_rotate(parent, root);
				else if (parent->balance_factor == 2 && p->balance_factor == -1) clock_and_counter(parent, root);
				else if (parent->balance_factor == -2 && p->balance_factor == 1) counter_and_clock(parent, root);
				else if (parent->balance_factor == -2 && p->balance_factor == -1) clockwise_rotate(parent, root);
			}
			else if (parent->balance_factor == 0)  break;
		}
	}
	return root;
}


void dele(int key, AVLNode*& root)
{
	AVLNode* p = root;
	int flag = 0;
	while (p)
	{
		if (key < p->data)   p = p->lchild;                                                 //�ҵ�Ҫɾ����λ��
		else if (key > p->data)  p = p->rchild;
		else if (key == p->data)
		{
			delete_rotate(p, root);
			deleteNode(p, root);
			flag = 1;
			break;
		}
	}
	if (flag != 1) printf("����û������ɾ���Ľڵ㣡\n");
	else if (flag == 1)  printf("ɾ���ɹ���\n");
}

void delete_rotate(AVLNode* &p, AVLNode*& root)
{
	AVLNode* q = p->parent;
	AVLNode* r = p;
	
	int flag = 0;
	while (q)
	{
		if (r == q->lchild)  q->balance_factor++;
		else if (r == q->rchild)  q->balance_factor--;

		if (q->balance_factor == 1 || q->balance_factor == -1 || q->balance_factor == 0)
		{
			r = q;
			q = q->parent;
		}
		else if (q->balance_factor == 2)
		{
			r = q->parent;
			if (q == r->lchild)  flag = 0;
			else if (q == r->rchild)  flag = 1;
			counter_clockwise_rotate(r, root);
			q = r;
			if (flag == 0)  r = q->lchild;
			else if (flag == 1) r = q->rchild;
		}
		else if (q->balance_factor == -2)
		{
			r = q->parent;
			if (q == r->lchild)  flag = 0;
			else if (q == r->rchild)  flag = 1;
			clockwise_rotate(r, root);
			q = r;
			if (flag == 0)  r = q->lchild;
			else if (flag == 1) r = q->rchild;
		}
	}
}

void deleteNode(AVLNode* p, AVLNode* root)
{
	AVLNode* q;
	if (!p->lchild && !p->rchild)
	{
		if (p == p->parent->lchild)  p->parent->lchild = NULL;
		else if (p == p->parent->rchild)  p->parent->rchild = NULL;
		delete p;
	}
	else if (!p->lchild && p->rchild)
	{
		q = p;
		p = q->rchild;
		p->parent = q->parent;
		if (q == q->parent->lchild) q->parent->lchild = p;
		else if (q == q->parent->rchild)  q->parent->rchild = p;
		delete q;
	}
	else if (p->lchild && !p->rchild)
	{
		q = p;
		p = q->lchild;
		p->parent = q->parent;
		if (q == q->parent->lchild) q->parent->lchild = p;
		else if (q == q->parent->rchild)  q->parent->rchild = p;
		delete q;
	}
	else {
		q = p->rchild;
		while (q->lchild)  q = q->lchild;
		p->data = q->data;
		deleteNode(q, root);
	}
}


void Midorder(AVLNode* root)
{
	if (root)
	{
		Midorder(root->lchild);
		printf("%d ", root->data);
		printf("ƽ������Ϊ%d\n", root->balance_factor);
		Midorder(root->rchild);
	}
}

void destory_AVL(AVLNode* root)
{
	if(root)
	{
		destory_AVL(root->lchild);
		destory_AVL(root->rchild);
		delete root;
	}
}

void menu()
{
	int op, key;
	int flag = 0;
	AVLNode* root = NULL;
	while (1)
	{
		if (flag == 1)  break;
		printf("*************************************************\n");
		printf("***********    1.��AVL�в�������     ************\n");
		printf("***********    2.��AVL��ɾ������     ************\n");
		printf("***********    3.�������AVL         ************\n");
		printf("***********    4.����AVL             ************\n");
		printf("***********    0.�˳�����            ************\n");
		printf("*************************************************\n");
		printf("����������ִ�еĲ��������:\n");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
		{
			printf("����������Ҫ�����ֵ:\n");
			scanf("%d", &key);
			root = Insert(root, key);
			break;
		}
		case 2:
		{
			printf("����������Ҫɾ����ֵ:\n");
			scanf("%d", &key);
			dele(key, root);
			break;
		}
		case 3:
		{
			if (!root)  printf("��Ϊ�գ�\n");
			else {
				printf("�������AVL�Ľ��Ϊ:\n");
				Midorder(root);
				printf("\n");
			}
			break;
		}
		case 4:
		{
			destory_AVL(root);
			root = NULL;
			printf("AVL�Ա�����!\n");
			break;	
		}
		case 0:
		{
			flag = 1;
			break;
		}
		default: printf("��Ŵ�������������:\n");
		}
	}
}
