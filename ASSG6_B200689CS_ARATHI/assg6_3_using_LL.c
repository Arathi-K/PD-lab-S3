#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct node
{
	char data;
	struct node* next;
};
struct Stack
{
    struct node* top;
};
typedef struct Stack* stack;
struct node* CREATE_NODE(char k)
{
	struct node* new=(struct node*)malloc(sizeof(struct node));
	new->data=k;
	new->next=NULL;
	return new;
}

int Stack_empty(stack S)
{
    if(S->top==NULL)
        return -1;
    else 
        return 1;
}

void PUSH(stack S,char k)
{
      struct node* x=CREATE_NODE(k);
      x->next=S->top;
      S->top=x;
}
char POP(struct Stack* S)
{
	if(Stack_empty(S)!=-1)// Not empty
	{	
		struct node* r=S->top;
		S->top=S->top->next;
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

int precedence(char a)
{
	if(a=='^')
		return 3;
	else if(a=='*' || a=='/')
		return 2;
	else if(a=='+' || a=='-')
		return 1;
	return 0;
}

void InfixToPostfix(stack S,char* infix_exprsn,char* postfix_exprsn)
{
    // printf("1...%s\n",infix_exprsn);
    // printf("1...%s\n",postfix_exprsn);
	int x=0;
	int len=strlen(infix_exprsn);
	
	for(int i=0;i<len;i++)
	{
	   // printf("\npostfix is:");
	   // for(int i=0;i<strlen(postfix_exprsn);i++)
    //         printf("%c",postfix_exprsn[i]);
    // 	printf("\n");
    // 	if(S->top==NULL)
    // 	    printf("stack empty");
    // 	else 
    // 	    printf("S->top->data=%c",S->top->data);
	   // printf("infix_exprsn[%d]=%c\n",i,infix_exprsn[i]);
		if(isalnum(infix_exprsn[i])!=0)//if its an operand
			{
			 //   printf("%c=oprerand\n",infix_exprsn[i]);
			   // printf("%c..\n",infix_exprsn[i]);
			    postfix_exprsn[x]=infix_exprsn[i];
			 //   printf("added to postfix\n");
			   // printf("%c\n",postfix_exprsn[x]);
			    x++;
			}
		
		else if(isoperator(infix_exprsn[i])==1)
		{
		  //   printf("%c=operator\n",infix_exprsn[i]);
		    if(Stack_empty(S)==-1)
		    {
		       PUSH(S,infix_exprsn[i]); 
		      // printf("pushed to stack (stack is empty");
		       //printf("%c\n",S->arr[S->top]);
		    }
		    else
		    {
		      //  printf("S->top= %c",S->top->data);
			while(S->top!=NULL && precedence(S->top->data)>=precedence(infix_exprsn[i]))
					{
					   // printf("added %c to postfix",S->top->data);
					    postfix_exprsn[x]=POP(S);
					   // printf("%s\n",postfix_exprsn);
					    x++;
					}

      		 	PUSH(S,infix_exprsn[i]);
      		 //	printf("%c\n",S->arr[S->top]);
		    }
		}
		else if(infix_exprsn[i]=='(')
		{
		     //printf("count=%d\n",count++);
			PUSH(S,infix_exprsn[i]);
		}
		else if(infix_exprsn[i] == ')')         /* if current symbol is ')' then */
		{
			int K = POP(S);                   /* pop and keep popping until */
			while(K != '(')                /* '(' encounterd */
			{
				postfix_exprsn[x] = K;
				x++;
				K = POP(S);
			}
		}
		
		
	}
	while(Stack_empty(S)!=-1)
		{
		    postfix_exprsn[x]=POP(S);
		   // printf("%s\n",postfix_exprsn);
		    x++;
		}
}
void main()
{
    char infix_exprsn[500];
    char postfix_exprsn[500];
    stack S=(stack)malloc(sizeof(stack));
     scanf("%s",infix_exprsn);
    InfixToPostfix(S,infix_exprsn,postfix_exprsn);
    for(int i=0;i<strlen(postfix_exprsn);i++)
        printf("%c",postfix_exprsn[i]);
}
