#include <bits/stdc++.h>
#include "Node.cpp"
using namespace std;

Node* arrangeElements(Node *head, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        return (newNode);
    }
    else
    {
        Node *temp = head;
        while (temp->next!= NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        return head;
    }
}

void evenAfterOdd(Node *head){
    Node *oddHead = NULL;
    Node *evenHead = NULL;
    // Node *oddTail=NULL;

    Node *temp = head;
    while (temp != NULL)
    {
        if ((temp->data) % 2 != 0)
        {
            oddHead = arrangeElements(oddHead, temp->data);
        }
        else{
            evenHead=arrangeElements(evenHead,temp->data);
        }
        temp = temp->next;
    }
    cout<<endl;
    display(oddHead);
    cout<<endl;
    display(evenHead);

    temp=oddHead;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=evenHead;
    cout<<endl;
    display(oddHead);
}

int main()
{
    Node *head = insert();
    display(head);
    evenAfterOdd(head);
    return (0);
}