//Prog to implement linear q, circuler q and deque using array.
#include<stdio.h> 
#include<stdlib.h>
int front1=-1,front2=0,front3=0,rear1=-1,rear2=0,rear3=0,q[100],n1,cq1[100],n2,dq1[100],n3,item;
void lq();
void dq();
void cq();
void enq();
void deq();
void cenq();
void cdeq();
void denq_end();
void ddeq_beg();
void denq_beg();
void ddeq_end();
void main()
{
	int ch,ch1,ch2;
	printf("Enter the size of the LQueue:");
	scanf("%d",&n1);
	printf("Enter the size of the CQueue:");
	scanf("%d",&n2);
	printf("Enter the size of the DQueue:");
	scanf("%d",&n3);
	while(1)
	{
		printf("1.Linear Queue\n2.Circular Queue\n3.Deque\n4.Exit\nEnter the choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	lq();
				break;
			case 2:	cq();
				break;
			case 3:	dq();
				break;
			case 4: exit(0);
		}			
	}
}		
void lq()
{	
	int ch, ch1;
	do
	{
		printf("1.Insertion\n2.Deletion\n3.Display\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: enq();
				break;
			case 2: deq();
				break;
			case 3: printf("Linear Queue\n");
				for(int i=front1; i<=rear1; i++)
					printf("%d\n",q[i]);
				break;
		}
		printf("\nEnter '0' to continue.");
		scanf("%d",&ch1);
	}while(ch1=='0');
}
void cq()
{	
	int ch,ch1;
	do
	{
		printf("1.Insertion\n2.Deletion\n3.Display\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: cenq();
				break;
			case 2: cdeq();
				break;
			case 3: printf("Circular Queue\n");
				for(int i=front2; i<=rear2; i++)
					printf("%d\n",cq1[i]);
				break;
		}
		printf("\nEnter '0' to continue.");
		scanf("%d",&ch1);
	}while(ch1=='0');
}
void dq()
{	
	int ch,ch1,ch2;
	do
	{
		printf("\n1.Insertion at end\n2.Deletion at the front\n3.Insertion at the begining\n4.Deletion at the end\n5.Display from end\n6.Display from front.\nEnter the choice:");
		scanf("%d",&ch2);
		switch(ch2)
		{
			case 1: denq_end();
				break;
			case 2: ddeq_beg();
				break;
			case 5: printf("Deque\n");
				for(int i=front3; i<=rear3; i++)
					printf("%d\n",dq1[i]);
				break;
			case 6: printf("Deque\n");
				for(int i=rear3; i>=front3; i--)
					printf("%d\n",dq1[i]);
				break;
			case 3:	denq_beg();//insertion at the end
				break;
			case 4:	ddeq_end();//deletion at the end
				break;
		}
		printf("\nEnter '0' to continue.");
		scanf("%d",&ch1);
	}while(ch1=='0');
}
void enq()
{
	printf("Enter the item to be inserted:");
	scanf("%d",&item);
	if(rear1==n1)
	{
		printf("Queue Full!!!!!!!");
	}
	else
	{
		if(front1==rear1==0)
			front1=0;
		rear1++;
		q[rear1]=item;
	}
}
void deq()
{
	if(rear1==front1==-1)
		printf("Queue Empty!");
	else
	{
		item=q[front1];
		if(front1==rear1)
		{
			front1=0;
			rear1=0;
		}
		front1++;
	}
	printf("Deleted item is %d",item);
}
void cenq()
{
	printf("Enter the item:");
	scanf("%d",&item);
	if(front2==(rear2%n2)+1)		
		printf("Queue full!");
	else
	{
		if(front2==0 && rear2==0)
			front2=1;
		rear2=(rear2%n2)+1;
		cq1[rear2]=item;
	}
}
void cdeq()
{
	int temp;
	if(front2==0 && rear2==0)
		printf("Queue empty!");
	else
	{
		temp=cq1[front2];
		if(front2==rear2)
		{
			front2=0;
			rear2=0;
		}
		else
		{
			front2=(front2%n2)+1;
		}
	}
	printf("Deleted item is %d",item);
}
void denq_beg()
{
	printf("Enter the item:");
	scanf("%d",&item);
	if(front3==(rear3%n2)+1)
		printf("Queue full!");
	else
	{
		if(front3==0 &&rear3==0)
		{
			front3=1;
			rear3=1;
		}
		else if(front3=1)
			front3=n3;
		else
			front3--;
		dq1[front3]=item;
	}
}
void ddeq_end()
{
	if(front3==0)
		printf("Queue empty!!");
	else
	{
		item=dq1[rear3];
		if(front3==rear3)
		{
			front3=0;
			rear3=0;
		}
		else if(rear3==1)
			rear3=n3;
		else
			rear3--;
	}
	printf("Deleted item is %d",item);
}
void denq_end()
{
	printf("Enter the item:");
	scanf("%d",&item);
	if(front3==(rear3%n3)+1)		
		printf("Queue full!");
	else
	
		if(front3==0 && rear3==0)
			front3=1;
		rear3=(rear3%n3)+1;
		dq1[rear3]=item;
	
}
void ddeq_beg()
{
	int temp;
	if(front3==0 && rear3==0)
		printf("Queue empty!");
	else
	{
		temp=cq1[front3];
		if(front3==rear3)
		{
			front3=0;
			rear3=0;
		}
		else
		{
			front3=(front3%n3)+1;
		}
	}
	printf("Deleted item is %d",item);
}
