#include<stdio.h>
int main()
{
    int i,j,n,z,a[50],l,frame[10],no,avail=0,fcount=0;
    printf("Enter no. of pages:");
    scanf("%d",&n);
    printf("Enter resource string:-\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter no. of frames:");
    scanf("%d",&no);
    for(i=0;i<no;i++)
    {
        frame[i]=-1;
    }
    printf("\nRef string\t\t page frames\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<no;j++)
        {
            if(a[i]=frame[j])
            {
                avail=1;
                printf("%d\t\t",a[i]);
                for(z=j;z>=0;z--)
                {
                    frame[z]=frame[z-1];
                }
                frame[0]=a[i];
                for(l=0;l<no;l++)
                {
                    printf("%d\t\t",frame[l]);
                }
                printf("\n");
                break;
            }
        }
        if(avail==0)
        {
            fcount++;
            for(z=no-1;z>0;z--)
            {
                frame[z]=frame[z-1];
            }
            frame[0]=a[i];
            printf("%d\t\t",a[i]);
            for(l=0;l<no;l++)
            {
                printf("%d\t\t",frame[l]);
            }
            printf("\n");
        }
        avail=0;
    }
    printf("No of page fault=%d",fcount);
}