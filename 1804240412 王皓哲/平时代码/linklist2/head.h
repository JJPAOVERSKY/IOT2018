#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
typedef int ElemType;
typedef struct LNode{
   ElemType data;  //���Ԫ��ֵ
   struct LNode *next;//ָ����ָ���̽��
}LinkList;

void CreateListHead(LinkList *&L,ElemType a[],int n);//ͷ�巨����
void CreateListTail(LinkList *&L,ElemType a[],int n);//β�巨����
void DispList(LinkList *L);//���
int main();