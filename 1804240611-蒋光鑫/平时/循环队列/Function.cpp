#include"head.h"
int  menu_select()
{
	int sn;
	printf("###################----");
	printf("\n");
	printf("      menu\n");
	printf("\n");
	printf("1:����ѭ������Q\n");
	printf("2:������г���\n");
	printf("3:����Ԫ��\n");
	printf("4:��������\n");
	printf("5:��ջԪ��\n");
	printf("6:\n");
	printf("7:\n");

	printf("0:�˳�\n");
	printf("###################");

	printf("\n");
	printf("enter your choice:");
	for(;;)
	{
		scanf("%d",&sn);
		if(sn<0||sn>9)
			printf("\n error!");
		else
			break;
	}
	return sn;
}

Status InitQueue(SqQueue &Q)
{
	Q.base=(QElemType*)malloc(MAXQSIZE* sizeof (QElemType));
	if(!Q.base)
		exit(OVERFLOW);
	Q.front=Q.rear=0;
	printf("�����ɹ���\n");
	return OK;
}

int QueueLength(SqQueue Q)	//������г���
{
	int Length;
	Length=(Q.front-Q.rear+MAXQSIZE)%MAXQSIZE;
	printf("���г���Ϊ:%d\n",Length);
	return 0;
}

Status InQueue(SqQueue &Q)
{
	int i,n,e;//����Ԫ�ظ���
	printf("�������Ԫ�ظ���\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("����Ҫ����ĵ�%d��Ԫ��\n",i+1);
		scanf("%d",&e);
		if((Q.rear+1)%MAXQSIZE==Q.front)
			return ERROR;
		Q.base[Q.rear]=e;
		Q.rear=(Q.rear+1)%MAXQSIZE;
		
	}
	return OK;
}

/*void Browser(SqQueue Q)
{
	while(Q.front<=Q.rear)
	{
		printf(" %d ",Q.front);
		Q.front++;
	}
}*/
int  Gethead(SqQueue Q)
{
	if(Q.front!=Q.rear)
		return Q.base[Q.front];
}
Status DelQueue(SqQueue &Q)	//ɾ����e����ֵ
{
	int e;
	if(Q.front=Q.rear)
		return ERROR;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXQSIZE;
	printf("ɾ��Ԫ��Ϊ%d",e);

		return OK;
}