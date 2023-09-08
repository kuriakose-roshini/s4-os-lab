#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int start,end,n,a[20],i,h,difference=0;
    printf("Enter the range of the cylinder:");
    scanf("%d%d",&start,&end);
    printf("enter number of resources:");
    scanf("%d",&n);
    printf("Enter the resources within the limit\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the head position");
    scanf("%d",&h);
    a[0]=h;
    for(i=0;i<n;i++)
    {
        printf("%d->",a[i]);
    }
    printf("%d",a[n]);
    for(i=0;i<n;i++)
    {
        difference=difference+(abs(a[i]-a[i+1]));
    }
    printf("total head movement=%d",difference);
}