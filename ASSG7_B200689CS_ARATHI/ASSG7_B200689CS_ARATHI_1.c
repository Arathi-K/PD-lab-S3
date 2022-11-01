#include<stdio.h>
#include<stdlib.h>
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
struct node* SEARCH(struct node* root,int info)
{
	if(root==NULL || info==root->key)
		return root;
	if(info< root->key)
		return SEARCH(root->left,info);
	else 
		return SEARCH(root->right,info);
}
struct node* TREE_mininum(struct node* given_node)
{
	while(given_node->left !=NULL)
		given_node=given_node->left;
	return given_node;
}	
struct node* TREE_maximum(struct node* given_node)
{
	while(given_node->right !=NULL)
		given_node=given_node->right;
	return given_node;
}	
struct node* CREATE_NODE(int k)
{
	struct node* x=(struct node*)malloc(sizeof(struct node));
	x->key=k;
	x->right=NULL;
	x->left=NULL;
	x->parent=NULL;
	return x;
} 
void INORDER(struct node* x)
{
    if(x!=NULL)
   {
    INORDER(x->left);
    printf("%d ",x->key);
    INORDER(x->right);
   }
}				
void PREORDER(struct node* x)
{
   if(x!=NULL)
   {
    printf("%d ",x->key);
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
    printf("%d ",x->key);
   }
}
void TRANSPLANT(struct BST* T, struct node* remove, struct node* replace_by_me)
{
	if(remove->parent ==NULL)
		T->root=replace_by_me;
	else if(remove==remove->parent->left)//if its the left child
		remove->parent->left=replace_by_me;
	else
		remove->parent->right=replace_by_me;
	if(replace_by_me!=NULL)
		replace_by_me->parent=remove->parent;
}
struct node* SUCCESSOR(struct BST* T,int info)
{
	struct node* given_node=SEARCH(T->root,info);
	if(given_node==NULL)return NULL;
	if(given_node->right !=NULL)
		return TREE_mininum(given_node->right);
	struct node* sucsr=given_node->parent;
	while(sucsr!=NULL && given_node==sucsr->right)
	{
		given_node=sucsr;
		sucsr=sucsr->parent;
	}
	        return sucsr;
}
struct node* PREDECESSOR(struct BST* T,int info)
{
	struct node* given_node=SEARCH(T->root,info);
	if(given_node==NULL)return NULL;
	if(given_node->left !=NULL)
		return TREE_maximum(given_node->left);
	struct node* prdcsr=given_node->parent;
	while(prdcsr!=NULL && given_node==prdcsr->left)
	{
		given_node=prdcsr;
		prdcsr=prdcsr->parent;
	}
    return prdcsr;
}
void DELETE(struct BST* T, struct node* given_node)
{
	if(given_node->left==NULL)//either leaf node or node with only right child
		TRANSPLANT(T,given_node,given_node->right);
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
void INSERT(struct BST* T,int info)
{
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

void main()
{
	char ch;
	int info;
	struct node* present;
	struct BST* T=(struct BST*)malloc(sizeof(struct BST));
	T->root=NULL;
while(1)
	{
		scanf(" %c",&ch);

		switch(ch)
		{
    	case 'a':scanf("%d",&info);
			    INSERT(T,info);
			    break;
		case 'e':exit(0);
		case 'd':scanf("%d",&info);
			 present=SEARCH(T->root,info);
			 if(present==NULL)
			    printf("-1\n");
			 else
			    {
			        printf("%d\n",present->key);
			        DELETE(T,present);
			    }
			 break;
		case 'r':scanf("%d",&info);
			 present=PREDECESSOR(T,info);
			 if(present==NULL)
			 	printf("-1\n");
			 else 
			 	printf("%d\n",present->key);
			 break;
		case 'p':PREORDER(T->root);
		        printf("\n");
			 break;
		case 't':POSTORDER(T->root);
		        printf("\n");
			 break;
		case 's':scanf("%d",&info);
			     present=SEARCH(T->root,info);
			    if(present==NULL)
			 	printf("-1\n");
			    else 
			 	printf("1\n");
			    break;
		case 'c':scanf("%d",&info);
			    present=SUCCESSOR(T,info);
			     if(present==NULL)
			 	printf("-1\n");
			    else 
			 	printf("%d\n",present->key);
			    break;
		case 'i':INORDER(T->root);
		        printf("\n");
			     break;
		}
	}
}
