#include<stdlib.h>
#include<stdio.h>
void bubble(int a[],int n)
{	
	int temp;
	for(int i=0;i<n;i++)
		for(int j=0;j<n-i-1;j++)
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
	printf("Array after sorting.\n\n");
	for(int i=0;i<n;i++)
		printf("%d\n",a[i]);
}
void selec(int a[],int n)
{
	int temp;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
	printf("Array after sorting.\n\n");
	for(int i=0;i<n;i++)
		printf("%d\n",a[i]);
}
/*void insert(int e,int a[],int i)
{
	a[0]=e;
	while(e<a[i])
	{
		a[i+1]=a[i];
		i--;
	}
	a[i+1]=e;
}*/
void insertion(int a[],int n)
{
	/*for(int i=1;i<n;i++)
		insert(a[i],a,i-1);
	printf("insertion sort:\n");
    	for(int i=1;i<=n;i++)
    	{
     		printf("%d",a[i]);
        	printf("\n");
    	}*/
    	int j,t;
    	for(int i=0;i<=n;i++)
    	{
    		j=i;
    		while(j>0&&a[j-1]>a[j])
    		{
    			t=a[j];
    			a[j]=a[j-1];
    			a[j-1]=t;
    			j--;
    		}
    	}
    	for(int i=1;i<=n;i++)
    	{
     		printf("%d",a[i]);
        	printf("\n");
    	}
}
void quick(int list[], int low, int high)
{
    int pivot, i, j, temp;
    if (low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while (i < j) 
        {
            while (list[i] <= list[pivot] && i <= high)
            {
                i++;
            }
            while (list[j] > list[pivot] && j >= low)
            {
                j--;
            }
            if (i < j)
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
        temp = list[j];
        list[j] = list[pivot];
        list[pivot] = temp;
        quick(list, low, j - 1);
        quick(list, j + 1, high);
    }
}	
void merge(int a[],int l,int mid,int u)
{
	int i,j,k,c[100],m;
	i=l;
	j=mid+1;
	k=l;
	while(i<=mid && j<=u)
	{
		if(a[i]<=a[j])
		{
			c[k]=a[i];
			i++;
			k++;
		}
		else
		{
			c[k]=a[j];
			j++;
			k++;
		}
	}
	while(i<=mid)
	{
			c[k]=a[i];
			k++;
			i++;	
	}
	while(j<=u)
	{
			c[k]=a[j];
			k++;
			j++;
		
	}
	for(m=l;m<=u;m++)
	{
		a[m]=c[m];
	}
}
void mergesort(int a[],int l,int u)	
{
	int mid;
	if(l!=u)		
	{
		mid=(l+u)/2;
		mergesort(a,l,mid);
		mergesort(a,mid+1,u);
		merge(a,l,mid,u);
	}
}
void main()
{
	int a[100],n,ch;
	printf("Enter the size:");
	scanf("%d",&n);
	while(1)
	{
		printf("1.Bubble\n2.Select\n3.Insertion\n4.Reccusive Quick\n5.reccusive Merge\n6.Heap \n7.Exit\nEnter the choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	printf("Enter the elements of the array:\n");
				for(int i=0;i<n;i++)
					scanf("%d",&a[i]);
				bubble(a,n);//working
				break;
			case 2:	printf("Enter the elements of the array:\n");
				for(int i=0;i<n;i++)
					scanf("%d",&a[i]);
				selec(a,n);//working
				break;
			case 3:	printf("Enter the elements of the array:\n");
				a[0]=0;
				for(int i=1;i<n+1;i++)
					scanf("%d",&a[i]);
				insertion(a,n);//1st and last element wrong
				break;
			case 4:	printf("Enter the elements of the array:\n");
				for(int i=0;i<n;i++)
					scanf("%d",&a[i]);
				quick(a,0,n-1);//working
				printf("Array after sorting.\n\n");
				for(int i=0;i<n;i++)
					printf("%d\n",a[i]);
				break;
			case 5:	printf("Enter the elements of the array:\n");
				for(int i=0;i<n;i++)
					scanf("%d",&a[i]);
				mergesort(a,0,n-1);
				printf("Array after sorting.\n\n");
				for(int i=0;i<n;i++)
					printf("%d\n",a[i]);
				break;
			case 7: exit(0);
		}
	}
}
