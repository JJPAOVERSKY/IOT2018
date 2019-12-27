#include "head.h"

void CreateListHead(LinkList *&L, ElemType a[], int n)
{
	LinkList *s;
	L=(LinkList *)malloc(sizeof(LinkList));//����ͷ���
	L->next=NULL;//��ͷ���next���ÿ�
	for(int i=0;i<n;i++)
	{   
	    s=(LinkList *)malloc(sizeof(LinkList));//ѭ���������ݽ�㣬�������ݽ��*s
		s->data=a[i];//�����s����ԭ��ʼ�ڵ�֮ǰ��ͷ���֮��
		s->next=L->next;
		L->next=s;
	}
}

void CreateListTail(LinkList *&L, ElemType a[], int n)
{
    LinkList *s,*r;
	L=(LinkList *)malloc(sizeof(LinkList));//����ͷ���
	r=L;//rʼ��ָ��β��㣬��ʼʱͷ����β�����ͬһ��
	for(int i=0;i<n;i++)
	{
	  s=(LinkList *)malloc(sizeof(LinkList));//�������ݽ��
	  s->data=a[i];//������
	  r->next=s;//��s���뵽r��
	  r=s;//ʹrָ��β���
	}
	r->next=NULL;//βָ��ָ�����ÿ�
 
}

void DispList(LinkList *L)
{
	LinkList *p=L->next;//pָ��ʼ���
	while(p!=NULL)
	{
		cout<<p->data<<" "; //���������
		p=p->next;
	}
	cout<<endl;
}

int main()
{
    LinkList *L;
	int n;
	cout<<"n:";
	cin>>n;
	int *a=new int(n);
	for(int i=0;i<n;i++)
	{
	  cin>>a[i];
	}

	CreateListHead(L,a,n);	
	cout<<"ͷ�巨����";
	DispList(L);//���
 
	CreateListTail(L,a,n);	
	cout<<"β�巨����";
	DispList(L);//���
}