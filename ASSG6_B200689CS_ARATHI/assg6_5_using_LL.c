#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct node
{
	int data;
	struct node* next;
};
struct Stack
{
    struct node* top;
};
typedef struct Stack *stack;
int Stack_empty(stack S)
{
    if(S->top==NULL)
        return -1;
    else 
        return 1;
}
struct node* CREATE_NODE(int k)
{
	struct node* x=(struct node*)malloc(sizeof(struct node));
	x->data=k;
	x->next=NULL;
	return x;
} 
void PUSH(stack S,int k)
{
      struct node* x=CREATE_NODE(k);
      x->next=S->top;
      S->top=x;
}
int POP(struct Stack* S)
{
	if(Stack_empty(S)!=-1)// Not empty
	{	
		struct node* r=S->top;
		printf("S->top->data=%d \n",S->top->data);
		printf("r->data=%d ",r->data);
		S->top=S->top->next;
		printf("r->data=%d ",r->data);
		return r->data;
	}
}
int isoperator(char ch)
{
    if(ch=='/'||ch=='*'||ch=='+'||ch=='-')
        return 1;
    else
        return 0;
}

int Evaluate_postfix(stack S,char postfix_exprsn[])
 { 
    int num,i,x,a,b,result;
    
    
    int len=strlen(postfix_exprsn);
	for(i=0;i < len-1;i++)
	{
	    int x=0;
		if(isoperator(postfix_exprsn[i])==1)//if its an operator
		{
		    b=POP(S);
		    a=POP(S);
		     printf("popped %d and %d out of the stack\n",a,b);
		    result=0;
		    switch(postfix_exprsn[i])
		    {
		    case '+':
		     result=a+b;
		     printf("%d + %d = %d\n",a,b,result);
			 break;
		    case '-':
		     result=a-b;
		     printf("%d - %d = %d\n",a,b,result);
			 break;
		    case '/':
		     result=a/b;
		     printf("%d / %d = %d\n",a,b,result);
			 break;
		    case '*':
		     result=a*b;
		     printf("%d * %d = %d\n",a,b,result);
			 break;
		    }
		    i++;
		    printf("pushed %d into the stack\n",result);
	    	PUSH(S,result);
		}
		else
		{
		    num=0;
		    while(postfix_exprsn[i]!=' ')  
		    {
		        num = num*10 + (int)postfix_exprsn[i]-48;
		        i++;
		    }
		    printf("pushed %d into the stack\n",num);
		     PUSH(S,num); 
		}
	}
	return POP(S);
	//return S->top->data;
}
		   
		   
		   
void main()
{
    char postfix_exprsn[500];
    int result=0;
     fgets(postfix_exprsn, 500, stdin);
    stack S=(stack)malloc(sizeof(stack));
    result=Evaluate_postfix(S,postfix_exprsn);
    printf("%d",result);
}
