#include<stdio.h>
#include<ctype.h>
#include<math.h>
char c[20],s[20],h[20],t=-1,t2=-1,j=0;
void push(char c)
{
	t++;
	s[t]=c;
}
char pop()
{
	int y;
  	y=s[t];
  	t--;
  	return(y);
}
int opr(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
 	       return 1;
}
int isp(char c)
{
	if(c=='+'||c=='-')
    		return 2;
  	else if(c=='*'||c=='/')
    		return 4;
  	else if(c=='^')
    		return 5;
  	else if(c=='(')
  		return 0;
  	else if(c=='#')
    		return 0;
}
int icp(char c)
{
	if(c=='+'||c=='-')
    		return 1;
  	else if(c=='*'||c=='/')
    		return 3;
  	else if(c=='^')
    		return 6;
  	else if(c=='(')
    		return 9;
  	else if(c==')')
    		return 9;
  	else if(c=='#')
    		return 0;
}
void inpo()
{
	char ch, elem;
    	int i = 0, k = 0;
    	push('#');
    	while ((ch = c[i++]) != '\0')
    	{
		if (ch == '(')
        		push(ch);
     		else if (isalnum(ch))
        		h[k++] = ch;
     		else if (ch == ')')
    		{
			while (s[t] != '(')
            			h[k++] = pop();
        		elem = pop();
    		}
     		else
     		{
			while (isp(s[t]) >= icp(ch))
            			h[k++] = pop();
        		push(ch);
     		}
    	}
    	while (s[t] != '#')
        	h[k++] = pop();
}
int eval(char postfix[])
{
	char ch;
  	int i = 0, op1, op2;
  	while((ch = postfix[i++])!='\0')
  	{
		if(isdigit(ch))
        		push(ch-'0');
    		else
    		{
			op2 = pop();
  	    		op1 = pop();
    			switch(ch)
    			{
				case '+' :
      	 			{
					push(op1+op2);
          				break;
       				}
       				case '-' :
       				{
					push(op1-op2);
        	  			break;
       				}
       				case '*' :
       				{
					push(op1*op2);
           				break;
       				}
       				case '/' :
			       	{
					push(op1/op2);
           				break;
       				}
       				case '^':
       				{
					push(pow(op1,op2));
           				break;
       				}
    			}
  		}
	}
 	return s[t];
}
void main()
{
	long int r;
    	printf("Enter the Infix Expression:-");
    	scanf("%s",c);
    	inpo();
	printf("Postfix Expression:-");
    	printf("%s",h);
    	t=-1;
    	r=eval(h);
    	printf("\nResult is %ld",r);
}


