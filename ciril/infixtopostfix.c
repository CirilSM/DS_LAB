#include<ctype.h>
#include<stdio.h>
int top=-1;
char s[100];
void push(char ch)
{
	s[++top]=ch;
}
char pop()
{
	return (s[top--]);
}
int pr(char ch)
{
	switch(ch)
	{
		case '#': return 0;
		case '(': return 1;
		case '+':
		case '-': return 2;
		case '*': 
		case '/': return 3;
	}
}
void main()
{
	char in[50],po[50],ch,e;
	int i=0,k=0;
	printf("Enter expression:");
	scanf("%s",in);
	while(ch=in[i++]!='\0')
	{
		if(ch=='(')
			push(ch);
		else 
			if(isalnum(ch))
			po[k++]=ch;
		else 
			if(ch==')')
			{
			while(s[top]!='(')
				po[k++]=pop();
			e=pop();
			}
			else
			{
			while(pr(s[top])>=pr(ch))
				po[k++]=pop();
			push(ch);
			}
	}
	while(s[top]!='#')
		po[k++]=pop();
	po[k]='\0';
	printf("%s",po);
} 
