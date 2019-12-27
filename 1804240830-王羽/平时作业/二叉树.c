#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

typedef char DataType;
typedef struct Node 
{ 
	DataType data;
struct Node *LChild;
struct Node *RChild;
}BiTNode ,*BiTree;

void CreateBitree(BiTree *bt)
{ char ch;
ch=getchar();
if(ch=='.')
*bt=NULL;
else 
{ *bt=(BiTree)malloc(sizeof(BiTNode));
(*bt)->data=ch;
CreateBitree(&((*bt)->LChild));
CreateBitree(&((*bt)->RChild));
}
}

int Create(BiTree *T)
{//生成一个二叉树
  printf("按先序遍历的结果输入二叉树\n");
  printf("请输入先序遍历二叉树的结果,程序据此建立二叉树。\n");
  printf("对于叶子结点以空格表示。\n");
  printf("例如:abc..de.g..f...(回车)，建立如下二叉树：\n");
  printf("           a      \n");
  printf("          /       \n");
  printf("         b        \n");
  printf("        / \\       \n");
  printf("       c   d      \n");
  printf("          / \\     \n");
  printf("         e   f    \n");
  printf("          \\       \n");
  printf("           g      \n");
  CreateBitree(T);
  return OK;
}


int DestroyBiTree(BiTree *T)
{ if(*T)
{if((*T)->LChild) DestroyBiTree(&((*T)->LChild));   //销毁左子树
    if((*T)->RChild) DestroyBiTree(&((*T)->RChild));   //销毁右子树
    free(*T);   //销毁根结点
    *T=NULL;
  }
  return OK;
}


int Visit(char c)
{
  printf("%c",c);  //显示结点数据域
  return OK;
}


void preOrder(BiTree root)
{  if(root!=NULL)
{ Visit(root->data);
preOrder(root->LChild);
preOrder(root->RChild);
}
}

void  InOrder(BiTree root)  
{ if(root!=NULL)
{ preOrder(root->LChild);
preOrder(root);
preOrder(root->RChild);
}
}


void PostOrder(BiTree root)
{ if(root!=NULL)
{  preOrder(root->LChild);
preOrder(root->RChild);
preOrder(root);
}
}

void PrintTree(BiTree bt,int nLayer)
{ if(bt==NULL)
return ;
PrintTree(bt->RChild,nLayer+1);
int i;
for(i=0;i<nLayer;i++)
 printf(" ");
printf("%c\n",bt->data);
PrintTree(bt->LChild,nLayer+1);
}
void main(){
  BiTree T;
  int choice,flag=1;
  printf("本程序实现二叉树的操作:\n");
  printf("可以进行建立二叉树, 递归先序、中序、后序遍历等操作。\n");
  Create(&T);
  while(flag)
{
    printf("请选择: \n");
    printf("1.递归先序遍历\n");
    printf("2.递归中序遍历\n");
    printf("3.递归后序遍历\n");
    printf("4.按树状输出二叉树\n");
    printf("5.重新构建二叉树\n");
    printf("6.退出程序\n");
    scanf("%d",&choice);
    switch(choice){
      case 1:
	if(T){
	  printf("先序遍历二叉树:");
	  preOrder(T); //先序递归遍历二叉树
	  printf("\n");
	}
	else
	  printf("二叉树为空!\n");
	break;
      case 2:
	if(T){
	  printf("中序遍历二叉树:");
	  InOrder(T);  //中序递归遍历二叉树
	  printf("\n");
	}
	else
	  printf("二叉树为空!\n");
	break;
      case 3:
	if(T){
	  printf("后序遍历二叉树:");
	  PostOrder(T);//后序递归遍历二叉树
	  printf("\n");
	}
	else
	  printf("二叉树为空!\n");
	break;



哈夫曼树代码：
#include <stdio.h>
#include <stdlib.h>
#define N 20
#define M 2*N-1
typedef struct
{ int weight;
  int parent;
  int LChild;
  int RChild;
} HTNode ,HuffmanTree[M+1];

void select(HuffmanTree ht,int n,int *s1,int *s2)
{ int i=0;
int min;
for(i=1;i<=n;i++)
 if (ht[i].parent==0)
 {min=i; break;}
for(i=1;i<=n;i++)
{ if (ht[i].parent==0)
if(ht[i].weight<ht[min].weight)
min=i;
}
*s1=min;
for(i=1;i<=n;i++)
if (ht[i].parent==0&&i!=*s1)
{min=i;break;}
for(i=1;i<=n;i++)
{ if (ht[i].parent==0&&i!=*s1)
 if(ht[i].weight<ht[min].weight)
min=i;
}
*s2=min;
}
void crtHuffmanTree(HuffmanTree ht ,int w[],int n)
{ int i,m,s1,s2,sum=0;
	for(i=1;i<=n;i++)   //ht[i]={w[i],0,0,0};
	{ ht[i].weight=w[i];
	ht[i].parent=0;
	ht[i].LChild=0;
	ht[i].RChild=0;
	}
m=2*n-1;
for(i=n+1;i<=m;i++)
{ ht[i].weight=0;
	ht[i].parent=0;
	ht[i].LChild=0;
	ht[i].RChild=0;
	}
for(i=n+1;i<=m;i++)
{ select(ht,i-1,&s1,&s2);
ht[i].weight=ht[s1].weight+ht[s2].weight;
ht[s1].parent=i;   ht[s2].parent=i;
ht[i].LChild=s1;   ht[i].RChild=s2;
sum=sum+ht[i].weight;
}
printf("%d",sum);
}

void main()
{HuffmanTree HT;	
 int w[50],i,n,m;  
 printf("n=\n");
  scanf("%d",&n);     
 
  for(i=1; i<=n; i++)
 {
  scanf("%d",&w[i]);
  }
   crtHuffmanTree(HT, w, n);
}