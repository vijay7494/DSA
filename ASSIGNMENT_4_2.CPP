#include <iostream>
using namespace std;

class QLinkedList
{
 public:
 int data;
 QLinkedList* next;
};

void enqueue(QLinkedList **front,QLinkedList **rear,int data)
{
 QLinkedList *temp=new QLinkedList();
 temp->data=data;
 if(*rear==NULL){
 *front=*rear=temp;
 
 }
 else{
 (*rear)->next=temp;
 *rear=temp;
 }
}

void dequeue(QLinkedList **front,QLinkedList **rear)
{
 if(*front==NULL){
 cout<<"\nQueue is empty ";
 }
 else{
 QLinkedList* temp=*front;
 int poppedData=temp->data;
 *front=(*front)->next;
 if(*front==NULL){
 *rear=NULL;
 }
 cout<<"\nPopped element is : "<<poppedData;
 free(temp);
 }
}

int main()
{
 
 int ch;
 int n;
 QLinkedList* front=NULL;
 QLinkedList* rear=NULL;
 
 do{
 cout<<"\n1.Enter an element to queue ";
 cout<<"\n2.Pop an element form the queue ";
 cout<<"\n3.Exit"<<endl;
 cin>>ch;
 switch (ch)
 {
 case 1:cout<<"\nEnter data :";
 cin>>n;
 enqueue(&front,&rear,n);
 break;
 case 2:
 dequeue(&front,&rear);
 break;
 
 case 3:
 ch=0;
 break; 
 
 default:
 break;
 }
 }while(ch);
 return 0;
}