#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>

void main()
{


int data,c;

struct node
{
  int data;
  struct node *next;
};
struct node *temp, *head, * newnode;
printf("\noption\n 1.insert\n 2.end\n 3.diplay\n\n");
scanf("%d",&c);
while(1)
{
  switch(c)
    {
      case 1:  if(head==NULL)
		 {
		   head=0;
		   newnode=(struct node*)malloc(sizeof(struct node));
		   printf("\nenter the data\n");
		   scanf("%d",&data);
		   newnode->data=data;
		   newnode->next=NULL;
		   head=newnode;
		 }
	       else if(head==newnode)
		 {
		   temp=head;
		   newnode=(struct node*)malloc(sizeof(struct node));
		   printf("\nenter the data\n");
		   scanf("%d",&data);
		   newnode->data=data;
		   newnode->next= temp;
		 }


      case 2: exit(0);
      case 3:while(temp!=NULL)
	       {
		 printf("->%d",newnode->data);
	       }
    }
}
}
