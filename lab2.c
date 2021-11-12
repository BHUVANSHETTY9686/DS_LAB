#include<stdio.h>
#include<string.h>
char str[50], pat[50], rep[50], ans[50];
int c=0, m=0, i=0, j=0, k=0, found=0;
void stringmatch()
{
    while(str[c] !='\0')
    {
        if(str[i] == pat[j])
        {
            j++;
            i++;
            if(pat[j] == '\0')
            {
                j=0;
                found = 1;
                for(k=0; rep[k]!='\0'; k++, m++)
                {
                    ans[m] = rep[k];
                }
                c=i;
            }

        }
        else
        {
            ans[m]= str[c];
            m++;
            c++;
            i=c;
            j=0;
        }
    }
}
void main()
{
    printf("\nEnter the main string:");
    gets(str);
    printf("\nEnter the pat string:");
    gets(pat);
    printf("\nEnter the replace string:");
    gets(rep);
    stringmatch();
    if(found == 1)
        printf("Resultant string is %s\n", ans);
    else
        printf("Pattern string is not found\n");
}
