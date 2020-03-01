#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_SIZE 512
typedef struct
{
    char name[40];
    char age[40];
    char birth_of_date[40];
    char birth_of_place[40];
    int icct20ranking[10];
    int icconedayranking[10];
    int icctestranking[10];


} Contact;
typedef enum {NAME,AGE} search_t;
Contact phonebook[MAX_SIZE];
int size = 0;
void entry();
void display(int index);
void contact(char *key, search_t type);
void delete(char *key, search_t type);
void readfromFile();
void save_to_file();
void strtolower(char *str);


int main()
{
    void readfromFile();
    int i;
    char selection[41];
    int choice;
    while(1)
    {
        printf("\n1 - Add Player List\n"
               "2 - Search Player Information\n"
               "3 - Delete Player Information\n"
               "4 - Display all Player\n"
               "5 - Save Player Information\n"
               "6 - Exit\n\n"
              );

            printf("Select an option: ");
            gets(selection);
            choice=atoi(selection);

        if(choice==1)
        {
            entry();
        }
        else if(choice==2)
        {
            printf("\n\nEnter name to search: ");
            gets(selection);
            contact(selection,NAME);
        }
        else if(choice==3)
        {
            printf("\n\nEnter name to delete: ");
            gets(selection);
            delete(selection,NAME);
        }
        else if(choice==4)
        {
            int i;
            for(i=0; i<size; i++)
            {
                display(i);
                puts("");
            }
        }
        else if(choice==5)
        {
            save_to_file();
        }
        else if(choice==6)
        {
            exit(0);
            break;
        }

    }

    return 0;
}
void entry()
{
    if(size==MAX_SIZE)
    {
        printf("\nError: File is full\n");
        return;
    }
    Contact c;
    printf("\n\nPlayer Name: ");
    gets(c.name);
    printf("Player Age: ");
    gets(c.age);
    printf("Player Birth Of Date: ");
    gets(c.birth_of_date);
    printf("Player Birth Of Place: ");
    gets(c.birth_of_place);
    printf("Player T20 Ranking: ");
    gets(c.icct20ranking);
    printf("Player One Day Ranking: ");
    gets(c.icconedayranking);
    printf("Player Test Ranking: ");
    gets(c.icctestranking);

    phonebook[size]=c;
    size++;
}
void display(int index)
{
    int j;
    char temp[50],str[40],name[40];
    if(index <0 || index>=size)
    {
        printf("Error: invalid index!\n");
        return;
    }
    Contact c = phonebook[index];
     printf("\nName: \t\t\t%s\n",c.name);
     printf("Age: \t\t\t%s\n",c.age);

    printf("Birth Of Date: \t\t%s\n",c.birth_of_place);
    printf("T20 Ranking: \t\t%s\n",c.icct20ranking);
    printf("One Day Ranking: \t%s\n",c.icconedayranking);
    printf("Test Ranking: \t\t%s\n",c.icctestranking);

}
void strtolower(char *str)
{
    strlwr(str);
}
void contact(char *key, search_t type)
{
    int i,found=0;
    strtolower(key);
    char content[41];
    if(type==NAME)
    {
        for(i = 0 ; i < size ; i++)
        {
            strcpy(content,phonebook[i].name);
            strtolower(content);
            if(strcmp(phonebook[i].name,key)==0)
            {
                display(i);
                found=1;
            }
        }
    }
    else  if(type==AGE)
    {
        for(i = 0 ; i < size ; i++)
        {
            strcpy(content,phonebook[i].age);
            strtolower(content);
            if(strcmp(phonebook[i].age,key)==0)
            {
                display(i);
                found=1;
            }
        }
    }
    else
    {
        printf("\n\nError: invalid search type!\n\n");
        return;
    }
    if(found != 1)
    {
        printf("\n\nNot found in File!\n\n");
        return;
    }
}
void delete(char *key, search_t type)
{
    int i,found=0;
    strtolower(key);
    char content[41];

    if(type==NAME)
    {
       for(i = 0 ; i < size ; i++)
       {
          strcpy(content,phonebook[i].name);
           strtolower(content);
           if(strcmp(phonebook[i].name,key)==0)
           {
               strcpy(phonebook[i].name,phonebook[i+1].name);
              strcpy(phonebook[i].age,phonebook[i+1].age);

                size--;
               printf("\nDelete Successfully\n");
                found=1;
          }
        }
    }
    else  if(type==AGE)
    {
       for(i = 0 ; i < size ; i++)
        {
            strcpy(content,phonebook[i].age);
            strtolower(content);
            if(strcmp(phonebook[i].age,key)==0)
            {
                strcpy(phonebook[i].name,phonebook[i+1].name);
              strcpy(phonebook[i].age,phonebook[i+1].age);

                size--;
                found=1;
           }
        }
    }
    else
    {
        printf("\n\nError: invalid search type!\n\n");
       return;
    }
    if(found != 1)
   {
        printf("\n\nNot found in File!\n\n");
        return;
    }
}
void readfromFile()
{
    FILE *fp;
    if((fp=fopen("phonebook.txt","r"))==NULL)
    {
        puts("Error: can't load  database file");
        return;
    }
    if(fread(&size,sizeof(size),1,fp)!=1)
    {
        puts("Error: can't save data");
        return;
    }
    if(fread(phonebook,sizeof(phonebook),1,fp)!=1)
    {
        puts("Error: can't save data");
        return;
    }
}
void save_to_file()
{
    FILE *fp;
    if((fp=fopen("phonebook.txt","w"))==NULL)
    {
        puts("Error: can't create a database file");
        return;
    }
    if(fwrite(&size,sizeof(size),1,fp)!=1)
    {
        puts("Error: can't save data");
        return;
    }
    if(fwrite(phonebook,sizeof(phonebook),1,fp)!=1)
    {
        puts("Error: can't save data");
        return;
    }
}


