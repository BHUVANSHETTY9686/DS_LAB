#include<stdio.h>
#include<math.h>
#define MAX 20
typedef struct
{
	int top;
	int item[MAX];
}STACK;
void push(STACK *s, int ele)
{
	if(s->top==MAX-1)
	printf("stack overflow\n");
		else
	{
		s->top++;
		s->item[s->top]=ele;
	}
}
int pop(STACK *s)
{
	if(s->top==-1)
		printf("stack underflow\n");
	else
		return s->item[s->top--];
}
void main()
{
	STACK s;
	char postfix[MAX],token;
	int i,op1,op2;
	s.top=-1;
	printf("Enter the postfix expression\n");
	scanf("%s",postfix);
	for(i=0;postfix[i]!='\0';i++)
	{
		token=postfix[i];
		switch(token)
		{
			case '+':op2=pop(&s);
 				 op1=pop(&s);
 				 push(&s,op1 + op2);
 				 break;
			case '-':op2=pop(&s);
 				 op1=pop(&s);
 				 push(&s ,op1- op2);
 				 break;
			case '*':op2=pop(&s);
 				 op1=pop(&s);
 				 push(&s ,op1* op2);
				 break;
			case '/':op2=pop(&s);
				 op1=pop(&s);
				 push(&s ,op1/ op2);
				 break;
			case '^':op2=pop(&s);
				 op1=pop(&s);
				 push(&s ,(pow(op1,op2)));
				 break;
			case '%':op2=pop(&s);
				 op1=pop(&s);
				 push(&s ,op1% op2);
				 break;
			default:push(&s ,token-'0');
		}
	}	
	printf("result= %d",s.item[s.top]);
}

