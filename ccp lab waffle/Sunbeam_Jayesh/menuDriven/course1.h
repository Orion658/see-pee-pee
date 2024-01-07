#include <bits/stdc++.h>
using namespace std;

class Courses{
    string course_name;
    string fees;

    public:

        Courses()
        {
            course_name="";
            fees="";
        }

        Courses(string course_name, string fees)
        {
            this->course_name = course_name;
            this->fees = fees;
        }

        // void setCourse()
//         {
        //     cout<<"Courses Name : ";
        //     cin>>this->course_name;
        //     cout<<"Courses Fees : ";
        //     cin>>this->fees;
        // }

        void displayCourse()
        {
            if(this->course_name=="" && this->fees=="")
            {
                cout<<"\nNo Courses Enrolled!....\n";
                return;
            }
            cout<<"\nCourse Name : "<<this->course_name;
            cout<<"\nCourse Fees: "<<this->fees;
        }


};
