#include<stdio.h>
struct process
{
    int ps;
    int flag;
}p[50];
struct size
{
    int size;
    int alloc;
}s[5];

int main()
{
    int i=0,np=0,n=0,j=0,k=0,big=0,full=0;
    printf("\nworst fit\n");
    printf("\nEnter the number of blocks:");
    scanf("%d",&n);
    printf("\nEnter the size of blocks:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&s[i].size);
    }
    printf("\nEnter the number of process:");
    scanf("%d",&np);
    printf("Enter the size of process\n");
    for(i=0;i<np;i++)
    {
        scanf("%d",&p[i].ps);
    }
    printf("\nAllocation of blocks using worst fit");
    printf("\nprocess\tprocess size\tblock\tblock size\n");
    for(i=0;i<np;i++)
    {
        big=-1;
        for(k=0;k<n;k++)
        {
            if(p[i].ps<=s[k].size)
            {
                if(big<s[k].size)
                {
                    if(s[k].alloc!=1)
                    {
                        big=s[k].size;
                    }
                }
            }
        }
        for(j=0;j<n;j++)
        {
            if(big==s[j].size)
            {
                break;
            }
        }
        if(p[i].flag!=1)
        {
            if(p[i].ps<=s[j].size)
            {
                p[i].flag=1;
                s[j].alloc=1;
                printf("\n%d\t\t%d\t\t%d\t\t%d\t",i,p[i].ps,j,s[i].size);
            }
        }
    }
    for(i=0;i<np;i++)
    {
        if(p[i].flag!=1)
        {
            full=1;
            printf("\nsorry!!process%d must wait as there is no sufficient memory",i);
        }
    }
    if(full==0)
    {
        printf("\nAllocation successfully completed!!!");
    }
}

