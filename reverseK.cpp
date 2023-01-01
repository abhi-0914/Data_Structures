#include <bits/stdc++.h>
#include "Node.cpp"
using namespace std;

Node *reverse(Node *head, int k)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    if(k <= 1){
        return head;
    }
    Node *newTail = head->next;
    Node *newHead = reverse(newTail,k - 1);

    newTail->next = head;
    head->next = NULL;
    return newHead;
}

Node* findTail(Node* head){
    while(head != NULL && head ->next != NULL){
        head = head->next;
    }
    return head;
}

Node *reverseK(Node *head, int k)
{
    if (head == NULL)
    {
        return head;
    }

    Node *tail = head;

    Node *nextHead = tail;
    int i = 0;
    while (nextHead != NULL && i < k)
    {
        nextHead = nextHead->next;
        i++;
    }
    
    Node *newHead = reverse(head, k);
    findTail(head)->next = reverseK(nextHead,k);
    return newHead;
}

int main()
{
    Node *head = insert();
    display(head);
    cout << endl;
    int k;
    cin >> k;
    head = reverseK(head, k);
    cout << endl;
    display(head);
    return (0);
}