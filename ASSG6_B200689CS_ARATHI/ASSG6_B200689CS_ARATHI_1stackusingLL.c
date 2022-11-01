#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct Stack
{
	struct node* top;
};
struct node* CREATE_NODE(int k)
{
	struct node* x=(struct node*)malloc(sizeof(struct node));
	x->data=k;
	x->next=NULL;
	return x;
}
int Stack_empty(struct Stack* S)
{
	if(S->top==NULL)
		return -1;
	else
		return 1;
}
void PUSH(struct Stack* S,struct node* x)
{
	x->next=S->top;
	S->top=x;
}
void POP(struct Stack* S)
{
	if(Stack_empty(S)==-1)
		printf("-1\n");
	else
	{
		printf("%d\n",S->top->data);
       	        S->top=S->top->next;
	}
}


void main()
{
	char ch;
	int k;
	struct node* x;
//	scanf(" %c",&ch);
	struct Stack* S=(struct Stack*)malloc(sizeof(struct Stack));
	while(1)
	{
		scanf(" %c",&ch);

		switch(ch)
		{
		case 'i':scanf("%d",&k);
			 x=CREATE_NODE(k);
			 PUSH(S,x);
			 break;
		case 'd':POP(S);
			 break;
		case 'e':printf("%d\n",Stack_empty(S));
			 break;
		case 't':exit(0);
		}
	}
}
