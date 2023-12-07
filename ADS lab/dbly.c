#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node *back;
};

struct node *head=0,*tail,*newnode,*prev,*temp;

void insertend(){
	int data;
	printf("Enter the data:");
	scanf("%d",&data);
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=NULL;
	newnode->back=NULL;
	if(head==0){
		head=tail=newnode;
	}else{
		tail->next=newnode;
		newnode->back=tail;
		tail=newnode;
	}
}
void insertatbig(){
	int data;
	printf("Enter the data:");
	scanf("%d",&data);
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=NULL;
	newnode->back=NULL;
	if(head==0){
		head=tail=newnode;
	}
	else{
		head->back=newnode;
		newnode->next=head;
		head=newnode;
	}
}

void insertatpos(){
	int data,i=1,pos;
	printf("Enter the position:");
	scanf("%d",&pos);
	printf("Enter the data:");
	scanf("%d",&data);
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=NULL;
	newnode->back=NULL;
	if(pos<1){
		printf("wrong pos\n");
		return;
	}
	if(pos==1 && head==0){
		head=tail=newnode;
		return;
	}
	else if(pos==1){
		head->back=newnode;
		newnode->next=head;
		head=newnode;
		return;
	}
	
	else{
		temp=head;
    	prev=0;
		while(i<pos && temp!=NULL){
			prev=temp;
			temp=temp->next;
			i++;
		}
		if(i<pos){
			printf("out of range\n");
			return;
		}
		prev->next=newnode;
		newnode->next=temp;
		temp->back=newnode;
		newnode->back=prev;
		
	}
}

void deleteend(){
	if(head==0){
		printf("empty\n");
		
	}
	else{
	temp=tail;
	tail=temp->back;
	tail->next=NULL;
	free(temp);
  } 
  return;
}
void deletebig(){
	if(head==0)
		printf("Empty list\n");
	else{
	temp=head;
	head=temp->next;
	head->back=NULL;
	if(head==temp){
		head=NULL;
	}
	free(temp);

  }
  return;
}
void deletepos(){
	int i=1,pos;
	printf("Enter the position:");
	scanf("%d",&pos);
	if(head==0)
		printf("Empty list\n");
	else{
		if(pos<1){
			printf("wrong position:\n");
			return ;
		}else if(pos==1){
			temp=head;
			head=temp->next;
			head->back=NULL;
			free(temp);
		}else{
			temp=head;
			prev=0;
			while(i<pos && temp!=NULL){
				prev=temp;
				temp=temp->next;
				i++;
			}
			if(i<pos){
				printf("Out of range!!");
				return;
			}
			newnode=temp->next;
			prev->next=newnode;
			newnode->back=prev;
			free(temp);
		}
	
	}
	return;
}

void display(struct node *head){
	temp=head;
	printf("List elemnets :");
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("NULL");
}

int main(){

	int c;
	clrscr();
	while(1){
		printf("\nEnter the option\n 1.insert\n 2.Display\n 3.insert at big\n 4.exit\n 5.at pos in\n 6.delete end\n 7.delete begining\n 8.delete pos\n");
		scanf("%d",&c);
		switch(c){
			case 1:
				   insertend();
				   break;
			case 2:display(head);
			       break;
			case 3:insertatbig();
					break;
			case 4:exit(1);
			case 5:insertatpos();
					break;
			case 6:deleteend();
					break;
			case 7:deletebig();
					break;
			case 8:deletepos();
					break;
			default:printf("Enter correct option");
		}
	}
 return 0;
}
