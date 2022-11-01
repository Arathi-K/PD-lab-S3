#include<stdio.h>
#include <stdlib.h>
#include<string.h>
struct node
{
	int key;
	struct node* right;
	struct node* left;
	struct node* parent;
};
struct BST
{
   struct node* root; 
};
struct node* CREATE_NODE(int k)
{
	struct node* x=(struct node*)malloc(sizeof(struct node));
	x->key=k;
	x->right=NULL;
	x->left=NULL;
	x->parent=NULL;
	return x;
} 
void INSERT(struct BST* T,int info)
{
	//printf("Info is...%d ",info);
    //if(T->root==NULL)printf("ROOT null");
	struct node* new=CREATE_NODE(info);
	struct node* p=NULL;
	struct node* now=T->root;
	//if(T->root==NULL)printf("root null");
	while(now!=NULL)
	{
		p=now;
		if(new->key < now->key)
			now=now->left;
		else
			now=now->right;
	}
	new->parent=p;
	if(p==NULL)
		T->root=new;//printf("new element added as the root");
	else if (new->key < p->key)
		p->left =new;
	else p->right=new;
}
void INORDER(struct node* x)
{
   //printf("welcome to inorder");
    if(x!=NULL)
   {
    INORDER(x->left);
    printf("%d ",x->key);
    INORDER(x->right);
   }
   //printf("exit from inorder");
}
void Combine1(struct BST* T1,struct BST* T2,int k,struct BST* T)
{

	T->root=CREATE_NODE(k);
	T->root->left=T1->root;
	if(T1->root!=NULL)
	T1->root->parent=T->root;
	
	T->root->right=T2->root;
	if(T2->root!=NULL)
	T2->root->parent=T->root;
	
//Pass T1.root and make it the left subtree of T
//Pass each element of T1 to INSERT(T) function 
//Delete that node from T1
//Pass T2.root and make it the right subtree of T
//Pass each element of T2 to INSERT(T) function 
//Delete that node from T2
 INORDER(T->root);
 }

void main()
{
	char info;
	int k,num=0,i=0;
	struct BST* T1=(struct BST*)malloc(sizeof(struct BST));
	T1->root=NULL;
	struct BST* T2=(struct BST*)malloc(sizeof(struct BST));
	T2->root=NULL;
	struct BST* T=(struct BST*)malloc(sizeof(struct BST));
	T->root=NULL;
	char t1_arr[10000];
	char t2_arr[10000];
	int len;
	fgets(t1_arr,10000,stdin);
	//printf("....%s...",t1_arr);
	len=strlen(t1_arr);
	//printf("len%d",len);
	len=len-1;
	while(i<len)
		{
		    if(t1_arr[i]!=' ')  
		    {
			num = 0;
			while(t1_arr[i]!=' ' && i<len)
			{	      
		        num = num*10 +((int)t1_arr[i]-48);
		        i++;
		        }
		   // printf("num..%d ",num);
		     INSERT(T1,num);
		   }
		   i++;
		}
		//printf("i=%d",i);
		//INORDER(T1->root);
	//INORDER(T1->root);
	fgets(t2_arr,10000,stdin);
	//printf("%s",t2_arr);
	len=strlen(t2_arr);
	len--;
	num=0;
	i=0;
	//printf("%d",len);
	while(i<len)
		{
	
		    if(t2_arr[i]!=' ')  
		    {
			num = 0;
			while(t2_arr[i]!=' ' && i<len)
			{	      
		        num = num*10 +((int)t2_arr[i]-48);
		        i++;
		        }
		   // printf("num..%d ",num);
		     INSERT(T2,num);
		   }
		   i++;
		}
	//INORDER(T2->root);
	scanf("%d",&k);
	//printf("k=%d",k);
	Combine1(T1,T2,k,T);
}

