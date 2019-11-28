# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>
struct node
{
	int info;
	struct node *lchild;
	struct node *rchild;
}*root;
int maxDepth(struct node* node)  
{ 
   if (node==NULL)  
       return 0; 
   else 
   { 
       
       int lDepth = maxDepth(node->lchild); 
       int rDepth = maxDepth(node->rchild); 
  
       if (lDepth > rDepth)  
           return(lDepth+1); 
       else
        return(rDepth+1); 
   } 
}  
void mirror(struct node* node)  
{ 
  if (node==NULL)  
    return;   
  else 
  { 
    struct Node* temp; 
      
  
    mirror(node->lchild); 
    mirror(node->rchild); 
  
    
    temp=node->lchild; 
    node->lchild=node->rchild; 
    node->rchild=temp; 
  } 
}  

int find(int item,struct node **par,struct node **loc)
{
	struct node *ptr,*ptrsave;

	if(root==NULL)  
	{
		*loc=NULL;
		*par=NULL;
		return 0;
	}
	if(item==root->info) 
	{
		*loc=root;
		*par=NULL;
		return 0;
	}
	
	if(item<root->info)
		ptr=root->lchild;
	else
		ptr=root->rchild;
	ptrsave=root;

	while(ptr!=NULL)
	{
		if(item==ptr->info)
		{       *loc=ptr;
			*par=ptrsave;
			return 0;
		}
		ptrsave=ptr;
		if(item<ptr->info)
			ptr=ptr->lchild;
		else
			ptr=ptr->rchild;
	 }
	 *loc=NULL;
	 *par=ptrsave;
}

void insert(int item)
{       struct node *tmp,*parent,*location;
	find(item,&parent,&location);
	if(location!=NULL)
	{
		printf("Item already present");
		return;
	}

	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=item;
	tmp->lchild=NULL;
	tmp->rchild=NULL;

	if(parent==NULL)
		root=tmp;
	else
		if(item<parent->info)
			parent->lchild=tmp;
		else
			parent->rchild=tmp;
}


void case_a(struct node *par,struct node *loc )
{
	if(par==NULL) 
		root=NULL;
	else
		if(loc==par->lchild)
			par->lchild=NULL;
		else
			par->rchild=NULL;
}
void case_b(struct node *par,struct node *loc)
{
	struct node *child;

	if(loc->lchild!=NULL)
		child=loc->lchild;
	else              
		child=loc->rchild;

	if(par==NULL )  
		root=child;
	else
		if( loc==par->lchild)   
			par->lchild=child;
		else                 
			par->rchild=child;
}

void case_c(struct node *par,struct node *loc)
{
	struct node *ptr,*ptrsave,*suc,*parsuc;

	
	ptrsave=loc;
	ptr=loc->rchild;
	while(ptr->lchild!=NULL)
	{
		ptrsave=ptr;
		ptr=ptr->lchild;
	}
	suc=ptr;
	parsuc=ptrsave;

	if(suc->lchild==NULL && suc->rchild==NULL)
		case_a(parsuc,suc);
	else
		case_b(parsuc,suc);

	if(par==NULL) 
		root=suc;
	else
		if(loc==par->lchild)
			par->lchild=suc;
		else
			par->rchild=suc;

	suc->lchild=loc->lchild;
	suc->rchild=loc->rchild;
}
void del(int item)
{
	struct node *parent,*location;
	if(root==NULL)
	
		printf("Tree empty");
	

	find(item,&parent,&location);
	if(location==NULL)
	
		printf("Item not present in tree");

	

	if(location->lchild==NULL && location->rchild==NULL)
		case_a(parent,location);
	if(location->lchild!=NULL && location->rchild==NULL)
		case_b(parent,location);
	if(location->lchild==NULL && location->rchild!=NULL)
		case_b(parent,location);
	if(location->lchild!=NULL && location->rchild!=NULL)
		case_c(parent,location);
	free(location);
}
void preorder(struct node *ptr)
{
	if(root==NULL)
	{
		printf("Tree is empty");
		return ;
	}
	if(ptr!=NULL)
	{
		printf("%d  ",ptr->info);
		preorder(ptr->lchild);
		preorder(ptr->rchild);
	}
}

void inorder(struct node *ptr)
{
	if(root==NULL)
	{
		printf("Tree is empty");
		return;
	}
	if(ptr!=NULL)
	{
		inorder(ptr->lchild);
		printf("%d  ",ptr->info);
		inorder(ptr->rchild);
	}
}

void postorder(struct node *ptr)
{
	if(root==NULL)
	{
		printf("Tree is empty");
		return;
	}
	if(ptr!=NULL)
	{
		postorder(ptr->lchild);
		postorder(ptr->rchild);
		printf("%d  ",ptr->info);
	}
}

void display(struct node *ptr,int level)
{
	int i;
	if ( ptr!=NULL )
	{
		display(ptr->rchild, level+1);
		printf("\n");
		for (i = 0; i < level; i++)
			printf("    ");
		printf("%d", ptr->info);
		display(ptr->lchild, level+1);
	}
}
void main()
{
	int choice,num,h;
	root=NULL;
	while(1)
	{
		printf("\n");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Inorder Traversal\n");
		printf("4.Preorder Traversal\n");
		printf("5.Postorder Traversal\n");
		printf("6.mirror\n");
		printf("7.Height\n");
		printf("8.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			printf("Enter the number to be inserted : ");
			scanf("%d",&num);
			insert(num);
			break;
		 case 2:
			printf("Enter the number to be deleted : ");
			scanf("%d",&num);
			del(num);
			break;
		 case 3:
			inorder(root);
			break;
		 case 4:
			preorder(root);
			break;
		 case 5:
			postorder(root);
			break;
		 case 78:
			display(root,1);
			break;
		 case 6:	
		 	mirror(root);
		 	break;
		 
           	case 7:
           		printf("%d is the height of the tree.",maxDepth(root));
           		break;
           	case 8: exit(0);
            	
		 default:
			printf("Wrong choice\n");
		}
	}
}
