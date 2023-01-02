#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
};
class singlelinkedlist {
public:
  Node *header = NULL;
  void insertatbegin();
  void insertatend();
  void insertatposition();
  void deleteatbegin();
  void deleteatend();
  void deleteatposition();
  void displaylist();
};
void singlelinkedlist::insertatbegin() {
  Node *n1;
  int n;
  n1 = new Node();
  cout << "\nEnter the data part of the first node" << endl;
  cin >> n;
  n1->data = n;
  n1->next = header;
  header = n1;
}
void singlelinkedlist::insertatend() {
  Node *n1;
  n1 = new Node();
  int n;
  cout << "\nEnter the data part of last node" << endl;
  cin>>n;
  n1->data = n;
  n1->next = NULL;
  if (header == NULL) {
    header = n1;
  } else {
    Node *temp;
    temp = header;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = n1;
  }
}
void singlelinkedlist::insertatposition() {
  int p;
  int count = 0;
  cout << "\nEnter the position for new node" << endl;
  cin >> p;
  Node *temp;
  temp = header;
  while (temp != NULL) {
    temp = temp->next;
    count++;
  }
  if (p > count) {
    cout << "You cant insert any element" << endl;
  } else if (p == 1) {
    insertatbegin();
  } else {
    Node *n1;
    Node *n2;
    n1 = new Node();
    int n;
    cout << "\nEnter the data part to be added" << endl;
    cin >> n;
    n1->data = n;
    Node *temp = header;
    for (int i = 0; i < p - 2; i++) {
      temp = temp->next;
    }
    n1->next = temp->next;
    temp->next = n1;
  }
}
void singlelinkedlist::deleteatbegin() { header = header->next; }
void singlelinkedlist::deleteatend() {
  if (header != NULL) {
    Node *temp;
    Node *temp1;
    temp = header->next;
    temp1 = header;
    while (temp->next != NULL) {
      temp1 = temp;
      temp = temp->next;
    }
    delete temp;
    temp1->next = NULL;
  } else {
    cout << "You haven't entered any element" << endl;
  }
}
void singlelinkedlist::deleteatposition() {
  Node *temp;
  int count = 0;
  temp = header;
  while (temp != NULL) {
    temp = temp->next;
    count++;
  }
  int n;
  cout << "\nEnter the position to be deleted" << endl;
  cin >> n;
  if (n > count) {
    cout << "You can't delete element" << endl;

  } else {
    temp = header;
    for (int i = 0; i < n; i++) {
      temp = temp->next;
    }
    temp->next = temp->next->next;
  }
}
void singlelinkedlist::displaylist() {
  Node *temp;
  temp = header;
  while (temp != NULL) {
    cout << temp->data << "\t";
    temp = temp->next;
  }
}
int main() {
  int ch;
  singlelinkedlist s;
 do {
    cout << "\nEnter 1 to insert at beginning" << endl;
    cout << "\nEnter 2 to insert at end" << endl;
    cout << "\nEnter 3 to insert at position" << endl;
    cout << "\nEnter 4 to display" << endl;
    cout << "\nEnter 5 to delete at beginning" << endl;
    cout << "\nEnter 6 to delete at end" << endl;
    cout << "\nEnter 7 to delete at position" << endl;
    cout << "\nEnter 8 to exit" << endl;
   cin>>ch;
    switch(ch)
		    {
		    case 1:
		    	s.insertatbegin();
		    	break;
		    case 2:
		    	s.insertatend();
		    	break;
		    case 3:
		    	s.insertatposition();
		    	break;
          case 4:
          s.displaylist();
          break;
          case 5:
          s.deleteatbegin();
          break;
          case 6:
          s.deleteatend();
          break;
          case 7:
          s.deleteatposition();
          break;
		    default :
		    	cout<<"Wrong choice"<<endl;
		    	break;
		    case 8:
		    	return 0;
		    }
  }while(1);
}