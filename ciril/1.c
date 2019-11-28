#include<string.h>
#include<stdlib.h>
void main()
{
char s1[50],s2[50],str[50];
int ch,f;
printf("1.String Concatination.\n2.Deletion of substring.\nEnter your choice\nPRESS ANY OTHER KEY TO EXIT");
scanf("%d",&ch);
do
{
f=0;
if(ch==1)
{
printf("enter the 1st string:\n");
scanf("%s",s1);
printf("Enter the 2nd string:\n");
scanf("%s",s2);
strcat(s1,s2);
puts(s1);
printf("Press 1 to continue");
scanf("%d",f);
}
else if(ch==2)
{
char text[100],str[100],newtext[100];
      int i=0,j=0,k,n=0,c=0;  
      printf("\n Enter the main text: ");
      scanf("%s",text);
      printf("\n Enter the string to be deleted: ");
      scanf("%s",str);  
    while(text[i]!='\0')
    {
    j=0,k=i;
              while (text[k]==str[j]&&str[j]!='\0')
              {
              k++;
              j++;
              }
                  if(str[j]=='\0')
                  {
                        c=k;
                  }
                        newtext[n]=text[c];
                        i++;
                        c++;
                        n++;
    }
str[n]='\0';
                printf("\n The new string is: ");
                puts(
newtext);
printf("Press 1 to continue");
scanf("%d",f);
}
else
	exit(0);
}while(f==1);
} 
