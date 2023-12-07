#include<stdio.h>
#include<conio.h>
#include<math.h>

struct node{
  int data;
  struct node *next;
};
 struct node *prev,*head,*newnode,*temp;

struct node* insert(struct node* head,int data,int pos){
   int i=1;
   if(pos<1){
      printf("invalid option");
      return head;
    }

    newnode=(struct node*)malloc(sizeof(struct node));
    if(!newnode){
      printf("Memory allocation failed");
      exit();
     }

    newnode->data=data;
    newnode->next=NULL;

    if(pos==1){
     newnode->next=head;
      printf("%d inserted at %d position",data,pos);
     return newnode;
    }

    temp=head;
    prev=NULL;
    while(i<pos && temp!=NULL){
     prev=temp;
     temp=temp->next;
     i++;
    }
    if(i<pos){
     printf("Out of range");
     free(newnode);
     return head;
    }
    prev->next=newnode;
    newnode->next=temp;
    printf("%d inserted at %d position",data,pos);

    return head;
}


struct node* Delete(struct node* head,int pos){
 int i=1;
 if(pos<1){
   printf("Invalid option");
   return head;
  }
  if(pos==1){
   temp=head;
   head=head->next;
   printf("%d deleted from position %d ",temp->data,pos);
   free(temp);
   return head;
  }
  temp=head;
  prev=0;

  while(i<pos && temp!=0){
    prev=temp;
    temp=temp->next;
    i++;
   }
   if(i<pos || temp==0){
    printf("Out of range");
    return head;
   }
    prev->next=temp->next;
    printf("%d deleted from position %d ",temp->data,pos);
    free(temp);
 return head;
}

void display(struct node* head){
  if(head==0){
     printf("Empty list");
  }else{
  temp=head;
  while(temp!=0){
   printf("%d->",temp->data);
   temp=temp->next;
  }
     printf("NULL");
  }
}

void main(){
 int c,data,pos;
 head=0;
 clrscr();
 while(1){


   printf("\nSelect an option: \n 1.insert\n 2.delete\n 3.display\n 4.exit\n\n");
   scanf("%d",&c);
   if(c==1){
       printf("Enter the position:");
       scanf("%d",&pos);
       printf("Enter the data:");
       scanf("%d",&data);
       head=insert(head,data,pos);
   }

   else if(c==2){

      printf("Enter the position:");
      scanf("%d",&pos);
      head=Delete(head,pos);

   }

   else if(c==3){
	  display(head);
   }

   else if(c==4)
	exit();

   else
	printf("Enter a valid option\n");
  }
   getch();
}
