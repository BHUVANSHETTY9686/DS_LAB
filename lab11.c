#include<stdio.h>
#include<stdlib.h>

int a[10][10], n, m, i, j, source,b[10];
int visited[10];

void create()
{
printf("\nEnter the number of cities:\n ");
scanf("%d", &n);
printf("\nEnter the adjacency matrix of the graph:\n");
for(i=1; i<=n; i++)
for(j=1; j<=n; j++)
scanf("%d", &a[i][j]);
}


void bfs()
{
int queue[10], v, front=0, rear=-1;
printf("\nEnter the starting vertex\n");
scanf("%d", &source);
queue[++rear] = source;
visited[source] = 1;
while(front<=rear)
{
v = queue[front++];
for(i=1; i<=n; i++)
{
if(a[v][i] == 1 && visited[i] == 0)
{
queue[++rear] = i;
visited[i] = 1;
printf("\n%d", i);
}
}
}
}

void dfs(int source)
{
int v;
b[source] = 1;
for(v=1; v<=n; v++)
{
if(a[source][v] == 1 && b[v] == 0)
{
printf("\n%d -> %d", source, v);
dfs(v);
}
}
}

void main()
{
int choice;

while(1)
{
printf("\n1.Create Graph\n2.BFS\n3.Check graph connected or  not(DFS)\n4.Exit");
printf("\nEnter your choice: ");
scanf("%d", &choice);
switch(choice)
{
case 1: create();
break;
case 2: bfs();

   for(i=1;i<=n;i++)
   if(!visited[i])
       printf("\nThe vertex that is not rechable %d" ,i);
   break;
case 3: printf("\nEnter the source vertex to find the connectivity: ");
   scanf("%d",&source);
   m=1;
              dfs(source);
   for(i=1;i<=n;i++)
   {
       if(!b[i])
           m=0;
   }
   if(m==1)
           printf("\nGraph is Connected");
   else
       printf("\nGraph is not Connected");
   break;
case 4: exit(0);
default: printf("Invalid choice");
}
}
}