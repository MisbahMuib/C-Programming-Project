
#include <stdio.h>
#include <stdlib.h>
#define max 500
typedef struct node
{
    int num;
    int p;
    int q,r;
    char ch[max],m_name[max],f_name[max],m_contact[max],f_contact[max];
    char email[max],sec[max],batch[max],cgpa[max];
    char add[max];
    char blood[max];
    struct node *next;
}node;
node *head=NULL;
void save()
{
    int n;
    char x,y,z;
    node *temp=head;
    node *newnode=(node*)malloc(sizeof(node));
    newnode->p=0;
    newnode->q=0;
    newnode->r=0;
    printf("Enter Student ID:");
    scanf("%d",&n);
    if(head==NULL)
    {
        newnode->num=n;
    }
    else
    {
    while(temp!=NULL)
    {
    if(n==temp->num)
    {
        printf("The information about this ID is already saved..\n");
        free(newnode);
        return;
    }
    else
    {
      newnode->num=n;
    }
    temp=temp->next;
    }

  }
    printf("Enter student name:");
    fflush(stdin);
    gets(newnode->ch);
    printf("Enter batch no:");
    fflush(stdin);
    gets(newnode->batch);
     printf("Enter section:");
    fflush(stdin);
    gets(newnode->sec);
     printf("Enter father name:");
    fflush(stdin);
    gets(newnode->f_name);
    printf("Enter mother name:");
    fflush(stdin);
    gets(newnode->m_name);
     printf("Enter father contact number:");
    fflush(stdin);
    gets(newnode->f_contact);
     printf("Enter mother contact  number:");
    fflush(stdin);
    gets(newnode->m_contact);
    printf("Enter student CGPA:");
    fflush(stdin);
    gets(newnode->cgpa);
    printf("Enter y for save Email Address:");
    fflush(stdin);
    scanf("%c",&x);

    if(x=='y')
    {
        printf("Enter Email Address:");
        fflush(stdin);
        gets(newnode->email);
        newnode->p=1;
    }
    printf("Enter y for save Address:");
    fflush(stdin);
    scanf("%c",&y);
    if(y=='y')
    {
        printf("Enter Address:");
        fflush(stdin);
        gets(newnode->add);
        newnode->q=1;
    }
    printf("Enter y for save Blood Group:");
    fflush(stdin);
    scanf("%c",&z);
    if(z=='y')
    {
        printf("Enter Blood group:");
        fflush(stdin);
        gets(newnode->blood);
        newnode->r=1;
    }
    newnode->next=head;
    head=newnode;
    printf("Information saved successfully...\n\n");
}
void list()
{
    if(head==NULL)
    {
        printf("No information has been saved...\n\n");
        return;
    }
    else
    {
        node *temp=head;
        while(temp!=NULL)
        {   printf("Student ID is:%d\n",temp->num);
            printf("Name:");
            puts(temp->ch);
            printf("Batch:");
            puts(temp->batch);
            printf("Section:");
            puts(temp->sec);
            printf("Father Name:");
            puts(temp->f_name);
            printf("Father contact:");
            puts(temp->f_contact);
            printf("Mother Name:");
            puts(temp->m_name);
            printf("mother Contact:");
            puts(temp->m_contact);
            printf("CGPA:");
            puts(temp->cgpa);
            if(temp->p==1)
            {
            printf("Email:");
            puts(temp->email);
            }
            if(temp->q==1)
            {
            printf("Address:");
            puts(temp->add);
            }
            if(temp->r==1)
            {
            printf("Blood group is:");
            puts(temp->blood);
            }
            temp=temp->next;
            printf("\n \n");
        }

    }
}
void search()
{
    node *temp=head;
    int n,z,x=0;
    char d[100];
    printf("which ID you want to search?:");
    scanf("%d",&n);
    while(temp!=NULL)
    {
        if(temp->num==n)
        {
            x=1;
            printf("Name:");
            puts(temp->ch);
            printf("number is:%d\n",temp->num);
            printf("Batch:");
            puts(temp->batch);
            printf("Section:");
            puts(temp->sec);
            printf("Father Name:");
            puts(temp->f_name);
            printf("Father contact name:");
            puts(temp->f_contact);
            printf("Mother Name:");
            puts(temp->m_name);
            printf("mother Contact:");
            puts(temp->m_contact);
            printf("CGPA:");
            puts(temp->cgpa);
            if(temp->p==1)
            {
            printf("Email is:");
            puts(temp->email);
            }
            if(temp->q==1)
            {
            printf("Address is:");
            puts(temp->add);
            }
            if(temp->r==1)
            {
            printf("Blood group is:");
            puts(temp->blood);
            }

            printf("\n \n");
        }

        temp=temp->next;
    }
    if(x==0)
        {
            printf("Not found...\n\n");
        }
}
deletee()
{
    int a;
    printf("Enter Student Id you want to delete:");
    scanf("%d",&a);
    node *p,*q;
    if(head==NULL)
    {
        printf("No Information has been saved...\n\n");
        return;
    }
    else
    {
        p=head;
        int z=0;
        while(p!=NULL)
        {
            if(head->num==a)
            {
                head=head->next;
                free(p);
                printf("Information of ID no.%d is deleted...\n\n",a);
                z=1;
                return;
            }
            else if(p->num==a)
            {
                q->next=p->next;
                free(p);
                p=q->next;
                printf("Information Of ID no.%d is deleted...\n\n",a);
                z=1;
                return;
            }
            else
            {
                q=p;
                p=p->next;
            }
        }
        if(z==0)
            printf("information wasn't saved...\n");
    }
}
modify()
{

    int a;
    char n,e,a1,b,m,f,mc,fc,s,bh,i,c;
    printf("Enter Student Id you want to modify:");
    scanf("%d",&a);

    if(head==NULL)
    {
        printf("No Information has been saved...\n\n");
        return;
    }
    else
    {
    node *temp;
    temp=head;
    int z=0;
    while(temp!=NULL)
    {
    if(temp->num==a)
    {
    z=1;
     printf("Enter y for change student name:");
    fflush(stdin);
    scanf("%c",&n);

    if(n=='y')
    {
        //char name[100];
        printf("Enter correct name:");
        fflush(stdin);
        gets(temp->ch);
    }
    printf("Enter y for change batch:");
    fflush(stdin);
    scanf("%c",&bh);

    if(bh=='y')
    {

        printf("Enter new batch:");
        fflush(stdin);
        gets(temp->batch);
    }
      printf("Enter y for change section:");
    fflush(stdin);
    scanf("%c",&s);

    if(s=='y')
    {

        printf("Enter new section:");
        fflush(stdin);
        gets(temp->sec);
    }
      printf("Enter y for modify father name:");
    fflush(stdin);
    scanf("%c",&f);

    if(f=='y')
    {

        printf("Enter correct father name:");
        fflush(stdin);
        gets(temp->f_name);
    }
      printf("Enter y for modify mother name:");
    fflush(stdin);
    scanf("%c",&m);

    if(m=='y')
    {

        printf("Enter correct mother name:");
        fflush(stdin);
        gets(temp->m_name);
    }
    printf("Enter y for modify father contact:");
    fflush(stdin);
    scanf("%c",&fc);

    if(fc=='y')
    {

        printf("Enter correct father contact:");
        fflush(stdin);
        gets(temp->f_contact);
    }

     printf("Enter y for modify mother contact:");
    fflush(stdin);
    scanf("%c",&mc);

    if(mc=='y')
    {

        printf("Enter correct mother contact:");
        fflush(stdin);
        gets(temp->m_contact);
    }
    printf("Enter y for modify student CGPA:");
    fflush(stdin);
    scanf("%c",&c);

    if(c=='y')
    {

        printf("Enter correct CGPA:");
        fflush(stdin);
        gets(temp->cgpa);
    }

    printf("Enter y for change Email Address:");
    fflush(stdin);
    scanf("%c",&e);

    if(e=='y')
    {
        printf("Enter new Email Address:");
        fflush(stdin);
        gets(temp->email);
        temp->p=1;
    }
     printf("Enter y for modify Address:");
    fflush(stdin);
    scanf("%c",&a1);
    if(a1=='y')
    {
        printf("Enter new Address:");
        fflush(stdin);
        gets(temp->add);
        temp->q=1;
    }
    printf("Enter y for modify Blood Group:");
    fflush(stdin);
    scanf("%c",&b);
    if(b=='y')
    {
        printf("Enter Blood group:");
        fflush(stdin);
        gets(temp->blood);
        temp->r=1;
    }
    }
    temp=temp->next;
    }
    if(z==0)
    printf("information wasn't saved...\n");

    }
 }
int main()
{
    system("color a");
    system("cls");
    while(1)
    {
        int n,x=0;
        printf("\nEnter 1 for save information.\n\nEnter 2 to see information list.\n\nEnter 3 for search information.\n\nEnter 4 for Delete information.\n\nEnter 5 for modify information.\n\nEnter 6 for Exit.\n\n");

        printf("Enter your choice:");
        fflush(stdin);
        scanf("%d",&n);
        printf("\n\n");
        switch(n)
        {
        case 1:
            save();
            break;
        case 2:
            list();
            break;
        case 3:
            search();
            break;
        case 4:
            deletee();
            break;
        case 5:
            modify();
            break;
        case 6:
            x=1;
            break;
        default:
            printf("Wrong choice.....\n");

        }
        if(x==1)
            break;
    }
    return 0;
}
