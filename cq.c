#include<stdio.h>
int q[200],cq[200],dq[200];
int fq,rq,fcq,rcq,fdq,rdq,nq,ncq,nrq;
void insert(char wq)
{
	switch(wq)
	{
		case('n'):
		{
			if(rq==n-1)
				printf("\nQUEUE FULL");
			else
			{
				printf("\Enter an element ");
				scanf("%d",&q[++rq]);
			}
			break;
		}
		case('c'):
		{
			if((fcq==rcq+1)||(fcq==0&&rcq==ncq-1))
				printf("\nQUEUE FULL");
			else
			{
				if(rcq==ncq-1)
					rcq=-1;
				printf("\nEnter an element ");
				scanf("&d",&cq[++rcq]);
			}
			break;
		}
		case('d'):
		{
			if((fcq==rcq+1)||(fcq==0&&rcq==ncq-1))
                                printf("\nQUEUE FULL");
                        else
                        {
				printf("input through front or rear? ");
				char s;
				scanf("%c",&s);
				if(s=='r')
                                if(rcq==ncq-1)
                                        rcq=-1;
                                printf("\nEnter an element ");
                                scanf("&d",&cq[++rcq]);
                        }

}
