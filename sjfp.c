#include<stdio.h>
int n,p[30],bt[30],tat[30],wt[30],at[30],temp[30],time=0,count=0,tot_wt=0,tot_tat=0,smallest,end;
void main()
{
    int i;
    printf("no. of process:");
    scanf("%d",&n);
    printf("Enter bt and at");
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&bt[i],&at[i]);
        temp[i]=bt[i];
        p[i]=i;
    }
    calculation();
    print();
}

int calculation()
{
    int i;
    bt[9]=9999;
    for(time=0;count!=n;time++)
    {
        smallest=9;
        for(i=0;i<n;i++)
        {
            if(at[i]<=time && bt[i]<bt[smallest] && bt[i]>0)
            {
                smallest=i;
            }
        }
        bt[smallest]--;
        if(bt[smallest]==0)
        {
            count++;
            end=time+1;
            wt[smallest]=end-at[smallest]-temp[smallest];
            tat[smallest]=end-at[smallest];
            tot_wt=tot_wt+wt[smallest];
            tot_tat=tot_tat+tat[smallest];
        }
    }
    return 0;
}

void print()
{
    int i;
    printf("process\t\tbt\t\tat\t\ttat\t\twt");
    for(i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\ta%d\t\t%d\t\t%d",p[i],temp[i],at[i],tat[i],wt[i]);
    }
    printf("total turn around time:%d\nAverage turn around time%dtotal waiting time:%d\nAverage waiting time%d",tot_tat,tot_tat/n,tot_wt,tot_wt/n);
}