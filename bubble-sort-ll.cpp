#include<bits/stdc++.h>
#include "Node.cpp"
using namespace std;

Node* bubbleSort(Node *head){

    Node *previous,*next,*current;
    current=head;
    next=current->next;
    previous=NULL;

    while(current->next!=NULL){
        
        
    }
}

int main()
{
    Node *head=insert();
    display(head);
    head=bubbleSort(head);
    return(0);
}