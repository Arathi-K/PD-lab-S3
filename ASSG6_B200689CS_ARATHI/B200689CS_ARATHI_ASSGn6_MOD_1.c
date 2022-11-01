#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct node
{
    char data;
    struct node* left;
    struct node* right;
    struct node *next; 
};
struct Stack
{
    struct node *top; 
};
struct ExpressionTree
{
	struct node* root;
};
struct node* CREATE_NODE(struct node* l,struct node* r,char k)
{    //printf("hhi..welcome to create node\n");
    struct node* x;
    x=(struct node*)malloc(sizeof(struct node));
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

void CREATE_EXPRESSIONTREE(struct Stack* S,char* postfix_exprsn,struct ExpressionTree* T)
{
    S->top=NULL;
	int len=strlen(postfix_exprsn);
	//printf("len is %d \n",len);
	for(int i=0;i<len-1;i++)
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
		//	printf("S->top->data=%c",S->top->data);
		//	printf("S->top->left=%c",S->top->left->data);
		//	printf("S->top->right=%c",S->top->right->data);
		}
	}
	T->root=POP(S);
	//printf("T->root->data=%c",T->root->data);
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
int InfixToPostfix(struct Stack* S,char* infix_exprsn,char* postfix_exprsn)
{
    S->top=NULL;
    // printf("1...%s\n",infix_exprsn);
    // printf("1...%s\n",postfix_exprsn);
	int x=0;
	struct node* tempnode;
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
		       tempnode=CREATE_NODE(NULL,NULL,infix_exprsn[i]);
		       PUSH(S,tempnode); 
		      // printf("pushed to stack (stack is empty");
		       //printf("%c\n",S->arr[S->top]);
		    }
		    else
		    {
		      //  printf("S->top= %c",S->top->data);
			while(S->top!=NULL && precedence(S->top->data)>=precedence(infix_exprsn[i]))
					{
					   // printf("added %c to postfix",S->top->data);
					    postfix_exprsn[x]=POP(S)->data;
					   // printf("%s\n",postfix_exprsn);
					    x++;
					}
			tempnode=CREATE_NODE(NULL,NULL,infix_exprsn[i]);
      		 	PUSH(S,tempnode);
      		 //	printf("%c\n",S->arr[S->top]);
		    }
		}
		else if(infix_exprsn[i]=='(')
		{
		     //printf("count=%d\n",count++);
			tempnode=CREATE_NODE(NULL,NULL,infix_exprsn[i]);
      		 	PUSH(S,tempnode);
		}
		else if(infix_exprsn[i] == ')')         /* if current symbol is ')' then */
		{
			char K = POP(S)->data;                   /* pop and keep popping until */
			while(K != '(')                /* '(' encounterd */
			{
				postfix_exprsn[x] = K;
				x++;
				K = POP(S)->data;
			}
		}
		
		
	}
	while(Stack_empty(S)!=-1)
		{
		    postfix_exprsn[x]=POP(S)->data;
		   // printf("%s\n",postfix_exprsn);
		    x++;
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
    struct ExpressionTree* T_right=(struct ExpressionTree*)malloc(sizeof(struct ExpressionTree));
    struct ExpressionTree* T=(struct ExpressionTree*)malloc(sizeof(struct ExpressionTree));
    int i=0;
    char k,a,b;
    char infix[1000],postfix[1000];
     scanf("%c",&a);
      scanf("%c",&b);
     // printf("a=%c,b=%c\n",a,b);
    while(1)
    {
        scanf("%c",&k);
        if(k==';')
            break;
        else
            infix[i++]=k;
    }
	//Read and store into a character array until a ; is encountered
	//Create expression tree
	//print post order traversal
	struct Stack* S=(struct Stack*)malloc(sizeof(struct Stack));
	InfixToPostfix(S,infix,postfix);
	//printf("infix is %s",infix);
	//printf("postfix is %s",postfix);
	CREATE_EXPRESSIONTREE(S,postfix,T_right);
	//POSTORDER(T_right->root);
	struct node* x=CREATE_NODE(NULL, NULL,a);
	T->root=CREATE_NODE(x, T_right->root,b);
	POSTORDER(T->root);
}

