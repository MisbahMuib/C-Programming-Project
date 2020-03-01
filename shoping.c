#include <stdio.h>
int main( )
{
    int n, i, W;
    printf("Enter the number of Item:");
    scanf("%d", &n);
    int price[n], weight[n];

    printf("Enter the Price(Tk) & Weight(Kg) of your %d Item : \n", n);
    for(i=0; i<n; i++)
    {
        printf("Price(Tk) & Weight(Kg) %dth Item: ", i+1);
        scanf("%d%d", &price[i], &weight[i]);
    }
      printf("\n");


    printf("Enter the weight of your bag: ");
    scanf("%d", &W);
    printf("\n\n");


    printf("\t\t------OUTPUT------\n\n");

    int cur_w;
    float tot_price=0.0;
    int  maxi;
    int used[10];

    for (i = 0; i < n; ++i)
        used[i] = 0;

    cur_w = W;
    while (cur_w > 0)
    {

        maxi = -1;
        for (i = 0; i < n; ++i)
            if ((used[i] == 0) &&
                    ((maxi == -1) || ((float)price[i]/weight[i] > (float)price[maxi]/weight[maxi])))
                maxi = i;

        used[maxi] = 1;
        cur_w -= weight[maxi];
        tot_price += price[maxi];
        if (cur_w >= 0)
            printf("Added item %d (%dTk, %dKg) completely in the bag. Space left: %d.\n", maxi + 1, price[maxi], weight[maxi], cur_w);
        else
        {
            printf("Added %d%% (%dTk, %dKg) of item %d in the bag.\n", (int)((1 + (float)cur_w/weight[maxi]) * 100), price[maxi], weight[maxi], maxi + 1);
            tot_price -= price[maxi];
            tot_price += (1 + (float)cur_w/weight[maxi]) * price[maxi];
        }
    }
      printf("\n\n");

    printf("\tFilled the bag with item worth %.2f Tk.\n", tot_price);

    return 0;
}
