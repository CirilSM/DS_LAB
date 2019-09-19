#include<stdio.h>
int n,i=0,top=-1;
char inf[10],stack[10],d;
void push(char a)
{
	if(top==10)
		printf("\nSTACK FULL");
	else
		{
			stack[top+1]=a;
			top++;
		}
}
char pop()
{
	if(top==-1)
		printf("\nSTACK EMPTY");
	else
		{
			return stack[top--];
		}
}
int check(char c) 
{ 
    if(c=='^') 
    return 3; 
    else if(c=='*'||c=='/') 
    return 2; 
    else if(c=='+'||c=='-') 
    return 1; 
    else
    return -1; 
} 
void main()
{
	push('#');
	printf("Enter the infix Expression::");
	scanf("%s",inf);
	while(inf[i]!='\0')
	{
          if(isalnum(inf[i]))
		printf("%c",inf[i]);
	  else if(inf[i]=='(')
		push(inf[i]);
	  else if(inf[i]==')')
	  {
		while((d=pop())!='(')
			printf("%c",d);
	  }
          else
	  {
		while(check(stack[top]) >= check(inf[i]))
			printf("%c",pop());
		push(inf[i]);
	  }
	i++;
	}//end of while

	while(top!=0)//0 is given so that # will not be printed
	{
		printf("%c",pop());
	}
	printf("\n");//for a space
}

			
	
	
