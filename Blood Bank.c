#include<stdio.h>
#include<string.h>

struct Blood_Bank
{
    char Donar_name[30];
    char Donar_ID[15];
    char Donar_Blood_group[5];
    char Donar_Phone_number[12];

} Donar[5];

int main(void)
{
    char tDonar_name[30];
    char searchkey[10];
    int i, value;

    for(i=0; i<5; i++)
    {
        printf("Enter ID for Donar[%d]\n", i);
        scanf("%s", Donar[i].Donar_ID);

        printf("\nEnter Name for Donar[%d]\n", i);
        scanf("%s", tDonar_name);
        strcpy(Donar[i].Donar_name, tDonar_name);

        printf("\nEnter Blood group  for Donar[%d]\n", i);
        scanf("%s", Donar[i].Donar_Blood_group);

        printf("\nEnter Phone Number  for Donar[%d]\n\n\n", i);
        scanf("%s", Donar[i].Donar_Phone_number);





    }

    while(1)
    {
        printf("Enter Blood group for searching: ");
        scanf("%s", searchkey);

        for(i=0; i<5; i++)
        {
            value = strcmp(searchkey, Donar[i].Donar_Blood_group);

            if(value==0)
            {
                printf("Info for Donar[i] are as follows-\n", i);
                printf("ID: %s\n", Donar[i].Donar_ID);
                printf("Name: %s\n", Donar[i].Donar_name);
                printf("Blood group:%s\n", Donar[i].Donar_Blood_group);
                printf("Mobile Number:%s\n",Donar[i].Donar_Phone_number);
            }
            else
            {
                printf("Not Founded any name like %s", searchkey);
            }
        }
    }


}
