#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10

struct stack
{
    int top;
    char data[MAX];
}s;
void initstack();
int isempty();
int isfull();
char stacktop();
int priority(char c);
void push(char ch);
char pop();
void postfix(char in[MAX],char post[MAX]);

void initstack()
{
   s.top=-1;
}

int isfull()
{
    if(s.top==MAX-1)
    return 1;
    else
    return 0;
}
int isempty()
{
   if(s.top==-1)
   return 1;
   else
   return 0;
}

void push(char ch)
{
    if(isfull())
    printf("\nStack is full\n");
    else
    s.data[++s.top]=ch;
}

char pop()
{
   if(isempty())
   {
       printf("\nStack is empty\n");
       return -1;
   }
   else
   return s.data[s.top--];
}

char stacktop()
{
   return s.data[s.top];
}

int priority(char c)
{
   switch(c)
   {
       case '(':return 0;
       case '+':case '-':case '$':return 1;
       case '*':case '/':case '%':return 2;
       case '^':return 3;
    }
    return -1;
}

void postfix(char in[MAX],char post[MAX])
{
     int i,j=0;
     char ch;
     initstack();

     for(i=0;in[i]!='\0';i++)
     {
	 if(in[i]=='(')
	     push(in[i]);

	 else if((in[i]>='A'&&in[i]<='Z')||(in[i]>='a'&&in[i]<='z'))
	      post[j++]=in[i];

	 else if(in[i]=='+'||in[i]=='-'||in[i]=='$'||in[i]=='*'||in[i]=='/'|| in[i]=='%')
	 {
	     while(priority(stacktop())>=priority(in[i]))
	     {
		 post[j++]=pop();

	     }
	     push(in[i]);
	 }
	  else if(in[i]==')')
	  {
	      while((ch=pop())!='(')
	      {
		  post[j++]=ch;
	      }
	  }
      }

	 while(isempty()!=1)
	 {
	    post[j++]=pop();
	 }


     post[j]='\0';
}
//postfix
/*
void main()
{
    char in[MAX],post[MAX];
    int i,j;
    clrscr();
    printf("E\Enter the infix expression\n");
    scanf("%s",in);
    postfix(in,post);
    printf("%s",post);
    getch();
    }
*/
//prefix
/*
void main()
{
char in[MAX],post[MAX];
int i;
clrscr();
printf("\nEnter infix expression:");
scanf("%s",in);
strrev(in);
for(i=0;in[i]!='\0';i++)
{
if(in[i]=='(')
in[i]=')';
else if(in[i]==')')
in[i]='(';
}
postfix(in,post);
strrev(post);
printf("Prefix expression is %s",post);
getch();
}
*/
//Evaluatue

