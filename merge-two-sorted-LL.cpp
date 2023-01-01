#include<bits/stdc++.h>
#include "Node.cpp"
using namespace std;

Node* mergeSortedLL(Node *h1,Node *h2){

    Node *newHead=NULL,*newTail=NULL;

    if(h1->data > h2->data){
        newHead=newTail=h2;
        h2=h2->next;
    }
    else{
        newHead=newTail=h1;
        h1=h1->next;
    }

    while(h1!=NULL && h2!=NULL){

        if(h1->data > h2->data){
            newTail->next=h2;
            newTail=h2;
            h2=h2->next;
        }
        else{
            newTail->next=h1;
            newTail=h1;
            h1=h1->next;
        }
    }
    if(h1==NULL){
        newTail->next=h2;
    }
    else{
        newTail->next=h1;
    }
    return newHead;
}

int main()
{
    Node *h1,*h2;
    h1=insert();
    h2=insert();
    // display(h1);
    // cout<<endl;
    // display(h2);
    // cout<<endl;
    Node *head=mergeSortedLL(h1,h2);
    display(head);
    return(0);
}