#include<stdio.h>
#include<stdlib.h>
int buffersize,full=0,mutex=1,empty;
int main()
{
    printf("Enter buffersize:");
    scanf("%d",&buffersize);
    empty = buffersize;
    void producer();
    void consumer();
    int wait(int);
    int signal(int);
    int option;
    printf("\n***MENU***\n1.Producern\2.consumer\n3.exit");
    printf("\nEnter your choice");
    scanf("%d",&option);
    switch(option)
    {
        case 1: if((mutex==1)&&(empty!=0))
                {
                    producer();
                    break;
                }
        case 2: if((mutex==1)&&(full!=0))
                {
                    consumer();
                    break;
                }
        case 3: exit(0);
        default:printf("\nInvalid choice");
                 break;
    }
}

int wait(int s)
{
    return(--s);
}

int signal(int s)
{
    return(++s);
}
//producer
void producer()
{
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    printf("producer produced an item");
}

void consumer()
{
    mutex=wait(mutex);
    full=wait(full);
    empty=signal(empty);
    printf("consumer consumed an item");
}