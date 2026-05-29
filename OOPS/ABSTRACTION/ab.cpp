#include<iostream>
#include<string>
using namespace std;

// a pure virtual function is a function with no definiton or no logic
// it is declared by assigning 0 at the tome of definition

// class Shape{
//     public:

//     void draw();//pure virtual function
// };

// abstract clas
class Shape{
    public:

    virtual void draw()=0;//abstract function and pure virtual function 
};

class Circle : public Shape{
    public:

    void draw(){
        cout<<"draw circle\n";
    }
};

class square : public Shape{
    public:
    void draw(){
        cout<<"draw square";
    }
};

int main(){
    Circle c1;
    c1.draw();

    square s1;
    s1.draw();
    return 0;
}