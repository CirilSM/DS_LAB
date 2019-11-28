#include<stdio.h>
int ch,cho,l[20],c[20],d[20],nl,nc,nd=-1,fl=-1,fc=-1,fd=-1,rl=-1,rc=-1,rd=-1;
void lqi()
{
	int x;
    	if(rl==nl-1)
        	printf("Linear Queue full\n");
    	else
    	{
		printf("Enter the element\n");
        	scanf("%d",&x);
        	if(fl==-1)
        	{
            		fl=0;
            		rl=0;
            		l[rl]=x;
        	}
        	else
        	{
            		rl++;
            		l[rl]=x;
        	}
    	}
}
void lqd()
{
	int s;
    	s=l[fl];
    	if(fl==-1)
        	printf("Linear Queue empty\n");
    	else
    	{
		if(fl==rl)
        	{
           	 	fl=-1;
            		rl=-1;
        	}
        	else
            		fl++;
        	printf("Deleted %d\n",s);
    	}
}
void lqdi()
{
   	int i;
    	if(fl==-1)
        	printf("Linear Queue is empty\n");
    	else
    	{
		for(i=fl;i<=rl;i++)
			printf("%d\n",l[i]);
    	}
}
void cqi()
{
	int x;
   	if((fc==0&&rc==nc-1)||(fc==rc+1))
        	printf("Circular Queue full\n");
   	else
   	{
		printf("Enter the element\n");
       		scanf("%d",&x);
       		if(fc==-1)
       		{
           		fc=0;
           		rc=0;
           		c[rc]=x;
       		}
       		else
       		{
           		rc++;
           		c[rc]=x;
       		}
   	}
}
void cqd()
{
	int s;
    	if(fc==-1)
        	printf("Circular Queue is empty\n");
    	else
    	{
		s=c[fc];
        	if(fc==rc)
        	{
            		fc=-1;
            		rc=-1;
        	}
        	else if(fc==nc-1)
            		fc=0;
        	else
            		fc++;
        	printf("Deleted %d\n",s);
    	}
}
void cqdi()
{
	int i;
    	if(fc==-1)
        	printf("Circular Queue is empty\n");
    	else
    	{
		if(fc<=rc)
        	{
			for(i=fc;i<=rc;i++)
            			printf("%d",c[i]);
       	 	}
        	else
        	{
            		for(i=fc;i<=nc-1;i++)
            		{
				printf("%d",c[i]);
                		printf("\n");
            		}
        	}
    	}
}
void dqif()
{
	int x;
    	if((fd==0&&rd==nd-1)||(fd==rd+1))
        	printf("Double Ended Queue full\n");
    	else
    	{
		printf("Enter the element\n");
       		scanf("%d",&x);
       		if(fd==-1)
       		{
           		fd=0;
           		rd=0;
           		d[fd]=x;
       		}
       		else if(fd==0)
       		{
			fd=nd-1;
            		d[fd]=x;
       		}
       		else
       		{
			fd--;
            		d[fd]=x;
       		}
   	}
}
void dqir()
{
	int x;
   	if((fd==0&&rd==nd-1)||(fd==rd+1))
        	printf("Circular Queue full\n");
   	else
   	{
		printf("Enter the element\n");
       		scanf("%d",&x);
       		if(fd==-1)
       		{
           		fd=0;
           		rd=0;
           		d[rd]=x;
       		}
       		else if(rd==nd-1)
       		{
           		rd=0;
           		d[rd]=x;
       		}
       		else
       		{
           		rd++;
           		d[rd]=x;
       		}
   	}
}
void dqdf()
{
    	int s;
    	if(fd==-1)
        	printf("Double ended Queue is empty\n");
   	else
    	{
		s=d[fd];
        	if(fd==rd)
        	{
            		fd=-1;
            		rd=-1;
        	}
        	else if(fd==nd-1)
            		fd=0;
        	else
            		fd++;
        	printf("Deleted %d\n",s);
    	}
}
void dqdr()
{
    	if(fd==-1&&rd==-1)
        	printf("Double Ended Queue empty");
    	else
    	{
        	int s;
        	s=d[rd];
        	if(fd==rd)
        	{
            		fd=-1;
            		rd=-1;
        	}
        	else if(rd==0)
            		rd=nd-1;
        	else
            		rd--;
        	printf("Deleted %d\n",s);
    	}
}
void dqdi()
{
    	int i;
    	if(fd==-1)
        	printf("Double Ended Queue is empty\n");
    	else
    	{
		if(fd<=rd)
			for(i=fd;i<=rd;i++)
				printf("%d\n",d[i]);
        	else if(fd>=rd)
        	{
			for(i=rd;i>=0;i--)
          			printf("%d\n",d[i]);
         		for(i=fd;i<=nd-1;i++)
         			printf("%d\n",d[i]);
        	}
        	else
            	for(i=0;i<=nd-1;i++)
               		printf("%d",d[i]);
    	}
}
void dq()
{
    	int z,l;
	if(nd==-1)
	{
    		printf("Enter the size\n");
    		scanf("%d",&nd);
	}
	printf("1.Insertion\n2.deletion\n3.display\n4.exit\n");
       	printf("Enter your choice\n");
       	scanf("%d",&z);
       	switch(z)
      	{
      		case 1:
       		{
			printf("1.Insert at front\n2.Insert at rear\n");
               		scanf("%d",&l);
               		switch(l)
               		{
               			case 1:
               			{
                      			dqif();
                       			break;
              			}
                 		case 2:
                    		{
                        		dqir();
                        		break;
                    		}
               		}
			dq();
               		break;
           	}
            	case 2:
            	{
			int k;
                	printf("1.Delete at front\n2.Delete at rear\n");
                	scanf("%d",&k);
                	switch(k)
                	{
                   		case 1:
                   		{
                        		dqdf();
                        		break;
                    		}
                    		case 2:
                    		{
                        		dqdr();
                        		break;
                    		}
                	}
			dq();
                	break;
            	}
            	case 3:
            	{
                	dqdi();
			dq();
                	break;
            	}
            	case 4:
            	{
			break;
            	}
            	default:
		{
			printf("Invalid choice");
			dq();
        	}
	}
}
void cq()
{
    int choi=0,z;
    printf("Enter the size\n");
    scanf("%d",&nc);
    do
    {   printf("1.Insertion\n2.deletion\n3.display\n4.exit\n");
        printf("Enter your choice\n");
        scanf("%d",&z);
        switch(z)
        {
            case 1:
            {
                cqi();
                break;
            }
            case 2:
            {
                cqd();
                break;
            }
            case 3:
            {
                cqdi();
                break;
            }
            case 4:
            { choi++;
            break;
            }
            default:printf("Invalid choice");
        }
    }while(choi==0);
}
void lq()
{   int choi=0;
    printf("Enter the size\n");
    scanf("%d",&nl);
    do
    {   printf("1.Insertion\n2.deletion\n3.display\n4.exit\n");
        printf("Enter your choice\n");
        scanf("%d",&cho);
        switch(cho)
        {
            case 1:
            {
                lqi();
                break;
            }
            case 2:
            {
                lqd();
                break;
            }
            case 3:
            {
                lqdi();
                break;
            }
	case 4:
            { choi++;
      	      break;
            }
            default:printf("Invalid choice\n");
        }
    }while(choi==0);
}
void main()
{   int d;
    do
   {    printf("1.Linear Queue\n2.Circular Queue\n3.Double Ended Queue\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                lq();
                break;
            }
            case 2:
            {
                cq();
                break;
            }
            case 3:
            {
                dq();
                break;
            }
            default:printf("Invalid choice");
        }
        printf("Do you want to continue? if yes type 1\n");
        scanf("%d",&d);
   }while(d==1);
}
