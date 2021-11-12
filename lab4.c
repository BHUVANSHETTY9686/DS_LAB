#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define max 20
typedef struct
{
char item[20];
int top;
}stack;

void push(stack *,char op);
int prcd(char op);
char pop(stack *);
void conversion(stack *,char infix[30],char postfix[30]);
void main()
{
	stack s;
	char infix[30],postfix[30];
	s.top=-1;
	s.item[++s.top]='#';
	printf("Enter a valid infix expression\n");
	scanf("%s",infix);
	conversion(&s,infix,postfix);
	printf("Postfix expression is %s\n",postfix);

}

void push(stack *s,char op)
{
	if(s->top==max-1)
         printf("stack overflow\n");
   else
         s->item[++s->top]=op;
}

char pop(stack *s)
{
	char x;
	if(s->top==-1)
	{
		printf("Invalid Expression\n");
		exit(0);
	}
	else
  	{
		return(s->item[s->top--]);
	}
}
void conversion(stack *s,char infix[30],char postfix[30])
{
	int i=0,j=0;
	char token;
	while(infix[i]!='\0')
  	{
   		token=infix[i];
   		if(isalnum(token))
    		{
      			postfix[j++]=token;
    		}
   		else if(token=='(')
    			push(s,token);
   		else if (token==')')
    		{
     			while(s->item[s->top]!='(')
      			{
 				postfix[j++]=pop(s);
      			}
      			pop(s);
    		}
   		else
    		{
      			while(prcd(s->item[s->top])>=prcd(token))
       			{
 				postfix[j++]=pop(s);
 	  		}
 			push(s,token);
    		}
   		i++;
	}
	while(s->item[s->top]!='#')
		postfix[j++]=pop(s);
 	postfix[j++]='\0';
}

int prcd(char op)
{
 	switch(op)
 	{
 		case '^':return 4;
 		case '*':
 		case '/':
 		case '%':return 3;
 		case '+':
 		case '-':return 2;
 		case '(':return 1;
 		case '#':return 0;
	  	         break;
 		default :printf("Invalid expression\n");
 	}
}
