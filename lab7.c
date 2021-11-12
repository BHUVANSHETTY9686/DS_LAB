#include<stdio.h>
#include<stdlib.h>
struct node
{
char usn[11];
char name[20];
char branch[5];
int  sem;
char phno[20];
struct node *link;
};
typedef struct node *NODE;
NODE temp, last, FIRST=NULL;
NODE getnode()
{
	NODE x;
	x=(NODE)malloc(sizeof(struct node));
	x->link=NULL;
	return x;
}
void read()
{
	temp=getnode();
	printf("\nusn\t");
	scanf("%s",temp->usn);
	printf("Name\t");
	scanf("%s",temp->name);
	printf("Branch\t");
	scanf(" %s",temp->branch);
	printf("sem\t");
	scanf("%d",&temp->sem);
	printf("phone no\t");
	scanf("%s",temp->phno);
}
void create()
{
	int n,i;
	printf("Enter the number of students\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++) //read student details
	{
 		printf("Enter details of student %d\n",i);
 		read();
		 if(FIRST==NULL) //if first node is not there or if list is empty (for student 1)
 		{
 			FIRST=temp; //set new node as first node
 		}
 		else
 		{
 			temp->link=FIRST; // inserting at the beginning
 			FIRST=temp; //make temp node(new node) as first node
 		}
	}
}
void display()
{
	int count=0;
	temp=FIRST;
	printf("Student details\n");
	if(FIRST==NULL)
 	printf("No student records available");
	else
	{
 		printf("\nusn\tname\tbranch\tsem\tphone\n");
 		while(temp!=NULL)
 		{
 			count++;
 			printf("%s\t%s\t%s\t%d\t%s\n",temp->usn,temp->name,temp->branch,temp->sem,temp->phno);
 			temp=temp->link; //next node
 		}
		printf("\ntotal no of nodes=%d",count);
	}
}
void insert_front()
{
	printf("Enter the details of new student\n");
	read();
	if(FIRST==NULL)
	FIRST=temp;
	else
	{
 		temp->link=FIRST;
 		FIRST=temp;
 	}
}
void insert_end()
{
	last=FIRST;
	printf("Enter the details of new student\n");
	read();
	if(FIRST==NULL)
 	FIRST=temp;
	else
	{
 		while(last->link!=NULL) // traverse till the last node
 		{
 			last=last->link;
 		}
 		last->link=temp;
	}
}
void del_front()
{
	temp=FIRST;
	if(FIRST==NULL)
 		printf("list is empty\n");
	else
 	{
 		FIRST=FIRST->link; //set second node as the first node
 		free(temp);
 		printf("Node deleted\n");

 	}
}
void del_end()
{
	NODE lastButOne=NULL;
	temp=FIRST;
	if(FIRST==NULL)
 		printf("list is empty\n");
	else if(FIRST->link==NULL) //CHECK FOR SINGLE NODE
	{
 		printf("Deleted\n");
 		free(FIRST);
 		FIRST=NULL;
	}
	else
	{
 		while(temp->link!=NULL)
 		{
 			lastButOne =temp;
 			temp=temp->link;
 		}
 		lastButOne ->link=NULL;
		printf("deleted\n");
		free(temp); //delete last node
	}
}
void main()
{
	int choice;
	while(1)
	{
		printf("\n1.Create\n2.Display\n3.Insert front\n4.Delete front\n5.Insert end\n6.Delete end\n7.exit\n");
		printf("Enter ur choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
 			case 1:create();
			       break;
 			case 2:display();
 			       break;
 			case 3:insert_front();
 		               break;
			case 4:del_front();
 			       break;
 			case 5:insert_end();
 			       break;
			case 6:del_end();
 			       break;
 			case 7:return;
 			default: printf("Invalid choice\n");
		}
	}
}

