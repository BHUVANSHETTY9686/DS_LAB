#include<stdio.h>
int a[20];
int elem,i,pos,n;
void create();
void display();
void insert();
void delete();
int main()
{
    int choice;
    while(1)
    {

        printf("\nMENU\n");
        printf("1.CREATE\n");
        printf("2.DISPLAY\n");
        printf("3.INSERT\n");
        printf("4.DELETE\n");
        printf("5.EXIT\n");
        //read choice
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: create();
                    break;
            case 2: display();
                    break;
            case 3: insert();
                    break;
            case 4: delete();
                    break;
            case 5: return 0;
                    break;
            default:printf("Invalid choice\n");
        }
    }
}
void create()
{
    printf("Enter the size of the array elements\n");
    scanf("%d",&n);
    printf("Enter the elements of the array\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

}
void display()
{
    printf("Array elements are:\n");
    for(i=0;i<n;i++)
        printf("a[%d]=%d\n",i,a[i]);
}
void insert()
{
    printf("Enter the position for the new elements\n");
    scanf("%d",&pos);
    if(pos>=n+1)
        printf("Innsertion not possible\n");
    else
        {
            printf("Enter the element to be inserted\n");
            scanf("%d",&elem);
            for(i=n-1;i>=pos;i--)
                a[i+1]=a[i];
            a[pos]=elem;
            n++;
        }
}
void delete()
{
    printf("Enter the position of the elements to be deleted\n");
    scanf("%d",&pos);
    if(pos>=n)
        printf("Deletion is not posible\n");
    else
        {
            printf("The deleted elments is %d\n",a[pos]);
            for(i=pos;i<n-1;i++)
                a[i]=a[i+1];
            n--;
        }
}
