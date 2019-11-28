#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int top=-1,stack[20],i;
void push();
void pop();
void peep();
void isempty();
void isfull();
void disp();
void main()
{
	int n;
	printf("\n\n1.Push\n2.Pop\n3.Peep\n4.Is Empty\n5.Is Full\n6.Display\n7.Exit\nENTER YOUR CHOICE: ");
	scanf("%d",&n);
	if(n==1)
		push();
	else if(n==2)
		pop();
	else if(n==3)
		peep();
	else if(n==4)
		isempty();
	else if(n==5)
		isfull();
	else if(n==6)
		disp();
	else
		exit(0);
}
void push()
{
	if(top==4)
		printf("\nSTACK FULL");
	else
		{
			printf("\nENTER THE ELEMENT :");
			scanf("%d",&stack[top+1]);
			top++;
			printf("\nPUSH SUCCESSFULL");
		}
main();
}
void pop()
{
	if(top==-1)
		printf("\nSTACK EMPTY");
	else
		{
			top--;
			
			printf("\nPOP SUCCESSFULL");
		}
main();
}
void peep()
{
	printf("%d",stack[top]);
	main();
}
void isempty()
{
	if(top==-1)
		printf("\nSTACK EMPTY");
	else
		printf("\nSTACK NOT EMPTY");
main();
}
void isfull()
{
	if(top==4)
		printf("\nSTACK FULL");
	else
		printf("\nSTACK NOT FULL");
main();
}
void disp()
{
	if(top==-1)
		printf("STACK EMPTY");
	else
		for(i=top;i>-1;i--)
			printf("%d\n",stack[i]);
main();
}

	

	
	
	

