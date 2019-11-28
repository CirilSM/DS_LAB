#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node *list=NULL;
struct node *head;
int count=0;
void insertb()
{
    struct node *temp;
    int item;
    printf("Enter the item to be entered:");
    scanf("%d",&item);
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=item;
    temp->next=NULL;

    if(list==NULL)
    {
        list=temp;
    }
    else
    {
        temp->next=list;
        list=temp;
    }
    count++;
}
void inserte()
{
    struct node *temp,*t;
    int item;
    printf("Enter the item to be entered:");
    scanf("%d",&item);
    temp=(struct node*)malloc(sizeof(struct node));
    t=list;
     if(list==NULL)
    {
        list=temp;
        temp->data=item;
        temp->next=NULL;
    }
    else
    {
        while(t->next!=NULL)
            t=t->next;
        t->next=temp;
        temp->data=item;
        temp->next=NULL;
    }
    count++;
}
void insert()
{
    struct node *temp,*t;
    int search,item;
    printf("Enter the item to be searched:");
    scanf("%d",&search);
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=item;
    temp->next=NULL;

     if(list==NULL)
    {
        list=temp;
    }
    else
    {
        t=list;
        while(t->next!=NULL)
        {
            if(t->data==search)
            {
                printf("Enter the item to be entered:");
                scanf("%d",&item);
                temp=(struct node*)malloc(sizeof(struct node));
                temp->data=item;
                temp->next=t->next;
                t->next=temp;
                count++;
                return;
            }
            else
            {
               t=t->next;
            }
        }
        if(t->data==search)
            {
                 printf("Enter the item to be entered:");
                scanf("%d",&item);
                temp=(struct node*)malloc(sizeof(struct node));
                temp->data=item;
                temp->next=NULL;
                t->next=temp;
                count++;
                return;
            }
    }
        printf("Entered element doesn't exist\n");
}
void deleteb()
{
    struct node *temp;
    int item;
    if(list==NULL)
        {
        printf("Linked list is Empty\n");
        return;
        }
    item=list->data;
    temp=list;
    list=list->next;
    free(temp);
    printf("\n%d has been deleted\n",item);
    count--;
}
void deletee()
{
    struct node *temp,*t;
    int item;
    if(list==NULL)
    {
        printf("Linked list is Empty\n");
        return;
    }
    else if(list->next==NULL)
    {
        count--;
        item=list->data;
        free(list);
        list=NULL;
        printf("\n%d has been deleted",item);
        return;
    }
    else
    {
        count--;
        t=list;
        while(t->next!=NULL)
        {
        temp=t;
        t=t->next;
        }
        item=t->data;
        temp->next=NULL;
        free(t);
        printf("\n%d has been deleted\n",item);
        return;
    }
    printf("Item doesn't exist\n");
}
void deleten()
{

    struct node *temp,*t;
    int search,item;

    if(list==NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    else
    {
    	printf("Enter the item to be searched:");
        scanf("%d",&search);
    }
    if(list->next==NULL&&list->data==search)
    {
        count--;
        item=list->data;
        free(list);
        list=NULL;
        printf("\n%d has been deleted\n",item);
        return;
    }
    else if(list->data==search)
    {
        count--;
        temp=list;
        list=list->next;
        free(temp);
        printf("\n%d has been deleted\n",search);
        return;
    }
    else
    {
        t=list;
        while(t->next!=NULL)
        {
            if(t->data==search)
            {
                count--;
                temp->next=t->next;
                free(t);
                printf("\n%d has been deleted\n",search);
                return;
            }
            else
            {
                temp=t;
                t=t->next;
            }
        }
        if(t->data==search)
        {
                count--;
                temp->next=NULL;
                free(t);
                printf("\n%d has been deleted\n",search);
                return;
        }
    }
    printf("%d doesn't exist\n",search);
}
void main()
{
    int op,x=0;
    head=list;
    do
    {
        printf("1.Insertion at the beginning\n2.Insertion at the end\n3.Insertion after a specific node\n4.Delete at beginning\n5.Delete at the end\n6.Delete a specific node\n7.Display the linked list\n8.Exit\nEnter an option:");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            insertb();
            break;
        case 2:
            inserte();
            break;
        case 3:
            insert();
            break;
        case 4:
            deleteb();
            break;
        case 5:
            deletee();
            break;
        case 6:
            deleten();
            break;
        case 7:
            head=list;
            if(count==0)
                printf("Linked list is empty\n");
            else
            {

                printf("\nElements are:%d",head->data);
                head=head->next;
                for(int i=2;i<=count;i++)
                {
                    printf(",%d",head->data);
                    head=head->next;
                }
                printf("\n");
            }
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("Invalid option\n");
        }
    }while(x==0);

}

