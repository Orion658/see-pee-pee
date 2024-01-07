 #include "course1.h"
#include<bits/stdc++.h>
using namespace std;

class Student{
    int roll_no;
    string name;
    string ph_no;
    string city;
    vector<Courses *> course;
    public:
        Student()
        {
            roll_no = 0;
            name = "";
            ph_no = "";
            city = "";
        }

        void set_course()
        {
            string course_name,fees;
            cout<<"\n\nCourses Name : ";
            cin>>course_name;
            cout<<"Courses Fees : ";
            cin>>fees;
            this->course.push_back(new Courses(course_name,fees));
            cout<<"\n--------------------------------"<<endl;
            cout<<"\tCourse added successfully "<<endl;
            cout<<"--------------------------------"<<endl;

        }

        void setStudent()
        {
            cout<<"\n\nEnter Roll No: ";
            cin>>this->roll_no;
            cout<<"Enter Name: ";
            cin>>this->name;
            cout<<"Enter Mobile Number: ";
            cin>>this->ph_no;
            cout<<"Enter City: ";
            cin>>this->city;

        }



        void displayStudent()
        {

            cout<<"\nName : "<<this->name;
            cout<<"\nRoll No. : "<<this->roll_no;
            cout<<"\nMobile Number: "<<this->ph_no;
            cout<<"\nCity : "<<this->city<<endl;
//            cout<<"\n---------------------------------------------------------\n";
        }

        void getDisplayCourse()
        {
            for (int i=0;i<course.size();i++)
            {
                course.at(i)->displayCourse();
            }
        }

        int getRoll(){return roll_no;}
        string getName(){return name;}
        string getPhno(){return ph_no;}
        string getCity(){return city;}


};
