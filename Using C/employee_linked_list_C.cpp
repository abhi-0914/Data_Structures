#include <stdio.h>
#include <conio.h>
#include <windows.h>

void gotoxy(int x, int y)
{
    COORD c = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
struct employee
{
    int e_no;
    char e_name[24];
    char address[40];
    float salary;

    struct employee *link;
};
struct employee *top = NULL;

void input();
void modify();
void display();
void search();
void _delete();

int main()
{
    system("cls");
    printf("\t\t\t This Program Illustrates Working Of Employee Linked List As Stack");

    int x = 5, y = 3;
    gotoxy(x, y);
    printf("ADD Records");
    gotoxy(x + 30, y);
    printf("Press 1");

    gotoxy(x, y + 2);
    printf("Delete Records");
    gotoxy(x + 30, y + 2);
    printf("Press 2");

    gotoxy(x, y + 4);
    printf("Modify Program");
    gotoxy(x + 30, y + 4);
    printf("Press 3");

    gotoxy(x, y + 6);
    printf("Display Records");
    gotoxy(x + 30, y + 6);
    printf("Press 4");

    gotoxy(x, y + 7);
    printf("Search Employee");
    gotoxy(x + 30, y + 7);
    printf("Press 5");

    int choice;
    gotoxy(x, y + 9);
    printf("Please Enter Your Choice ::");
    gotoxy(x + 30, y + 9);
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        input();
        main();
    case 2:
        _delete();
        main();
    case 4:
        display();
        main();
    case 5:
        search();
        main();
    case 3:
        modify();
        main();
    default:
        exit(0);
    }
    return 0;
}

void input()
{
    struct employee *obj = (struct employee *)malloc(sizeof(struct employee *));

    system("cls");
    printf("Enter Employee Number :: ");
    scanf("%d", &obj->e_no);
    printf("\n\n Enter Employee Name :: ");
    scanf("%s", &obj->e_name);
    printf("\n\n Enter Employee Address :: ");
    scanf("%s", &obj->address);
    printf("\n\n Enter Employee Salary :: ");
    scanf("%f", &obj->salary);

    obj->link = top;
    top = obj;
}
void display()
{
    system("cls");
    struct employee *obj = top;
    if (obj == NULL)
    {
        printf("!!! Currently No Records In Memory ");
        getch();
    }
    else
    {
        while (obj != NULL)
        {
            printf("Employee Number :: %d", obj->e_no);
            printf("\n\n Employee Name :: %s", obj->e_name);
            printf("\n\n Employee Address :: %s", obj->address);
            printf("\n\n Employee salary :: %f", obj->salary);
            getch();
            obj = obj->link;
            system("cls");
        }
    }
}
void _delete()
{
    system("cls");
    struct employee *obj = top;
    if (obj == NULL)
    {
        printf("!!! Currently No Records In Memory ");
        getch();
    }
    else
    {
        bool flag;
        int n;
        printf("\n\n Enter The Employee Number Of Record To Be Deleted :: ");
        scanf("%d", &n);
        while (obj != NULL)
        {
            if (obj->e_no == n)
            {
                printf("\n\n Record Found And Its Details Are");
                printf("\n\n Employee Number :: %d", obj->e_no);
                printf("\n\n Employee Name :: %s", obj->e_name);
                printf("\n\n Employee Address :: %s", obj->address);
                printf("\n\n Employee Salary :: %f", obj->salary);

                flag = true;
                printf("\n\n Press Y To Delete The Record With Above Details "); 
                getch();
                char ch;
                scanf("%c",&ch);
                if(ch=='Y'||ch=='y')
                {
                    employee *temp=top;
                    printf("\n\n Deleting Record With Employee Number :: %d",obj->e_no);
                    printf("\n .... Record Deleted Successfully ");
                    getch();
                    while(temp!=NULL)
                    {
                        if(temp->link==obj)
                        {
                            temp->link=obj->link;
                        }
                        temp=temp->link;
                    }
                    delete obj;
                }

                break;
            }
            obj = obj->link;
        }
        if (flag != true)
        {
            printf("!!! Records Not Found Try Again ");
            getch();
        }
    }
}
void search()
{
    system("cls");
    struct employee *obj = top;
    if (obj == NULL)
    {
        printf("!!! Currently No Records In Memory ");
        getch();
    }
    else
    {
        bool flag;
        int n;
        printf("\n\n Enter The Employee Number :: ");
        scanf("%d", &n);
        while (obj != NULL)
        {
            if (obj->e_no == n)
            {
                printf("\n\n Record Found And Its Details Are");
                printf("\n\n Employee Number :: %d", obj->e_no);
                printf("\n\n Employee Name :: %s", obj->e_name);
                printf("\n\n Employee Address :: %s", obj->address);
                printf("\n\n Employee Salary :: %f", obj->salary);

                getch();
                flag = true;
                break;
            }
            obj = obj->link;
        }
        if (flag != true)
        {
            printf("!!! Records Not Found Try Again ");
            getch();
        }
    }
}
void modify()
{
    system("cls");

    struct employee *obj = top;
    if (obj == NULL)
    {
        printf("!!! Currently No Records In Memory ");
        getch();
    }
    else
    {
        bool flag;
        int n;
        printf("\n\n Enter The Employee Number Of Record to Be Modified :: ");
        scanf("%d", &n);
        while (obj != NULL)
        {
            if (obj->e_no == n)
            {
                printf("\n\n Record Found And Its Details Are");
                printf("\n\n Employee Number :: %d", obj->e_no);
                printf("\n\n Employee Name :: %s", obj->e_name);
                printf("\n\n Employee Address :: %s", obj->address);
                printf("\n\n Employee Salary :: %f", obj->salary);
                getch();

                printf("\n\n Enter New Details To Be Entered ::");
                printf("\n\n Employee Number :: ");
                scanf("%d", &obj->e_no);
                printf("\n\n Employee Name :: ");
                scanf("%s", &obj->e_name);
                printf("\n\n Employee Address :: ");
                scanf("%s", &obj->address);
                printf("\n\n Employee Salary :: ");
                scanf("%f", &obj->salary);
                getch();
                printf("\n\n ---- Records Modified SuccessFully ---");
                getch();
                flag = true;
                break;
            }
            obj = obj->link;
        }
        if (flag != true)
        {
            printf("!!! Records Not Found Try Again");
            getch();
        }
    }
}