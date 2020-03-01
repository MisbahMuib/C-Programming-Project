#include<stdio.h>

    int queue_array[50];

    int rear = - 1;

    int front = - 1;

    int pending=0;

    int received=0,customer=0,j=0;
    struct rest{
          int f_number;
          char size[100];
          int quantity;

    };

    void serve()
    {
         int srve;
         printf("\n\n\nIf %d number order is ready then press 1 to serve it\n",front+1);

            printf("choose = ");
            scanf("%d",&srve);
            if(srve==1)
            {
                if (front == - 1 || front > rear)

                {

                    printf("Queue Underflow \n");

                    return ;

                }

                else

                {

                    front = front + 1;


                }
                    printf("\n\n      :)      The %d number order is served      (: \n",front);
                    j+=1;
            }

    }
    void display()
    {

        int serve_check2,r,pending=0,z;

        printf("\n\n            THE NUMBER OF ORDER RECEIVED = %d\n\n",rear+1);
        printf("\n\n            THE NUMBER OF ORDER SERVED = %d\n\n",front);
        for(z=front;z<=rear;z++)
            {
                pending+=1;

            }
        printf("\n\n            THE NUMBER OF ORDER PENDING................ = %d\n\n",pending);


        for(r=j+1;r<=received;r++)
        {
            printf("\n\n\nIf u want to serve the next order then press 1 else press 0\n\n");
            printf("Please choose = ");
            scanf("%d",&serve_check2);

            if(serve_check2==1)
            {
                serve();
                if(j==received)
               {
                printf("\n\n         !!!ALL OF THE ORDERS HAVE SERVED SUCCESSFULLY!!!\n\n\n");
               }
            }
            else
            {
                break;
            }

        }



    }

    void order()
    {
            int food_type;
            printf("SIR WHAT KIND OF FOOD YOU WANT ? \n");
            printf("            for Thai food press 1\n");
            printf("            for Chinese food press 2\n");
            printf("            for Bengali food press 3\n");
            printf("            for drinks press 4\n");

            printf(" please choose = ");
            scanf("%d",&food_type);
            if(food_type==1)
            {
                printf("            SIR THIS IS OUR FOOD CHART == \n\n");
                printf("            1.Thai crispy fried noodles\n");
                printf("            2.Northern Thai curry noodles\n");
                printf("            3.Clear vegetable soup\n");
                printf("            4.Coconut soup with chicken\n");
                printf("            5.Bitter melon soup\n");
                printf("            6.Grilled prawns\n");
                printf("            7.Thai papaya salad\n");
                printf("            8.Ginger fried chicken\n");
                printf("            9.Deep fried chicken and lemon grass\n");
                printf("            10.Deep-fried fish\n");
            }

            if(food_type==2)
            {
                printf("        SIR THIS IS OUR FOOD CHART = \n\n");
                printf("            11.fried rice\n");
                printf("            12.pickled vegetables\n");
                printf("            13.moon cake\n");
                printf("            14.shaved ice\n");
                printf("            15.Beef chow fun\n");
                printf("            16.fish ball in light soup\n");
                printf("            17.Sizzling rice with tomato sauce\n");
                printf("            18.west lake fish in vinegar sauce\n");
                printf("            19.chicken fried rice\n");
                printf("            20.sea cucumber\n");


            }

            if(food_type==3)
            {
                printf("            SIR THIS IS OUR FOOD CHART == \n\n");
                printf("            21.Alu vorta\n");
                printf("            22.Begun vorta\n");
                printf("            23.Ilish bhapa\n");
                printf("            24.biriyani\n");
                printf("            25.fresh rice\n");
                printf("            26.shobji(curry)\n");
                printf("            27.tehari\n");
                printf("            28.chingri malai kari\n");
                printf("            29.roshogolla\n");
                printf("            30.mishti doi\n");

            }
            if(food_type==4)
            {
                printf("            SIR THIS IS OUR FOOD CHART == \n\n");
                printf("            31.Coca-cola\n");
                printf("            32.Spright\n");
                printf("            33.Lassi(mango)\n");
                printf("            34.Lassi(strawberry)\n");
                printf("            35.orange soda\n");
                printf("            36.chocolate milk shake\n");
                printf("            37.Mango juice\n");
                printf("            38.fresh papaya juice\n");
                printf("            39.Borhani\n");
                printf("            40.lemon juice\n");

            }
        struct rest p1;

            printf("\n\n\n\n        ---- Please choose the order according to food chart ----\n\n\n\n");
            printf("please choose the food number = ");
            scanf("%d",&p1.f_number);
            getchar();
            printf("please choose food size =");
            gets(p1.size);
            printf("please choose the quantity = ");
            scanf("%d",&p1.quantity);
            getchar();

            printf("\n\n            SIR YOUR ORDER HAS BEEN TAKEN SUCCESSFULLY \n\n");

            received+=1;

            if (rear == 50 - 1)
            {
                printf("Queue Overflow \n");
            }

            else

            {

            if (front == - 1)

            /*If queue is initially empty */

            front = 0;

            rear = rear + 1;

            queue_array[rear] = rear+1;

        }


    }
    int main()
    {
            int customer_check,i,p,q,serve_check,disp_check;
            printf("****************WELCOME TO OUR RESTAURANT SIR****************\n\n\n\n\n\n");
            printf("$$$$$$$$$$$$$$  PLEASE SIR TAKE YOUR SIT $$$$$$$$$$$$$ \n\n\n\n");

            order();

            for(i=0;i<=10;i++)
            {
            printf("\n\n\nIF THERE ARE MORE CUSTOMERS PLEASE PRESS 1, OR ELSE PRESS 0 \n");
            printf("Please choose = ");
            scanf("%d",&customer_check);
            if(customer_check==1)
            {
                order();
            }
            else
            {
                break;
            }
            }
            printf(" \n\n           %d CUSTOMERS HAVE GIVEN ORDERS.... \n\n\n",rear+1);


            for(p=1;p<=received;p++)
                {
                   printf("If you want to serve food then press 1 , else press 0\n");
                   printf("Please choose = ");
                   scanf("%d",&serve_check);
                   if(serve_check==1)
                     {
                        serve();
                     }
                   else
                     {
                        break;
                     }

                }

                for(q=0;q<=received;q++)
                {
                printf("\n\n\nIf you want to know the condition of orders then press 1 else press 0");
                printf("\nChoose = ");
                scanf("%d",&disp_check);
                    if(disp_check==1)
                    {
                        display();
                    }
                    else
                    {
                        break;
                    }
                }


        return 0;
    }
