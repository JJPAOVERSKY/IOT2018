#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>

using namespace std;

#define Status int
#define QElemType int
#define MaxQSize 100//ѭ���������ݽṹ

typedef struct
{
	QElemType data[MaxQSize];//������
	int front,rear;          //��ͷ��βָ��
}SqQueue;

void menu();
int main();
Status InitQueue(SqQueue &Q);
bool QueueEmpty(SqQueue Q);
bool EnQueue(SqQueue &Q,QElemType e);
bool DeQueue(SqQueue &Q,QElemType &e);
bool GetHead(SqQueue &Q,QElemType &e);
void EnterToQueue(SqQueue &Q);
void DeleteFromQueue(SqQueue &Q);
void GetHeadOfQueue(SqQueue Q);

