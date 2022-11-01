#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int count=1;
struct Stack
{
    int top;
    unsigned capacity;
    char* arr;
};
typedef struct Stack *stack;
int Stack_empty(stack S)
{
    if(S->top==-1)
        return -1;
    else 
        return 1;
}

void PUSH(stack S,char k)
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

int InfixToPostfix(stack S,char* infix_exprsn,char* postfix_exprsn)
{
    // printf("1...%s\n",infix_exprsn);
    // printf("1...%s\n",postfix_exprsn);
	int x=0;
	int len=strlen(infix_exprsn);
	for(int i=0;infix_exprsn[i]!='\0';i++)
	{
	    //printf("%c..\n",infix_exprsn[i]);
		if(isalnum(infix_exprsn[i])!=0)//if its an operand
			{
			   // printf("%d=oprerand\n",count++);
			   // printf("%c..\n",infix_exprsn[i]);
			    postfix_exprsn[x]=infix_exprsn[i];
			   // printf("%c\n",postfix_exprsn[x]);
			    x++;
			}
		
		else if(isoperator(infix_exprsn[i])==1)
		{
		    // printf("%d=operator\n",count++);
		    if(Stack_empty(S)==-1)
		    {
		       PUSH(S,infix_exprsn[i]); 
		       //printf("%c\n",S->arr[S->top]);
		    }
		    else
		    {
			while(precedence(S->arr[S->top])>=precedence(infix_exprsn[i]))
					{
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
			//printf("%c\n",S->arr[S->top]);
		//	 printf("%c..\n",infix_exprsn[i]);
		len--;
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
			len--;
		}
		
		
		
		
		else if(infix_exprsn[i]== ')')
		{
		    //printf("%c",infix_exprsn[i]);
		    // printf("count=%d\n",count++);
			while(S->top != '(')
			   {
			      // postfix_exprsn[x]=POP(S);
			     //printf("%c\n",postfix_exprsn[x]);
			       x++;
			   }
			POP(S);
		}  
		
	}
	while(Stack_empty(S)!=-1)
		{
		    postfix_exprsn[x]=POP(S);
		   // printf("%s\n",postfix_exprsn);
		    x++;
		}
	return len;
}
void main()
{
    char infix_exprsn[500];
    char postfix_exprsn[500];
    stack S=(stack)malloc(sizeof(stack));
     scanf("%s",infix_exprsn);
     int len=strlen(infix_exprsn);
    // infix_exprsn[len]='\0';
    //printf("%d\n",len);
    //printf("%s\n",infix_exprsn);
    S->capacity=500;
    S->top=-1;
    //printf("stack capacity is %d ",S->capacity);
    S->arr=(char*)malloc(S->capacity*sizeof(char));
    len=InfixToPostfix(S,infix_exprsn,postfix_exprsn);
    for(int i=0;i<len;i++)
        printf("%c",postfix_exprsn[i]);
}
