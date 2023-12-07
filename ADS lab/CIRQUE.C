#include<stdio.h>
#include<conio.h>

int cq[100],n,front=-1,rear=-1;

void insert(){
   int item;
   if((rear+1)%n==front){
     printf("Overflow\n");
     return;
   }
   printf("Enter the element:");
   scanf("%d",&item);
   if(rear==-1){
     front=rear=0;
     cq[rear]=item;
     printf("%d inserted",item);
     return;
   }
   else if(rear>n){
	  rear=(rear+1)%n;
	  cq[rear]=item;
   }
   else{
	  rear++;
	  cq[rear]=item;
   }
   printf("%d inserted ",item);
}

void Delete(){

     int item;
     if(front==-1){
       printf("Underflow!!");
       return;
     } else{
      if(rear==front){
	item=cq[front];
	rear=front=-1;
      } else{
       item=cq[front];
       front=(front+1)%n;
      }
     }
     printf("%d is deleted",item);
}

void display(){
     int i,c;
     if(front==-1 && rear==-1){
      printf("empty queue");
      return;
     }
     else{
     printf("Queue elements are:");
     if(rear>=front){
	for(i=front;i<=rear;i++)
	printf("%d\t",cq[i]);
      }
      if(rear<front){
       for(i=front;i<=rear;i++)
	 printf("%d\t",cq[i]);
       for(i=0;i<=rear;i++)
	 printf("%d\t",cq[i]);
      }
     }
}

void search(){
  int item,i,c;
   if(front==-1 && rear==-1){
      printf("empty queue");
      return;
     }
  printf("Enter the item to search:");
  scanf("%d",&item);
	for(i=front;i<=rear;i++){
	  if(cq[i]==item){
	    printf("Item found at position %d",i);
	    return;
	  }
	}
       for(i=0;i<=rear;i++){
	   if(cq[i]==item){
	    printf("Item found at position %d",i);
	    return;
	  }
      }
	printf("Item not found");

}

void main()
{
  int c;
clrscr();
 printf("Enter the size of the queue:");
 scanf("%d",&n);
 while(1){
  printf("\nEnter the option\n 1.insert\n 2.delete\n 3.display\n 4.search\n 5.exit\n");
  scanf("%d",&c);
  switch(c){
    case 1:insert();
	   break;
    case 2:Delete();
	   break;
    case 3:display();
	   break;
    case 4:search();
	   break;
    case 5:exit();

    default:printf("Wrong option!!");
	   break;
  }

 }

  getch();

}
