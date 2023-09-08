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
}s[50];
int main()
{
    int i=0,np=0,n=0,j=0,full=0;
    printf("\nFirst fit\n");
    printf("Enter the number of blocks:");
    scanf("%d",&n);
    printf("Enter the size of blocks\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&s[i].size);
    }
    printf("\nEnter the number of process:");
    scanf("%d",&np);
    printf("Enter size of each process");
    for(i=0;i<np;i++)
    {
        scanf("%d",&p[i].ps);
    }
    printf("\nAllocation of blocks using first fit as follows\n");
    printf("\nprocess\tprocess size\t block\tblock size\tfragment");
    for(i=0;i<np;i++)
    {
        for(j=0;j<n;j++)
        {
            if(p[i].flag!=1)
            {
                if((p[i].ps<=s[j].size)&&(s[j].alloc!=1))
                {
                    p[i].flag=1;
                    printf("\n%d\t\t%d\t\t%d\t%d\t%d",i,p[i].ps,j,s[i].size,(s[i].size-p[i].ps));
                    s[j].alloc=1;
                }

            }
        }
    }
    for(i=0;i<np;i++)
    {
        if(p[i].flag!=1)
        {
            full=1;
            printf("\nsorry!!process %d must wait as there is no sufficient memory",i);
        }
    }
    if(full==0)
    {
        printf("\nAllocation successfully completed!!!");
    }
}