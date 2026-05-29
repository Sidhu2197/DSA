#include<iostream>
using namespace std;

class student{
    //prppoperties
    string name;
    float cgpa;

    //methods
    void getpercentage(){
        cout<<(cgpa*10);
    }

};

int main(){
    student s1;
    cout<<sizeof(s1);
    return 0;

}