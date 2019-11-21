#include<stdio.h>
#include<stdlib.h>
struct tree
{
	int data;
	struct tree *rchild,*lchild;
}*temp;
void create(struct tree *t)
{
	char ch='y';
	int item;
	struct tree *top;
	temp=(struct tree*)malloc(sizeof(struct tree));
	if(t!=NULL)
	{
		printf("Any left child(l):");
		scanf("%c",&ch);
		if(ch=='y')
		{
			printf("Enter the value(l):");
			scanf("%d",&item);
			//temp=(struct tree*)malloc(sizeof(struct tree));
			temp->data=item;
			temp->lchild=NULL;
			temp->rchild=NULL;
			t->lchild=temp;
			//create(temp);
		}
		else
			printf("left failed");
		printf("Any right child(r):");
		scanf("%c",&ch);
		if(ch=='y')
		{
			printf("Enter the value(r):");
			scanf("%d",&item);
			//temp=(struct tree*)malloc(sizeof(struct tree));
			temp->data=item;
			temp->lchild=NULL;
			temp->rchild=NULL;
			t->rchild=temp;
			//create(temp);
		}
	}
}
void delete(struct tree *t,int k)
{
	if(t!=NULL)
	{
		if(t->lchild!=NULL)
		{
			if(t->lchild->data==k)
			{
				temp=t->lchild;
				if(temp->lchild==NULL && temp->rchild==NULL)
					free(temp);
			}
			else
				printf("Delete not possible.");
		}
		else if(t->rchild!=NULL)
		{
			if(t->rchild->data==k)
			{
				temp=t->rchild;
				if(temp->lchild==NULL && temp->rchild==NULL)
					free(temp);
			}
			else
				printf("Delete not possible");
		}
		delete(t->lchild,k);
		delete(t->rchild,k);
	}
}
void search(struct tree *t,int k)
{	
	if(t!=NULL)
	{
		if(t->data==k)
		{
			printf("Found");
		}
		else
		{
			search(t->lchild,k);
			search(t->rchild,k);
		}
	}
}
void main()
{
	int ch,k,item;
	struct tree *t;
	t=(struct tree*)malloc(sizeof(struct tree));
	printf("Enter the root element:");
	scanf("%d",&item);
	t->data=item;
	t->rchild=NULL;
	t->lchild=NULL;
	while(1)
	{
		printf("1.Insertion\n2.Deletion\n3.Search\nEnter the choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	create(t);
				break;
			case 2:	printf("Enter the item to be deleted:");
				scanf("%d",&k);
				delete(t,k);
				break;
			case 3:	printf("Enter the item to be searched:");
				scanf("%d",&k);
				search(t,k);
				break;
		}
	}
}
