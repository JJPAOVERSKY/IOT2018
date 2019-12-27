#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10
typedef struct node* SeqStack;
typedef char ElementType;
struct node {
    ElementType data[MaxSize];
    int top;  //���ջ������  
};
//��ʼ��
void InitNode(SeqStack *L) {
    (*L) = (SeqStack)malloc(sizeof(struct node));
    (*L)->top = -1;
}
//��ջ
void PushStack(SeqStack L, ElementType x) {
    if (L->top == MaxSize - 1) {
        printf("����");
    }
    else {
        L->top++;  //��ջ���Լ�1
        L->data[L->top] = x;
    }
}
//��ջ
void PopStack(SeqStack L, ElementType *x) {
    if (L->top == -1) {
        printf("�յ�");
    }
    else {
        *x = L->data[L->top];
        L->top--;
    }
}
//�������
void PrintNode(SeqStack L) {
    for (int i = 0; i <= L->top; i++) {
        printf("%c", L->data[i]);
    }
    printf("\n");
}
int main() {
    SeqStack s;
    ElementType c;
    ElementType* y;
    y = &c;  //yָ��c��Ϊ�˳�ջ��
    InitNode(&s);
    printf("������ջ����");
    scanf("%c", &c);
    while (c != &apos;\n&apos;) {
        PushStack(s, c);
        scanf("%c", &c);
    }
    PrintNode(s);
    PopStack(s, y);
    printf("��ջԪ����%c\n", *y);
    PrintNode(s);
}
