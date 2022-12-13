#include<bits/stdc++.h>
using namespace std;

class Node{
    
    public:

    int data;
    Node *next;

    Node(int data){
        this->data=data;
        next=NULL;
    }
};

Node* insert(){

    int data;
    cin>>data;

    Node *head=NULL;
    Node *tail=NULL;
    while(data!=0){
        Node *newNode=new Node(data);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
        cin>>data;
    }
    return head;
}
void display(Node *head){
    while(head!=NULL){
        cout<<head->data<<"\t";
        head=head->next;
    }
}