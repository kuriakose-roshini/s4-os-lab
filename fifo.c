#include<stdio.h>
int main()
{
    int i,j,k=0,n,l,no,rs[30],frame[10],avail=0,fcount=0;
    printf("Enter number of pages:");
    scanf("%d",&n);
    printf("Enter the reference strings:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&rs[i]);
    }
    printf("Enter number of frames:");
    scanf("%d",&no);
    for(i=0;i<no;i++)
    {
        frame[i]=-1;
    }
    printf("\nRef string \t\tPage frame\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<no;j++)
        {
            
            if(rs[i]==frame[j])
            {
                avail=1;
                printf("%d\t\t",rs[i]);
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
            frame[k]=rs[i];
            printf("%d\t\t",rs[i]);
            for(l=0;l<no;l++)
            {
                printf("%d\t\t",frame[l]);
            }
            printf("\n");
            k=(k+1)%no;
        }
        avail=0;
    }
    printf("Number of page faults:%d",fcount);
}