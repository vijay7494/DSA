#include <iostream>
using namespace std;

class StackLinkedList
{
public:
int data;
StackLinkedList *next;
};

void push(StackLinkedList **head,int data)
{
 StackLinkedList* newNode=new StackLinkedList();
 newNode->data=data;
 newNode->next=*head;
 *head=newNode;
}

void pop(StackLinkedList **head)
{
 if(*head==NULL){
 cout<<"Stack is empty";
 }
 else{
 StackLinkedList *temp=*head;
 int poppedData=temp->data;
 *head=(*head)->next;
 cout<<"\nPopped element is : "<<poppedData;
 free(temp);
 }
}

void peek(StackLinkedList **head)
{
 if(*head==NULL){
 cout<<"Stack is empty";
 }
 else{
 cout<<"\nTop element is : "<<(*head)->data;
 }
}

int main()
{
 int ch;
 int n;
 StackLinkedList* st=NULL;
 do{
 cout<<"\n1.Enter an element to stack ";
 cout<<"\n2.Pop an element form the stack ";
 cout<<"\n3.Peek the top element of the stack ";
 cout<<"\n4.Exit"<<endl;
 cin>>ch;
 switch (ch)
 {
 case 1:cout<<"\nEnter data :";
 cin>>n;
 push(&st,n);
 break;
 case 2:
 pop(&st);
 break;
 case 3:
 peek(&st);
 break; 
 case 4:
 ch=0;
 break; 
 
 default:
 break;
 }
 }while(ch);
 return 0;
}