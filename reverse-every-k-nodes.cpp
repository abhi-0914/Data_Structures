#include <bits/stdc++.h>
#include "Node.cpp"
using namespace std;

Node *reverse(Node *head, Node *tail)
{

    Node *current = head;
    Node *previous, *next;
    previous = next = NULL;

    while (previous != tail)
    {

        next = current->next;
        current->next = previous;

        previous = current;

        current = next;
    }
    // display(previous);
    return previous;
}
Node *reverseK(Node *head, int k)
{

    if (head == NULL)
    {
        return NULL;
    }

    int count = 1;
    Node *h1, *t1;
    h1 = t1 = head;
    while (count < k)
    {
        if (t1 == NULL)
        {
            break;
        }
        t1 = t1->next;
        count++;
    }

    h1 = reverse(h1, t1); /// reversed nodes from h1 to t1
    // cout<<endl;
    // display(h1);

    Node *temp = h1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = reverseK(t1->next, k);
    return temp;
    
}

int main()
{
    Node *head = insert();
    display(head);
    int k;
    cout << endl;
    cin >> k;
    head = reverseK(head, k);
    cout << endl;
    display(head);
    return (0);
}