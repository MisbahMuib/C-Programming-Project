#include<stdio.h>


int main()
{
    int pass,i=1,u,out;
    int totalbalance;
    printf("Enter Password:");
    scanf("%d",&pass);


    if(pass==1234)
    {
        printf("Press %d:Check Balance\n",i);
        printf("Press %d:Withdraw Balance\n",i+1);

        scanf("%d",&u);

        int total=100000;
        if(u==i)
        {
            printf("Your Option:%d\n",i);

            printf("Total Balance:%d",total);
        }
        else
        {
            printf("Your Option:%d\n",i+1);
            printf("Enter Amount: ");
            scanf("%d",&out);


            if(total<out)
            {
                printf("Insufficient Funds.\n ");

            }
            else
            {

            totalbalance=total-out;

            printf("Your Transaction is completed Successfully.\nNow You Have BDT %d in your account.",totalbalance);


            }

        }






    }

    else
    {
        printf("Wrong Password.Police is coming for you Bro.");
    }








    return 0;
}
