#include<bits/stdc++.h>
#include "Node.cpp"
using namespace std;

void deleteNodes(Node *head,int n,int m){
    Node *temp=head;
    int count1=0,count2=0;
    Node *temp1,*temp2;
    
    while(temp!=NULL){

        count1++;
        if(count1==m){
            temp1=temp;
            if(temp1==NULL){
                break;
            }
            temp2=temp1->next;
            while(count2!=n){
                temp2=temp2->next;
                if(temp2==NULL){
                    break;
                }
                count2++;
            }
            temp1->next=temp2;
            count1=0;
            count2=0;
        }
        temp=temp->next;
    }
    
}

int main()
{
    Node *head=insert();
    display(head);

    deleteNodes(head,2,3);
    cout<<endl;
    display(head);
    return(0);
}