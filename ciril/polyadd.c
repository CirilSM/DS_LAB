#include<stdio.h>
#include<malloc.h>
struct node
{
    int c;
    int e;
    struct node *next;
};
struct node *p1=NULL,*p2=NULL,*p=NULL;
int t1,t2;
struct node *insertpoly(struct node *list,int coef,int exp)
{

        struct node *temp,*t;
        temp=(struct node*)malloc(sizeof(struct node));
        t=list;
         if(list==NULL)
        {
            temp->c=coef;
            temp->e=exp;
            temp->next=NULL;
            list=temp;
        }
        else
        {
            while(t->next!=NULL)
                t=t->next;
            t->next=temp;
            temp->c=coef;
            temp->e=exp;
            temp->next=NULL;
        }

return list;
}
struct node *readpoly(struct node *poly,int terms)
 {
     int co,ex;
     for(int i=1;i<=terms;i++)
    {
        printf("Enter the value of coefficient %d:",i);
        scanf("%d",&co);
        printf("Enter the value of exponential %d:",i);
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
        printf("%dX^%d + ",poly->c,poly->e);
        poly=poly->next;
    }
    if(poly->e==0)
            printf("%d\n",poly->c);
    else
        printf("%dX^%d\n",poly->c,poly->e);

}
struct node *polyadd(struct node *p1,struct node *p2)
{
    while(t1!=0&&t2!=0)
   {
        if(p1->e>p2->e)
        {
            p=insertpoly(p,p1->c,p1->e);
            p1=p1->next;
            t1--;
        }
        else if(p1->e<p2->e)
        {
            p=insertpoly(p,p2->c,p2->e);
            p2=p2->next;
            t2--;
        }
       else if(p1->e==p2->e)
        {
            p=insertpoly(p,p1->c+p2->c,p1->e);
            p1=p1->next;
            p2=p2->next;
            t1--;
            t2--;
        }
   }
            while(t2!=0)
            {
                p=insertpoly(p,p2->c,p2->e);
                p2=p2->next;
                t2--;
            }
            while(t1!=0)
            {
                p=insertpoly(p,p1->c,p1->e);
                p1=p1->next;
                t1--;
            }


   return p;
}
void main()
{
    printf("POLYNOMIAL 1 \nEnter the no of terms:");
    scanf("%d",&t1);
    p1=readpoly(p1,t1);
    printf("POLYNOMIAL 2 \nEnter the no of terms:");
    scanf("%d",&t2);
    p2=readpoly(p2,t2);
    printf("Entered polynomials are:-\n");
    display(p1);
    display(p2);
    p=polyadd(p1,p2);
    printf("Result:\n");
    display(p);
}

