#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *ptr;
}*front,*rear,*temp,*front1;


void enq(int data);
void deq();
void empty();
void display();
void create();
void queuesize();
int frontelement();
int complete();
int count = 0;
int no, ch, e,v,r,n,i,j;
void main()
{  // int i,j;
   // int no, ch, e,v,r,n;

    printf("Input Information:");
    printf("\n 1 - Input voters & Vote center Information \n");
    printf("Do your desire function:");
    printf("\n 2 - Give vote(deq)");
    printf("\n 3 - who is in first?");
    printf("\n 4 - Empty");
    printf("\n 5 - Exit");
    printf("\n 6 - Display Voters in line:");
    printf("\n 7 - Waiting Voters number:");
    printf("\n 8 - Completed Voters:");
    create();
    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
             printf("How many voters in the poling_center?");
             scanf("%d",&v);
             printf("How many returning_officers do you have?");
             scanf("%d",&r);
             n=v/r;
             if (v%2!=0)
             {
                 n=n+1;
             }
            for(j=0;j<r;j++)
            {
            printf("Enter Line%d voter's information \n",j+1);
             for(i=0;i<n;i++)
             {
            scanf("%d", &no);
            enq(no);
             }
            }
            printf("The total wainting voters:");
            display();

            break;
        case 2:
            deq();
            break;
        case 3:
            e = frontelement();
            if (e != 0)
                printf("First voter : %d", e);
            else
                printf("\n No front element in Queue as queue is empty");
            break;
        case 4:
            empty();
            break;
        case 5:
            exit(0);
        case 6:
            display();
            break;
        case 7:
            queuesize();
            break;
        case 8:
            complete();
            break;
        default:
            printf("Wrong choice, Please enter correct choice  ");
            break;
        }
    }
}

/* Create an empty queue */
void create()
{
    front = rear = NULL;
}

/* Returns queue size */
void queuesize()
{
    printf("\n Now waitng : %d person in Line", count);
}

/* Enqueing the queue */
void enq(int data)
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(1*sizeof(struct node));
        rear->ptr = NULL;
        rear->info = data;
        front = rear;
    }
    else
    {
        temp=(struct node *)malloc(1*sizeof(struct node));
        rear->ptr = temp;
        temp->info = data;
        temp->ptr = NULL;

        rear = temp;
    }
    count++;
}

/* Displaying the queue elements */
void display()
{
    front1 = front;

    if ((front1 == NULL) && (rear == NULL))
    {
        printf("Queue is empty");
        return;
    }
    while (front1 != rear)
    {
        printf("%d ", front1->info);
        front1 = front1->ptr;
    }
    if (front1 == rear)
        printf("%d", front1->info);
}

/* Dequeing the queue */
void deq()
{
    front1 = front;

    if (front1 == NULL)
    {
        printf("\n Error: Trying to display elements from empty queue");
        return;
    }
    else if (front1->ptr != NULL)
    {
        front1 = front1->ptr;
       // printf("\n Dequed value : %d", front->info);
        free(front);
        front = front1;
    }
    else
    {
        printf("\n Dequed value : %d", front->info);
        free(front);
        front = NULL;
        rear = NULL;
    }
    count--;
}

/* Returns the front element of queue */
int frontelement()
{
    if ((front != NULL) && (rear != NULL))
        return(front->info);
    else
        return 0;
}

/* Display if queue is empty or not */
void empty()
{
    if ((front == NULL) && (rear == NULL))
        printf("\n Queue empty");
    else
        printf("Queue not empty");
}
int complete()
{
    printf("%d Person given theair vote",v-count);
}
