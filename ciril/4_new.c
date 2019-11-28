#include<stdio.h>
int n,i=0,top=-1;
char inf[10],stack[10],post[10],d,s;
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
		{
		printf("%c",inf[i]);
		post[i]=inf[i];
		}
	  else if(inf[i]=='(')
		{
		push(inf[i]);
		}
	  else if(inf[i]==')')
	  {
		while((d=pop())!='(')
			{
			printf("%c",d);
			post[i]=d;
			}
	  }
          else
	  {
		while(check(stack[top]) >= check(inf[i]))
			{
			s=pop();
			printf("%c",s);
			post[i]=s;
			}
		push(inf[i]);
	  }
	i++;
	}//end of while
	i=0;
	while(post[i]!='\0')//0 is given so that # will not be printed
	{
		post[i]=pop();
		printf("%c3",post[i]);
		i++;
	}
	printf("\n%s\n",post);//for a space
}

			
	
	
