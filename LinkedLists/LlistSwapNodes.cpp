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
void printList(node *head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
node* swapNodes(node *head,int x,int y){
    node* temp=head;
    if(head->data==x&&head->data==y)
    return head;
    if(head->data==x){
        while(temp->next){
            if(temp->next->data==y)
                break;
            temp=temp->next;
        }
        node* t1=temp->next;
        temp->next=head;
        node*t2=t1->next;
        t1->next=head->next;
        head->next=t2;
        return t1;
    }
    if(head->data==y){
        while(temp->next){
            if(temp->next->data==x)
            break;
            temp=temp->next;
        }
        node* t1=temp->next;
        temp->next=head;
        node*t2=t1->next;
        t1->next=head->next;
        head->next=t2;
        return t1;
    }
    else{
        node* t1=head;
        node* t2=head;
        while(t1->next){
            if(t1->next->data==x)
            break;
            t1=t1->next;
        }
        while(t2->next){
            if(t2->next->data==y)
            break;
            t2=t2->next;
        }
        node*a=t1->next;
        t1->next=t2->next;
        t1=t2->next;
        t2->next=a;
        t2=a->next;
        a->next=t1->next;
        t1->next=t2;
        return head;
    }
}
int main(){
    node *head=new node(1);
    head->next=new node(2);
    head->next->next=new node(3);
    head->next->next->next=new node(4);
    head->next->next->next->next=new node(5);
    printList(head);
    head=swapNodes(head,1,5);
    printList(head);
    return 0;
}