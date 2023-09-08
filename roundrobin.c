#include<stdio.h>
int TRUE=0;
int FALSE=-1;
int tbt[30],bt[30],tat[30],n=0,wt[30],qt=0,tqt=0,time=0,Imore,t_tat=0,t_wt=0;
void main()
{
    int i,j;
    printf("Enter the no. of process");
    scanf("%d",&n);
    printf("Enter quantum time");
    scanf("%d",&qt);
    printf("Enter burst time of each process");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
        tbt[i]=bt[i];
        wt[i]=tat[i]=0;
    }
    Imore=TRUE;
    while(Imore==TRUE)
    {
        Imore=FALSE;
        for(i=0;i<n;i++)
        {
            //calculating wt;
            if(bt[i]!=0)
            {
                wt[i]=wt[i]+(time-tat[i]);
            }
            //calculating tat;
            tqt=1;//temporary qt is assigned 1
            while(tqt<=qt && bt[i]!=0)
            {
                Imore=TRUE;
                bt[i]--;
                tqt++;
                time++;
                tat[i]=time;
            }
        }
    }

    printf("\nProcess ID\t\tBurst time\tTurnAroundTime\tWaiting time\n");
    for(i=0;i<n;i++)
    {
        printf("process[%d]\t\t%d\t\t%d\t\t%d\n",i+1,tbt[i],tat[i],wt[i]);
        t_tat=t_tat+tat[i];
        t_wt=t_wt+wt[i];
    }

    printf("\nTotal turn around time:%d",t_tat);
    printf("\nAverage turn around time:%d",t_tat/n);
    printf("\nTotal waiting time:%d",t_wt);
    printf("\nAverage waiting time:%d",t_wt/n);
    printf("total time=%d",time);
}