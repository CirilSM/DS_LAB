#include<stdio.h>
#include<stdlib.h>
int q[50],cq[50],dq[50],n,front=0,rear=0,cfront=0,crear=0,dfront=0,drear=0,ccount=0,dcount=0;
void display(int fr,int rr,int arr[])
{
    printf("\nElements are: \n"); 
    if (rr >= fr) 
    { 
        for (int i=fr;i<=rr;i++) 
            printf("%d \n",arr[i]); 
    } 
    else
    { 
        for (int i=fr;i<=n;i++) 
            printf("%d \n",arr[i]); 
        for (int i=1;i<=rr;i++) 
            printf("%d \n",arr[i]); 
    } 
} 
void qinsert()
{
    int item;
    if(rear==n)
        printf("Queue is full\n");
    else
    {
        printf("Enter the item:");
        scanf("%d",&item);
        if(front==0&&rear==0)
        front++;
        rear++;
        q[rear]=item;
    }
}
void qdelete()
{
    int item;
    if(front==0&&rear==0)
        printf("Queue is empty\n");
    else
    {
        item=q[front];
        if(front==rear)
        {
            front=0;
            rear=0;
        }
        else
            front++;
        printf("Item deletd is:%d\n",item);
    }
}
void cqinsert()
{
    int item;
    if(cfront==(crear%n)+1)
        printf("Queue is full\n");
    else
    {
        printf("Enter the item:\n");
        scanf("%d",&item);
        if(cfront==0&&crear==0)
            cfront++;
        crear=(crear%n)+1;
        cq[crear]=item;
    	ccount++;
    }
}
void cqdelete()
{
    int item;
    if(cfront==0&&crear==0)
        printf("Queue is empty\n");
    else
    {
        item=cq[cfront];
        if(cfront==crear)
        {
            cfront=0;
            crear=0;
        }
        else if(cfront==n)
            cfront=1;
        else
            cfront++;
        printf("Item deleted is:%d\n",item);
    	ccount--;
    }
}
void dqinsertrear()
{
    int item;
    if(dfront==(drear%n)+1)
        printf("Queue is full\n");
    else
    {
        printf("Enter the item:\n");
        scanf("%d",&item);
        if(dfront==0&&drear==0)
            dfront++;
        drear=(drear%n)+1;
        dq[drear]=item;
    	dcount++;
    }
}
void dqinsertfront()
{
    int item;
    if(dfront==(drear%n)+1)
        printf("Queue is full\n");
    else
    {
        printf("Enter the item:\n");
        scanf("%d",&item);
         if(dfront==0&&drear==0)
        {
         dfront=1;
         drear=1;
        }
        else if(dfront==1)
            dfront=n;
        else
            dfront--;
        dq[dfront]=item;
    dcount++;
    }
}
void dqdeletefront()
{
    int item;
    if(dfront==0&&drear==0)
        printf("Queue is empty\n");
    else
    {
        item=dq[dfront];
        if(dfront==drear)
        {
            dfront=0;
            drear=0;
        }
        else if(dfront==n)
            dfront=1;
        else
            dfront++;
        printf("Item deletd is:%d\n",item);
    	dcount--;
    }
}
void dqdeleterear()
{
     int item;
    if(dfront==0&&drear==0)
        printf("Queue is empty\n");
    else
    {
        item=dq[drear];
        if(dfront==drear)
        {
            dfront=0;
            drear=0;
        }
        else if(drear==1)
            drear=n;
        else
            drear--;
    printf("Item deleted is:%d\n",item);
    dcount--;
    }
}
void main()
{
    int op,i;
    printf("Enter the size of queue:");
    scanf("%d",&n);
    do
    {
        printf("\n\n\n1.Linear queue\n2.Circular queue\n3.Double Ended queue\n4.Exit\nEnter an option:\n");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            do
            {
                printf("\n\n1.Insertion\n2.Deletion\n3.Display\n4.Main menu\nEnter an option:\n");
                scanf("%d",&i);
                if(i==1)
                {
                    qinsert();
                }
                else if(i==2)
                {
                    qdelete();
                }
                else if(i==3)
                {                
   		 if (front==0)  
  		      printf("Queue is empty\n"); 
    		 else
                	display(front,rear,q);                
                }
                else if(i!=4)
                    printf("Invalid option\n");
            }while(i!=4);
            break;
        case 2:
            do
            {            
            printf("\n\n1.Insertion\n2.Deletion\n3.Display\n4.Main menu\nEnter an option:");
                scanf("%d",&i);
                if(i==1)
                {

                    cqinsert();
                }
                else if(i==2)
                {
                    cqdelete();
                }
                else if(i==3)
                {	
   		 if (ccount==0)  
  		      printf("Queue empty\n"); 
    		 else
                	display(cfront,crear,cq);               
                }
                else if(i!=4)
                    printf("Invalid option\n");
            }while(i!=4);
            break;
        case 3:
            do
            {           
            printf("\n\n1.Insertion at front\n2.Insertion at rear\n3.Deletion at front\n4.Deletion at rear\n5.Display\n6.Main menu\nEnter an option:\n");
                scanf("%d",&i);
                if(i==1)
                {
                    dqinsertfront();
                }
                else if(i==2)
                {
                    dqinsertrear();
                }
                 else if(i==3)
                {
                    dqdeletefront();
                }
                 else if(i==4)
                {
                    dqdeleterear();
                }
                else if(i==5)
                {
                	
   		 if (dcount==0)  
  		      printf("Queue is Empty"); 
    		 else
                	display(dfront,drear,dq);           
                }
                else if(i!=6)
                    printf("Invalid option\n");
            }while(i!=6);
            break;
        case 4:              
 		exit(0);
    }
}while(1);
}
