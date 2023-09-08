#include<stdio.h>
int main()
{
    int n,A[20],c,d,i,j,t,temp,h,index,head=0,start,end,move;
    printf("Enter the cylinder ranging");
    scanf("%d%d",&start,&end);
    printf("Enter number of elements in queue:");//resources
    scanf("%d",&n);
    printf("Enter queue within the range\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("Enter the head start:");
    scanf("%d",&h);
    A[n]=h;
    A[n+1]=start;
    A[n+2]=end;
    t=n+3;
    for(c=0;c<t-1;c++)
    {
        for(d=0;d<t-c-1;d++)
        {
            if(A[d]>A[d+1])
            {
                temp=A[d];
                A[d]=A[d+1];
                A[d+1]=temp;
            }
        }
    }

    for(i=0;i<t;i++)
    {
        if(A[i]==h)
        {
            index=i;
            break;
        }
    }
    printf("move left or right for left enter 0 and for right enter 1");
    scanf("%d",&move);
    if(move==0)
    {
       
        for(i=index;i>=0;i--)
        {
            
            printf("%d->",A[i]);
        }
        for(j=index+1;j<t-2;j++)
        {
             
            printf("%d->",A[j]);
        }
        
        printf("%d",A[t-2]);
        head=head+(A[index]-A[0])+(A[t-2]-A[0]);
    }
    else
    {
        for(j=index;j<t;j++)
        {
            printf("%d->",A[j]);
        }
        for(i=index-1;i>=2;i--)
        {
            printf("%d->",A[i]);
        }
        printf("%d",A[i]);
        head=head+(A[t-1]-A[index])+(A[t-1]-A[i]);
    }
    printf("\nTotal head movement=%d",head);
}