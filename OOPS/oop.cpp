#include<iostream>
#include<string>
using namespace std;

class Student{
    public:
    //properties
    string name;
    float cgpa;

    //methods
    void getpercentage(){
        cout<<(cgpa*10)<<"% \n";
    }

    //setters
    void setname(string nameval){
        name=nameval;
    }

    void setcgpa(float cgpaval){
        cgpa=cgpaval;
    }

    //getters

    string getname(){
        return name;
    }

    float getcgpa(){
        return cgpa;
    }

    // class user{
    //     int id;
    //     string username;
    //     string password;
    //     string bio;

    //     void deactivate(){
    //         cout<<"deleting account";
    //     }

    //     void EditBio(string NewBio){
    //         bio=NewBio;
    //     }
    // };
};

int main(){
    Student s1;//object
    // s1.name="meow";
    // s1.cgpa=6.5;
    // cout<<"name of the student is : "<<s1.name<<endl;
    // cout<<"cgpa of the student is : " <<s1.cgpa<<endl;
    // s1.getpercentage();

    s1.setname("orange car");
    s1.setcgpa(9.8);

    cout<<"student name is : "<<s1.getname()<<endl;
    cout<<"cgpa of the student is : "<<s1.getcgpa()<<endl;
    return 0;
}