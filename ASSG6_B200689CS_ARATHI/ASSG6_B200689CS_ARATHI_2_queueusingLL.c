#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct Queue
{
	struct node* head;
	struct node* tail;
};
struct node* CREATE_NODE(int k)
{
	struct node* x=(struct node*)malloc(sizeof(struct node));
	x->data=k;
	x->next=NULL;
	return x;
}
int QUEUE_EMPTY(struct Queue* Q)
{
	if(Q->head==NULL)
		return -1;
	else
		return 1;
}
void ENQUEUE(struct Queue* Q,struct node* x)
{
	if(QUEUE_EMPTY(Q)==-1)
	{
	    Q->head=x;
	    Q->tail=x;
	}
	else
	{
	Q->tail->next=x;
	Q->tail=x;
	}
}
void DEQUEUE(struct Queue* Q)
{
	if(QUEUE_EMPTY(Q)==-1)
		printf("-1\n");
	else
	{
		printf("%d\n",Q->head->data);
       	        Q->head=Q->head->next;
	}
}
void main()
{
	char ch;
	int k;
	struct node* x;
//	scanf(" %c",&ch);
	struct Queue* Q=(struct Queue*)malloc(sizeof(struct Queue));
	Q->head=NULL;
	Q->tail=NULL;
	while(1)
	{
		scanf(" %c",&ch);

		switch(ch)
		{
		case 'i':scanf("%d",&k);
			 x=CREATE_NODE(k);
			 ENQUEUE(Q,x);
			 break;
		case 'd':DEQUEUE(Q);
			 break;
		case 'e':printf("%d\n",QUEUE_EMPTY(Q));
			 break;
		case 't':exit(0);
		}
	}
}
