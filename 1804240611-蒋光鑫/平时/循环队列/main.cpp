#include"head.h"
int main()
{
	SqQueue Q;
	for(;;)
	{
		switch(menu_select())
		{
		case 1:
			InitQueue(Q);
			printf("\n");
			break;
		case 2:
			printf("���г���Ϊ:%d\n",QueueLength(Q));
			break;
		case 3:
			InQueue(Q);
			printf("success!\n");
			break;
		case 4:
			//Browser(Q);
			printf("Success!\n");
			break;
		case 5:
			DelQueue(Q);
			//printf("ɾ��Ԫ��Ϊ%d",e);
			break;
		case 0:
			printf("���������лл��\n");
			exit(0);
		}
		
	}
	return 0;
}
