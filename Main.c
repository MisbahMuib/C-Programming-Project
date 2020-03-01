
#include <stdio.h>
#include <stdlib.h>

struct node
{
    char firstname[100];
    char lastname[100];
    char num[100];
    struct node* link;
};
struct node *root=NULL;
int main()
{
    int ch;
    system("color FD");
    printf("\n\t\t     Daffodil International University\n");
    printf("\n\t\t********************************************");
    printf("\n\t\t  *** WELCOME TO OUR PHONE BOOK SYSTEM ***");
    printf("\n\t\t********************************************\n");
    printf("\n\n");
    while(1)
    {
        printf("\n\n");
        printf("Enter your choice :\n");
        printf("1.Insert\n2.Display\n3.Update\n4.Delete\n5.Exit\n\n");
        printf("Input Number : ");
        scanf("%d",&ch);
        printf("\n\n");
        switch(ch)
        {
        case 1 :
            insert();
            break;
        case 2 :
            display();
            break;
        case 3 :
            update();
            break;
        case 4 :
            deleteContact();
            break;
        case 5 :
            exit(1);
        }
    }
    return 0;
}
void insert()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("First name : ");
    scanf("%s",temp->firstname);
    printf("Last name : ");
    scanf("%s",temp->lastname);
    printf("Number : ");
    scanf("%s",temp->num);
    temp->link=NULL;
    if(root == NULL)
    {
        root=temp;
    }
    else
    {
        struct node *p=root;
        while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link=temp;
    }
}
void display()
{
    struct node *temp =root;
    int i=1;
    if(temp==NULL)
    {
        printf("Phone book is empty\\n");
        printf("\n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d.",i);
            printf("Name : ");
            printf("%s ",temp->firstname);
            printf("%s\n",temp->lastname);
            printf("Number : ");
            printf("%s\n",temp->num);
            temp=temp->link;
            i++;

        }
    }
}

void update()
{
    struct node *temp = root;
    char name[100];
    printf("Please enter First Name/Last Name :");
    scanf("%s",&name);
    int i=1;
    while(temp!=NULL)
    {
        if(searchContact(temp->firstname, name) == 1 || searchContact(temp->lastname, name) == 1)
        {
            printf("First name : ");
            scanf("%s",temp->firstname);
            printf("Last name : ");
            scanf("%s",temp->lastname);
            printf("Number : ");
            scanf("%s",temp->num);
        }
        temp=temp->link;
        i++;
    }
}

void deleteContact()
{
    struct node *temp = root;
    struct node *tempNode = root;
    int loc = -1;

    char name[100];
    printf("Please enter First Name/Last Name :");
    scanf("%s",&name);
    int i=1;
    while(tempNode!=NULL)
    {
        if(searchContact(tempNode->firstname, name) == 1 || searchContact(tempNode->lastname, name) == 1)
        {
            loc = i;
        }
        tempNode=tempNode->link;
        i++;
    }

    if(loc == -1)
    {
        printf("Contact is not found\n");
    }

    else if(loc == 1)
    {

        root=temp->link;
        temp->link=NULL;
        free(temp);
    }
    else
    {
        struct node* p=root,*q;
        int i=1;
        while(i<loc-1)
        {
            p=p->link;
            i++;
        }
        q=p->link;
        p->link=q->link;
        q->link=NULL;
        free(q);
    }
}

int searchContact(char input[], char check[])
{
    int i,result=1;
    for(i=0; input[i]!='\0' || check[i]!='\0'; i++)
    {
        if(input[i] != check[i])
        {
            result=0;
            break;
        }
    }
    return result;
}
