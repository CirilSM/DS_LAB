#include<stdio.h>
#include<malloc.h>
struct node
{
    int c;
    int e;
    struct node *next;
};
struct node *p1=NULL,*p2=NULL,*pr=NULL;
int t1,t2;
struct node *insertpoly(struct node *list,int coeff,int exp)
{

        struct node *temp,*t;
        temp=(struct node*)malloc(sizeof(struct node));
        t=list;
         if(list==NULL)
        {
            temp->c=coeff;
            temp->e=exp;
            temp->next=NULL;
            list=temp;
        }
        else
        {
            while(t->next!=NULL)
                t=t->next;
            t->next=temp;
            temp->c=coeff;
            temp->e=exp;
            temp->next=NULL;
        }
	return list;
}
struct node *readpoly(struct node *poly,int terms)
{
	int i,co,ex;
	for(i=1;i<=terms;i++)
	{
	        printf("Enter the coeff %d",i);
	        scanf("%d",&co);
	        printf("Enter the exp %d:",i);
	        scanf("%d",&ex);
	        poly=insertpoly(poly,co,ex);
	}
	return poly;
}
void display(struct node *poly)
{
    printf("\n");
   while(poly->next!=NULL)
    {
        printf("%dX^%d+",poly->c,poly->e);
        poly=poly->next;
    }
    if(poly->e==0)
            printf("%d",poly->c);
    else
        printf("%dX^%d",poly->c,poly->e);

}
struct node *polyadd(struct node *p1,struct node *p2)
{
    while(t1!=0&&t2!=0)
   {
        if(p1->e>p2->e)
        {
            pr=insertpoly(pr,p1->c,p1->e);
            p1=p1->next;
            t1--;
        }
        else if(p1->e<p2->e)
        {
            pr=insertpoly(pr,p2->c,p2->e);
            p2=p2->next;
            t2--;
        }
       else if(p1->e==p2->e)
        {
            pr=insertpoly(pr,p1->c+p2->c,p1->e);
            p1=p1->next;
            p2=p2->next;
            t1--;
            t2--;
        }
   }
            while(t2!=0)
            {
                pr=insertpoly(pr,p2->c,p2->e);
                p2=p2->next;
                t2--;
            }
            while(t1!=0)
            {
                pr=insertpoly(pr,p1->c,p1->e);
                p1=p1->next;
                t1--;
            }


   return pr;
}
void main()
{
    printf("Enter the no of terms for poly1");
    scanf("%d",&t1);
    p1=readpoly(p1,t1);
    printf("\nEnter the no of terms for poly2");
    scanf("%d",&t2);
    p2=readpoly(p2,t2);
    printf("polynomials are\n");
    display(p1);
    display(p2);
    pr=polyadd(p1,p2);
    printf("\nResult is");
    display(pr);
}
