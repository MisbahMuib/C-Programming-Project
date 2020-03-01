#include<stdio.h>
#include<string.h>
int main()
{
    printf("Bag size(kg): ");
    int n;
    scanf("%d",&n);
    int bag=n;
    printf("Quantity of Products: ");
    int m;
    scanf("%d",&m);
    int product[m][2];
    char name[m][20];
    double price[m];
    int i,j;
    printf("Your products: \n");
    for(i=0; i<m; i++)
    {
        printf("Product Name: ");
        scanf("%s",&name[i]);
        printf("Product Weight(kg): ");
        scanf("%d",&product[i][0]);
        printf("Product Price(tk): ");
        scanf("%d",&product[i][1]);
    }
    //main process starts here
    //finding price per kg = tk/weight
    for(i=0; i<m; i++)
    {
        price[i] = (double)product[i][1]/(double)product[i][0];
    }
    //sorting
    for(i=0; i<m; i++)
    {
        for(j=i; j<m-1; j++)
        {
            if(price[i]>=price[j+1])
            {
                //changing product price
                double temp;
                temp = price[i];
                price[i]=price[j+1];
                price[j+1]=temp;

                //changing product name
                char ctemp[10];
                strcpy(ctemp,name[i]);
                strcpy(name[i],name[j+1]);
                strcpy(name[j+1],ctemp);

                int wtemp,ptemp;

                //changing product weight
                wtemp = product[i][0];
                product[i][0]=product[j+1][0];
                product[j+1][0]=wtemp;

                //changing product price
                ptemp = product[i][1];
                product[i][1]=product[j+1][1];
                product[j+1][1]=ptemp;
            }
        }
    }
    /*
    //checking all sort
    for(i=0; i<m; i++)
    {
        printf("\t%s ==,,,,, weight =%d,,,,,,price total = %d.,,,,price kg = %lf \n",name[i],product[i][0],product[i][1],price[i]);
    }*/
    int v=m;
    int w=0,p=1;
    int took[m][2];
    int ser=1;
    int x=-1;
    for(i=m-1; i>=0; i--)
    {
        if(bag<=product[i][w])
        {
            x++;
            // printf("taking the last one =  %s ",name[i]);
            // printf("Weight = %d\n",bag);
            took[x][w]=bag;//koi kg
            took[x][ser]=i;//kto number product;
            bag = 0;
            break;
        }
        x++;
        // printf("weight = %d\n",product[i][w]);
        took[x][w]=product[i][w];
        took[x][ser]=i;
        // printf("taking = %s ",name[i]);
        // printf("weight = %d\n",took[x][w]);
        bag = bag - product[i][w];
        // printf("space left = %d\n",bag);

    }
    int out;
    double profit=0.0;
    printf("\n\n");
    printf("Output\n");
    printf("We are taking %d item.\n",x+1);
    for(i=0; i<=x; i++)
    {
        out = took[i][ser];
        //  printf("Product name: %s\n",name[out]);
        //    printf("how much we will took: %d\n",took[i][w]);
        printf("%d. %s - %d kg\n",i+1,name[out],took[i][w]);
        profit = ((double)took[i][w]*price[out])+ profit;
    }

    printf("This is the fucking profit : %lf\n",profit);

    return 0;
}
