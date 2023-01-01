#include<bits/stdc++.h>
#include "Node.cpp"
using namespace std;

Node* reverseLL(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *smallOutput=reverseLL(head->next);
    // Node *temp=smallOutput;
    // while(temp->next!=NULL){
    //     temp=temp->next;
    // }
    // temp->next=head;
    // Node *tail=head->next;
    // tail->next=head;
    // head->next=NULL;
    return(smallOutput);
}

int main()
{
    Node *head=insert();
    display(head);
    head=reverseLL(head);
    cout<<endl;
    display(head);
    return(0);
}