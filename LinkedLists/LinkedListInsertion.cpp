#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node* next;
        node(int d){
            data=d;
            next=NULL;
        }
};
void printList(node* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
//insertion at the beginning of the list
node* insertionAtFront(node* head,int d){
    node* newnode=new node(d);
    newnode->next=head;
    return newnode;
}
//isnertion at the end of the list
void insertionAtEnd(node*head,int d){
    node*newnode=new node(d);
    while(head->next)
    head=head->next;
    head->next=newnode;
}
//insertion before a given key
void insertBeforeKey(node*head,int key,int d){
    node* newnode=new node(d);
    while(head){
        if(head->next->data==key)
        break;
        head=head->next;
    }
    newnode->next=head->next;
    head->next=newnode;
}
//insertion after a givenkey
void insertAfterKey(node*head,int key,int d){
    node*newnode=new node(d);
    while(head){
        if(head->data==key)
        break;
        head=head->next;
    }
    newnode->next=head->next;
    head->next=newnode;
}
int main(){
    node* head=new node(1);
    head=insertionAtFront(head,0);
    insertionAtEnd(head,2);
    insertionAtEnd(head,3);
    insertionAtEnd(head,4);
    insertionAtEnd(head,5);
    printList(head);
    insertBeforeKey(head,2,10);
    printList(head);
    insertAfterKey(head,2,20);
    printList(head);
    return 0;
}