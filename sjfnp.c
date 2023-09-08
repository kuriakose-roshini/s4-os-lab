#include<stdio.h>
int sort();
int swap();
int wt_tat();
int n,p[30],bt[30],wt[30],tat[30],tot_tat=0,tot_wt=0,SJF_wt=0,SJF_tat=0;
void main()
{
    printf("Enter number of processes");
    scanf("%d",&n);
    printf("Enter burst time of each process");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
        p[i]=i;
    }
    sort();
    wt_tat(&SJF_tat,&SJF_wt);
    printf("\nTotal turn around time:%d",SJF_tat);
    printf("\nAverage turn around time:%d",SJF_tat/n);
    printf("\nTotal waiting time:%d",SJF_wt);
    printf("\nAverage waiting time:%d",SJF_wt/n);

}


//Sorting
int sort()
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(bt[i]>bt[j])
            {
                swap(&bt[j],&bt[i]);
                swap(&p[j],&p[i]);
            }
        }
    }
   
}

//swapping
int swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
    return 0;

}


//finding waiting time and turn around time
int wt_tat(int *a,int *b)
{
    int i;
    for( i=0;i<n;i++)
    {
        if(i==0)
        {
            tat[i]=bt[i];
        }
        else
        {
            tat[i]=tat[i-1]+bt[i];
        }
        tot_tat=tot_tat+tat[i];
    }
        *a=tot_tat;
        wt[0]=0;
        for(i=1;i<n;i++)
        {
            wt[i]=wt[i-1]+bt[i-1];
            tot_wt=tot_wt+wt[i];
        }

        *b=tot_wt;
        printf("\nprocess\t\tBurst time\tturn around time\twaiting time");
        for(i=0;i<n;i++)
        {
            printf("\nProcess[%d]\t\t%d\t\t%d\t\t%d",p[i]+1,bt[i],tat[i],wt[i]);
        }
    }