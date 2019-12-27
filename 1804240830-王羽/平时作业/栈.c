#define Status int
#define SElemType int
#define MaxSize 100
typedef struct Stack
{
	SElemType *base;//栈底指针 不变
	SElemType *top;//栈顶指针
	int stacksize;//栈可用的最大容量
}SqStack;
Status InitStack(SqStack &s)
{
	s.base=new SElemType[MaxSize];//动态分配最大容量
	if(!s.base)
	{
		printf("分配失败\n");
		return 0;
	}
	s.top=s.base;//栈顶指针与栈底相同
	s.stacksize=MaxSize;
	return 1;
}
Status Push(SqStack &s,SElemType e)//入栈
{
	if(s.top-s.base==s.stacksize)
		return 0;//栈满
	*(s.top++)=e;//先入栈，栈顶指针再上移
	return 1;
}
Status Pop(SqStack &s,SElemType &e)//出栈 用e返回值
{
	if(s.top==s.base) return 0;//栈空
	e=*--s.top;//指向栈顶元素，把值赋予e
	return 1;
}
bool GetTop(SqStack s,SElemType &e) //得到栈顶元素，不修改指针
{
	if(s.top==s.base) return false;//栈空
	else e=*--s.top;
	return true;
}
void PushToStack(SqStack &s)//入栈功能函数 调用Push函数
{
	int n;
	SElemType e;
	int flag;
	printf("请输入入栈元素个数(>=1)：\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("请输入第%d个元素的值:",i+1);
		scanf("%d",&e);
		flag=Push(s,e);
		if(flag)printf("%d已入栈\n",e);
		else {printf("栈已满！！！\n");break;}
	}
}
void PopFromStack(SqStack &s)//出栈功能函数 调用Pop函数
{
	int n;SElemType e;int flag;
	printf("请输入出栈元素个数(>=1)：\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		flag=Pop(s,e);
		if(flag)
			printf("%d已出栈\n",e);
		else
		{
			printf("栈已空！！！\n");
			break;
		}
	}
}
void StackEmpty(SqStack &s)
{
    if(s.top==s.base)
		printf("栈为空\n");
	else
		printf("栈不为空\n");

}
void GetTopOfStack(SqStack &s)//取栈顶功能函数 调用GetTop
{
	SElemType e;
	bool flag;
	flag=GetTop(s,e);
	if(flag)printf("栈顶元素为:%d\n",e);
	else
		printf("栈已空！！！\n");
}
Status ClearStack(SqStack &S)//清空栈
{

	S.top=S.base;
	printf("清空成功\n");
	return true;
 }
int StackLength(SqStack S)
{
    if(S.base==S.top)
	{
        return 0;
    }
    return S.top-S.base;
}
Status DestroyStack(SqStack &S)
{
    free(S.base);
    free(S.top);
    S.base=NULL;
	printf("销毁成功\n");
	return true;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "head.h"
#include<iostream.h>
int main()//主函数
{
	int choice;
	SqStack s;
	InitStack(s);
	printf("初始化成功！\n");//初始化
	while(1)
	{
		printf("请输入菜单序号：\n");
		printf("1.入栈\n");
		printf("2.出栈\n");
		printf("3.取栈顶\n");
		printf("4.判空\n");
		printf("5.求长\n");
		printf("6.清空\n");
		printf("7.销毁\n");
		printf("0.退出\n");
		scanf("%d",&choice);
		if(choice==0) break;
		switch(choice)
		{
		case 1:PushToStack(s);
			break;
		case 2:PopFromStack(s);
			break;
		case 3:GetTopOfStack(s);
			break;
		case 4:StackEmpty(s);
			break;
		case 5:printf("栈的长度：%d\n",StackLength(s));
			getchar();
			break;
		case 6:ClearStack(s);
			break;
		case 7:DestroyStack(s);
			break;
		default:printf("输入错误！！！\n");
		}
	}
	return 0;
}