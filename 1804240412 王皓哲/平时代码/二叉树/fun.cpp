#include"head.h"


void CreateBiTree(BiTree &T)	//���򴴽�������
{								
    char ch;
    cin>>ch;
    if(ch=='#') T=NULL;
    else{
        T=new BiTNode;
        T->data=ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

void InOrderTraverse(BiTree T)
{//�������
    if(T)
    {
        InOrderTraverse(T->lchild);
        cout<<T->data;
        InOrderTraverse(T->rchild);
    }
}
void PreOrderTraverse(BiTree T)
{//�������
    if(T)
    {
        cout<<T->data;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
void PostOrderTraverse(BiTree T)
{//�������
    if(T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout<<T->data;
    }
}

Status PrintElement(TElemType e)// �����������ֵ
{
        cout << e;
        return OK;
}
Status CreateBiThrTree(BiThrTree &T)// ��������������
{
        char ch;
        cin >> ch;
        if (ch == '^')
                 T = NULL;
        else
        {
                 if (!(T = (BiThrNode *)malloc(sizeof(BiThrNode))))
                         exit(OVERFLOW);
                 T->data = ch;
                 T->ltag = Link;
                 T->rtag = Link;
                 CreateBiThrTree(T->lchild);
                 CreateBiThrTree(T->rchild);
        }
        return OK;
}

// Tָ��ͷ��㣬ͷ����lchildָ����ڵ㣬�����������������
Status InOrderTraverse_Thr(BiThrTree T, Status(*Visit)(TElemType e))
{
        BiThrTree p = T->lchild;
        while (p&&(p != T))
        {
                 while (p->ltag == Link)
                 {                      
                         p = p->lchild;
                 }
                 Visit(p->data);
                 while (p->rtag == Thread && p->rchild != T)
                 {
                         p = p->rchild;
                         Visit(p->data);
                 }
                 p = p->rchild;
        }
        return OK;
}

void InThreading(BiThrTree p,BiThrTree &pre)// ����������ж�����������
{
        if (p)
        {
                 InThreading(p->lchild,pre);//������������
                 if (!p->lchild)
                 {
                         p->ltag = Thread;
                         p->lchild = pre;//ǰ������
                 }
                 if ((!pre->rchild)&&pre->rchild==NULL)
                 {
                         pre->rtag = Thread;
                         pre->rchild = p;//�������
                 }
                 pre = p;
                 InThreading(p->rchild, pre);//������������
        }

}

Status InOrderThreading(BiThrTree &Thrt, BiThrTree T)//���������������������T��Thrtָ��ͷ���
{
        if (!(Thrt = (BiThrTree)malloc(sizeof(BiThrNode))))   //����ͷ���
                 exit(OVERFLOW);
        Thrt->ltag = Link;
        Thrt->rtag = Thread;
        Thrt->rchild = Thrt;//��ָ���ָ
        BiThrTree pre;
        if (!T)
             Thrt->lchild = Thrt;//��������Ϊ�գ�����ָ���ָ
        else
        {
                 Thrt->lchild = T;
                 pre = Thrt;
                 InThreading(T,pre);//���������������������
                 pre->rchild = Thrt;//���һ�����������
                 pre->rtag = Thread;
                 Thrt->rchild = pre;
        }
        return OK;
}

HuffmanTree create_HuffmanTree(int *wet, int n)
{
	int total = 2 * n - 1;
	HuffmanTree HT = (HuffmanTree)malloc(total * sizeof(HTNode));
	if (!HT)
	{
		printf("HuffmanTree malloc faild!");
		exit(-1);
	}
	int i;
	for (i = 0; i < n; i++)
	{
		HT[i].parent = -1;
		HT[i].lchild = -1;
		HT[i].rchild = -1;
		HT[i].weight = *wet;
		wet++;
	}

	//HT[n],HT[n+1]...HT[2n-2]�д�ŵ����м乹�����ÿ�ö������ĸ��ڵ�  
	for (; i < total; i++)
	{
		HT[i].parent = -1;
		HT[i].lchild = -1;
		HT[i].rchild = -1;
		HT[i].weight = 0;
	}

	int min1, min2; 
	for (i = n; i < total; i++)
	{
		select_minium(HT, i, min1, min2);
		HT[min1].parent = i;
		HT[min2].parent = i;
		HT[i].lchild = min1;
		HT[i].rchild = min2;
		HT[i].weight = HT[min1].weight + HT[min2].weight;
	}
	return HT;
}

void select_minium(HuffmanTree HT, int k, int &min1, int &min2)
{
	min1 = min(HT, k);
	min2 = min(HT, k);
}

int min(HuffmanTree HT, int k)
{
	int i = 0;
	int min;        //�������weight��С��parentΪ-1��Ԫ�ص����  
	int min_weight; //�������weight��С��parentΪ-1��Ԫ�ص�weightֵ  
	while (HT[i].parent != -1)
		i++;
	min_weight = HT[i].weight;
	min = i;
	for (; i < k; i++)
	{
		if (HT[i].weight < min_weight && HT[i].parent == -1)
		{
			min_weight = HT[i].weight;
			min = i;
		}
	}
	HT[min].parent = 1;

	return min;
}
void HuffmanCoding1(HuffmanTree HT, HuffmanCode &HC, int n)
{
	HC = (HuffmanCode)malloc(n * sizeof(char *));
	if (!HC)
	{
		printf("HuffmanCode malloc faild!");
		exit(-1);
	}
	char *code = (char *)malloc(n * sizeof(char));
	if (!code)
	{
		printf("code malloc faild!");
		exit(-1);
	}

	code[n - 1] = '\0';  
	int i;
	for (i = 0; i < n; i++)
	{
		int current = i;           
		int father = HT[i].parent; 
		int start = n - 1;          
		while (father != -1)
		{
			if (HT[father].lchild == current)   
				code[--start] = '0';
			else                                    
				code[--start] = '1';
			current = father;
			father = HT[father].parent;
		}
		HC[i] = (char *)malloc((n - start) * sizeof(char));
		if (!HC[i])
		{
			printf("HC[i] malloc faild!");
			exit(-1);
		}
		strcpy(HC[i], code + start);
	}
	for (int i = 0; i < n; ++i) {
		printf("%s\n", HC[i]);
	}
	free(code); //�ͷű�����봮����ʱ�ռ�
}
void HuffmanCoding2(HuffmanTree HT, HuffmanCode &HC, int n)
{
	//��������ָ��ÿ���շ������봮��ָ��  
	HC = (HuffmanCode)malloc(n * sizeof(char *));
	if (!HC)
	{
		printf("HuffmanCode malloc faild!");
		exit(-1);
	} 
	char *code = (char *)malloc(n * sizeof(char));
	if (!code)
	{
		printf("code malloc faild!");
		exit(-1);
	}

	int cur = 2 * n - 2;    //��ǰ�������Ľڵ����ţ���ʼʱΪ���ڵ����  
	int code_len = 0;   //�������ĳ���  
	int i;
	for (i = 0; i < cur + 1; i++)
	{
		HT[i].weight = 0;
	}

	//�Ӹ��ڵ㿪ʼ���������ص����ڵ����  
	//��curΪ���ڵ��parentʱ���˳�ѭ��  
	while (cur != -1)
	{
		//���Һ��Ӿ�δ�����������������  
		if (HT[cur].weight == 0)
		{
			HT[cur].weight = 1;    //�����������Ѿ�����������  
			if (HT[cur].lchild != -1)
			{   //�����ǰ�ڵ㲻��Ҷ�ӽڵ㣬����±��룬�������������  
				code[code_len++] = '0';
				cur = HT[cur].lchild;
			}
			else
			{   //�����ǰ�ڵ���Ҷ�ӽڵ㣬����ֹ���룬�����䱣������  
				code[code_len] = '\0';
				HC[cur] = (char *)malloc((code_len + 1) * sizeof(char));
				if (!HC[cur])
				{
					printf("HC[cur] malloc faild!");
					exit(-1);
				}
				strcpy(HC[cur], code);  //���Ʊ��봮  
			}
		}
		else if (HT[cur].weight == 1)
		{
			HT[cur].weight = 2;   //���������Һ��Ӿ�����������  
			if (HT[cur].rchild != -1)
			{   //�����ǰ�ڵ㲻��Ҷ�ӽڵ㣬����±��룬���������ұ���  
				code[code_len++] = '1';
				cur = HT[cur].rchild;
			}
		}

		
		else
		{
			HT[cur].weight = 0;
			cur = HT[cur].parent;
			--code_len;
		}

	}
	for (int i = 0; i < n; ++i) {
		printf("%s\n", HC[i]);
	}
	free(code);
}
int countWPL1(HuffmanTree HT, int n)
{
	int i,countRoads,WPL=0;
	/*
	��creat_huffmanTree����������֪��HT[0]��HT[1]...HT[n-1]��ŵľ��Ǹ���Ҷ�ӽ�㣬
	���԰�����Ҷ�ӽ��Ĵ�Ȩ·�����ȼ���
	*/
	for (i = 0; i < n; i++)
	{
		int father = HT[i].parent; //��ǰ�ڵ�ĸ��ڵ�
		countRoads = 0;//�õ�ǰ·������Ϊ0
		//��Ҷ�ӽڵ�����շ�����ֱ�����ڵ�
		while (father != -1)
		{
			countRoads++;
			father = HT[father].parent;
		}
		WPL += countRoads * HT[i].weight;
	}
	return WPL;
}

int countWPL2(HuffmanTree HT, int n)
{
	int cur = 2 * n - 2;    //��ǰ�������Ľڵ����ţ���ʼʱΪ���ڵ����  
	int countRoads=0, WPL=0;//countRoads����Ҷ�ӽ���·������
	int visit[maxSize] = { 0 };//visit[]�Ǳ�ע����,��ʼ��Ϊ0

	//�Ӹ��ڵ㿪ʼ���������ص����ڵ����  
	//��curΪ���ڵ��parentʱ���˳�ѭ��  
	while (cur != -1)
	{
		//���Һ��Ӿ�δ�����������������  
		if (visit[cur]==0)
		{
			visit[cur] = 1;    //�����������Ѿ�����������  
			if (HT[cur].lchild != -1)
			{   //�����ǰ�ڵ㲻��Ҷ�ӽڵ㣬��·������+1���������������  
				countRoads++;
				cur = HT[cur].lchild;
			}
			else
			{   //�����ǰ�ڵ���Ҷ�ӽڵ㣬�����˽��Ĵ�Ȩ·�����ȣ������䱣������  
				WPL += countRoads * HT[cur].weight;
			}
		}
		else if (visit[cur]==1)
		{
			visit[cur] = 2;
			if (HT[cur].rchild != -1)
			{  
				countRoads++;
				cur = HT[cur].rchild;
			}
		}
		else
		{
			visit[cur] = 0;
			cur = HT[cur].parent;
			--countRoads;
		}

	}
	return WPL;
}