#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
	struct node* next;
};
struct Stack
{
  struct node* top;
};
struct ExpressionTree
{
	struct node* root;
};
struct node* CREATE_NODE(struct node* l,struct node* r,char k)
{
	struct node* x=(struct node*)malloc(sizeof(struct node));
	x->data=k;
	x->left=l;
	x->right=r;
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
struct node* POP(struct Stack* S)
{
	if(Stack_empty(S)!=-1)// Not empty
	{	
		struct node* r=S->top;
		S->top=S->top->next;
		return r;
	}
}
void Construct_tree(char* postfix_exprsn,struct ExpressionTree* T)
{
	int len=strlen(postfix_exprsn);
	struct Stack* S=(struct Stack*)malloc(sizeof(struct Stack));
	for(int i=0;i<len;i++)
	{
		if(postfix_exprsn[i]>=65 && postfix_exprsn[i]<=90 ||postfix_exprsn[i]>=97 && postfix_exprsn[i]<=122)
		{
			PUSH(S,CREATE_NODE(NULL,NULL,postfix_exprsn[i]));//when it is a letter its present in the leaf nodes
		}
		else
		{
			struct node* b=POP(S);
			struct node* a=POP(S);
			PUSH(S,CREATE_NODE(a,b,postfix_exprsn[i]));
		}
	}
	T->root=POP(S);
}
void INORDER(struct node* x)
{
    if(x!=NULL)
   {
    INORDER(x->left);
    printf("%c",x->data);
    INORDER(x->right);
   }
}				
void PREORDER(struct node* x)
{
   if(x!=NULL)
   {
    printf("%c",x->data);
    PREORDER(x->left);
    PREORDER(x->right);
   }
}
void POSTORDER(struct node* x)
{
   if(x!=NULL)
   {
    POSTORDER(x->left);
    POSTORDER(x->right);
    printf("%c",x->data);
   }
}

void main()
{
    char ch;
    char* postfix_exprsn;
    struct ExpressionTree* T=(struct ExpressionTree*)malloc(sizeof(struct ExpressionTree));
    while(1)
    {
        scanf(" %c", &ch);
        switch(ch)
        {
            case 'e':
                 scanf(" %s",postfix_exprsn);
                 Construct_tree(postfix_exprsn,T);
                 break;
            case 'i':
                 INORDER(T->root);
		 printf("\n");
                 break;

             case 'p':
                PREORDER(T->root);
		printf("\n");
                 break;
            case 's':
                POSTORDER(T->root);
		printf("\n");
                 break;
            case 't':
                 exit(0);
                 break;
        }
    }
}
