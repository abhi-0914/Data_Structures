#include<bits/stdc++.h>
#include "Node.cpp"
using namespace std;

Node* midNode(Node *head){
    Node *slow,*fast;
    slow=head;
    fast=head;
    
    while(fast!=NULL){
        if(fast->next==NULL){
            break;
        }
        fast=fast->next->next;
        if(fast==NULL){
            break;
        }
        slow=slow->next;
    }
    return slow;
}

int main()
{
    Node *head=insert();
    display(head);
    Node *mid=midNode(head);
    cout<<endl<<mid->data;
    return(0);
}