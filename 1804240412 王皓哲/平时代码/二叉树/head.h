#include<stdio.h>
#include <malloc.h>
#include<stdlib.h>
#include <iostream>
#include<cstdio>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef int Status;
typedef char TElemType;

typedef struct Node	//�������ṹ
{
    char data;
    struct Node *lchild,*rchild;
}*BiTree,BiTNode;

enum PointerTag{Link,Thread};//Link==0��ָ�룻Thread==1������

typedef struct BiThrNode

{

        TElemType data;    //�������

        PointerTag ltag, rtag;//���ұ�־

        struct BiThrNode *lchild,*rchild;//���Һ���ָ��

}BiThrNode,*BiThrTree;

typedef struct Node{
	int weight;                
	int parent;                
	int lchild, rchild;          
}HTNode, *HuffmanTree;          
typedef char **HuffmanCode;   


void CreateBiTree(BiTree &T);
void InOrderTraverse(BiTree T);
void PreOrderTraverse(BiTree T);
void PostOrderTraverse(BiTree T);
//int InOrderThreading(BiThrTree &Thrt,BiThrTree T);



Status PrintElement(TElemType e);// �����������ֵ
Status CreateBiThrTree(BiThrTree &T);
Status InOrderTraverse_Thr(BiThrTree T, Status(*Visit)(TElemType e));
void InThreading(BiThrTree p,BiThrTree &pre);
Status InOrderThreading(BiThrTree &Thrt, BiThrTree T);

HuffmanTree create_HuffmanTree(int *wet, int n);
void select_minium(HuffmanTree HT, int k, int &min1, int &min2);
int min(HuffmanTree HT, int k);
void HuffmanCoding1(HuffmanTree HT, HuffmanCode &HC, int n);
void HuffmanCoding2(HuffmanTree HT, HuffmanCode &HC, int n);
int countWPL1(HuffmanTree HT, int n);
int countWPL2(HuffmanTree HT, int n);