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

Node* insertAtPos(Node *head,int index,int data){
    if(head==NULL){
        return head;
    }
    if(index==0){
        Node *newNode=new Node(data);
        newNode->next=head;
        head=newNode;
        return head;
    }
    head->next=insertAtPos(head->next,index-1,data);
    return head;
}
Node* deleteAtPos(Node *head,int index,int data){
    if(head==NULL){
        return head;
    }
    if(index==0){
        head=head->next;
        return head;
    }
    head->next=deleteAtPos(head->next,index-1,data);
    return head;
}

void display(Node *head){
    while(head!=NULL){
        cout<<head->data<<"\t";
        head=head->next;
    }
}

int main()
{
    Node *head=insert();
    cout<<head<<endl;
    display(head);
    cout<<endl;
    head=insertAtPos(head,0,90);
    head=deleteAtPos(head,4,90);
    display(head);
    return(0);
}