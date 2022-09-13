#include<iostream>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<windows.h>
#include<string.h>
using namespace std;

void gotoxy(int x ,int y)
{
    COORD c={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
struct employee
{
    int e_no;
    char e_name[24];
    char address[40];

    employee *link;
};

void input();
void modify();
void display();
void search();
void pop();
employee *top=NULL;

int main()
{
    system("cls");
    cout<<"\t\t\t This Program Illustrates Working Of Employee Stack";

    int x=5,y=3;
    gotoxy(x,y);
    cout<<"ADD Records";
    gotoxy(x+30,y);
    cout<<"Press 1";
    
    gotoxy(x,y+2);
    cout<<"Delete Records";
    gotoxy(x+30,y+2);
    cout<<"Press 2";
    
    gotoxy(x,y+4);
    cout<<"Modify Program";
    gotoxy(x+30,y+4);
    cout<<"Press 3";
    
    gotoxy(x,y+6);
    cout<<"Display Records";
    gotoxy(x+30,y+6);
    cout<<"Press 4";
    
    gotoxy(x,y+7);
    cout<<"Search Employee";
    gotoxy(x+30,y+7);
    cout<<"Press 5";

    char choice;
    gotoxy(x,y+9);
    cout<<"Please Enter Your Choice ::";
    gotoxy(x+30,y+9);
    cin>>choice;

    int a;
    switch(choice)
    {
        case '1' : input();
                    a=main();
        case '2' : pop();
                    a=main();
        case '4' : display();
                    a=main();
        case '5' : search();
                    a=main();
        case '3' : modify();
                    a=main();
        default: exit(0);
    }
    return 0;
}

void input()
{
    employee *obj=new employee;

    system("cls");
    cout<<"Enter Employee Number :: ";
    cin>>obj->e_no;
    cout<<"\n\n Enter Employee Name :: ";
    cin>>obj->e_name;
    cout<<"\n\n Enter Employee Address :: ";
    cin>>obj->address;

    obj->link=top;
    top=obj;
}
void display()
{
    system("cls");
    employee *obj=top;
    if(obj==NULL)
    {
        cout<<"!!! Currently No Records In Memory ";
    }
    else
    {
        while (obj!=NULL)
        {
            cout<<"Employee Number :: "<<obj->e_no;
            cout<<"\n\n Employee Name :: "<<obj->e_name;
            cout<<"\n\n Employee Address :: "<<obj->address;
            getch();
            obj=obj->link;
            system("cls");
        }
    }
}
void pop()
{
    system("cls");
    employee *obj=top;
    if(obj==NULL)
    {
        cout<<"!!! Currently No Records In Memory ";
        getch();
    }
    else
    {
        cout<<"\n\n Deleting Record With Employee Number :: "<<obj->e_no;
        getch();
        top=top->link;
        delete obj;
    }
}
void search()
{
    system("cls");
    employee *obj=top;
    if(obj==NULL)
    {
        cout<<"!!! Currently No Records In Memory ";
        getch();
    }
    else
    {
        bool flag;
        int n;
        cout<<"\n\n Enter The Employee Number :: ";
        cin>>n;
        while (obj!=NULL)
        {
            if(obj->e_no==n)
            {
                cout<<"\n\n Record Found And Its Details Are";
                cout<<"\n\n Employee Number :: "<<obj->e_no;
                cout<<"\n\n Employee Name :: "<<obj->e_name;
                cout<<"\n\n Employee Address :: "<<obj->address;
                getch();
                flag=true;
                break;
            }
            obj=obj->link;
        }
        if(flag!=true)
        {
            cout<<"!!! Records Not Found ";
            getch();
        }
    }
}
void modify()
{
    system("cls");
    employee *obj=top;
    if(obj==NULL)
    {
        cout<<"!!! Currently No Records In Memory ";
        getch();
    }
    else
    {
        bool flag;
        int n;
        cout<<"\n\n Enter The Employee Number Of Record to Be Modified :: ";
        cin>>n;
        while (obj!=NULL)
        {
            if(obj->e_no==n)
            {
                cout<<"\n\n Record Found And Its Details Are";
                cout<<"\n\n Employee Number :: "<<obj->e_no;
                cout<<"\n\n Employee Name :: "<<obj->e_name;
                cout<<"\n\n Employee Address :: "<<obj->address;
                getch();
                
                cout<<"\n\n Enter New Details To Be Entered ::";
                cout<<"\n\n Employee Number :: ";
                cin>>obj->e_no;
                cout<<"\n\n Employee Name :: ";
                cin>>obj->e_name;
                cout<<"\n\n Employee Address :: ";
                cin>>obj->address;
                getch();
                cout<<"\n\n ---- Records Modified SuccessFully ---";
                getch();
                flag=true;
                break;
            }
            obj=obj->link;
        }
        if(flag!=true)
        {
            cout<<"!!! Records Not Found ";
            getch();
        }
    }
}