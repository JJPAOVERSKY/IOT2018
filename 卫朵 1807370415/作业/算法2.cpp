#define MaxSize 5 
#include<stdio.h> 
#include<malloc.h> 
struct queue{ 
int qu[MaxSize]; 
int front; 
int rear; 
int tag; //front==rearʱ��ʾ��������յı�־��tag==1��ʾ����tag==0��ʾ�� 
}; 
struct queue *InitQu() 
{struct queue *q; 
q=(struct queue *)malloc(sizeof(struct queue));//����ռ� 
q->front=0; 
q->rear=0; 
q->tag=0; 
return q; 
} 
int EnQu(struct queue *q,int x) 
{ 
if(q->rear==q->front && q->tag==1)//��ʾ�������� 
return 0; 
else 
{ q->qu[q->rear]=x; 
q->rear=(q->rear+1)%MaxSize; //βָ�������һ�� 
if(q->rear==q->front) //����Ԫ������Ժ����q->rear==q->front�����ʾ������ 
q->tag=1; 
return 1; 
} 
} 
int DeQu(struct queue *q) 
{ 
if(q->rear==q->front && q->tag==0)//��ʾ�ӿ� 
return 0; 
else 
{ q->qu[q->front]=0;//����ͷԪ�ص�ֵ��ֵΪ0 
q->front=(q->front+1)%MaxSize;//ͷָ�������һ�� 
if(q->rear==q->front)//����Ԫ�س����Ժ����q->rear==q->front�����ʾ���п� 
q->tag=0; 
return 1; 
} 
} 
void Display(struct queue *q) 
{int n,i;//nΪ������Ԫ�صĸ��� 
if(q->rear==q->front && q->tag==1)//������ 
n=MaxSize; 
else 
n=(q->rear-q->front+MaxSize)%MaxSize; 
for(i=0;i<n;i++) 
printf("%4d",q->qu[(q->front+i)%MaxSize]); 
printf("\n"); 
} 
main() 
{struct queue *q; 
int c,k,x; 
q=InitQu(); 
loop: 
printf("---------(1).������밴���ּ�1.---------------"); 
printf("\n---------(2).�������밴���ּ�2.---------------"); 
printf("\n---------(3).��ӡ�����밴���ּ�3.-------------"); 
printf("\n��ѡ��Ҫ���еĲ���:"); 
scanf("%d",&c); 
switch(c) 
{ case 1:{ 
do{ 
printf("���������Ԫ�ص�ֵ:"); 
scanf("%d",&x); 
EnQu(q,x); 
printf("\n�Ƿ�������,���밴���ּ�1,�����밴�������ּ�!"); 
scanf("%d",&k); 
}while(k==1); 
goto loop; 
break; 
} 
case 2:{ 
do{ 
DeQu(q); 
printf("\n�Ƿ��������,���밴���ּ�1,�����밴�������ּ�!"); 
scanf("%d",&k); 
}while(k==1); 
goto loop; 
break; 
} 
case 3:{ Display(q); 
goto loop; 
break; 
} 
} 
printf("\n"); 
