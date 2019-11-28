#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
struct tree
{
	int data;
	struct tree *lchild,*rchild;
}*temp,*head,*pos;
void disp(struct tree* t) 
{ 
	if (t == NULL) 
	        printf("\n"); 
	else
	{
		printf("%d",t->data);
		disp(t->lchild);
		disp(t->rchild);
	}	    
} 	
void ins(struct tree *t,int k)
{
	char ch;
	int item;
	search(t,k);
	if(pos==NULL)
		printf("cannot insert");
	else
	{
		printf("Left or right child:");
		scanf("%c",&ch);
		if(ch=='l')
		{
			if(pos->lchild==NULL)
			{
				printf("Enter the item:");
				scanf("%d",&item);
				temp=(struct tree*)malloc(sizeof(struct tree));
				temp->data=item;
				temp->lchild=NULL;
				temp->rchild=NULL;
				pos->lchild=temp;
			}
		}
		else
		{
			if(pos->rchild==NULL)
			{
				printf("Enter the item:");
				scanf("%d",&item);
				temp=(struct tree*)malloc(sizeof(struct tree));
				temp->data=item;
				temp->lchild=NULL;
				temp->rchild=NULL;
				pos->rchild=temp;
			}
		}
	}
}				
void create(struct tree *t)
{
	int item,ch;
	if(t!=NULL)
	{
		printf("Any lchild(Y=1||N=0):");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("Enter the item:");
			scanf("%d",&item);
			temp=(struct tree*)malloc(sizeof(struct tree));
			temp->data=item;
			temp->lchild=NULL;
			temp->rchild=NULL;
			t->lchild=temp;
			create(temp);
		}
		printf("Any rchild(Y=1||N==0):");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("Enter the item:");
			scanf("%d",&item);
			temp=(struct tree*)malloc(sizeof(struct tree));
			temp->data=item;
			temp->lchild=NULL;
			temp->rchild=NULL;
			t->rchild=temp;
			create(temp);
		}
	}
}
void search(struct tree *t,int key)
{
	if(t!=NULL)
	{
		if(t->data==key)
		{
			printf("Found");
			pos=t;
		}
		else
		{
			search(t->lchild,key);
			search(t->rchild,key);
		}
	}
}
void del(struct tree *t,int key)
{
	if(t!=NULL)
	{
		if(t->lchild!=NULL)
		{
			if(t->lchild->data==key)
			{
				temp=t->lchild;
				if(temp->lchild==NULL && temp->rchild==NULL)
				{	free(temp);
					printf("Deleted");
				}
				else 
					printf("Delete not possible!");
			}
		}
		else if(t->rchild!=NULL)
		{
			if(t->rchild->data==key)
			{
				temp=t->rchild;
				if(temp->lchild==NULL  && temp->rchild==NULL)
				{
					free(temp);
					printf("deleted");
				}
				else
					printf("Delete not possible!");
			}
		}
	}
}	
void main()
{
	int root,a,key;
	struct tree *t;
	t=(struct tree*)malloc(sizeof( struct tree));
	printf("Enter the root:");
	scanf("%d",&root);
	t->data=root;
	t->lchild=NULL;
	t->rchild=NULL;
	while(1)
	{
		printf("\n\n\tNOTE :TO EXIT FROM INSERTION OF ELEMENTS JUST KEPP ENTERING 0\n\n0.Create\n1.Insertion\n2.Deletion\n3.Exit\n4.Search\n5.Display\nChoice:");
		scanf("%d",&a);
		switch(a)
		{
			case 0: create(t);
				break;
			case 1:	printf("Enter key:");
				scanf("%d",&key);
				ins(t,key);
				break;
			case 2:	printf("Enter key:");
				scanf("%d",&key);
				del(t,key);
				break;
			case 4: printf("Enter key:");
				scanf("%d",&key);
				search(t,key);
				break;
			case 3:	exit(0);
				break;
			case 5:disp(t);
				break;
			default:
				printf("INVALID INPUT");
		}
	}
}

