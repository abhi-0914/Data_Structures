#include <iostream>

using namespace std;
struct student
{
    int rollNo;
    string name;

    student *next;
    void insert()
    {
        cout << "Enter Roll Number :: ";
        cin >> rollNo;
        cout << "Enter Name :: ";
        cin >> name;
    }
};
void display(student *top)
{
    while (top!= NULL)
    {
        cout << "\n\nRoll Number :: " << top->rollNo;
        cout << "\tStudent Name :: " << top->name;
        top = top->next;
    }
}
void reverse(student *top){
    if(top==NULL){
        return;
    }
    reverse(top->next);
    cout << "\n\nRoll Number :: " << top->rollNo;
    cout << "\tStudent Name :: " << top->name;
}

int main()
{

    int n;
    cout << "How Many Records :: ";
    cin >> n;
    student *head = NULL;
    for (int i = 0; i < n; i++)
    {
        student *obj = new student;
        obj->next = head;
        head = obj;
        obj->insert();
    }
    // display(head);
    reverse(head);
    return 0;
}