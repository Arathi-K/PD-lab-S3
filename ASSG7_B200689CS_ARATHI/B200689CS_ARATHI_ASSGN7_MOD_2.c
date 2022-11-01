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
struct node* TREE_mininum(struct node* given_node)
{
	//printf("welcome to TREE_mininum");
	while(given_node->left !=NULL)
		given_node=given_node->left;
	return given_node;
//	printf("exit from TREE_mininum");
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
	//printf("inserted %d ",new->key);
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
struct node* SEARCH(struct node* root,int info)
{
//	printf("welcome to search");
//	printf("%d",info);
	if(root==NULL || info==root->key)
		return root;
	if(info< root->key)
		return SEARCH(root->left,info);
	else 
		return SEARCH(root->right,info);
	//printf("exit from search");
}
struct node* SUCCESSOR(struct BST* T,int info)
{
	  //printf("welcome to SUCCESSOR");
	struct node* given_node=SEARCH(T->root,info);
	if(given_node==NULL)return NULL;
	// printf("given node's key is: %d",given_node->key);
	//  printf("root's key is: %d",T->root->key);
	if(given_node->right !=NULL)
		return TREE_mininum(given_node->right);
	struct node* sucsr=given_node->parent;
	while(sucsr!=NULL && given_node==sucsr->right)
	{
		given_node=sucsr;
		sucsr=sucsr->parent;
	}
// 	if(given_node->parent!=NULL)
// 	        printf("given node's parent's key is: %d",given_node->parent->key);
// 	 printf("exit from SUCCESSOR");
	 //if(sucsr>given_node)
	        return sucsr;
	  //else return NULL;
}
void TRANSPLANT(struct BST* T, struct node* remove, struct node* replace_by_me)
{//printf("replace_by_me  %p ",replace_by_me);
	if(remove->parent ==NULL)
		T->root=replace_by_me;
	else if(remove==remove->parent->left)//if its the left child
		remove->parent->left=replace_by_me;
	else
		remove->parent->right=replace_by_me;
	if(replace_by_me!=NULL)
		replace_by_me->parent=remove->parent;
}
void DELETE(struct BST* T, struct node* given_node)
{
	if(given_node->left==NULL)//either leaf node or node with only right child
	{	//printf("Deleting...%d ",given_node->key);
		//printf("right  %p ",given_node->right);
		TRANSPLANT(T,given_node,given_node->right);
	}
	else if(given_node->right==NULL)//only left child
		TRANSPLANT(T,given_node,given_node->left);
	else//both left and right present
	{
		struct node* succsr=SUCCESSOR(T,given_node->key);//we know that this successor will be to the right of the given node & that it will not have a left child 
		//case c5
		if(succsr->parent==given_node)//succsr is the right child of given node
		{
		TRANSPLANT(T,given_node,succsr);
		succsr->left=given_node->left;
		succsr->left->parent=succsr;	
		}
		else
		{
			TRANSPLANT(T,succsr,succsr->right);
			succsr->right=given_node->right;
			succsr->right->parent=succsr;
			
			TRANSPLANT(T,given_node,succsr);
			succsr->left=given_node->left;
			succsr->left->parent=succsr;
		}
	}
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
 struct node* TREE_maximum(struct node* given_node)
{
//	printf("welcome to TREE_maximum");
	while(given_node->right !=NULL)
		given_node=given_node->right;
		//printf("max is %d",given_node->key);
	return given_node;
//	printf("exit from TREE_maximum");
}
void main()
{
	char info;
	struct node* present;
	int k,num=0,i=0,len1=0,len2=0;
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
		     len1++;
		   }
		   i++;
		}
		//printf("i=%d",i);
		//INORDER(T1->root);
   //printf("\n");
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
		    //printf("num..%d ",num);
		     INSERT(T2,num);
		     len2++;
		   }
		   i++;
		}
	//INORDER(T2->root);
   //printf("\n");
	present=TREE_maximum(T1->root);
	k=present->key;
	DELETE(T1,present);
	Combine1(T1,T2,k,T);
	/*for(i=0;i<len1;i++)
	{
		present=TREE_maximum(T1->root);
		DELETE(T1,present);
	}
	for(i=0;i<len2;i++)
	{
		present=TREE_maximum(T2->root);
		DELETE(T2,present);
		printf("\n%d.",i+1);
		INORDER(T2->root);
	}
	printf("\n");
	T1->root=NULL;
	T2->root=NULL;
	INORDER(T1->root);
	printf("\n");
	INORDER(T2->root);
	INORDER(T->root);*/
}
