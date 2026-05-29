#include<iostream>
#include<string>
using namespace std;

class car{
    string name;
    string colour;

    public:

    void start(){
        cout<<"your car has started"<<endl;
    }

    void stop(){
        cout<<"your car has been stopped"<<endl;
    }

    car(string namevalue,string colourvalue){
        cout<<"constructor is called object being created ";
        name=namevalue;
        colour=colourvalue;
    }

    //getter
    string getname(){
        return name;
    }
};

int main(){
    car c1("meow cat","orange");
    cout<<c1.getname()<<endl;
    return 0;
}