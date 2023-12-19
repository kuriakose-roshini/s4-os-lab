#include<stdio.h>
int main()
{
    int n,m,i,j;
    int alloc[20][10],max[20][10],avail[10];
    printf("Enter number of process:");
    scanf("%d",&n);
    printf("Enter number of resources:");
    scanf("%d",&m);
    printf("Enter allocation matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&alloc[i]);
        }
    }

    printf("Enter maximum matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&max[i]);
        }
    }

    printf("Enter available matrix:\n");
    for(j=0;j<m;j++)
    {
         scanf("%d",&avail[i]);
    }

    int f[n],ans[n],ind=0,k;
    for(k=0;k<n;k++)
    {
        f[k]=0;
    }

    int need[n][m];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }

    }
    int y=0;
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            if(f[i]==0)
            {
                int flag=0;
                for(j=0;j<m;j++)
                {
                    if(need[i][j]>avail[j])
                    {
                        flag=1;
                        break;
                    }
                }

                if(flag==0)
                {
                    ans[ind++]=i;
                    for(y=0;y<m;y++)
                    {
                        avail[y]=avail[y]+alloc[i][y];
                        
                    }
                    f[i]=1;
                }
            }
        }
    }
    int flag=1;
    for(i=0;i<n;i++)
    {
            if(f[i]==0)
            {
                printf("the following system is unsafe\n");
                flag=0;
                
                break;
            }
    }

    if(flag==1)
    {
            printf("the following system is safe\n");
            for(i=0;i<n-1;i++)
            {
                printf("P%d->",ans[i]);
            }
            printf("P%d",ans[n-1]);
            printf("\n");
    }

        
    

}