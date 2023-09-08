#include<stdio.h>
int p[30],bt[30],wt[30],tat[30],tot_tat=0,tot_wt=0,FCFS_wt=0,FCFS_tat=0;
int n;//to read number of processes
int main()
{
    
    printf("Enter number of processes\n");
    scanf("%d",&n);
    printf("Enter burst time of each processes\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
        p[i]=i;
    }
    printf("\n FCFS Algorithm");
    WT_TAT(&FCFS_tat,&FCFS_wt);
    printf("\n\nTotal turn Around time:%d",FCFS_tat);
    printf("\n\nAverage Total turn Around time:%d",FCFS_tat/n);
    printf("\n\nTotal waiting time:%d",FCFS_wt);
    printf("\n\nAvearge Total waiting time:%d",FCFS_wt/n);
}

int WT_TAT(int *a, int*b)
{
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            tat[i]=bt[i];
        }
        else
        {
            tat[i]=tat[i-1]+bt[i];
            tot_tat=tot_tat+tat[i];
        }
    }
    *a=tot_tat;
    wt[0]=0;
    for(int i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
        tot_wt=tot_wt+wt[i];
    }
    *b=tot_wt;
    printf("\nProcess\tBurst time\tturn around time\twaiting time");
    for(int i=0;i<n;i++)
    {
        printf("\nprocess[%d]\t\t%d\t\t%d\t\t%d",p[i],bt[i],tat[i],wt[i]);
    }
    
    return 0;
}