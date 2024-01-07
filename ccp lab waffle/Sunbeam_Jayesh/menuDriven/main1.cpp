//#include "course1.cpp"
#include "student1.h"
#include<stdio.h>
#include<conio.h>
#include <bits/stdc++.h>
using namespace std;

enum StudMenu
{

    EXIT,
    REGISTER,
    SET_COURSE,
    DISPLAY_SPECIFIC_STUDENT,
    DISPLAY_ALL_STUDENT,

};

StudMenu menu()
{

    int choice;
    cout<<"\t\t\t\t\tSTUDENT DATA MENU DRIVEN\n\n\n0.Exit The Program\n1.Register the Student\n2.Set Course\n3.Display Specific Student\n4.Display All Students\n\nChoice: ";
    cin>>choice;
    return StudMenu(choice);

}

int main()
{
    system("color 0A");
    StudMenu choice;
    vector<Student *> vect;
    while((choice=menu())!=EXIT)
    {
        int flag=0;
        switch (choice)
        {
        case REGISTER:
            vect.push_back(new Student());
            vect.at(vect.size()-1)->setStudent();
            cout<<"\nStudent was added Successfully....!\n\n";
            getch();
            system("cls");
            break;

        case SET_COURSE:
        {
            cout<<"Enter Roll no to Set Course: ";
            int roll;
            cin>>roll;
            for (int i=0; i<vect.size(); i++)
            {
                if(vect.at(i)->getRoll()==roll)
                {
                    vect.at(i)->set_course();
                    flag=1;
                    break;
                }
            }
            if(flag==0)
                cout<<"\nStudent not found!!....\n";
            getch();
            system("cls");
        }
        break;

        case DISPLAY_SPECIFIC_STUDENT:
        {
            int roll;
            cout<<"Enter Roll No to Search: ";
            cin>>roll;
            for (int i=0; i<vect.size(); i++)
            {
                if(vect.at(i)->getRoll()==roll)
                {
                    cout<<"\n---------------------------------------------------------";
                    vect[i]->displayStudent();
                    vect[i]->getDisplayCourse();
                    cout<<"\n---------------------------------------------------------";
                }
            }
            getch();
            system("cls");

        }
        break;

        case DISPLAY_ALL_STUDENT:
            for (int i=0; i<vect.size(); i++)
            {
                cout<<"\n---------------------------------------------------------\n";
                vect[i]->displayStudent();
                vect[i]->getDisplayCourse();
                cout<<"\n---------------------------------------------------------\n";

            }
            getch();
            system("cls");
            break;

        }
    }

}


