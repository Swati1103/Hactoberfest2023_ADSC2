#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head=0;

void CreateList(int data){
   struct node *temp;
   temp=head;
   struct node *newnode;
   newnode=(struct node*)malloc(sizeof(struct node));
   if(head==0){
    head=newnode;
    temp=newnode;
    newnode->data=data;
   }
   else{
    newnode->data=data;
    temp->next=newnode;
    newnode->next=0;
    temp=newnode;
}
}

void InsertAtBeginning(int data){
struct node *newnode;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=data;
newnode->next=head;
head=newnode;
}

void InsertAtEnd(int data){
  struct node *temp;
  struct node *newnode;
  temp=head;
  newnode=(struct node*)malloc(sizeof(struct node));
  while(temp->next!=0){
    temp=temp->next;
  }
  newnode->data=data;
  temp->next=newnode;
  newnode->next=0;
}

void InsertAtPosition(int data){
  struct node *newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  int position,i=1;
  struct node *temp;
  temp=head;
position=1;
  while(i<position){
       temp=temp->next;
       i++;
  }
  newnode->data=data;
    newnode->next=temp->next;
    temp->next=newnode;
}

void DeleteFromBeg(){
  struct node *temp;
  temp=head;
  head=temp->next;
  free(temp);
}

void DeleteFromEnd(){
  struct node *temp;
  struct node *prevnode;
  temp=head;
  while(temp->next!=0){
    prevnode=temp;
    temp=temp->next;
  }
  prevnode->next=0;
  free(temp);
}

void DeleteFromPosition(){
  struct node *nextnode;
  struct node *temp;
  temp=head;
  int pos=3,i=1;
  while(i<pos-1){
    temp=temp->next;
    i++;
  }
  nextnode=temp->next;
  temp->next=nextnode->next;
}

void CountLength(){
  int count=0;
  struct node *temp;
  temp=head;
  while(temp!=0){
    count++;
    temp=temp->next;
  }
  printf("Legth of Linked List is %d ",count);
}

void Reverse(){
  struct node *prevnode,*currentnode,*nextnode;
  prevnode=0;
  currentnode=head;
  nextnode=head;
  while(nextnode!=0){
    nextnode=nextnode->next;
    currentnode->next=prevnode;
    prevnode=currentnode;
    currentnode=nextnode;
  }
  head=prevnode;
}

void printLinkedList(){
  if(head==NULL){
    printf("\nNULL");
  }
  else{
    struct node *temp=head;
    while(temp!=0){
        printf("%d\n",temp->data);  
        temp=temp->next;
    }
  }
}

void main(){
CreateList(1234);
CreateList(4567);
InsertAtBeginning(678);
InsertAtEnd(563);
InsertAtEnd(324);
InsertAtEnd(2342);
InsertAtBeginning(78348);
DeleteFromBeg();
DeleteFromEnd();
DeleteFromPosition();
Reverse();
printLinkedList();
}
