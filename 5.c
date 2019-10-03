#include<stdio.h>
int w=0,i,qs,op,max=10,num,frontl=0,rearl=0,frontc=0,rearc=0,drearA=0,dfrontA=0,drearB=10,dfrontB=10;
int queue[10],cqueue[10],de[20],inA,inB;
void linear()
{
		printf("1.INSERTION\n2.DELETION\n3.DISPLAY\nENTER ANY OTHER KEY TO EXIT\n\n");
		scanf("%d",&op);
		if(op==1)
		{
			printf("Enter the element to be inserted into the queue : ");
			scanf("%d", &num);
			if(rearl == max-1)
			printf("\n OVERFLOW!\n");
			else if(frontl == -1 && rearl == -1)
			frontl = rearl = 0;
			else
			rearl++;
			queue[rearl] = num;
			linear();//recursion
		}
		else if(op==2)
		{
			if (rearl == frontl)
				printf( "UNDERFLOW!");
			else
			{
				frontl = frontl + 1;
				printf("DELETION SUCCESSFULL\n\n");
			}
			linear();//recursion
		}
		else if(op==3)
		{
		while(queue[w]!='\0')
		{
			printf("%d",queue[w]);
		}
			linear();//recursion
		}
		else
			main();
}
void circular()
{
	printf("1.INSERTION\n2.DELETION\n3.DISPLAY\nENTER ANY OTHER KEY TO EXIT\n\n");
	scanf("%d",&op);
		if(op==1)
		{
			    printf("Enter the element to be inserted into the circular queue : ");
			    scanf("%d", &num);  
			    if ((frontc == 0 && rearc == max-1)||(rearc == (frontc-1)%(max-1))) 
  				  { 
       					 printf("\nQueue is Full"); 
					 circular();
   				  } 
  
   			    else if (frontc == -1) /* Insert First Element */
    				{ 
        				frontc = rearc = 0; 
        				cqueue[rearc] = num; 
					 circular();
    				} 
  
    				else if (rearc == max-1 && frontc != 0) 
    				{ 
        				rearc = 0; 
        				cqueue[rearc] = num; 
					 circular();
    				} 
  
    				else
    				{ 
        				rearc++; 
        				cqueue[rearc] = num; 
					 circular();
    				} 
		}
		else if(op==2)
  		  {  
           		 if (frontc == -1)  
            		{  
               		 printf("Queue Underflow\n");  
               		 circular();  
           		 }    
           		 if (frontc == rearc)  
          		  {  
           	          frontc = -1;  
              		  rearc = -1;  
			  circular();
           		 }  
            		else  
           		 {  
                		if (frontc == max - 1)  
                   		 frontc = 0;  
               		 	else  
                   		 frontc = frontc+ + 1;  
			  circular();
           		 }  
      		  }

		else if(op==3)
		{
		int i;
    		printf("\n");
    		if (frontc > rearc)
    		{
       		  for (i = frontc; i < max; i++)
       		    {
           		 printf("%d ", cqueue[i]);
       		    }
       		  for (i = 0; i <= rearc; i++)
           		 printf("%d ", cqueue[i]);
   		}
   	        else
   		  {
     		     for (i = frontc; i <= rearc; i++)
          		  printf("%d ", cqueue[i]);
  		  }
		circular();
	        }
		
		else
			main();
}
void deq()
{
		printf("1.INSERTION to A\n2.DELETION IN A\n3.DISPLAY OF A\n4.INSERTION to B\n5.DELETION OF B\n6.DISPLAY OF B\nENTER ANY OTHER KEY TO EXIT\n\n");
		scanf("%d",&op);
		if(op==1)
		{
		int inA;
		printf("Enter thr number::");
		scanf("%d",&inA);
		if(drearA==drearB-1)
			printf("QUEUE OVERFLOW");
		else
		{
 			de[drearA]=inA;
			drearA++;
		}
		deq();
		}
		else if(op==2)
		{
		if(dfrontA==drearA)
		{	
		printf("QUEUE IS EMPTY");
		}
		else
			dfrontA++;
		deq();
		}
		else if(op==3)		
		{
			for(int i=dfrontA;i<=drearA;i++)
				printf("%d\n",de[i]);
		deq();
		}
		else if(op==4)
		{
		int inB;
		printf("Enter thr number::");
		scanf("%d",inB);
		if(dfrontB=19)
		{
			printf("QUEUE IS FULL");
		}
		else
			{
			de[drearB]=inB;
			drearB++;
			} 
		deq();
		}
		else if(op==5)
		{
		if(dfrontB==drearB)
		{
			printf("QUEUE IS EMPTY");
		}
		else
			dfrontB--;
		deq();
		}
		else if(op==6)
		{
		for(int i=drearB;i<dfrontB;i++)
			printf("%d\n",de[i]);
		deq();
		}
		 else
			main();	

}					
void main()
{
	printf("1.LINEAR QUEUE\n2.CIRCULAR QUEUE\n3.DEQUE\n4.EXIT\nENTER THE CHOICE\n\n");
	scanf("%d",&qs);
	if(qs==1)
		linear();
	else if(qs==2)
		circular();
	else if(qs==3)
		deq();
	else
		printf("SED AYI NEN PON BEI");
}
		
		
