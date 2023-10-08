#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};
void insertAtHead(node* &head,int val){
    node* n = new node(val);
    n->next=head;
    head=n;
}
void insertAtTail(node* &head, int val){
    //now we create new node which is going to be inserted
    node* n = new node(val);

// if head is null then:
    if (head==NULL)
    {
       head=n;
       return;
    }
    
    //to traverse each node we take an itretrator

    node* temp =head;
    while (temp->next!=NULL){
        temp=temp->next;

    }
    temp->next=n; 
    
}
void display(node* head){
    node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

//to search an element:

bool search(node* head, int key){
  node* temp=head;
  while(temp!=NULL){
    if(temp->data==key){
        return true;
    }
    temp=temp->next;
  }
  return false;

}

 void deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;

    delete todelete;
 }

 void deletion(node* head, int val){
    node* temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;

    delete todelete;
 }
int main(){

node* head=NULL;
insertAtTail(head,1);
insertAtTail(head,2);
insertAtTail(head,3);
display(head);
insertAtHead(head,4);
display(head);
// cout<<search(head,3)<<endl;
// cout<<search(head,5);
cout<<"node after deletion"<<endl;
//deletion(head,3);
deleteAtHead(head);
display(head);

   return 0; 
}