#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node* head;
int search;

void insert()
{
	printf("\n1.Insert at Beginning\n2.Insert at End\n3.After a data");
	int c,s;
	scanf("%d",&c);
	struct node *temp=(struct node*)malloc(sizeof(struct node)),*list;
	printf("Enter the element to be inserted ");
        scanf("%d",&temp->data);
        temp->next=NULL;
	list=head;
	if(c==1)
	{
		temp->next=head;
		head=temp;
	}
	else if(c==2)
	{
		while(list!=NULL)
		{
			list=list->next;
		}
		list->next=temp;
	}
	else if(c==3)
	{
		printf("ENTER THE KEY::");
		scanf("%d",&search);	
		int f1=0;
		while(list->data!=search)
		{
			list=list->next;
			f1=1;
		}
		if(f1==1)
		{
		temp->next=list->next;
		list->next=temp;
		}
		else
			printf("KEY NOT FOUND");
	}
	else
	{
		printf("INVALID CHOICE\n");
		insert();
	}
}

void deletion()
{
	if(head==NULL)
		printf("LIST EMPTY\n");
	else
	{
		struct node *temp;
		printf("\n1.Delete at Beginning\n2.Delete at End\n3.Specific Node");
        	int c,s;
        	scanf("%d",&c);
			if(c==1)
			{
				temp=head;
				printf("%d is deleted\n",head->data);
				head=head->next;
				free(temp);
			}
			else if(c==2)
			{
				temp=head;
				while((temp->next)->next!=NULL)
					temp=temp->next;
	                        printf("%d is being deleted\n",temp->next->data);
				free(temp->next);
				temp->next=NULL;
			}
			else if(c==3)
			{
				temp=head;
				int f=0;
				printf("Enter element to be deleted ");
        	                scanf("%d",&s);
	                        while(temp!=NULL)
                	                if(temp->next->data==s)
                        	        {
                                	        f=1;
						temp->next=temp->next->next;
					}
				if(f==0)
	                                printf("NOT FOUND\n");
			}
			else
	                        printf("INVALID OPTION\n");
	}
}
void display()
{
        if(head==NULL)
                printf("LIST EMPTY\n");
	else
	{
	        struct node *temp;
		temp=head;
		while(temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
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
		default:
                        printf("INVALID OPTION\n");
	}
}
