#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node* head;
void insert()
{
	printf("\n1.Insert at Beginning\n2.Insert at End\n3.After a data");
	int c,s;
	scanf("%d",&c);
	struct node *temp=(struct node*)malloc(sizeof(struct node)),*a;
	printf("Enter the element to be inserted ");
        scanf("%d",&temp->data);
	switch(c)
	{
		case 1:
		{
			temp->next=head;
			head=temp;
			break;
		}
		case 2:
		{
			a=head;
			while(a->next!=NULL)
				a=a->next;
			a->next=temp;
			temp->next=NULL;
			break;
		}
		case 3:
		{
			a=head;
			int t,f=0;
			printf("Enter element after which to be inserted ");
			scanf("%d",&s);
			while(a!=NULL)
			{
				if(a->data==s)
				{
					f=1;
					temp->next=a->next;
					a->next=temp;
					break;
				}
				else
					a=a->next;
			}
			if(f==0)
				printf("NOT FOUND\n");
			break;
		}
		default:
			printf("INVALID OPTION\n");
	}
}
void deletion()
{
	if(head==NULL)
		printf("LIST EMPTY\n");
	else
	{
		struct node *temp;
		printf("\n1.Delete at Beginning\n2.Delete at End\n3.Specific Node\n4.Exit\n");
        	int c,s;
        	scanf("%d",&c);
		switch(c)
		{
			case 1:
			{
				temp=head;
				printf("%d is being deleted\n",head->data);
				head=head->next;
				free(temp);
				break;
			}
			case 2:
			{
				temp=head;
				while((temp->next)->next!=NULL)
					temp=temp->next;
	                        printf("%d is being deleted\n",temp->next->data);
				free(temp->next);
				temp->next=NULL;
				break;
			}
			case 3:
			{
				temp=head;
				int r,t=0;
				printf("Enter the item to be deleted::");
				scanf("%d",&r);
				while((temp->next->next)!=NULL)//a buffer one link is provided
				{
					if(temp->next->data==r)
					{
						printf("Item will be deleted\n");	
						temp->next=temp->next->next;
						t=1;
						free(temp->next);
					}
					temp=temp->next;
				}
				if(t==0)
					printf("NO SUCH ELELEMT WAS FOUND\n\n");
				break;
			}
			case 4:
			{
	                        main();
				break;
			}
			default:
			{
				printf("INVALID CHOICE\n\n");
				main();
			}
		}//end of switch
	}//end of else
}//emd of deletion
void display()
{
        if(head==NULL)
                printf("LIST EMPTY\n");
	else
	{
	        struct node *disp;
		disp=head;
		while(disp!=NULL)
		{
			printf("%d\n",disp->data);
			disp=disp->next;
		}
	}
}
void main()
{
	printf("1.Insert\n2.Delete\n3.Display\n4.exit\nEnter the option:-");
	int c;
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			{
				insert();
				main();
				break;
			}
		case 2:
			{
				deletion();
				main();
				break;
			}
		case 3:
			{
				display();
				main();
				break;
			}
		case 4:
			{
                       		exit(0);
			}
		default:
			{
				printf("INVALID CHOICE");
				main();
			}
		
	}
}
