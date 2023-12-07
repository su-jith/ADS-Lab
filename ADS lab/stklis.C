#include<stdio.h>
#include<conio.h>

struct node{
  int data;
  struct node *next;
};

struct node *head,*pre,*temp,*newnode;
int top=-1;

struct node *Push(struct node *head,int data){

   newnode=(struct node*)malloc(sizeof(struct node*));

   if(!newnode){
    printf("Memory allocation failed");
    exit();
   }

   newnode->data=data;
   newnode->next=NULL;

   if(head==0){
     printf("%d pushed to stack",newnode->data);
     return newnode;
   }

   temp=head;
   while(temp->next!=NULL){
     temp=temp->next;
   }
   temp->next=newnode;
   printf("%d is pushed to stack",newnode->data);
   return head;
}

struct node * Pop(struct node *head){
   temp=head;

   while(temp->next!=NULL){
       pre=temp;
       temp=temp->next;
    }
    pre->next=NULL;
    printf("%d is poped from stack",temp->data);
    if(temp==head){
	head=0;
	free(temp);
	return head;
     }
     free(temp);
   return head;
}

void display(struct node *head){

    temp=head;
    if(head==0){
     printf("Empty stack");
    }
     else{
    while(temp!=NULL){
     printf("%d->",temp->data);
     temp=temp->next;
    }
     if(temp->next==NULL)
	printf("NULL");
    }
}
void search(struct node *head){
  int item,i=0,c=0;
  temp=head;
  if(head==NULL)
  {
	printf("Empty stack");
	return;
  }
  printf("Enter the search item:");
  scanf("%d",&item);
  while(temp!=NULL){
       i++;
       if(temp->data==item){

       printf("ITEM FOUND AT %d POSITION",i);
       c++;
       }
       temp=temp->next;
     }
     if(c==0)
	printf("Item not found");
     return;

}

void main(){
int c,data,n;

clrscr();
head=0;
printf("Enter the size:");
scanf("%d",&n);
top=-1;
while(1){
    printf("\nEnter the option:\n 1.Push\n 2.Pop\n 3.Display\n 4.Search\n 5.Exit\n");
    scanf("%d",&c);
    switch(c){
	case 1:if(top==n-1){
	       printf("Stack overflow");
		break;
	      }
	       printf("Enter the data:");
	       scanf("%d",&data);
	       head=Push(head,data);
	       top++;
	       break;
	case 2:if(top==-1){
		 printf("Stack underflow");
		 break;
		}
	       head=Pop(head);
	       top--;
	       break;
	case 3:display(head);
	       break;
	case 4:search(head);
		break;
	case 5:exit();

	default:printf("Enter valid option!!");
		break;

    }
 }
getch();
}
