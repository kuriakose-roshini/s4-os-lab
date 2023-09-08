#include<stdio.h>
int main()
{
    int n,a[20],c,d,i,j,t,temp,h,index,head=0,start,end,move;
    printf("Enter the cylinder ranging:");
    scanf("%d%d",&start,&end);
    printf("Enter number of elements in queue");
    scanf("%d",&n);
    printf("Enter the queue within the range of the cylinder:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the head start:");
    scanf("%d",&h);
    a[n]=h;
    a[n+1]=start;
    a[n+2]=end;
    t=n+3;
    for(c=0;c<t-1;c++)
    {
        for(d=0;d<t-c-1;d++)
        {
            if(a[d]>a[d+1])
            {
                temp=a[d];
                a[d]=a[d+1];
                a[d+1]=temp;
            }
        }
    }

    for(i=0;i<t;i++)
    {
        if(a[i]==h)
        {
            index=i;
            break;
        }
    }

    printf("move left-0 or right-1");
    scanf("%d",&move);
    if(move==0)
    {
        for(i=index;i>=0;i--)
        {
            printf("%d->",a[i]);
        }
        for(j=t-1;j>index+1;j--)
        {
            printf("%d->",a[j]);
        }
        printf("%d",a[index+1]);
        head=head+(a[index]-a[0])+(end-start)+(end-a[index+1]);
        printf("\n total head movement=%d",head);
    }
    else
    {
        for(j=index;j<t;j++)
        {
            printf("%d->",a[j]);
        }
        for(i=0;i<index-1;i++)
        {
            printf("%d->",a[i]);
        }
        printf("%d",a[index-1]);
        head=(a[t-1]-a[index])+(end-start)+(a[index-1]-start);
        printf("\ntotal head movement=%d",head);
    }
}