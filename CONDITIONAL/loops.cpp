#include <iostream>
using namespace std;
int main() {
    int age;
    cin>>age;

    if(age<18)
    {
        cout<<"NOT ELIGIBLE FOR JOB";
    }
    else if(age<=54)
    {
        cout<<"ELIGIBLE FOR JOB";
    }
    else if(age>=55 && age<=57)
    {
        cout<<"eligible for job,but reirement soon";
    }
    else
    {
        cout<<"retirement time";
    }
    
    return 0;
}