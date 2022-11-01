#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int count=1;
struct Stack
{
    int top;
    unsigned capacity;
    int* arr;
};
typedef struct Stack *stack;
int Stack_empty(stack S)
{
    if(S->top==-1)
        return -1;
    else 
        return 1;
}

void PUSH(stack S,int k)
{
       
        S->top=S->top+1;
        S->arr[S->top]=k;
}
char POP(stack S)
{
    if(Stack_empty(S)!=-1)//stack not empty
    {
        int r=S->arr[S->top];
        S->top--;
	return r;
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
		if(isoperator(postfix_exprsn[i])==1)
		{
		    b=POP(S);
		    a=POP(S);
		    result=0;
		    switch(postfix_exprsn[i])
		    {
		    case '+':
		     result=a+b;
			 break;
		    case '-':
		     result=a-b;
			 break;
		    case '/':
		     result=a/b;
			 break;
		    case '*':
		     result=a*b;
			 break;
		    }
		    i++;
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
		     PUSH(S,num); 
		}
	}
	return POP(S);
}
		   
		   
		   
void main()
{
    char postfix_exprsn[500];
    int result=0;
     fgets(postfix_exprsn, 500, stdin);

    stack S=(stack)malloc(sizeof(stack));
    S->arr=(int*)malloc(S->capacity*sizeof(int));
    S->capacity=500;
    S->top=-1;
    result=Evaluate_postfix(S,postfix_exprsn);
    printf("%d",result);
}
