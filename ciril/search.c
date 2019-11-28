//SEARCH
#include<stdio.h>
#include<stdlib.h>
int arrl[10],arrb[10],search,nl,nb,searchl,count;
void binary()
{
	int flag=0;
	int first,last,mid;
	printf("\nEnter the size of array");
	scanf("%d",&nb);
	printf("\nEnter the elements in ascending order ");
	for(int i=0;i<nb;i++)
	{
		scanf("%d",&arrb[i]);
	}
	first=0;last=nb;mid=0,count=0;
	printf("\nEnter the search key::");
	scanf("%d",&search);
	while(count!=nb)
	{
		mid=(first+last)/2;
		if(arrb[mid]==search)
		{
			flag=1;
			printf("\n\tSEARCH FOUND\n\n");		
			break;

		}
		else if(arrb[mid]>search)
		{
			last=mid;
		}
		else
			first=mid;
		count++;
	}
	if(flag==0)
		{
		printf("\nSEARCH NOT FOUND\n\n");
		}
	main();
}//end of binary

void linear()
{
	printf("\nEnter the size of array");
	scanf("%d",&nl);
	int flag=0,j;
	printf("\nEnter the elements:");
	for(int i=0;i<nl;i++)
	{
		scanf("%d",&arrl[i]);
	}
	printf("\nEnter the search key::");
	scanf("%d",&j);
	for(int i=0;i<nl;i++)
	{
		if(arrl[i]==j)
		{
			flag=1;			
			printf("\nSEARCH SUCCESS\n\n");
			break;
		}
	}
	if(flag==0)
		printf("\nSEARCH NOT FOUND\n\n");
	main();
}//end of linear		
	
void main()
{
	int ch;
	printf("\n\n\t1.BINARY SEARCH\n\t2.LINEAR SEARCH\n\t3.Exit\n");
	scanf("%d",&ch);
	if(ch==1)
		binary();
	else if (ch==2)
		linear();
	else if(ch==3)
		exit(0);
	else
	{
		printf("INVALID CHOICE");
		main();
	}
}

