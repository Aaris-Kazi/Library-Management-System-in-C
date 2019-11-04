#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
struct node
{
   struct node *next;
   char user_name[10];
   char Book_name[10];
};
   struct node *h=NULL;
   int unique_id;
struct node1
{
    struct node1 *next;
    int date;
};

struct node *create_Node()
{
struct node *n;
n=(struct node*)malloc(sizeof(struct node));
return n;
}

struct node1 *create_node1()
{
 struct node1 *n1;
 n1=(struct node1*)malloc(sizeof(struct node1));
 return n1;
}

void insert_beg()
{
    struct node *temp;

    SYSTEMTIME stime;

    temp=create_Node();
    printf("\n\tEnter UserName:");
    scanf("%s",temp->user_name);
    printf("\n\tEnter BookName:");
    scanf("%s",temp->Book_name);
    printf("\n\tDate for renting book is:");
    GetSystemTime(&stime);
    printf("%d/%d/%d",stime.wDay,stime.wMonth,stime.wYear);
    temp->next=h;
    h=temp;
}

void returning_Book(int m)
{
  struct node1 *temp;
  temp=create_node1();
  printf("\n\tEnter date of returning book:");
  scanf("%d",&temp->date);
  if(temp->date-m > 7)
      printf("\n\tLibrary member is penalized!");
  else
      printf("\n\tLibrary member not penalized");
}

void return_Book()
{
  struct node *temp;
  if(h==NULL)
  printf("\n\tCannot delete list Empty!");
  else
  {
    temp=h;
    h=h->next;
    temp->next=NULL;
    free(temp);
   }
}

void display_Entries()
{
  struct node *temp;
    if(h==NULL)
    printf("\n\tList is Empty!");
    else
    {
      temp=h;
      printf("\n\tUser Name\tBook Name");
    while(temp->next!=NULL)
    {
      printf("\n\t%s\t\t| %s",temp->user_name,temp->Book_name);
      temp=temp->next;
    }
     printf("\n\t%s\t\t| %s",temp->user_name,temp->Book_name);
    }
}


int main()
{
SYSTEMTIME stime;

int ch,count=0;

int i=0;
int a,b;
printf("\n\t\tList of Books");
 printf("\n\t1-Let us C\n\t2-Java\n\t3-TechMax\n\t4-Intro to C++\n\t5-DS & Algo\n\t6-Java-Script\n\t7-Intro to C#\n\t8-Web-Dev\n");
 int Books_arr[9]={1,2,3,4,5,6,7,8,'\0'};
printf("\tEnter book of your choice:");
scanf("%d",&a);

while(Books_arr[i]!='\0')
{
    if(Books_arr[i]==a)
       {
        printf("\n\tBook found is on %d position!\n",i+1);
        }
    i++;
}

printf("\n\t1-Rent book,0-Exit:-");
scanf("%d",&b);

while(b)
{
   while(1)
	{
		printf("\n\t\tMenu");
		printf("\n\t1-Entry-Data\n\t2-Return-Book\n\t3-Display\n\t4-Exit");
		printf("\n\tenter operation to be performed:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\n\tYou are in insert Operation:");
             count++;
            insert_beg();
            break;

			case 2:
			printf("\n\tYou are in Return operation\n");
            GetSystemTime(&stime);
            int m=stime.wDay;
            returning_Book(m);
            return_Book();
            count--;
            break;


			case 3:
			printf("\n\tYou are in Display Operation\n");
            printf("\n\tNo of Entries in System are %d\n",count);
            display_Entries();
            break;

			case 4:
			printf("\n\tYou are in Exit Operation");
            exit(0);
            break;
			default:printf("\n\tEnter valid Operation!");
            break;
   }
   }
}
}
