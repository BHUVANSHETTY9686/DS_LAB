#include<stdio.h>
#include<stdlib.h>
#define MAX 4
typedef struct 
{
	int front,rear;
	char item[MAX];
}cqueue;
void insert(cqueue *,char c);
void delete(cqueue *);
void display(cqueue *);
void main()
{
	cqueue q;
	int choice;
	char c;
	q.front=q.rear=0;
 	while(1)
 	{
 		printf("\nMenu\n1.insert\n2.delete\n3.display\n4.exit\n");
 		printf("\nEnter your choice\n");
 		scanf("%d",&choice);
 		switch(choice)
 		{
 			case 1:printf("Enter the character to insert\n");
 			       scanf(" %c",&c);
			       insert(&q,c);
			       break;
 			case 2: delete(&q);
				break;
			case 3: display(&q);
				break;
			case 4: return;
 			default: printf("\nInvalid choice\n");
 		}
 	}
}


void insert(cqueue *q,char element)
{
	q->rear=(q->rear+1)%MAX;
	if(q->rear==q->front)
	{
		if(q->rear==0)
			q->rear=MAX-1;
		else
 			q->rear--;
		printf("Circular Queue is FULL\n");
		return;
 	}
	q->item[q->rear]=element;
 	printf("Element inserted\n");
}
void delete(cqueue *q)
{
	if(q->front==q->rear)
	{
 		printf("\nCircular QUEUE is empty\n");
 		return;
	}
	else
	{
 		q->front=(q->front+1)%MAX;
 		printf("Deleted element is %c\n",q->item[q->front]);

	}
}
void display(cqueue *q)
{
 	int i;
 	if(q->front==q->rear)
 	{
		 printf("Circular QUEUE is EMPTY\n");
 		return;
 	}
 	else if(q->front<q->rear)
 	{
 		for(i=q->front+1;i<=q->rear;i++)
 		printf("%c\t",q->item[i]);
 	}
 	else
 	{
 		for(i=q->front+1;i<=MAX-1;i++)
 			printf("%c\t",q->item[i]);
 		for(i=0;i<=q->rear;i++)
 			printf("%c\t",q->item[i]);
 	}
}
