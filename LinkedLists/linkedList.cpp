#include<iostream>
using namespace std;
//node represents a single unit of block or node of the list
class node{
    public:
        int data;
        node* next;
        node(){
            next=NULL;
        }
};

//list traversal
void printList(node* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<'\n';
}
int listLength(node* head){
    int count=0;
    while(head){
        count++;
        head=head->next;
    }
    return count;
}
int main(){
    node* head=new node();
    node* second=new node();
    node* third=new node();
    head->next=second;
    second->next=third;
    head->data=1;
    second->data=2;
    third->data=3;
    printList(head);
    cout<<"Length of the list is: "<<listLength(head)<<endl;
}