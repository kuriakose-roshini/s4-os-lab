#include<stdio.h>
#include<stdlib.h>
#define max 20
int firstfit();
int bestfit();
int worstfit();
static int bflag[max],fflag[max];
int nb,bsize[max],nf,fsize[max],temp,low;
int main()
{
    printf("Enter the number of blocks");
    scanf("%d",&nb);
    int i;
    printf("Enter the size of each block\n");
    for(i=0;i<nb;i++)
    {
        scanf("%d",&bsize[i]);
    }
    printf("Enter the number of files");
    scanf("%d",&nf);
    printf("Enter the size of each file");
    for(i=0;i<nf;i++)
    {
        scanf("%d",&fsize[i]);
    }
    int option;
    printf("\n***MENU***\n1.first fit\n2.best fit\n3.worst fit\nEnter your choice");
    scanf("%d",&option);
    switch(option)
    {
        case 1: firstfit();
            break;
        case 2: bestfit();
            break;
        case 3: worstfit();
            break;
        case 4: exit(0);
        default:printf("not a valid option");
    }
    /*printf("\nfile no\tfile size\tblock no\tblock size");
    for(i=0;i<=nf;i++)
    {
        printf("\n%d\t\t%d\t\t%d\t\t%d",,fsize[i],);
    }*/
}
int firstfit()
{
    int i,j;
    for(i=0;i<nf;i++)
    {
        for(j=0;j<nb;j++)
        {
            if(bflag[j]!=1)
            {
                temp=bsize[j]-fsize[i];
                if(temp>=0)
                {
                    if(low>temp)
                    {
                        fflag[i]=j;
                        low=temp;
                    }
                }
            }
        }
        bflag[fflag[i]]=1;
        low=10000;
    }
}
int bestfit()
{
    
}
int worstfit()
{
    
}