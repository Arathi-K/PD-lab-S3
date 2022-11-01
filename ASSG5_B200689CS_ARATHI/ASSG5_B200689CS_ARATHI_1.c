#include<stdio.h>
#include<stdlib.h>
struct node
{
    char key;
    struct node *next; 
};
typedef struct node *node;
struct LL
{
    node head; 
};
typedef struct LL *LL;
node CREATE_NODE(char x)
    node temp;
    temp=(node)malloc(sizeof(struct node));
    temp->key=x;
    temp->next=NULL;
    return temp;
}
node LIST_SEARCH(LL L, char k)
{
node nowat=L->head;
while(nowat!=NULL && nowat->key!=k)
   nowat=nowat->next;
return nowat;
}

void LIST_INSERT_FRONT(LL L,node x)
{  
   x->next = L->head;
   L->head = x;
}
void LIST_INSERT_TAIL(LL L,node x)
{  // printf("welcome to LIST_INSERT_TAIL");
    node nowat= L->head;
    if(nowat!=NULL)
    {  
        while(nowat->next!=NULL)
            nowat=nowat->next;
        nowat->next=x;
    }
    else 
        L->head=x;
}
void LIST_INSERT_AFTER(LL L,node x,char y)
{  
    //printf("hii");
    node nowat= L->head;
    while(nowat->key!=y)
            nowat=nowat->next;
    x->next=nowat->next;
    nowat->next=x;

}
void LIST_INSERT_BEFORE(LL L,node x,char y)
{  
    node nowat= L->head;
    while(nowat->next->key!=y)
            nowat=nowat->next;
    x->next=nowat->next;
    nowat->next=x;
    
}
void LIST_DELETE(LL L,char ch)
{  
    node nowat= L->head;
    node thott_munb=nowat;
    //printf("nowat key:%c L->head key:%c thott_munb key:%c \n",nowat->key,L->head->key,thott_munb->key);
    if(L->head==NULL)
         printf("-1\n");
    else if(L->head->key==ch)
    {       
            if(L->head->next == NULL)
                {
                    L->head=NULL;
                    printf("-2\n");
                }
            else
            {
                L->head=nowat->next;
               printf("%c\n",nowat->next->key);
            }
    }
    else
    {
        while(thott_munb->next != NULL)
        {   
            if(nowat->key==ch)
            {
                if(nowat->next==NULL)
                  {
                        printf("-2\n");
                        thott_munb->next= NULL;return;
                  } 
                else
                 {
                     printf("%c\n",nowat->next->key);
                        thott_munb->next= nowat->next;return;
                 } 
                
            }
            thott_munb = nowat;
            nowat = nowat->next;

        }
        printf("-1\n");
        //printf("only %c is left",L->head->key);
    }
}
void LIST_DELETE_FIRST(LL L)
{
    node nowat=L->head;
    if(nowat==NULL)
        printf("-1\n");
    else
    {
        printf("%c\n",nowat->key);
        L->head=L->head->next;
        free(nowat);
    }
}
void LIST_DELETE_LAST(LL L)
{
    node nowat=L->head;
    node thott_munb=nowat;
    if(nowat==NULL)
        printf("-1\n");
    else
    {
        while(nowat->next!=NULL)
        {
            thott_munb=nowat;
            nowat=nowat->next;
        }
        printf("%c\n",nowat->key);
        if(nowat!=L->head)
            thott_munb->next=NULL;
		else
            L->head=NULL;
        nowat=NULL;
    }
    free(nowat);
    //free(thott_munb);
}
void PRINT_LIST(LL L)
{
    node nowat=L->head;
    if(L->head==NULL)
        printf("NULL\n");
    else
    {
        while(nowat!=NULL)
        {
            printf("%c ",nowat->key);
            nowat=nowat->next;
        }
        printf("\n");
    }
}
void main()
{
    char ch,c,y;
    node x=NULL;
    LL L;
    L=(LL)malloc(sizeof(LL));
    //L->head=NULL;
    
    
    while(1)
    {
        scanf(" %c", &ch);
       // printf("char is %c \n",ch);
        switch(ch)
        {
            case 'f':
                 //printf("testing at f begining\n");
                 scanf(" %c",&c);
                // printf("cnew is %c\n",c);
                 x=CREATE_NODE(c);
                 
                 LIST_INSERT_FRONT(L,x);
                 //printf("testing at f ending\n");
                 break;

            case 't':
                 //printf("testing at t begining\n");
                 scanf(" %c",&c);
                 //printf("cnew is %c\n",c);
                 x=CREATE_NODE(c);
                 //printf("x created");
                 LIST_INSERT_TAIL(L,x);
                 //printf("testing at t ending\n");
                 break;

             case 'a':
                // printf("testing at a begining\n");
                 scanf(" %c %c",&c,&y);
                 x=CREATE_NODE(c);
                 //printf("ur inputs are %c %c\n",c,y);
                 LIST_INSERT_AFTER(L,x,y);//x inserted after y
                 //printf("testing at a ending\n");
                 break;

            case 'b':
                // printf("testing at b begining\n");
                 scanf(" %c %c",&c,&y);
                 //printf("ur inputs are %c %c\n",c,y);
                 x=CREATE_NODE(c);
                 LIST_INSERT_BEFORE(L,x,y);//x inserted before y
                 //printf("testing at b ending\n");
                 break;
            case 'd':
                 //printf("testing at d begining\n");
                 scanf(" %c",&c);
                 //printf("c is %c\n",c);
                 LIST_DELETE(L,c);
                 //printf("testing at d ending\n");
                 break;
               
            case 'i': LIST_DELETE_FIRST(L);break;//done

            case 'l': LIST_DELETE_LAST(L);break;//done

            case 'p': PRINT_LIST(L);break;//done

            case 'e': exit(0);break;
        }
    }
}



