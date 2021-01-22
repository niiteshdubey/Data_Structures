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
void printList(node*head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
void deleteNode(node**head,int key){
    node*temp=*head;
    node*prev=temp;
    while(temp){
        if(temp->data==key)
            break;
        prev=temp;
        temp=temp->next;
    }
    if(temp==*head){
        *head=(*head)->next;
        delete temp;
        return;
    }
    prev->next=temp->next;
    delete temp;
}
int main(){
    node*head=new node(1);
    head->next=new node(2);
    head->next->next=new node(3);
    head->next->next->next=new node(4);
    printList(head);
    deleteNode(&head,2);
    printList(head);
    deleteNode(&head,1);
    printList(head);
}