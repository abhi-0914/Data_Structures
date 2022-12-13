#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>

void gotoxy(int x,int y){
    COORD c={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
};

using namespace std;

struct student{
    int roll_no;
    char name[24];
    float marks;
    char grade;

    student* previous=NULL;
    student* next=NULL;

};
student* insertfrombeg(student*,student*);
student* display(student*);
int check(){
    cout<<"\n\n Press  1 to continue .... ";
    char ch;
    cin>>ch;
    if(ch=='1'){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){

    student *head,*tail;
    head=NULL;
    tail=NULL;
    int flag;
    do{
        system("cls");
        cout<<"\t\t :: Student Workspace :: ";
        cout<<"\n\n Add New Record           Press - 1";
        cout<<"\n Modify Record            Press - 2";
        cout<<"\n Search Record            Press - 3";
        cout<<"\n Delete Record            Press - 4";
        cout<<"\n Display Records          Press - 5";
        cout<<"\n Exit                     Press - 0";
        char ch;
        cout<<"\n\n Please Enter Your Choice :: ";
        cin>>ch;

        if(ch=='1'){
            if(head==NULL){
                head=insertfrombeg(head,tail);
                tail=head;
            }
            else
            {
                head=insertfrombeg(head,tail);
            }
        }
        else if(ch=='5'){
            student *p=display(head);
        }
        flag=check();

    }while(flag==1);

}

student* display(student *head){
    student *obj=head;
    if(obj==NULL){
        return NULL;
    }
    else{
        system("cls");
        cout<<"Roll Number :: "<<obj->roll_no;
        cout<<"\n Name :: "<<obj->name;
        cout<<"\n Marks :: "<<obj->marks;
        cout<<"\n Grade :: "<<obj->grade;

        system("pause");
        display(obj->next);
    }
}

student* insertfrombeg(student *head,student *tail){
    student *obj=new student;
    system("cls");
    cout<<"\n Enter Roll Number :: ";
    cin>>obj->roll_no;
    cout<<"\n Enter Name :: ";
    cin>>obj->name;
    cout<<"\n Enter Marks :: ";
    cin>>obj->marks;
    cout<<"\n Enter Grade :: ";
    cin>>obj->grade;

    obj->previous=NULL;
    obj->next=head;
    head->previous=obj;
    return(obj);
}