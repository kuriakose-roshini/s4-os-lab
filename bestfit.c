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
	int i=0,np=0,n=0,j=0,k=0,l=0,small=0,full=0;
	printf("\nBEST FIT ::");
	printf("\nEnter the no of blocks :");
	scanf("%d",&n);
	printf("\nEnter the size of %d block\n",n);
	for(i=0;i<n;i++)
	{
		printf("enter the size for %d block:: ",i);
		scanf("%d",&s[i].size);
	}
	printf("\n enter the no of process ::\t");
	scanf("%d",&np);
	printf("\nenter the size for %d processors",np);
	printf("\n");
	for(i=0;i<np;i++)
	{
		printf("enter the size of process %d:: ",i);
		scanf("\n%d",&p[i].ps);
	}
	printf("\nAllocation of blocks using best fit is as follows ::\n");
	printf("\nprocess\t process size\t blocks\t block size\n");
	for(i=0;i<np;i++)
	{
		//big=s[0].size;
		small=99999;
		for(k=0;k<n;k++)
		{
			
			if(p[i].ps<=s[k].size)
			{
			
				if(small>s[k].size)
				{
					if(s[k].alloc!=1)
					{
						small=s[k].size;
					}
				}
			}
		}
		for(j=0;j<n;j++)
		{
			if(small==s[j].size)
			{
				break;
			}
		}
        full=0;
        for(l=0;l<n;l++)
        {
            if(j==l)
            {
                full=1;
            }
        }
        if(full==1)
        {
                if(p[i].flag!=1)
                {
                    if(p[i].ps<=s[j].size)
                    {
                        p[i].flag=1;
                        s[j].alloc=1;
                        printf("\n%d\t\t%d\t%d\t\t%d",i,p[i].ps,j,s[j].size);
                    }
                }
        }
    }
        for(i=0;i<np;i++)
        {
            if(p[i].flag!=1)
            {
                full=1;
                printf("\n sorry !!! process %d must wait as there is no sufficient memory...",i);
            }
        }
        if(full==0)
        {
            printf("\n Allocation Successully Completed!!");
        }
}