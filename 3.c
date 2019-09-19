#include<stdio.h>
int A[100];
int topA=-1;
int topB;
int t;
int n;
void popA()
{
if(topA<0)
{
printf("STACK IS EMPTY");
}
else
topA--;
}
void popB()
{
if(topB==n)
{
printf("STACK IS EMPTY");
}
else
topB++;
}
void pushA()
{
if(topA==topB-1)
printf("\nSTACK OVERFLOW");
else
{
topA++;
scanf("%d",&t);
A[topA]=t;
}
}
void pushB()
{
if(topB-1==topA)
printf("\nSTACK OVERFLOW");
else
topB--;
scanf("%d",&t);
A[topB]=t;
}
void displayA()
{
for(int i=topA;i>=0;i--)
printf("\n%d   ",A[i]);
printf("\n");
}
void displayB()
{
for(int i=topB;i<n;i++)
printf("\n%d   ",A[i]);
printf("\n");
}
void isemptyA()
{
if(topA<0)
printf("EMPTY");
else 
printf("NOT EMPTY");
}
void isemptyB()
{
if(topB>=n)
printf("EMPTY");
else 
printf("NOT EMPTY");
}
void isfullA()
{
if(topA==topB)
printf("FULL");
else 
printf("NOT FULL");
}
void isfullB()
{
if(topB-1==topB)
printf("FULL");
else 
printf("NOT FULL");
}
void peepA()
{
printf("%d",A[topA]);
}
void peepB()
{
printf("%d",A[topB]);
}
void main()
{
int u;
int p=0;
printf("ENTER SIZE OF ARRAY");
scanf("%d",&n);
topB=(2*n);
do
{
printf("\n1:POP A\n2:PUSH A\n3.POP B\n4.PUSH B\n5:DISPLAY A\n6:DISPLAY B\n7.PEEP A \n8.PEEP B\n9IS EMPTY A \n10.ISEMPTY B \n11.ISFULL A \n12.ISFULL B\n13. EXIT");
scanf("%d",&u);
if(u==1)
popA();
else if(u==2)
pushA();
else if(u==3)
popB();
else if(u==4)
pushB();
else if(u==5)
displayA();
else if(u==6)
displayB();
else if(u==7)
peepA();
else if(u==8)
peepB();
else if(u==9)
isemptyA();
else if(u==10)
isemptyB();
else if(u==11)
isfullA();
else if(u==12)
isfullB();
else if(u==13)
{
p++;
}
}
while(p==0);
}
